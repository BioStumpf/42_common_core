*This project has been created as part of the 42 curriculum by \<dstumpf\>.*

# Push Swap
## Description
**Push_swap** is a sorting algorithm project. The goal is to sort a list of integers using two stacks (`a` and `b`) and a limited set of predefined operations.

The allowed operations are:   
- **sa** — Swap the first two elements at the top of stack `a`.
- **sb** — Swap the first two elements at the top of stack `b`. (not used)
- **ss** — Perform `sa` and `sb` at the same time.
- **pa** — Push the top element from stack `b` onto stack `a`.
- **pb** — Push the top element from stack `a` onto stack `b`.
- **ra** — Rotate stack `a` upward (the first element becomes the last).
- **rb** — Rotate stack `b` upward.
- **rr** — Perform `ra` and `rb` at the same time. (not used)
- **rra** — Reverse rotate stack `a` (the last element becomes the first).
- **rrb** — Reverse rotate stack `b`.
- **rrr** — Perform `rra` and `rrb` at the same time.

**The program**:
- Receives a list of integers as arguments
- Validates input (format, duplicates, overflow, underflow, non-numeric characters etc.)
- Outputs a sequence of stack operations that sorts the numbers in ascending order.


**The algorithm**:   
Is based on the **quicksort divide-and-conquer strategy** and uses two recursive functions: `qsort_a` and `qsort_b`.

- `qsort_a` partitions the current subset of elements in stack `a` by pushing the lower half into stack `b`, keeping the higher half in `a`.
- `qsort_b` performs the opposite operation by pushing the higher half of stack `b` back into stack `a`.

By continuously dividing the data into smaller subsets, the problem is reduced step by step, significantly lowering the total number of operations required.

## Instructions
### Requirements
- **Linux**
- **clang** (```sudo apt install clang```)
- **make** (```sudo apt install make```)

### Compilation
- ```make``` will compile the binary
- ```make clean``` will remove all object and dependency files
- ```make fclean``` will clean and remove the binary
- ```make re``` will fclean and make

### Excecution
The binary accepts zero or more arguments. Each argument may contain one or multiple integers separated by spaces.   
```./push_swap 1 2 3```   
```./push_swap 3 2 1 "5 6 0 8" "100 55 -1000"```   
```./push_swap 1 2 3```   
```./push_swap```   

## Resources
- For visualization, the [push-swap-visualizer.vercel.app](https://push-swap42-visualizer.vercel.app/) tool was used.
- To better understand quicksort, the [GeeksforGeeks](https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/) article was used as a reference.
