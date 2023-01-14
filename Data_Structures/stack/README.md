Stack PLS
=========

- The top of the stack started the first element
  - During the operation of inclusion and exclusion, all elements are shifted by one position to the end or to the beginning, respectively, 
  thereby increasing the complexity

- The top of the stack is the last element
  - During the inclusion operation, it is necessary to include a new element and make it the top of the stack, i.e. 
    increase the index of the current element. When performing an exclusion operation, 
     reduce the index of the current element, and exclude the next one after it.

Stack OLS
=========
- The top of the stack started the first element
  - The pointer of the current OLS element should point to a dummy element.
    The operations of reading, including and excluding an element are performed quickly enough, 
    do not require changing the pointer to the current element and moving the elements


- The top of the stack is the last element
  - When performing read operations and including an element in the stack, the current OLS element must be the last OLS element.
      When performing an exclusion operation, the current element must be the penultimate one in the OLS, 
      to search for which it is necessary to stand at the beginning of the OLS and subsequently go through all the elements to the penultimate one, 
      constantly re-dividing the pointer to the current element, which requires unjustified calculations and time.
