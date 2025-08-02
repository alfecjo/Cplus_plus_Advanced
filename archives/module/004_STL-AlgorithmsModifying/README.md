# Algorithms - Modifying in C++

## 🧾 Overview

**Modifying algorithms** are part of the C++ Standard Template Library (STL) that operate on container elements and may alter their values, reorder them, or remove them entirely.

These algorithms are fundamental when transformation, copying, replacement, or removal of elements is required.

---

## 📦 Categories of Modifying Algorithms

Some commonly used modifying algorithms include:
- `std::copy`, `std::copy_if`
- `std::move`
- `std::swap`, `std::iter_swap`, `std::swap_ranges`
- `std::transform`
- `std::replace`, `std::replace_if`
- `std::fill`, `std::generate`
- `std::remove`, `std::remove_if`, `std::unique`
- `std::reverse`, `std::rotate`
- `std::partition`, `std::stable_partition`

- [`std::containers`](https://en.cppreference.com/w/cpp/container.html): Containers.

> ⚠️ Note: These functions often require output iterators or allow in-place modification. Use them carefully with regard to container size and iterator validity.

---

## ⚙️ Characteristics

- Mutating: Modify values or structure of elements.
- Iterator-based: Compatible with any container that provides valid iterators.
- Predicate support: Many accept predicates for conditional modification.
- Useful for: Reordering, transforming, filtering, or filling ranges.

---

## 📌 Key Functions

- `std::copy`, `std::copy_if`
  Copy elements (optionally filtered) from one range to another.

- `std::move`
  Move elements from one range to another, transferring ownership.

- `std::transform`
  Apply a function to each element and write the result to a new range.

- `std::replace`, `std::replace_if`
  Replace elements matching a value or predicate.

- `std::fill`, `std::generate`
  Assign values or generated data across a range.

- `std::remove`, `std::remove_if`, `std::unique`
  Eliminate duplicates or unwanted values from a range.

- `std::reverse`, `std::rotate`
  Reorder elements within a container.

- `std::partition`, `std::stable_partition`
  Reorganize a container so that elements satisfying a condition appear first.

📝 Copying all odd numbers from one vector to another (`std::copy_if`)

🧪 Applying a square function to each element (`std::transform`)

🧹 Removing all zeros from a container (`std::remove_if`)

♻️ Reversing the order of elements (`std::reverse`)

---

### 📘 STL Algorithms Non-Modifying - mixed examples
[![Project 002](https://img.shields.io/badge/Algorithms_Non_Modifying-Mixed_examples-blue?style=for-the-badge)](https://github.com/alfecjo/Cplus_plus_Advanced/tree/main/archives/module/003_STL-AlgorithmsNonModifying/mixed)

---

## 📚 Further Reading

- [C++ Reference - Modifying Sequence Operations](https://en.cppreference.com/w/cpp/algorithm#Modifying_sequence_operations)
- [GeeksforGeeks: STL Algorithms](https://www.geeksforgeeks.org/cpp-stl-algorithms/)

---

## 🛠️ Build Instructions

If your repository includes buildable source files:
```bash
g++ -std=c++17 -o my_program main.cpp
./my_program

```
---

## 👤 Author
**[Antonio Almeida](https://alfecjo.github.io/)**

**Platform:** Ubuntu + GCC  
**Language:** C++17/C++20  

---

- ## Return to the main page
  [![C++ Advanced Projects](https://img.shields.io/badge/C++_Advanced-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/Cplus_plus_Advanced/tree/main/archives/module)




