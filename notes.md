### [Striver Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2)

# My Covered
- Time & space complexity
- C++ STL
- Basic maths (palindrome, count digits, GCD, Armstrong, Prime Numbers)
- Recursion (Backtracking, parameterized and functional recursion, factorial, fibonacci, recursion tree)
- Hashing(number and characrter hashing, map , collisions and divided hashing)
- Sorting(SELECTION, BUBBLE, INSERTION, MERGE, QUICK)
- Arrays

# General DSA Flowchart
![Flowchart](https://leetcode.com/explore/interview/card/cheatsheets/720/resources/Figures/DSA/Chapter_11/flowchart.png)


## Euclidean algorithm
#### The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number. Repeatedly subtract the smaller number from the larger number until one of them becomes 0.Once one of them becomes 0, the other number is the GCD of the original numbers.

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

## TC of Map Data Structure

- #### Storing(i.e. insertion) and fetching(i.e. retrieval) in a C++ map, both take always O(logN) time complexity, where N = the size of the map. 

- #### But the unordered_map in C++ take O(1) time complexity to perform storing(i.e. insertion) and fetching(i.e. retrieval). Now, it is valid for the best case and the average case. But in the worst case, this time complexity will be O(N) for unordered_map. Now, the worst case occurs very very rarely. It almost never happens and most of the time, we will be using unordered_map. 

- Note: Our first priority will be always to use unordered_map and then map. If unordered_map gives a time limit exceeded error(TLE), we will then use the map.

## Arrays
- they contain similar type of elements
- max size of array is 10^6 in int main() and 10^7 globally
- an array declared globally like arr[6] stores all values as 0, but in main, it stores garabage values.
- ### Problems(Brute force, better and then optimal)
  - Largest Element in an Array
  - Second Largest Element in an Array without sorting
  - Check if the array is sorted
  - Remove duplicates from Sorted array
  - #### Array rotation by k places right
    ```cpp 
    class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> rotated(n);

        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = nums[i];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = rotated[i];
        }
    }
    };
    ```
  - Move all zeroes to end
  - Linear Search 
  - Find the union and intersection
  - Find missing number in array
  - Maximum consecutive ones
  - Find the number that appears once, and other numbers twice.
  - Longest subarray with given sum K(positives and both postive and negative
