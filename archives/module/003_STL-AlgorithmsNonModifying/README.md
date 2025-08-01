# Algorithms - Non-Modifying in C++

## 🧾 Overview

**Non-modifying algorithms** are a category of algorithms provided by the C++ Standard Template Library (STL) that analyze, search, or compare elements in a container without changing their values or the structure of the container.

These algorithms are extremely useful for performing read-only operations such as searching for elements, counting elements that satisfy a condition, or comparing entire sequences.

---

## 📦 Categories of Non-Modifying Algorithms

Some of the most commonly used non-modifying algorithms include:
 - std::find / std::find_if
 - std::count / std::count_if
 - std::all_of, std::any_of, std::none_of
 - std::mismatch
 - std::equal
 - std::search
 - std::adjacent_find
 - std::for_each

- [`std::containers`](https://en.cppreference.com/w/cpp/container.html): Containers.

> 🔎 Note: Each of these functions takes iterators as input and performs an operation based on the contents they refer to.

---

## ⚙️ Characteristics

- Read-only: These algorithms never alter the container.
- Iterator-based: Work with any type of container that provides valid iterators.
- Predicate support: Many allow predicates (lambda functions, functors) for custom filtering.
- Functional and expressive: Greatly reduce the need for manual loops and conditional logic.

---

## ✅ Key Functions

- std::find / std::find_if
  Finds the first element equal to a given value or that satisfies a condition.
- std::count / std::count_if
  Counts how many elements match a value or satisfy a predicate.
- std::all_of, std::any_of, std::none_of
  Test conditions across the entire container.
- std::for_each
  Applies a function to each element, without modifying the container itself.
- std::search
  Finds a subsequence within another sequence.
- std::mismatch / std::equal
  Compare two sequences to detect differences or confirm equality.
- std::adjacent_find
  Detects adjacent duplicate elements.

---

## 📌 Key Functions

🔍 Searching for an element in a vector (std::find)

🔢 Counting how many even numbers exist in a list (std::count_if)

✔️ Verifying if all grades are above 7.0 (std::all_of)

🔁 Comparing two sequences of strings (std::equal)

🔍 Logging each value from a set (std::for_each)

---

## 📚 Further Reading

- [C++ Reference - Non_modifying](https://en.cppreference.com/w/cpp/container)
- [GeeksforGeeks: Containers in STL](https://www.geeksforgeeks.org/associative-containers-the-c-standard-template-library-stl/)

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
  [![C++ Advanced Projects](https://img.shields.io/badge/C++_Advanced-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/Cplus_plus_Advanced/tree/main/archives/module1)
