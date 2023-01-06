Brief information about sorting
==========
- Bubble sort:

  The principle of operation. At each step, we find the largest element of the two neighboring ones and put this element at the end of the pair. It turns out that with each run of the cycle, large elements will float to the end of the array like air bubbles — hence the name.

- Selection sort: 
  
  The algorithm searches for the smallest element in the current list and exchanges its value with the value of the first unsorted position. The same thing happens with the second element with the smallest value. The cycle repeats until all the elements occupy the desired sequence.
  
- Inseerton sort: 

  After the next position is processed, we know that all positions before it are sorted, and after it — not. An important point: insertion sorting processes array elements in order. Since the algorithm goes through the elements from left to right, we know that everything to the left of the current index is already sorted.
  
- Quick sort:

  Initially, some element (the central element) is placed in its place, and the remaining elements are reordered in such a way that the smaller elements are to the left of the central element, and the larger ones are to the right. Then the recursive sorting of the left and right parts of the array is performed.

- Merge sort:

  This sorting is a good example of using the principle of "divide and conquer". First, the task is divided into several smaller subtasks. Then these tasks are solved using a recursive call or directly if their size is small enough. Finally, their solutions are combined, and the solution of the original problem is obtained.
  
- Shell sort:

  The sorting algorithm, which is an improved variant of sorting by inserts. The idea of the Shell method is to compare elements standing not only side by side, but also at a certain distance from each other. In other words, it is sorting by inserts with preliminary "rough" passes. A similar method of improving bubble sorting is called comb sorting.
