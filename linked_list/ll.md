## Linked list
```cpp
class Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next
    }
    // or
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list
    }
};

int main() {
    vector<int> arr={2,5,8,7};
    Node* y= new Node(arr[0]);
    cout<<y<<'\n'; // returns the memory value
    cout<<y->data<<'\n'; // returns the data stored at that memory point
    return 0;
}
```

## Length of linked list
```cpp
int lengthOfLinkedList(Node* head) {
    Node* temp = head;
    int count = 0;
    // Traverse the linked list and count nodes
    while (temp != NULL) {
        temp = temp->next;
        count++; // increment cnt for every node traversed
    }
    return count;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    
    // Create a linked list
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    
    // Print the length of the linked list
    cout << lengthOfLinkedList(head) << '\n';
}
```

## Array to Linked_list
```cpp
class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* mover = head;
        for (int i=1; i<arr.size(); i++){
            mover->next = new Node(arr[i]);
            mover = mover->next;
        }
        return head;
    }
};
```

## Reverse a Linked List(Interative)
```cpp
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    
    while (curr != nullptr) {
        next = curr->next;  // Store the next node
        curr->next = prev;  // Reverse the link
        
        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }
    
    // prev is the new head of the reversed list
    return prev;
}
```

### Delete a node without head pointer
```cpp
void deleteNodeWithoutHead(Node* nodeToDelete) {
    // Cannot delete the last node with this approach
    if (nodeToDelete == nullptr || nodeToDelete->next == nullptr) return;
    
    // Copy the data from the next node
    Node* nextNode = nodeToDelete->next;
    nodeToDelete->data = nextNode->data;
    
    // Skip the next node
    nodeToDelete->next = nextNode->next;
    
    // Delete the next node
    delete nextNode;
}
```

## Doubly linked list
```cpp
class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
```

## Array to Doubly linked list
```cpp
Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}
```

## Tortoise and Hare Algo (THA) (to find middle of LL)
```cpp
Node *findMiddle(Node *head) {
    // Initialize the slow & fast pointer to the head.
    Node *slow = head; 
    Node *fast = head; 

    // Traverse the LL using the Tortoise and Hare algo
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step.
        slow = slow->next; 
        // Move fast two steps.
        fast = fast->next->next; 
    }
    
    // Return the slow pointer which is now at the middle node.
    return slow; 
}
```

## Loop/cycle detect using THA
```cpp
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast) {
            return true;  // Loop detected
        }
    }
    // If fast reaches the end of the list, there is no loop
    return false;
}
```

## Starting point of Loop
```cpp
Node* findStartOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool loopExists = false;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }
    // If no loop exists, return nullptr
    if (!loopExists) return nullptr;
    
    // Move slow to head and keep fast at meeting point
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    // The point where they meet is the start of the loop
    return slow;
}
```

## Loop length in Ll
```cpp
int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;     
        fast = fast->next->next;

        if (slow == fast) {
            int cnt = 1;
            fast = fast->next; // move fast by one step

            while(slow!=fast){
                // at each node increase count by 1 and move fast forward by one step
                cnt++;
                fast = fast->next;
            }
        // loop terminates when fast reaches slow again and the count is returned
        return cnt;
        }
    }
    return 0; 
}
```

## Circular Linked list
```cpp
class CircularNode {
public:
    int data;
    CircularNode* next;
    
    CircularNode(int data1) {
        data = data1;
        next = this;  // Points to itself initially
    }
};

// Circular linked list from an array
CircularNode* createCircularLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    CircularNode* head = new CircularNode(arr[0]);
    CircularNode* tail = head;
    
    for (int i = 1; i < arr.size(); i++) {
        CircularNode* newNode = new CircularNode(arr[i]);
        tail->next = newNode;
        tail = newNode;
    }
    // Make the list circular by linking last node to the first
    tail->next = head;
    
    return head;
}

```