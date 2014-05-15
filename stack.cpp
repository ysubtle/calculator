#include "stack.h"

Stack::Stack () {
}

char Stack::pop () {
	if (!this->is_empty()) {
		items.pop_back();
	} else {
		//To Do
	}
}

bool Stack::is_empty () {
	if (items.size() == 0) {
		return true;
	} else {
		return false;
	}
}

int Stack::size () {
	return items.size();
}

char Stack::peek () {
	return items.back();
}