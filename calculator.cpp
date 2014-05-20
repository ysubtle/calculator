#include "calculator.h"

#include "calc_button.h"

#include <iostream>
#include <cmath> 
#include <math.h> 

bool check_in (std::string, std::vector<std::string>);

Calculator::Calculator () {
	operands_stack = new Stack_C();
	//Stack_C* operators = new Stack_C();
	number = "";
	error = "";
	this->make_interface();
}

int Calculator::make_interface () {
	std::vector<std::string> btn_values {
		"+",
		"-",
		"*",
		"/",
		"^",
		"+-",
		"sqrt",
		"drop",
		"0",
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9"
	};


	Fl_Window* window = new Fl_Window(400, 700);

	display = new Fl_Button(24, 20, 352, 150, "");

	// Button Constants
	int width = 70;
	int height = 60;
	int id = 0;

	// dependent on i2
	int offset_x = 0;
	// dependent on i
	int offset_y = 0;
	int gutter_x = 24;
	int gutter_y = 20;
	for (int i = 0; i < 5; i++) {
		for (int i2 = 0; i2 < 4; i2++) {
			offset_x = gutter_x + (i2 * (gutter_x + width));
			offset_y = 190 + (i * (gutter_y + height));
			if (i < 3 || (i >= 3 && i2 < 3)) {
				Calc_Button* btn = new Calc_Button(offset_x, offset_y, width, height, "",
				btn_values[id], display, this);
				btn->copy_label(btn_values[id].c_str());
				btn->callback(Calc_Button::cb_click, 0);
				id++;
			}
		} 
	}

	enter = new Calc_Button(306, 430, 70, 140, "Enter",
		"enter", display, this);
	enter->callback(Calc_Button::cb_click, 0);

	display_stack = new Fl_Button(gutter_x, 600 + gutter_y, 352, 60, "Empty Stack");

	Fl_Box* title = new Fl_Box(gutter_x, 587, 352, 20, "Top 4 Elements of Stack");
	//enter = new Fl_Button(306, 430, 70, 140, "Enter");
	window->end();
	window->show();
	return Fl::run();
}

//void Calculator::press (const char* val) const {
void Calculator::press (std::string val) {
	std::vector<std::string> operands {
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
	};
	std::vector<std::string> operators {
		"+", "-", "*", "/", "^"
	};
	std::vector<std::string> special {
		"+-", "drop", "enter"
	};

	if (check_in(val, operands)) {
		number.append(val);
	} else if (check_in(val, operators)) {
		if (number != "") {
			operands_stack->push(number);
		}	
		if (operands_stack->size() < 2) {
			std::cout << "There is not enough on the stack!" << std::endl;
			error = "There is not enough on the stack!";
		} else {
			
			float i_1 = std::stof(operands_stack->pop());
			float i_2 = std::stof(operands_stack->pop());
			float result = this->do_math(i_2, i_1, val);
			operands_stack->push(std::to_string(result));
			number = "";
		}
	} else if (val == "sqrt") {
		if (number != "") {
			operands_stack->push(number);
		}
		float i_1 = std::stoi(operands_stack->pop());
		float result = this->do_math(i_1, 0, val);
		operands_stack->push(std::to_string(result));
		number = "";
	} else if (check_in(val, special)) {
		if (val == "enter") {
			operands_stack->push(number);
			number = "";
		}
		if (val == "drop") {
			if (error != "") {
				error == "";
			} else if (!operands_stack->is_empty()) {
				operands_stack->pop();
			}
		}
		if (val == "+-") {
			if (!operands_stack->is_empty()) {
				std::string number = operands_stack->pop();
				if (number.at(0) == '-') {
					number.erase(number.begin());
				} else {
					number.insert(number.begin(), '-');
				}
				operands_stack->push(number);
			}
			
		}
	}
	this->update_display();
	this->update_display_stack();
}

bool check_in (std::string token, std::vector<std::string> list) {
	bool flag = false;
	for (int i = 0; i < list.size(); i++) {
		if (token == list[i]) {
			flag = true;
		}
	}
	return flag;
}

void Calculator::update_display () {
	std::string display_str;
	if (error != "") {
		display_str = error;
		error = "";
	} else if (number == "") {
		display_str = operands_stack->peek();
	} else {
		display_str = number;
	}
	display->copy_label(display_str.c_str());
};

void Calculator::update_display_stack () {
	display_stack->copy_label(operands_stack->print().c_str());
}

float Calculator::do_math (float op1, float op2, std::string op) {
	if (op == "+") {
		return op1 + op2;
	}
	if (op == "-") {
		return op1 - op2;
	}
	if (op == "*") {
		return op1 * op2;
	}
	if (op == "/") {
		return op1 / op2;
	}
	if (op == "^") {
		return pow(op1, op2);
	}
	if (op == "sqrt") {
		return sqrt(op1);
	}

}
