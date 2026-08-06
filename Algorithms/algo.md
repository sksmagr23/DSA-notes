# Extra Concepts and Algos
---

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

## C++ Lambda Expressions

Lambda expressions (introduced in C++11) are anonymous and inline functions that allow writing small pieces of logic directly at the place of use. They improve code readability by keeping behavior close to where it is applied, making them ideal for passing custom logic to STL algorithms.

### Syntax

```cpp
[capture_clause](parameters) -> return_type {
    // function body
};
```
* **capture_clause**: Specifies which outside variables are available inside the lambda.
* **parameters**: (Optional) Parameters passed to the lambda function.
* **return_type**: (Optional) Inferred automatically by the compiler in most cases if omitted.
* **body**: Code to be executed.

### Capture Clauses
* `[]`: Capture nothing.
* `[=]`: Capture all local variables in scope by value (read-only).
* `[&]`: Capture all local variables in scope by reference (can modify).
* `[x, &y]`: Capture `x` by value and `y` by reference.
* `[=, &x]`: Capture all by value, except `x` by reference.
* `[&, x]`: Capture all by reference, except `x` by value.

### Example Lambda Function

```cpp
int main() {
    vector<int> v;

    //  Capture all by reference
    auto byRef = [&](int m) {
        v.push_back(m);
    };

    //  Capture all by value
    auto byVal = [=](int m) mutable {
        v.push_back(m);
    };

    byRef(20);
    byVal(30);
    for (auto x : v) cout << x << " ";
    return 0;

    // output: 20
}
```

### Example Usages with STL

#### 1. Custom Sorting (e.g. Descending Order)
```cpp
vector<int> arr = {4, 1, 3, 5, 2};

sort(arr.begin(), arr.end(), [](int a, int b) {
    return a > b;
});
```

#### 2. Using `std::for_each` and `std::find_if`
```cpp
vector<int> nums = {1, 2, 3, 4, 5, 6};

// Print all elements
for_each(nums.begin(), nums.end(), [](int x) {
    cout << x << " ";
});

// Find first number divisible by 3
auto it = find_if(nums.begin(), nums.end(), [](int x) {
    return x % 3 == 0;
});
```

#### 3. Capturing Local Variables
```cpp
vector<int> nums = {1, 2, 3, 4, 5};
int threshold = 3;

int count = count_if(nums.begin(), nums.end(), [threshold](int x) {
    return x > threshold;
});
```

#### 4. Mutable Lambda
By default, variables captured by value cannot be modified. Use the `mutable` keyword to modify them inside the lambda (note: this does not change the original variable outside the lambda).
```cpp
int x = 10;
auto modifyX = [x]() mutable {
    x = 20; // Allowed because of 'mutable'
    cout << x << endl;
};
modifyX(); // Prints 20
cout << x << endl; // Still prints 10
```

---

## Segment Tree (Point Update & Range Query)

A **Segment Tree** is a binary tree used to perform range queries (e.g., sum, min, max, gcd) and point/range updates on an array in **$O(\log N)$** time.

### Structure
- Size of tree array: $4N$ elements.
- Node $ind$ has left child at $2 \cdot ind + 1$ and right child at $2 \cdot ind + 2$.

```cpp
class SegmentTree {
    vector<int> tree;
    int n;

    void build(int ind, int low, int high, const vector<int>& arr) {
        if (low == high) {
            tree[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2]; // Range Sum
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            tree[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // Complete overlap
        if (low >= l && high <= r) return tree[ind];
        // No overlap
        if (high < l || low > r) return 0;
        // Partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        build(0, 0, n - 1, arr);
    }

    void update(int i, int val) {
        update(0, 0, n - 1, i, val);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
```

---

## Fenwick Tree / Binary Indexed Tree (BIT)

A **Fenwick Tree** provides $O(\log N)$ prefix sum queries and point updates with half the memory of a Segment Tree.

- **Isolation of LSB**: `i & (-i)` gives the lowest set bit.
- **Update**: `i += (i & -i)`
- **Query (Prefix Sum)**: `i -= (i & -i)`

```cpp
class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0); // 1-based indexing
    }

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};
```

---

## Difference Array Concept

A **Difference Array** is a helper array used to perform multiple range update queries of the form "add value $v$ to range $[l, r]$" in $O(1)$ time. After all updates are done, the final array can be reconstructed in $O(N)$ time.

### How it works:
1. **Initialize** a difference array `diff` of size $n+1$ with all zeros.
2. **For each query** $[l, r, v]$ (add $v$ to subarray `arr[l...r]`):
   - Add $v$ to `diff[l]`: `diff[l] += v`
   - Subtract $v$ from `diff[r+1]`: `diff[r+1] -= v` (if $r+1 < n$)
3. **Reconstruct** the actual updates by computing prefix sums of `diff`, and add them to the original array.

### Complexity:
- **Range Update Query**: $O(1)$
- **Rebuilding Array**: $O(N)$
- **Space Complexity**: $O(N)$ for the difference array

### C++ Code Implementation

```cpp
vector<int> diffArray(vector<int>& arr, vector<vector<int>> & queries) {
    int n = arr.size();
    vector<int> diff(n + 1, 0);
    for (auto q : queries) {
        int l = q[0], r = q[1], v = q[2];
        diff[l] += v;
        if (r + 1 < n)
            diff[r + 1] -= v;
    }

    vector<int> ans = arr;
    ans[0] += diff[0];
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
        ans[i] += diff[i];
    }
    return ans;
}
```

---