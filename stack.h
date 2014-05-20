#include <vector>
#include <string>
#include <iostream>

#ifndef stack_h
#define stack_h

class Stack_C {
private:
	std::vector<std::string> items;

protected:
	
public:
	Stack_C();
	void push(std::string item);
	std::string pop();
	bool is_empty();
	int size();
	std::string peek();
};

#endif