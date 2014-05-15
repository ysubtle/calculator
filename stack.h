#include <vector>

#ifndef stack_h
#define stack_h

class Stack {
private:
	std::vector<char> items;
protected:
public:
	Stack();
	void push(char item);
	char pop();
	bool is_empty();
	int size();
	char peek();
};

#endif