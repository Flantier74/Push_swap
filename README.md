*This activity has been created as part of the 42 curriculum by **eruffin**, **cribstei**.*

# DESCRIPTION

This push_swap project is a program that sorts a list of integers. It uses three
algorithms of different complexity class (simple, medium, complex) to sort the
list in the most efficient way.
Push_swap selects its algorithm based on the disorder of the list given as input.
Flags can be used to force the program to use one particular algorithm.

## Detail of program and algorithms:
The program first create two empty chained list 'stack a' and 'stack b' and then puts the values to sort into stack 'a'.<br>
Each algorithm will use basic operations: swap, push, roll, reverse on the chained lists to sorts the values.<br>

### Bubble sort:<br>
**Step 1 :** The algorith goes trough the chained list and compares the values at position n & position n+1 and swap when required, until reaching the end. The lower values are pushed to the front.<br>
**Step 2 :** Repeats step one until the chained is sorted.<br>

### Chunk base sorting:<br>
**Step 1 :** The algorith pushes all the values into 'stack b'<br>
**Creation of chunks:** The algorith will create √n chunks of range '(max - min) / √n'<br>
**Step 2 :** The algorith goes trough the chained list until finding values that can be pushed into stacked a.<br>
**Step 3 :** The algorithm then use and the simple algorithm 'insertion sort' to put the value at the good position.<br>

### Radix sort:
Radix sort is a non-comparative sorting algorithm. It ranks every value to be
sorted and sort by comparing the ranks instead of the element themselves.
The time complexity is 𝒪(n * k), where n is the number of elements and k is the
number of bits used to represent the highest rank.


# INSTRUCTIONS
### **Building**
```
make
```
This program uses stdlib.h (`malloc()`, `free()`) and unistd.h (`write()`).

### **USAGE**
push_swap [OPTION] LIST

### **OPTIONS**
`--simple`  
		Force the use of the simple algorithm (bubble sort, 𝒪(n²)).  

`--medium`  
		Force the use of the medium algorithm (chunk base sorting, 𝒪(n√n)).

`--complex`  
		Force the use of the complex algorithm (radix sort, 𝒪(nlog(n))).

`--adaptative`  
		Use the calculated disorder of the list to decide the algorithm to use.

# RESOURCES
AI was used to understand the difference between the algorithms by generating
   tests for each.

radix - https://github.com/To0nsa/push_swap

quicksort - https://www.youtube.com/watch?v=MZaf_9IZCrc
