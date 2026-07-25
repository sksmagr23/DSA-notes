# Bit Manipulation

Bit manipulation processes individual bits of a number using bitwise operators. It operates at the binary level and allows extremely fast $O(1)$ operations with zero extra memory.

---

## 1. Bitwise Operators Basics

| Operator | Symbol | Description | Example ($a=5=0101_2, b=3=0011_2$) |
| :--- | :---: | :--- | :--- |
| **AND** | `&` | 1 if both bits are 1 | `5 & 3` $\rightarrow 0001_2 = 1$ |
| **OR** | `\|` | 1 if at least one bit is 1 | `5 \| 3` $\rightarrow 0111_2 = 7$ |
| **XOR** | `^` | 1 if bits are different | `5 ^ 3` $\rightarrow 0110_2 = 6$ |
| **NOT** | `~` | Inverts all bits | `~5` $\rightarrow -(5+1) = -6$ |
| **Left Shift** | `<<` | Shifts bits left (multiplies by $2^k$) | `5 << 1` $\rightarrow 1010_2 = 10$ |
| **Right Shift**| `>>` | Shifts bits right (divides by $2^k$) | `5 >> 1` $\rightarrow 0010_2 = 2$ |

---

## 2. Core Bit Tricks & Operations

### Basic Bit Operations ($0$-indexed from right)

- **Check if $k$-th bit is set**: `(n & (1 << k)) != 0` or `((n >> k) & 1) == 1`
- **Set $k$-th bit**: `n | (1 << k)`
- **Clear $k$-th bit**: `n & ~(1 << k)`
- **Toggle $k$-th bit**: `n ^ (1 << k)`
- **Clear lowest set bit (rightmost 1)**: `n & (n - 1)`
- **Extract lowest set bit**: `n & (-n)`
- **Swap two numbers without extra variable**:
  ```cpp
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  ```

---

## 3. Count Set Bits (Kernighan's Algorithm)

- **Intuition**: `n & (n - 1)` clears the rightmost set bit in each iteration. The number of iterations equals the number of set bits.
- **TC**: $O(\text{number of set bits})$, max $O(32)$ or $O(64)$.
- **SC**: $O(1)$.

```cpp
class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1); // Clear the lowest set bit
            count++;
        }
        return count;
    }
};
// Built-in alternative in C++: __builtin_popcount(n) for int, __builtin_popcountll(n) for long long
```

---

## 4. Single Number Problems

### Single Number I (Every element appears twice except one)
- **Intuition**: $x \oplus x = 0$ and $x \oplus 0 = x$. XORing all elements cancels out pairs, leaving only the unique element.
- **TC**: $O(N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int num : nums) {
            xorr ^= num;
        }
        return xorr;
    }
};
```

### Single Number II (Every element appears 3 times except one)
- **Intuition**: Count set bits at each of the 32 bit positions across all numbers. If a bit position's count $\% 3 \neq 0$, that bit belongs to the single number.
- **TC**: $O(32 \times N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int num : nums) {
                if ((num >> i) & 1) {
                    count++;
                }
            }
            if (count % 3 != 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
```

### Single Number III (Two elements appear once, all others appear twice)
- **Intuition**: XOR of all numbers yields `XOR = a ^ b`. Find the rightmost set bit in `XOR` (which indicates where `a` and `b` differ). Partition array into two groups based on this bit and XOR each group.
- **TC**: $O(N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        for (int num : nums) xorr ^= num;

        // Find rightmost set bit (lowest set bit)
        long long rightmostBit = xorr & (-xorr);

        int b1 = 0, b2 = 0;
        for (int num : nums) {
            if (num & rightmostBit) {
                b1 ^= num;
            } else {
                b2 ^= num;
            }
        }
        return {b1, b2};
    }
};
```

---

## 5. Minimum Bit Flips to Convert Number

- **Intuition**: The number of different bits between `start` and `goal` is equal to the number of set bits in `start ^ goal`.
- **TC**: $O(1)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int count = 0;
        while (ans > 0) {
            ans = ans & (ans - 1);
            count++;
        }
        return count;
    }
};
```

---

## 6. Power Set (All Subsets using Bitmasking)

- **Intuition**: An array of size $N$ has $2^N$ subsets. We can map each subset to an integer from $0$ to $2^N - 1$. If the $i$-th bit of integer $f$ is 1, include $arr[i]$ in the current subset.
- **TC**: $O(N \cdot 2^N)$, **SC**: $O(N \cdot 2^N)$ for storing subsets.

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n; // 2^n
        vector<vector<int>> ans;

        for (int i = 0; i < totalSubsets; i++) {
            vector<int> sub;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sub.push_back(nums[j]);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
};
```

---

## 7. Divide Two Integers without `*`, `/`, `%`

- **Intuition**: Use exponential bit shifts (`dividend >= (divisor << count)`). Repeatedly subtract the largest power of 2 multiple of `divisor` from `dividend`.
- **TC**: $O((\log \text{dividend})^2)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // Overflow case

        bool sign = (dividend < 0) == (divisor < 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            ans += (1LL << count);
            n -= (d << count);
        }

        return sign ? ans : -ans;
    }
};
```
