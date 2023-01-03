#include <iostream>
#include "Header_stack_ols.h"

int main() {
	
	stack<int> st;
	
	st.push(4);
	st.push(3);

	std::cout << st.top() << " ";
	st.pop();
	std::cout << st.top();
	st.pop();
}