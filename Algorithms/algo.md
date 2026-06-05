# Extra Concepts and Algos

## Euclidean algorithm

##### The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number. Repeatedly subtract the smaller number from the larger number until one of them becomes 0.Once one of them becomes 0, the other number is the GCD of the original numbers.

Eg, n1 = 20, n2 = 15:

- gcd(20, 15) = gcd(20-15, 15) = gcd(5, 15)
- gcd(5, 15) = gcd(15-5, 5) = gcd(10, 5) 
- gcd(10, 5) = gcd(10-5, 5) = gcd(5, 5) 
- gcd(5, 5) = gcd(5-5, 5) = gcd(0, 5)
  
Hence, return 5 as the gcd.

```cpp
// cpp code :- TC = O(min(a, b)) 
int findGcd(int a, int b) {
    while(a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a; 
        }
    }
    if(a == 0) {
        return b;
    }
    return a;
```

---

## Power of 2 Check

A number n is a power of 2 if it has exactly one bit set in its binary representation.

Examples:
- 4  = 0100 = 2^2
- 8  = 1000 = 2^3

Observation:- For any power of 2, subtracting 1 turns all bits after the set bit into 1s.

Example:

- 8      = 1000
- 8 - 1  = 0111

Therefore:- 1000 & 0111 = 0000

Hence, for every power of 2: ``n & (n - 1) == 0``

```cpp
bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0;
}
```

---

## Matrix Exponentiation

Matrix Exponentiation is used to solve linear recurrence relations in **O(log N)** time. It converts a recurrence into a matrix transition problem and applies Binary Exponentiation.
Use when:
- Linear recurrence
- Fixed number of previous states
- Constant coefficients
- Very large N (10⁹, 10¹⁸, ...)

### Fibonacci Example

Recurrence:

```cpp
F(n) = F(n-1) + F(n-2)
```

State Vector: 

```text
[F(n)   ]
[F(n-1) ]
```

Transition Matrix:

```text
[1 1]
[1 0]
```

Thus,

```text
[F(n)   ]     [1 1] [F(n-1)]
[F(n-1) ]  =  [1 0] [F(n-2)]
```

Let:

```cpp
T = { {1,1},
      {1,0} };
```

Then:

```text
State(n) = T^(n-1) × State(1)
```

```text
State(n)
= T × State(n-1)
= T² × State(n-2)
= T³ × State(n-3)
...
= T^(n-1) × State(1)
```

The problem reduces to finding: `T^(n-1)`


#### Binary Exponentiation

Instead of: `T × T × T × ... × T`

Use:
```cpp
T¹
T² = T × T
T⁴ = T² × T²
T⁸ = T⁴ × T⁴
...
```

Complexity: ``O(log N)``

#### Matrix Multiplication

```cpp
vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
    int n = A.size();

    vector<vector<long long>> C(n, vector<long long>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

    return C;
}
```

Complexity: ``O(K³)``

#### Matrix Power (M<sup>b</sup>)

```cpp
vector<vector<long long>> power(vector<vector<long long>> base, long long b) {
    int n = base.size();

    vector<vector<long long>> res(n, vector<long long>(n, 0));

    for(int i = 0; i < n; i++) res[i][i] = 1;

    while(b) {
        if(b & 1)
            res = multiply(res, base);

        base = multiply(base, base);

        b >>= 1;
    }
    return res;
}
```

### Tribonacci Example

```cpp
f(n) = f(n-1) + f(n-2) + f(n-3)
```

Transition Matrix:
```text
[1 1 1]
[1 0 0]
[0 1 0]
```

### Recurrence with Constant

```cpp
f(n) = f(n-1) + 2*f(n-2) + 7
```

Add an extra state:

```text
[f(n)   ]
[f(n-1) ]
[1      ]
```

This preserves the constant term during transitions.

### Complexity

For a K × K matrix:

```cpp
Matrix Multiplication : O(K³)

Exponentiation       : O(log N)

Total                : O(K³ log N)

Rounded to O(log N) for small K (like Fibonacci, k= 2)
```

> Leetcode problem explanation : https://leetcode.com/problems/domino-and-tromino-tiling/solutions/8255420/efficient-ologn-solution-using-matrix-ex-on3x
---
