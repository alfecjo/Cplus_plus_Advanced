# STL Containers – Test Programs

This repository contains a collection of small C++ programs designed to explore and demonstrate the behavior and usage of various containers provided by the Standard Template Library (STL). These examples cover common operations, custom object handling, and iterator-based traversal across different container types.

## Purpose

The goal of these examples is to:

- Understand how STL containers like `vector`, `deque`, `list`, and `stack` work.
- Illustrate how elements can be inserted, erased, or printed using iterators and container member functions.
- Experiment with custom classes and overloading of operators in combination with containers.
- Demonstrate reverse iteration and memory management with dynamically allocated objects in containers.

## Containers Covered

- **`std::vector`** – Examples of element insertion, deletion by position or iterator, reverse iteration, and interaction with custom objects.
- **`std::deque`** – Used as an underlying container to initialize a stack.
- **`std::list`** – Tested for compatibility and interoperability with other container adapters.
- **`std::stack`** – Stack container adapter used with different underlying containers.
- **Pointer containers** – Handling dynamically allocated objects within containers and ensuring proper cleanup.

## Key Features

- Use of **custom types** (`class A`) within containers.
- Implementation of **`operator<<`** to support formatted output.
- Demonstration of **reverse iterators** (`rbegin`, `rend`).
- Explicit **memory management** (`new` and `delete`) when using containers of pointers.
- Template-based **generic print functions** for iterators.

## How to Use

Each program is self-contained and can be compiled individually with any standard C++ compiler, such as `g++`:

```bash
g++ tx.cpp -o tx
./tx

```
---

## 👤 Author
**[Antonio Almeida](https://alfecjo.github.io/)**

**Platform:** Ubuntu + GCC  
**Language:** C++17/C++20  

---

- ## Return to the main page
  [![C++ Advanced Projects](https://img.shields.io/badge/C++_Advanced-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/Cplus_plus_Advanced/tree/main)
