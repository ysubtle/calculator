#include <Fl/Fl_Button.H>

#include <string>

#ifndef calc_button_h
#define calc_button_h

class Calc_Button : public Fl_Button {
private:
	std::string val;
	Fl_Button* display;
	calculator* calc;
public:
	Calc_Button (int x, int y, int w, int h, const char* label,
		std::string val, Fl_Button* display, calculator* const calc)
	: Fl_Button (x, y, w, h, label) {
		this->val = val;
		this->display = display;
		this->calc = calc;
	}

	Fl_Button* get_display () {
		return this->display;
	}

	static void cb_click (Fl_Widget* w, void*) {
		Calc_Button* btn = (Calc_Button*) w;
		Fl_Button* display = btn->get_display();
		this->calc->press(this->val);
	}
};

#endif
