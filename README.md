# push_swap

A sorting algorithm project that utilizes two stacks and a limited set of operations to sort a list of integers efficiently.

---

## 📌 Project Description

`push_swap` is a project developed as part of the **42 School** curriculum. The objective is to sort a list of integers using two stacks, `A` and `B`, and a predefined set of operations. The challenge lies in achieving the sorting with the minimum number of moves.

The primary objectives of this project are:

- To develop an algorithm that sorts integers with minimal operations.
- To implement and utilize specific stack operations effectively.
- To handle edge cases, such as duplicate numbers and varying list sizes.

### ✨ Technologies Used

- **C language** – For system-level programming and algorithm implementation.
- **Makefile** – For build automation.

### 💡 Challenges Faced

- Designing an efficient sorting algorithm that minimizes the number of operations.
- Managing two stacks and ensuring the correct sequence of operations.
- Handling edge cases, including duplicate numbers and varying list sizes.

---

## 📖 Table of Contents

- [Project Description](#project-description)
- [How to Install and Run the Project](#how-to-install-and-run-the-project)
- [How to Use the Project](#how-to-use-the-project)
- [File Structure & Descriptions](#file-structure--descriptions)

---

## 🛠 How to Install and Run the Project

To compile and use the `push_swap` program, follow these steps:

```bash
# Clone the repository
git clone https://github.com/Thanagorn16/push_swap.git
cd push_swap

# Build the program
make
```
---

## 🚀 How to Use the Project
The push_swap program takes a list of integers as arguments and outputs a sequence of operations to sort them. Here's how to use it:
```bash
./push_swap [list of integers]

for example:

./push_swap 4 67 3 87 23

```
The program will output a sequence of operations to sort the numbers. These operations include:

* sa : Swap the first two elements of stack A.

- sb : Swap the first two elements of stack B.

- ss : Perform sa and sb simultaneously.

- pa : Push the top element from stack B to stack A.

- pb : Push the top element from stack A to stack B.

- ra : Rotate stack A upwards.

- rb : Rotate stack B upwards.

- rr : Perform ra and rb simultaneously.

- rra : Reverse rotate stack A downwards.

- rrb : Reverse rotate stack B downwards.

- rrr : Perform rra and rrb simultaneously.

>Ensure that the input numbers are all integers and do not contain duplicates.

---

## 📁 File Structure & Descriptions
Each file in this repository serves a specific purpose in the implementation of the `push_swap` program:

- `push_swap.c` – The main program that initializes stacks and triggers the sorting process.

- `push_swap.h` – The header file containing function prototypes, macro definitions, and necessary includes.

- `check_err.c` – Handles error checking and validation of input arguments.

- `ft_lstadd_back.c` – Adds a new element at the end of a linked list.

- `ft_lstfront.c` – Adds a new element at the beginning of a linked list.

- `ft_lstlast.c` – Returns the last element of a linked list.

- `ft_lstnew.c` – Creates a new linked list element.

- `ft_lstsize.c` – Returns the number of elements in a linked list.

- `sort_big_stack.c` – Implements sorting algorithms for larger stacks.

- `sort_five.c` – Implements sorting algorithms specifically for stacks of five elements.

- `sort_five_utils.c` – Utility functions to assist with sorting five elements.

- `sort_three.c` – Implements sorting algorithms specifically for stacks of three elements.

- `sort_two.c` – Implements sorting algorithms specifically for stacks of two elements.

- `sorting.c` – Contains the main sorting logic and operation executions.

- `util.c` – Utility functions for stack operations and management.

- `Makefile` – Automates the compilation and cleaning processes for the project.

---
