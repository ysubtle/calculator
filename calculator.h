// FL
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <string>


#include "stack.h"

#ifndef calculator_h
#define calculator_h

class Calc_Button;

class Calculator {
private:
	Fl_Button* display;
	Fl_Button* display_stack;
	Calc_Button* enter;
	std::string number;
	std::string error;
	Stack_C* operands_stack;
	std::string display_current;
protected:
	
public:
	Calculator();
	int make_interface();
	void press (std::string);	
	float do_math (float, float, std::string);
	void update_display();
	void update_display_stack();
};

#endif