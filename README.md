# GenericDataStructuresLibrary

This project implements a collection of fundamental **data structures and algorithms in C++ using templates**, allowing them to work with multiple data types. The implementation focuses on understanding internal working mechanisms rather than relying on STL containers.

---

# Data Structures & Algorithms Library – Pure Implementation in C++

## Overview

This project provides a **generic implementation of classic data structures and algorithms** using C++ templates. The goal is to demonstrate how core structures like **Linked Lists, Stacks, Queues, Sorting algorithms, and Searching algorithms** work internally.

Unlike the C++ STL, this project builds everything **from scratch**, helping learners understand memory management, pointer manipulation, and algorithm design.

All data structures are implemented using **generic programming (templates)** so they can operate with any data type.

This project provides practical understanding of:

- Data Structures
- Algorithm Design
- Pointer Manipulation
- Dynamic Memory Management
- Generic Programming in C++

---

# Key Features

## Generic Template Implementation
All data structures are implemented using **C++ templates**, allowing them to work with different data types such as:

- int
- float
- char
- double
- user-defined types

---

# Implemented Data Structures

## 1. Stack (StackX)

A **Last In First Out (LIFO)** data structure implemented using a singly linked list.

Operations implemented:

- push()
- pop()
- Display()
- Count()

Key Concepts:

- Dynamic memory allocation
- Linked list based stack implementation

---

## 2. Queue (Queue)

A **First In First Out (FIFO)** data structure implemented using linked lists.

Operations implemented:

- enqueue()
- dequeue()
- Display()
- Count()

Key Concepts:

- FIFO principle
- Dynamic node allocation

---

## 3. Singly Linear Linked List (SinglyLLL)

A basic linked list where each node points to the next node.

Operations implemented:

- InsertFirst()
- InsertLast()
- DeleteFirst()
- DeleteLast()
- InsertAtPos()
- DeleteAtPos()
- Display()
- Count()

Key Concepts:

- Node traversal
- Dynamic insertion and deletion

---

## 4. Doubly Linear Linked List (DoublyLLL)

Each node contains two pointers:

- Next pointer
- Previous pointer

Operations implemented:

- InsertFirst()
- InsertLast()
- DeleteFirst()
- DeleteLast()
- InsertAtPos()
- DeleteAtPos()
- Display()
- Count()

Key Concepts:

- Bidirectional traversal
- Efficient node deletion

---

## 5. Singly Circular Linked List (SinglyCLL)

A circular list where the last node points back to the first node.

Operations implemented:

- InsertFirst()
- InsertLast()
- DeleteFirst()
- DeleteLast()
- InsertAtPos()
- DeleteAtPos()
- Display()
- Count()

Key Concepts:

- Circular traversal
- Maintaining first and last pointers

---

## 6. Doubly Circular Linked List (DoublyCLL)

A circular list with both **next and previous pointers**.

Operations implemented:

- InsertFirst()
- InsertLast()
- DeleteFirst()
- DeleteLast()
- InsertAtPos()
- DeleteAtPos()
- Display()
- Count()

Key Concepts:

- Circular linking
- Two-way traversal

---

# Implemented Algorithms

## Sorting Algorithms

The project includes a **generic sorting class** that supports multiple sorting algorithms.

Algorithms implemented:

- Bubble Sort
- Efficient Bubble Sort
- Selection Sort
- Insertion Sort

Features:

- Generic implementation using templates
- Supports multiple data types
- Includes optimized bubble sort

Concepts covered:

- Time complexity analysis
- In-place sorting
- Algorithm optimization

---

## Searching Algorithms

The project includes a **generic searching class** supporting multiple searching techniques.

Algorithms implemented:

- Linear Search
- Bi-Directional Search
- Binary Search (Ascending)
- Binary Search (Descending)
- Efficient Binary Search

Features:

- Automatic detection of sorted arrays
- Switches to binary search when possible
- Supports both ascending and descending order arrays

Concepts covered:

- Search optimization
- Algorithm selection based on data ordering

---

# Memory Management

The project uses:

- **Dynamic memory allocation**
- **Pointer-based node structures**
- **Manual memory deallocation**

This helps understand how memory is managed internally without relying on STL containers.

---

# Technologies Used

- **Language:** C++
- **Concepts:** Templates, Pointers, Dynamic Memory Allocation
- **Paradigm:** Object-Oriented Programming

---

# Educational Purpose

This project is designed to help understand:

- Internal working of data structures
- Algorithm implementation
- Template programming
- Pointer manipulation
- Memory management in C++

---

# Project Structure

The project contains implementations for:

- Stack
- Queue
- Singly Linked List
- Doubly Linked List
- Singly Circular Linked List
- Doubly Circular Linked List
- Sorting Algorithms
- Searching Algorithms

All implementations are written in **pure C++ without using STL containers**.

---

# How to Compile and Run

```bash
//Compile
g++ datastructures.cpp -o Myexe

//Run
./Myexe (for Linux distro or Mac)
Myexe.exe (for Windows)
