# Dynamic Integer Array with `std::vector` (C++)

## Purpose

This project demonstrates how to manage dynamic arrays in modern C++ using the standard container `std::vector`. While traditional manual memory management teaches low-level fundamentals, `std::vector` provides a safer, more scalable, and efficient alternative aligned with modern best practices.

## Cause

Understanding dynamic memory is crucial, but using `std::vector` allows developers to:

- Avoid manual memory leaks (`new` / `delete`)
- Benefit from built-in bounds checking and size management
- Focus on logic instead of infrastructure
- Apply idiomatic C++ practices for real-world projects

## Effect

This implementation allows:

- Dynamically appending and removing elements with ease
- Efficient memory handling managed by the STL
- Safe and intuitive element access using `[]` or `.at()`
- Modern C++ syntax and RAII (Resource Acquisition Is Initialization)

## Key Differences from Raw Arrays

| Feature                  | Manual Allocation (`new[]`)     | `std::vector<int>`              |
|--------------------------|----------------------------------|----------------------------------|
| Memory Management        | Manual (`new` / `delete`)        | Automatic via RAII              |
| Bounds Safety            | No                               | Safe with `.at()` or `range-for` |
| Resizing Support         | Needs reallocation logic         | Built-in with `.push_back()`     |
| Exception Safety         | Requires manual try/catch blocks | Handles internally               |
| STL Compatibility        | No                               | Fully compatible                 |

## Techniques & References

The techniques applied here are commonly used in:

- **Books**:
  - *Effective Modern C++* – Scott Meyers
  - *Accelerated C++* – Koenig & Moo

- **Courses**:
  - CS106L – Stanford University
  - Modern C++ Nanodegree – Udacity

- **Online Resources**:
  - [cppreference.com – std::vector](https://en.cppreference.com/w/cpp/container/vector)
  - [cplusplus.com – STL vector](https://cplusplus.com/reference/vector/vector/)
  - [Modern C++ Tutorial](https://changkun.de/modern-cpp/)

## Where to Find These Techniques in the App

You can see `std::vector` in action in:

- `ArrayVector.hpp` – encapsulates the vector logic with add/remove/search methods.
- `main.cpp` – shows a typical usage scenario including construction, insertion, deletion, and iteration.
- Exception-safe access is demonstrated using `.at(index)` in `main.cpp`.

---

![ArrayVector](https://github.com/alfecjo/Cplus_plus_Advanced/blob/main/templates/module1/vector-array/vectorarray.jpg)

---

## How to Build

```bash
g++ -std=c++17 -o array main.cpp ArrayVector.cpp
./array

```
---

## 👤 Author
**[Antonio Almeida](https://alfecjo.github.io/)**

**Platform:** Ubuntu + GCC  
**Language:** C++17/C++20  

---

- ## Return to the main page
  [![C++ Advanced Projects](https://img.shields.io/badge/C++_Advanced-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/Cplus_plus_Advanced/tree/main)

