#include <iostream>
#include "Stack_Header.h"

using namespace std;


int main(){
	
	stack<int> st;

	for (int i = 0; i < 10; i++) {
		st.push(i+10);
	}

	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.top() << std::endl;
	std::cout << st.peek(4);

}

