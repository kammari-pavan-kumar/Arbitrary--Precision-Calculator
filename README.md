# Arbitrary Precision Calculator (APC)

## Project Description

The Arbitrary Precision Calculator (APC) is a C application designed to perform arithmetic operations on very large integers using Doubly Linked Lists.

It supports calculations on numbers that exceed the limits of standard integer data types.

## Features

- Addition
- Subtraction
- Multiplication
- Division
- Handling very large integers
- Support for positive and negative numbers
- Input validation
- Error handling for division by zero

## Technologies Used

- C Programming
- Doubly Linked Lists
- Dynamic Memory Allocation
- Command-Line Arguments
- Data Structures

## Arithmetic Operations

| Operator | Operation |
|---|---|
| `+` | Addition |
| `-` | Subtraction |
| `x` | Multiplication |
| `/` | Division |

## Compilation

Compile the project using the provided Makefile:

    make

Check the `makefile` for the compilation instructions.

## How to Run

Run the executable with two operands and an operator.

### 1. Addition

Command:

    ./a.out 20 + 40

Output:

    60

Example with large numbers:

    ./a.out 9999999999999999999999999999999999999999 + 1111111111111111111111111111111111111111

Output:

    11111111111111111111111111111111111111110

### 2. Subtraction

Command:

    ./a.out 40 - 20

Output:

    20

Example with negative result:

    ./a.out 423 - 478

Output:

    -55

### 3. Multiplication

Command:

    ./a.out 40 x 20

Output:

    800

Example with negative result:

    ./a.out 23 x -24

Output:

    -552

### 4. Division

Command:

    ./a.out 40 / 20

Output:

    2

Example with negative result:

    ./a.out 40 / -20

Output:

    -2

## Error Handling

The program validates command-line arguments and numeric operands.

### Invalid Arguments

Command:

    ./a.out -23 @ 45

Output:

    INFO: Enter Correct Arguments
    INFO : Validation Failure

### Invalid Number

Command:

    ./a.out -4a56 + 23

Output:

    INFO: Invalid number in argv[1]
    INFO : Validation Failure

### Division by Zero

Command:

    ./a.out 423 / 0

Output:

    ERROR: Value can't be Divided by zero

## Project Structure

- `main.c` - Main program and operation selection.
- `addition.c` - Addition implementation.
- `substraction.c` - Subtraction implementation.
- `multiplication.c` - Multiplication implementation.
- `division.c` - Division implementation.
- `create_two_dll.c` - Doubly linked list creation.
- `insert_at_first.c` - Inserts a node at the beginning.
- `insert_at_last.c` - Inserts a node at the end.
- `print_list.c` - Prints the linked list.
- `validation.c` - Validates arguments and numbers.
- `dll.h` - Doubly linked list declarations.
- `makefile` - Compilation instructions.
- `doc.txt` - Project documentation and additional examples.

## Learning Outcomes

- Understanding doubly linked lists.
- Implementing arithmetic operations in C.
- Working with large integers beyond standard data type limits.
- Using dynamic memory allocation.
- Validating command-line arguments and handling errors.

## Author

K. Pavan Kumar
