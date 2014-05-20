#include "stack.h"

Stack_C::Stack_C () {
}

void Stack_C::push(std::string item) {
	items.push_back(item);
}

std::string Stack_C::pop () {
	if (!this->is_empty()) {
		items.pop_back();
	} else {
		//To Do
	}
}

bool Stack_C::is_empty () {
	if (items.size() == 0) {
		return true;
	} else {
		return false;
	}
}

int Stack_C::size () {
	return items.size();
}

std::string Stack_C::peek () {
	//return items[items.size() - 1];
	return "5";
}