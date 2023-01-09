Tree implementation
====================
The tree elements are in an array located in dynamic memory. The base type depends on the task. 
Each element of the array has a sign of whether it is a tree element or "free". The root of the tree is located in the first element of the array. 
For a tree vertex located in the nth element of the array, LSon will be in the (2*n)th element, and RSon will be in the (2*n + 1)th element.

- Tasks
Tasks:
1) Build a tree
2) Output all the leaves
3) Output outputs all paths from the leaves to the root (in the i-th line you are the water - the i-th path).

Program output:

![image](https://user-images.githubusercontent.com/97832253/211320851-ae9ce216-7fb1-4d7d-a652-e366a431d5cd.png)

The tree from the example

![image](https://user-images.githubusercontent.com/97832253/211320995-e1ed5df4-307a-413d-8e3c-39ea77e50cde.png)
