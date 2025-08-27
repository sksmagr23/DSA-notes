# Mathematical Algorithms

This section covers essential mathematical algorithms commonly used in competitive programming and software development.

---

## Number Theory Algorithms

### Euclidean Algorithm (GCD)

The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number. Repeatedly subtract the smaller number from the larger number until one of them becomes 0. Once one of them becomes 0, the other number is the GCD of the original numbers.

Eg, n1 = 20, n2 = 15:

- gcd(20, 15) = gcd(20-15, 15) = gcd(5, 15)
- gcd(5, 15) = gcd(15-5, 5) = gcd(10, 5) 
- gcd(10, 5) = gcd(10-5, 5) = gcd(5, 5) 
- gcd(5, 5) = gcd(5-5, 5) = gcd(0, 5)
  
Hence, return 5 as the gcd.

```cpp
// Efficient implementation using modulo
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive version
int gcdRecursive(int a, int b) {
    if (b == 0) return a;
    return gcdRecursive(b, a % b);
}

// LCM using GCD
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
```

**Time Complexity**: O(log(min(a, b)))

### Extended Euclidean Algorithm

Find integers x and y such that ax + by = gcd(a, b).

```cpp
int extendedGCD(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    
    x = y1;
    y = x1 - (a / b) * y1;
    
    return gcd;
}
```

### Sieve of Eratosthenes

Find all prime numbers up to n efficiently.

```cpp
vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return isPrime;
}

// Get list of primes
vector<int> getPrimes(int n) {
    vector<bool> isPrime = sieveOfEratosthenes(n);
    vector<int> primes;
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}
```

**Time Complexity**: O(n log log n)
**Space Complexity**: O(n)

### Prime Factorization

```cpp
vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> factors;
    
    // Check for 2
    if (n % 2 == 0) {
        int count = 0;
        while (n % 2 == 0) {
            count++;
            n /= 2;
        }
        factors.push_back({2, count});
    }
    
    // Check for odd factors
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            factors.push_back({i, count});
        }
    }
    
    // If n is still > 1, then it's a prime
    if (n > 1) {
        factors.push_back({n, 1});
    }
    
    return factors;
}
```

### Fast Exponentiation (Binary Exponentiation)

Calculate a^b % mod efficiently.

```cpp
long long fastPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    
    return result;
}

// Without modulo
long long fastPowerSimple(long long base, long long exp) {
    if (exp == 0) return 1;
    
    long long half = fastPowerSimple(base, exp / 2);
    half = half * half;
    
    if (exp % 2 == 1) {
        half = half * base;
    }
    
    return half;
}
```

**Time Complexity**: O(log b)

### Modular Multiplicative Inverse

Find x such that (a * x) % m = 1.

```cpp
// Using Extended Euclidean Algorithm
long long modInverse(long long a, long long m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);
    
    if (gcd != 1) {
        return -1; // Inverse doesn't exist
    }
    
    return (x % m + m) % m;
}

// Using Fermat's Little Theorem (when m is prime)
long long modInverseFermat(long long a, long long m) {
    return fastPower(a, m - 2, m);
}
```

---

## Combinatorics

### Factorial and Combinations

```cpp
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

vector<long long> fact(MAXN + 1);
vector<long long> invFact(MAXN + 1);

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    invFact[MAXN] = modInverseFermat(fact[MAXN], MOD);
    for (int i = MAXN - 1; i >= 0; i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * invFact[r] % MOD) * invFact[n-r] % MOD;
}

long long nPr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * invFact[n-r]) % MOD;
}
```

### Catalan Numbers

```cpp
// nth Catalan number using DP
long long catalan(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + dp[j] * dp[i-1-j]) % MOD;
        }
    }
    
    return dp[n];
}

// Using combination formula: C(n) = C(2n, n) / (n+1)
long long catalanFormula(int n) {
    return (nCr(2*n, n) * modInverseFermat(n+1, MOD)) % MOD;
}
```

---

## Matrix Operations

### Matrix Multiplication

```cpp
vector<vector<long long>> matrixMultiply(
    vector<vector<long long>>& A, 
    vector<vector<long long>>& B, 
    int mod
) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();
    
    vector<vector<long long>> C(n, vector<long long>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    
    return C;
}
```

### Matrix Exponentiation

```cpp
vector<vector<long long>> matrixPower(
    vector<vector<long long>> matrix, 
    long long n, 
    int mod
) {
    int size = matrix.size();
    vector<vector<long long>> result(size, vector<long long>(size, 0));
    
    // Initialize result as identity matrix
    for (int i = 0; i < size; i++) {
        result[i][i] = 1;
    }
    
    while (n > 0) {
        if (n & 1) {
            result = matrixMultiply(result, matrix, mod);
        }
        matrix = matrixMultiply(matrix, matrix, mod);
        n >>= 1;
    }
    
    return result;
}

// Fibonacci using matrix exponentiation
long long fibonacciMatrix(long long n) {
    if (n <= 1) return n;
    
    vector<vector<long long>> base = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = matrixPower(base, n-1, MOD);
    
    return result[0][0];
}
```

---

## Bit Manipulation Algorithms

### Count Set Bits

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1); // Remove rightmost set bit
    }
    return count;
}

// Built-in function
int countSetBitsBuiltIn(int n) {
    return __builtin_popcount(n);
}
```

### Find Missing Number

```cpp
int findMissingNumber(vector<int>& nums) {
    int n = nums.size();
    int xorAll = 0;
    int xorArray = 0;
    
    for (int i = 0; i <= n; i++) {
        xorAll ^= i;
    }
    
    for (int num : nums) {
        xorArray ^= num;
    }
    
    return xorAll ^ xorArray;
}
```

### Power of Two Check

```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

---

## Applications

1. **Cryptography**: RSA algorithm uses modular exponentiation
2. **Computer Graphics**: Matrix operations for transformations
3. **Competitive Programming**: Fast computation of large values
4. **Data Structures**: Hash functions use prime numbers
5. **Algorithm Analysis**: Mathematical proofs and complexity analysis
