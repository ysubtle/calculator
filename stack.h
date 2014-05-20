#include <vector>
#include <string>
#include <iostream>

#include "node.h"

#ifndef stack_h
#define stack_h

class Stack_C {
private:
	Node* head;
	int length;
protected:
	
public:
	Stack_C();
	void push(std::string);
	std::string pop();
	bool is_empty();
	int size();
	std::string peek();
};

#endif