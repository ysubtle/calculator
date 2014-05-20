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

class Calculator {
private:
	Fl_Button* display;
	Fl_Button* enter;
	Stack* operands;
	Stack* operators;
	std::string number;
protected:
	
public:
	Calculator();
	int make_interface();
	void press (std::string) const;	
	void do_math (int, int, std::string);
	void update_display();
};

#endif