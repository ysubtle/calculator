// FL
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <string>

#include "calc_button.h"
#include "stack.h"

#ifndef calculator_h
#define calculator_h

class calculator {
private:
	Fl_Button* display;
	Fl_Button* enter;
	Stack* operands;
	Stack* operators;
protected:
public:
	calculator();
	int make_interface();
	void press(std::string);	
};

#endif