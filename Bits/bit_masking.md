# Bit Masking

Bit Masking is a programming technique used to manipulate individual bits within a byte or a larger integer. It is highly valued for its execution speed and memory efficiency, making it a critical topic for competitive programming and technical placement interviews.

---

## 1. Core Concept

A **mask** is a binary value (an integer) that defines which bits you want to keep, modify, or query. By applying bitwise operations between a variable and a mask, you can perform queries and modifications on specific bits in $O(1)$ time.

### Why use Bit Masking?
1. **Memory Efficiency**: Instead of using an array of booleans (`bool arr[N]`), which takes $N$ bytes (since 1 bool = 1 byte in C++), you can represent up to 32 flags in a single 4-byte `int`, or 64 flags in an 8-byte `long long`.
2. **Speed**: Bitwise operations are executed directly by the CPU in a single clock cycle, which is faster than arithmetic operations or array index lookups.
3. **Set Representation**: An integer can represent a mathematical set. For a set of size $N$, any integer in the range $[0, 2^N - 1]$ represents a unique subset.

---

## 2. Core Bitwise Operators in C++

| Operator | Name | Operation | Example (`A = 5 (0101)`, `B = 3 (0011)`) |
| :---: | :--- | :--- | :--- |
| `&` | Bitwise AND | 1 if both bits are 1, else 0. | `A & B = 1 (0001)` |
| `\|` | Bitwise OR | 1 if at least one bit is 1, else 0. | `A \| B = 7 (0111)` |
| `^` | Bitwise XOR | 1 if bits are different, else 0. | `A ^ B = 6 (0110)` |
| `~` | Bitwise NOT | Flips all bits (0 to 1, 1 to 0). | `~A = -6` (2's complement representation) |
| `<<` | Left Shift | Shifts bits left, filling with 0s. Effectively multiplies by $2^k$. | `A << 1 = 10 (1010)` |
| `>>` | Right Shift | Shifts bits right. Effectively divides by $2^k$ (integer division). | `A >> 1 = 2 (0010)` |

---

## 3. Standard Bit Masking Operations

Let `num` be the number and `i` be the 0-indexed bit position (counting from the right, starting at 0).

```
Bit position index:
  7   6   5   4   3   2   1   0
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ 0 │ 1 │ 0 │ 0 │ 1 │ 1 │ 0 │ 1 │  --> Value = 77
└───┴───┴───┴───┴───┴───┴───┴───┘
```

### A. Checking the $i$-th Bit
To check if the $i$-th bit of a number is set (1) or unset (0), perform a bitwise AND with a mask where only the $i$-th bit is 1 (`1 << i`).
```cpp
bool isSet(int num, int i) {
    return (num & (1 << i)) != 0;
}
```

### B. Setting the $i$-th Bit (Turn 1)
To force the $i$-th bit to 1 (regardless of its current state), use a bitwise OR with `1 << i`.
```cpp
int setBit(int num, int i) {
    return num | (1 << i);
}
```

### C. Clearing the $i$-th Bit (Turn 0)
To force the $i$-th bit to 0 (regardless of its current state), use a bitwise AND with the bitwise NOT of the mask (`~(1 << i)`).
```cpp
int clearBit(int num, int i) {
    return num & ~(1 << i);
}
```

### D. Toggling the $i$-th Bit (Flip state)
To flip the $i$-th bit (if it is 1, make it 0; if it is 0, make it 1), use a bitwise XOR with `1 << i`.
```cpp
int toggleBit(int num, int i) {
    return num ^ (1 << i);
}
```

---

## 4. Common Bit Masking Tricks

* **Check if Even or Odd**:
  Since the least significant bit (LSB) determines parity:
  ```cpp
  bool isOdd(int n) { return (n & 1) != 0; }
  bool isEven(int n) { return (n & 1) == 0; }
  ```
* **Check if Power of 2**:
  A power of 2 has exactly one set bit (e.g., `8 = 1000`). If we subtract 1, all trailing bits flip (e.g., `7 = 0111`). Therefore, `n & (n - 1)` will equal `0` for powers of 2.
  ```cpp
  bool isPowerOfTwo(int n) {
      return n > 0 && (n & (n - 1)) == 0;
  }
  ```
* **Multiply/Divide by Powers of 2**:
  ```cpp
  int multiplyByPowerOfTwo(int n, int k) { return n << k; } // n * (2^k)
  int divideByPowerOfTwo(int n, int k) { return n >> k; }   // n / (2^k)
  ```

---

## 5. Subset Generation Using Bitmasking

Bitmasking can represent and generate all subsets of a set. For a set of size $N$, there are $2^N$ subsets. We can map each subset to an integer from $0$ to $2^N - 1$.
* If the $i$-th bit of the integer is `1`, the $i$-th element of the set is present in the subset.
* If the $i$-th bit is `0`, the element is absent.

### C++ Code Example
```cpp
#include <iostream>
#include <vector>

void generateSubsets(const std::vector<int>& set) {
    int n = set.size();
    int totalSubsets = 1 << n; // 2^n

    for (int mask = 0; mask < totalSubsets; ++mask) {
        std::cout << "{ ";
        for (int i = 0; i < n; ++i) {
            // Check if the i-th element is included in the current mask
            if ((mask & (1 << i)) != 0) {
                std::cout << set[i] << " ";
            }
        }
        std::cout << "}\n";
    }
}

int main() {
    std::vector<int> set = {1, 2, 3};
    generateSubsets(set);
    return 0;
}
```

---

## 6. C++ Standard Library & Compiler Tools

C++ provides native utilities to work with bits efficiently:

### A. `std::bitset`
`#include <bitset>` provides a container to work with fixed-size bit configurations.
```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<8> b1(77); // Represent 77 in 8 bits: 01001101
    
    cout << "Bitset: " << b1 << "\n";
    cout << "Size: " << b1.size() << "\n";          // 8
    cout << "Set bits (1s): " << b1.count() << "\n"; // 4
    cout << "Any bit set? " << b1.any() << "\n";     // true
    cout << "No bits set? " << b1.none() << "\n";    // false
    cout << "Is index 2 set? " << b1.test(2) << "\n"; // true
    
    b1.set(1);    // Set bit at index 1 to 1
    b1.reset(0);  // Reset bit at index 0 to 0
    b1.flip();    // Toggle all bits
    
    return 0;
}
```

### B. GCC Built-in Bit Functions (Highly Used in Placements)
The GCC compiler provides optimized built-in functions that translate directly to fast CPU instructions:
* **`__builtin_popcount(unsigned int x)`**: Returns the number of set bits (1s) in a number.
  ```cpp
  int ones = __builtin_popcount(15); // Returns 4 (15 = 1111)
  ```
  *(For 64-bit integers (`long long`), use `__builtin_popcountll(x)`)*
* **`__builtin_clz(unsigned int x)`**: Returns the number of leading zeros (counting from the most significant bit).
* **`__builtin_ctz(unsigned int x)`**: Returns the number of trailing zeros (counting from the least significant bit).
