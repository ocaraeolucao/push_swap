*This project has been created as part of the 42 curriculum by **lsantann** and **luvieira**.*

## Description

**Push_swap** is a program that sorts a random list of integers using two stacks and a limited set of stack operations.

The goal of this project is to deepen understanding of fundamental C programming concepts, including:
* **Data Structures:** Doubly linked lists for efficient stack manipulation.
* **Algorithm Efficiency:** Application of Big-O notation in real-world scenarios.
* **Sorting Algorithms:** Implementation of custom non-comparison and heuristic-based sorts.
* **Architecture:** Modular system design with an adaptive strategy engine and a robust benchmark suite.

## Instructions

### Compilation

* **Compile the program:** `make`
* **Clean object files:** `make clean`
* **Full cleanup (objects + executable):** `make fclean`
* **Recompile everything:** `make re`

### Usage in your projects

```bash
./push_swap 3 2 1

./push_swap --adaptive 5 2 8 1 3

./push_swap --bench --complex 3 2 1
```

## Push_swap Program

## 1. Algorithms

- **Selection sort**: Rotates the stack until the target element reaches the top, pushes it to stack B, and rebuilds stack A in sorted order.
- **Chunk sort**: Splits the input into chunks, moves them to stack B, and reconstructs stack A efficiently.
- **Radix Sort**: Processes the indexed values bit by bit. Elements with a 0 at the current bit are pushed to stack B, while the others are rotated in stack A.

## 2. Benchmark Mode

Enable benchmarking with:

```bash
./push_swap --bench --adaptive 3 2 1
```

The benchmark reports:

- Disorder percentage
- Selected strategy
- Complexity class
- Total number of operations
- Count of each operation

## 3. Flags

Available flags:

- --simple
- --medium
- --complex
- --adaptive
- --bench

## Resources

### Documentation
- [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [man pages](https://man7.org/linux/man-pages/)
- [42 Norminette Documentation](https://github.com/42School/norminette)

### AI Usage

For this project, AI was used in the following ways:
- Code review to identify edge cases
- Debugging off-by-one errors
- Assistance with README structure

## 👥 Authors & Contributions

### Luciano Santanna (`lsantann`)
* Stack primitives & core operations (`sa`, `pb`, `ra`, etc.)
* **Radix Sort** algorithm implementation
* Error handling & memory leak prevention
* Linked list utility functions

### Lucas Vieira (`luvieira`)
* **Selection Sort** & **Chunk Sort** algorithms implementation
* **Benchmark mode** engine & metrics logic
* Input parsing, validation, and indexing
* Project directory structure & global architecture
