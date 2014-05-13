#include <Fl/Fl_Button.H>

#ifndef calc_button_h
#define calc_button_h

class Calc_Button : public Fl_Button {
private:
	int id;
public:
	Calc_Button (int x, int y, int w, int h, const char* label,
		int id)
	: Fl_Button (x, y, w, h, label) {
		this->id = id;
	}
};

#endif