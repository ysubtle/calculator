#include "calculator.h"

calculator::calculator () {
	this->make_interface();
}

int calculator::make_interface () {
	std::cout << "Test" << std::endl;
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


	Fl_Window* window = new Fl_Window(400, 600);

	Fl_Button* display = new Fl_Button(24, 20, 352, 150, "");

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
				id);
				btn->copy_label(btn_values[id].c_str());
				id++;
			}
		} 
	}
	Fl_Button* enter = new Fl_Button(306, 430, 70, 140, "Enter");

	window->end();
	window->show();
	return Fl::run();
}