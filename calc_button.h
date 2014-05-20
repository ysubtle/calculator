#include <Fl/Fl_Button.H>

#include <string>

#ifndef calc_button_h
#define calc_button_h

#include "calculator.h"

class Calc_Button : public Fl_Button {
private:
	std::string val;
	Fl_Button* display;
	Calculator* calc;
public:
	Calc_Button (int x, int y, int w, int h, const char* label,
		std::string val, Fl_Button* display, Calculator* calc)
	: Fl_Button (x, y, w, h, label) {
		this->val = val;
		this->display = display;
		this->calc = calc;
	}

	Fl_Button* get_display () {
		return this->display;
	}

	Calculator* get_calculator () {
		return this->calc;
	}

	std::string get_value () {
		return this->val;
	}

	static void cb_click (Fl_Widget* w, void*) {
		Calc_Button* btn = (Calc_Button*) w;
		Calculator* calc = btn->get_calculator();
		std::string val = btn->get_value();
		Fl_Button* display = btn->get_display();
		//const char* testing = val.c_str();
		calc->press(val);
	}
};

#endif
