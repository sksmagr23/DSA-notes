### [Striver Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2)

# My Covered
- Time & space complexity
- C++ STL
- Basic maths (palindrome, count digits, GCD, Armstrong, Prime Numbers)
- Recursion (Backtracking, parameterized and functional recursion, factorial, fibonacci, recursion tree)
- Hashing(number and characrter hashing, map , collisions and divided hashing)
- Sorting(SELECTION, BUBBLE, INSERTION, MERGE, QUICK)
- Arrays
- Binary Search
- Linked List

# General DSA Flowchart
![Flowchart](https://leetcode.com/explore/interview/card/cheatsheets/720/resources/Figures/DSA/Chapter_11/flowchart.png)


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
