#ifndef stack_h
#define stack_h

class Stack {
private:
protected:
public:
	void push(char item);
	char pop();
	bool is_empty();
	int size();
	char peek();
};

#endif