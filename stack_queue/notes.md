## Stack from array

```cpp
class Stack {
  int size; int top;
  int * arr;
  public:
    Stack() {
      top = -1; size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};
```

## Queue from array
```cpp
class Queue {
  int * arr;
  int start, end, currSize, maxSize;
  public:
    Queue() {
      arr = new int[16];
      start = -1; end = -1;
      currSize = 0;
    }

   Queue(int maxSize) {
      ( * this).maxSize = maxSize;
      arr = new int[maxSize];
      start = -1; end = -1;
      currSize = 0;
    }

  void push(int x) {
    if (currSize == maxSize) {
      cout << "Queue is full" << endl;
      exit(1);
    }
    if (end == -1) {
      start = 0; end = 0;
    } else {
      end = (end + 1) % maxSize;
    }  
    arr[end] = x;
    currSize++;
  }
  int pop() {
    if (start == -1) return -1;

    int tem = arr[start];
    if (currSize == 1) {
      start = -1; end = -1;
    } else {
      start = (start + 1) % maxSize;
    } 
    currSize--;
    return tem;
  }
  int top() {
    if (start == -1) return -1;
    return arr[start];
  }
  int size() {
    return currSize;
  }

};
```

## Stack and Queue from Linked List
```cpp
struct Node {
  int data;
  Node * next; int size;
  Node(int d) {
    data = d;
    next = NULL;
  }
};
struct stack {
  Node * top;
  int size;
  stack() {
    top = NULL;
    size = 0;
  }
  void Push(int x) {
    Node * element = new Node(x);
    element->next = top;
    top = element;
    size++;
  }
  int Pop() {
    if (top == NULL) return -1;
    
    int topData = top -> data;
    Node * temp = top;
    top = top->next;
    delete temp;
    size--;
    return topData;
  }
  int Size() {
    return size;
  }
  bool IsEmpty() {
    return top == NULL;
  }
  int Top() {
    if (top == NULL) return -1;
    return top->data;
  }
};
```

```cpp
struct Node {
  int data;
  Node* next;
  Node(int d) {
    data = d;
    next = NULL;
  }
};

struct Queue {
  Node* front; Node* end;
  int size;
  
  Queue() {
    front = NULL; end = NULL;
    size = 0;
  }
  
  void Push(int x) {
    Node* element = new Node(x);
    
    if (end == NULL) {
      front = end = element;
    } else {
      end->next = element;
      end = element;
    }
    size++;
  }
  
  int Pop() {
    if (front == NULL) return -1;
    
    Node* temp = front;
    int frontData = front->data;
    front = front->next;
    
    if (front == NULL) {
      end = NULL;
    }
    delete temp;
    size--;
    return frontData;
  }
  
  int Size() {
    return size;
  }
  
  bool IsEmpty() {
    return front == NULL;
  }
  
  int Front() {
    if (front == NULL) return -1;
    return front->data;
  }
};
```

## Stack using queue
```cpp
class MyStack {
private:
      queue<int> q;    
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top ;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
```
## Queue using two stacks
```cpp
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}
    
    void push(int x) {
        s1.push(x) ;
    }
    
    int pop() {
        if (s2.empty()){
            while (s1.size() > 0) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int tem = s2.top();
        s2.pop();
        return tem;
    }
    
    int peek() {
        if (s2.empty()){
            while (s1.size() > 0) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s2.empty() && s1.empty() ;
    }
};
```

### Valid Parantheses
```cpp
bool isValid(string s) {
    stack<char> st;
    for (auto it : s){
        if (it == '(' || it == '{' || it == '[') st.push(it);
        else {
            if (st.empty()) return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' && ch == '(') || (it == '}' && ch == '{') || (it == ']' && ch == '[') )continue;
            else return false;
        }
    }
    return st.empty();
    }
```

### Implementing MinStack from stack to retrive min element in constant time
```cpp
class MinStack {
public:
    stack<int> st, minSt;
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
        else minSt.push(minSt.top());
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
```

### Reversing String word by word without trailing spaces using stack

```cpp
string Solution::solve(string A) {
    string res;
    int n = A.size();
    stack<string> st;
    for (int i = 0; i < n;i++){
        while(A[i] == ' ') i++;
        if (i >= n) break;
        int j = i+1;
        while(A[j] != ' ') j++;
        res = A.substr(i, j-i);
        st.push(res);
        i = j; 
    }
    string ans;
    while (!st.empty()){
        if (st.size() != 1){
            ans = ans + st.top() + ' ';
        } else {
            ans = ans + st.top();
        }
        st.pop();
    }
    return ans;
}
```

---

## Monotonic Stack & Monotonic Queue Patterns

A **Monotonic Stack** is a stack whose elements are always sorted in either strictly increasing or strictly decreasing order.
- **Monotonic Decreasing Stack**: Used to find the **Next Greater Element (NGE)** or **Previous Greater Element (PGE)**.
- **Monotonic Increasing Stack**: Used to find the **Next Smaller Element (NSE)** or **Previous Smaller Element (PSE)**.

---

### 1. Next Greater Element (NGE I & II)

#### NGE I (Standard Array)
- **Intuition**: Iterate from right to left. Maintain a decreasing stack. Pop elements $\le arr[i]$ because they can never be the next greater element for any element to the left.
- **TC**: $O(N)$, **SC**: $O(N)$.

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(arr[i]);
        }
        return nge;
    }
};
```

#### NGE II (Circular Array)
- **Intuition**: Simulate array duplication by iterating $2N - 1$ down to $0$ using index `i % n`.
- **TC**: $O(N)$, **SC**: $O(N)$.

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n && !st.empty()) {
                nge[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return nge;
    }
};
```

---

### 2. Largest Rectangle in Histogram

- **Intuition**: For each bar, find its Previous Smaller Element (PSE) and Next Smaller Element (NSE). Width of rectangle with height `heights[i]` is `NSE[i] - PSE[i] - 1`. Perform in 1-pass using monotonic stack.
- **TC**: $O(N)$, **SC**: $O(N)$.

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
```

---

### 3. Maximal Rectangle (2D Matrix of 1s)

- **Intuition**: Treat each row as the base of a histogram (accumulating consecutive 1s upwards). For each row, run the 1D Largest Rectangle in Histogram algorithm.
- **TC**: $O(N \times M)$, **SC**: $O(M)$.

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            // Calculate max area for histogram in heights
            stack<int> st;
            for (int j = 0; j <= m; j++) {
                int h = (j == m) ? 0 : heights[j];
                while (!st.empty() && heights[st.top()] >= h) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, height * width);
                }
                st.push(j);
            }
        }
        return maxArea;
    }
};
```

---

### 4. Trapping Rain Water

- **Intuition (Two Pointers optimal)**: Trapped water at index `i` is $\min(\text{maxL}, \text{maxR}) - height[i]$. Maintain `left` and `right` pointers along with `leftMax` and `rightMax`.
- **TC**: $O(N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) leftMax = height[left];
                else water += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax) rightMax = height[right];
                else water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};
```

---

### 5. Sliding Window Maximum (Monotonic Queue / Deque)

- **Intuition**: Maintain a `deque` storing indices such that elements are in strictly decreasing order. Remove elements out of current window boundary `[i - k + 1, i]` from front, and pop elements smaller than `nums[i]` from back.
- **TC**: $O(N)$, **SC**: $O(K)$.

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Remove numbers out of current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Maintain decreasing deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Store max for current window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
```

---

### 6. Asteroid Collision

- **Problem**: Given an array of integers representing asteroids in a row, for each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed. Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode.
- **Intuition**: Positive asteroids move right, negative asteroids move left. Collision happens only when top of stack moves right (`st.top() > 0`) and current asteroid moves left (`ast < 0`).
- **TC**: $O(N)$, **SC**: $O(N)$.

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;
            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (st.back() < -ast) {
                    st.pop_back(); // Stack asteroid destroyed, keep checking
                } else if (st.back() == -ast) {
                    st.pop_back(); // Both destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // Current asteroid destroyed
                    break;
                }
            }
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        return st;
    }
};
```

---

### 7. Sum of Subarray Minimums

- **Intuition**: For each element `arr[i]`, count how many subarrays have `arr[i]` as the minimum element. That count is `(i - PSE[i]) * (NSE[i] - i)`. Contribution to total sum is `arr[i] * count`.
- **TC**: $O(N)$, **SC**: $O(N)$.

```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n), nse(n);
        stack<int> st;
        int mod = 1e9 + 7;

        // Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }
        return total;
    }
};
```

