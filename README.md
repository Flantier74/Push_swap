*This activity has been created as part of the 42 curriculum by **eruffin**, **cribstei**.*

# DESCRIPTION

This push_swap project is a program that sorts a list of integers. It uses three
algorithms of different complexity class (simple, medium, complex) to sort the
list in the most efficient way.
Push_swap selects its algorithm based on the disorder of the list given as input.
Flags can be used to force the program to use one particular algorithm.

TODO: input greater than int range.

# INSTRUCTIONS
### **Building**
```
make
```
This program uses stdlib.h (`malloc()`, `free()`) and unistd.h (`write()`).

### **USAGE**
push_swap [OPTION] LIST

### **OPTIONS**
--simple
		Force the use of the simple algorithm (bubble sort, 𝒪(n²)).

--medium
		Force the use of the medium algorithm ( sort, 𝒪(n√n)).

--complex
		Force the use of the complex algorithm (radix sort, 𝒪(nlog(n))).

--adaptative
		Use the calculated disorder of the list to decide the algorithm to use.

# RESOURCES
AI was used to understand the difference between the algorithms by generating
   tests for each.
radix - https://github.com/To0nsa/push_swap
quicksort - https://www.youtube.com/watch?v=MZaf_9IZCrc
