# Signal Filtering Example Using C++ Algorithms

## Example t027.cpp

This project demonstrates the use of **modifying algorithms** from the C++ Standard Library in the context of **signal filtering** — specifically, applying a **low-pass filter** to noisy sensor data. This is particularly relevant in fields like engineering, instrumentation, and embedded systems, where signals acquired from sensors often contain noise due to environmental or electrical interference.

![low-pass filter]() 

## 🧪 Scenario

Imagine we are measuring a **physical quantity** such as:

- Temperature of a pipe
- Voltage from an analog sensor
- Electrical current in a motor

The real value is assumed to be **9.76** (in appropriate units), but the signal received from the sensor is noisy due to fluctuations and transient interference. 

## 🧰 Implementation

We simulate the noisy signal using a random generator and apply a **low-pass filter** to smooth the data. The filtering technique used here is a **moving exponential average**, which is simple yet effective for real-time systems.

```cpp
filtered = alpha * new_sample + (1 - alpha) * previous_filtered;
