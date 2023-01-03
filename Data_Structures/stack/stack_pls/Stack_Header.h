#define _CRTDBG_MAP_ALLOC

template<typename T>
class stack {
public:

	stack();

	stack(const int size);

	void push(T element);

	void pop();

	T top();

	bool empty();

	T peek(const int n);

private:
	T* data;
	int __ptr;
	int __max_size;
};

template<typename T>
stack<T>::stack() {
	data = nullptr;
	__ptr = 0;
	__max_size = INT_MAX;
}

template<typename T>
stack<T>::stack(const int size) : __max_size(size) {
	__ptr = 0;
	data = nullptr;
}

template<typename T>
void stack<T>::push(T element) {
	if (__max_size == INT_MAX) {
		data = (T*)realloc(data, (__ptr * 2 * sizeof(T)));
		__ptr += 1;
		data[__ptr] = element;
	}
	else {
		if (__ptr != __max_size) {
			data = (T*)realloc(data, (__ptr * 2 * sizeof(T)));
			__ptr += 1; data[__ptr] = element;
		}
		else {
			std::cerr << " Error" << std::endl;
			exit(-42);
		}
	}
}

template<typename T>
void stack<T>::pop() {
	if (__ptr > 0) {
		--__ptr;
	}
	else {
		std::cerr << "Error" << std::endl;
		exit(-42);
	}
}
template<typename T>
T stack<T>::top() {
	if (__ptr > 0)
		return static_cast<T>(data[__ptr]);
	exit(-42);
}

template<typename T>
bool stack<T>::empty() {
	if (!(__ptr > 0))
		return true;
	return false;
}

template<typename T>
T stack<T>::peek(const int n) {
	if (__ptr >= n) {
		return data[n];
	}
	else {
		std::cerr << "Error " << std::endl;
		exit(-42);
	}
}