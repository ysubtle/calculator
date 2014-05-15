#include <Fl/Fl_Button.H>

#ifndef calc_button_h
#define calc_button_h

class Calc_Button : public Fl_Button {
private:
	int id;
	Fl_Button* display;
public:
	Calc_Button (int x, int y, int w, int h, const char* label,
		int id, Fl_Button* display)
	: Fl_Button (x, y, w, h, label) {
		this->id = id;
		this->display = display;
	}

	Fl_Button* get_display () {
		return this->display;
	}

	static callback (Fl_Widget* w, void*) {
		Calc_Button* btn = (Calc_Button*) w;
		Fl_Button* display = btn->get_display();

	}
};

#endif
