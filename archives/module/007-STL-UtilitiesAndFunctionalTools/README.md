# Utilities and Functional Tools

## STL Functors and Adaptors in C++: `ptr_fun`, `bind1st` and `bind2nd`

## 1. The `ptr_fun` Function

### What is it?

- `ptr_fun` is an adapter function that transforms a **free function** (a normal function, not an object) into a **function object** (functor).
- This allows using normal functions where the STL expects objects that behave like functions (functors).

### Why?

- Many STL algorithms (`std::for_each`, `std::transform`, `std::count_if`, etc.) operate with **functors**.
- Free functions **are not** functors directly, but `ptr_fun` wraps the function so it can be used as one.

### Simple example:

```cpp
bool isEven(int x) { return x % 2 == 0; }

// Using ptr_fun:
auto func = ptr_fun(isEven);

// Now func can be used in STL algorithms that expect functors.


```

## 2. `bind1st` and `bind2nd`

### What are they?

- Adaptors that bind a specific argument (first or second) of a binary function, returning a unary functor (a function with one argument).

### Why?

- Many STL algorithms expect functions with one argument, but your functions may require two.
- `bind1st` binds the first argument; the user provides the second.
- `bind2nd` binds the second argument; the user provides the first.

### Simple example:

```cpp
bool greaterThan(int value, int limit) {
    return value > limit;
}

auto greaterThan10 = bind2nd(ptr_fun(greaterThan), 10);

// greaterThan10 now only takes the value and compares it with 10:
bool result = greaterThan10(15); // true, since 15 > 10


```

## 3. `ptr_fun`, `bind1st`, and `bind2nd` help adapt legacy functions for the STL.

- Since C++11, prefer `std::bind` and lambda expressions — they are more expressive, safer, and more flexible.
- Learning these techniques makes it easier to efficiently use STL algorithms in real-world applications, such as sensor data processing in embedded systems or telecommunications.

## 📌 Study Tips: STL, Functors, and Functional Tools

| Concept               | Description                                                               |
|-----------------------|---------------------------------------------------------------------------|
| `ptr_fun`             | Adapts a regular (free) function into a function object. **(Deprecated)** |
| `bind1st` / `bind2nd` | Binds (fixes) the first or second argument of a binary functor. **(Deprecated)** |
| `transform`           | Applies an operation to each element in a sequence (like a functional `map`). |
| `lambda`              | Inline anonymous function. **Modern**, replaces `bind` and `ptr_fun`.     |

---

## 👤 Author
**[Antonio Almeida](https://alfecjo.github.io/)**

**Platform:** Ubuntu + GCC  
**Language:** C++17/C++20  

---

- ## Return to the main page
  [![C++ Advanced Projects](https://img.shields.io/badge/C++_Advanced-000000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/alfecjo/Cplus_plus_Advanced/tree/main/archives/module)
