#pragma once
#include <assert.h>

template <typename T> class stack {
public:

	stack();

	bool empty();

	void push(T value);

	T top();

	void pop();

	~stack();

private:

	template <typename type> struct Element {
		type data;
		Element<T>* next;
		size_t size;
	};

	Element<T>* head;
};

template <typename T> stack<T>::stack() : head(nullptr) {}

template <typename T> bool stack<T>::empty() {
	return head == 0 ? 0 : 1;
}

template <typename T> void stack<T>::push(T value) {
	Element<T>* node = (Element<T>*)malloc(sizeof(T) * sizeof(T));
	node->data = value;

	node->next = head;
	head = node;
}

template <typename T> T stack<T>::top() {
	if (head != 0)
		return head->data;
	else
		assert(head != 0, "Error stack empty!");
}

template <typename T> void stack<T>::pop() {
	if (head != 0)
		head = head->next;
	else
		assert(head != 0, "Error stack empty!");
}

template <typename T> stack<T>::~stack() {
	delete[] head;
}