#include <vector>
#include <string>

#ifndef stack_h
#define stack_h

class Stack {
private:
	std::vector<std::string> items;

protected:
	
public:
	Stack();
	void push(std::string item);
	char pop();
	bool is_empty();
	int size();
	char peek();
};

#endif