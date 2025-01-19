#include<bits/stdc++.h>
using namespace std;

void vectors() {
    vector<int> v;
    v.push_back(1);                    // Insert at end
    v.emplace_back(2);                 // Faster insertion
    vector<int> v2(5, 100);           // 5 elements with value 100
    
    cout << v[0] << endl;             // Access element
    cout << v.front() << endl;        // First element
    cout << v.back() << endl;         // Last element
    
    for(auto it : v) cout << it << " ";    // Range-based loop
    for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";  // Iterator
    
    v.erase(v.begin());              // Erase first element
    v.erase(v.begin(), v.begin()+2); // Erase range
    v.pop_back();                    // Remove last element
    v.clear();                       // Clear vector
    cout << v.size() << endl;        // Size of vector
    cout << v.empty() << endl;       // Check if empty
}

void sets() {
    set<int> s;                      // Ordered unique elements
    s.insert(1);                     // Insert element
    s.emplace(2);                    // Insert element
    
    auto it = s.find(1);            // Find element
    s.erase(1);                     // Erase by value
    s.count(1);                     // Count occurrences (0 or 1)
    
    // Multiset allows duplicates
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
}

void maps() {
    map<int, string> mp;            // Ordered key-value pairs
    mp.insert({1, "one"});
    mp[2] = "two";                  // Another way to insert
    
    for(auto &pr : mp) {
        cout << pr.first << " " << pr.second << endl;
    }
    
    cout << mp.count(1) << endl;    // Check if key exists
    mp.erase(1);                    // Remove by key
    
    // Multimap allows duplicate keys
    multimap<int, string> mmp;
}

void stackQueue() {
    stack<int> st;
    st.push(1);
    st.pop();
    cout << st.top() << endl;       // View top element
    
    queue<int> q;
    q.push(1);
    q.pop();
    cout << q.front() << endl;      // First element
    cout << q.back() << endl;       // Last element
}

void priorityQueue() {
    // Max heap
    priority_queue<int> pq;
    // Min heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    
    pq.push(1);
    cout << pq.top() << endl;       // Get max element
    pq.pop();                       // Remove top element
}

void algorithms() {
    vector<int> v = {4, 2, 5, 1, 3};
    
    sort(v.begin(), v.end());       // Sort ascending
    sort(v.begin(), v.end(), greater<int>()); // Sort descending
    
    reverse(v.begin(), v.end());    // Reverse
    
    auto it = lower_bound(v.begin(), v.end(), 3);  // First element >= value
    auto it2 = upper_bound(v.begin(), v.end(), 3); // First element > value
    
    int mini = *min_element(v.begin(), v.end());
    int maxi = *max_element(v.begin(), v.end());
    
    int sum = accumulate(v.begin(), v.end(), 0);   // Sum of elements
    
    count(v.begin(), v.end(), 1);   // Count occurrences
    find(v.begin(), v.end(), 1);    // Find element
    
    next_permutation(v.begin(), v.end()); // Next lexicographical permutation
}

void strings() {
    string s = "hello";
    s.push_back('!');              // Add char at end
    s.pop_back();                  // Remove last char
    
    cout << s.substr(0, 2) << endl;  // Get substring
    cout << s.find("ll") << endl;    // Find substring
    
    // String to integer
    string num = "123";
    int n = stoi(num);
    
    // Integer to string
    string str = to_string(123);
}