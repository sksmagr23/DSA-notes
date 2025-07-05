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