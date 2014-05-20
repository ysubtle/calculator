#include "stack.h"

Stack_C::Stack_C () {
	head = NULL;
	length = 0;
}

void Stack_C::push(std::string item) {
	Node* node_new = new Node();
	node_new->data = item;
	node_new->next = head;
	head = node_new;
	length++;
}

std::string Stack_C::pop () {
	if(this->is_empty()) {
		std::cout << "Empty!" << std::endl;
		return "\0";
	}
	std::string item_pop;
	item_pop = head->data;
	Node* node_delete = head;
	head = head->next;
	delete node_delete;
	length--;
	return item_pop;
}

bool Stack_C::is_empty () {
	if (head == NULL) {
		return true;
	} else {
		return false;
	}
}

int Stack_C::size () {
	return this->length;
}

std::string Stack_C::peek () {
	if(this->is_empty()) {
		std::cout << "Empty!" << std::endl;
		return "\0";
	}
	return head->data;
}

std::string Stack_C::print () {
	std::string stack_string = "";
	if(this->is_empty()) {
		return "Empty Stack";
	} else {
		Node* node_current = head;
		stack_string.append(node_current->data);
		for (int i = 0; i < length - 1 && i < 3; i++) {
			stack_string.append(" / ");
			node_current = node_current->next;
			stack_string.append(node_current->data);
		}
		
		return stack_string;
	}
}