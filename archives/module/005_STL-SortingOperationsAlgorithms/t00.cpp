#include <deque>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

/*
Sorting Operations Algorithms:

Sorting algorithms are fundamental for organizing data in a specified order (ascending or descending). 
Common algorithms include quicksort, mergesort, heapsort, and insertion sort. The C++ Standard Library 
provides generic sorting functions such as sort(), stable_sort(), partial_sort(), and nth_element(), 
optimized for different use cases.

Sorting is critical in applications such as signal processing, sensor data analysis, embedded systems, 
and communication protocols where ordered data facilitates faster searching, filtering, and decision-making.

in this example, a deque is used to store signal levels, which are then sorted and manipulated using STL algorithms.
- Using std::sort with a custom comparator,
- Utilizing std::equal_range to find ranges of equal elements,
- Combining std::deque and std::set containers for efficient data manipulation.
*/

class SignalLevel {
  int dBm;  // Signal strength in decibels-milliwatts

public:
  SignalLevel(int dBm) : dBm(dBm) {}

  int getValue() const { return dBm; }

  // For ascending order sorting by default
  bool operator<(const SignalLevel& other) const {
    return dBm < other.dBm;
  }
};

ostream& operator<<(ostream& os, const SignalLevel& s) {
  os << s.getValue() << " dBm";
  return os;
}

void printer(const SignalLevel& s) {
  cout << s << ", ";
}

int main() {
  int raw_measurements[] = { -70, -85, -60, -90, -75, -65, -88, -60, -70 };

  deque<SignalLevel> signals(raw_measurements, raw_measurements + sizeof(raw_measurements)/sizeof(int));

  // Sort signals descending (strongest first) using custom comparator lambda
  sort(signals.begin(), signals.end(), [](const SignalLevel& a, const SignalLevel& b){
    return a.getValue() > b.getValue();
  });

  cout << "Signals sorted by strength (strongest to weakest):\n";
  for_each(signals.begin(), signals.end(), printer);
  cout << "\n\n";

  // Find range of signals with level -60 dBm using equal_range with descending order
  auto range = equal_range(signals.begin(), signals.end(), SignalLevel(-60),
                           [](const SignalLevel& a, const SignalLevel& b){
                             return a.getValue() > b.getValue();
                           });

  cout << "Occurrences of signal -60 dBm:\n";
  for_each(range.first, range.second, printer);
  cout << "\n\n";

  // Store unique signals in a set (ascending order)
  set<SignalLevel> uniqueSignals(signals.begin(), signals.end());

  cout << "Unique signals (ascending order):\n";
  for_each(uniqueSignals.begin(), uniqueSignals.end(), printer);
  cout << "\n";

  return 0;
}
