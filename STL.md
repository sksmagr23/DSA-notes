# **C++ STL**

## Containers

### Sequence Containers

```cpp
// VECTORS
void vectors() {
    vector<int> v;
    v.push_back(1);                    // Insert at end
    v.emplace_back(2);                 // Faster insertion
    vector<int> v2(5, 100);            // 5 elements with value 100
    vector<int> v3 = {1, 2, 3, 4, 5};  // Initialize with values
    vector<int> v4(v3);                // Copy constructor

    cout << v[0] << endl;              // Access element (no bounds checking)
    cout << v.at(0) << endl;           // Access with bounds checking
    cout << v.front() << endl;         // First element
    cout << v.back() << endl;          // Last element

    for(auto it : v) cout << it << " ";    // Range-based loop
    for(auto it = v.begin(); it != v.end(); it++) cout << *it << " ";  // Iterator

    v.erase(v.begin());                // Erase first element
    v.erase(v.begin(), v.begin()+2);   // Erase range
    v.pop_back();                      // Remove last element
    v.insert(v.begin(), 5);            // Insert at position
    v.insert(v.begin(), 3, 10);        // Insert multiple copies
    v.insert(v.begin(), {1, 2, 3});    // Insert initializer list
    v.clear();                         // Clear vector
    
    cout << v.size() << endl;          // Size of vector
    cout << v.empty() << endl;         // Check if empty
    v.resize(10);                      // Resize to 10 elements
    v.resize(15, 100);                 // Resize to 15 elements, fill with 100

    // Swap two vectors
    vector<int> a = {1, 2}, b = {3, 4};
    a.swap(b);                         // a is now {3, 4}, b is {1, 2}
}

// ARRAY
void arrays() {
    array<int, 5> arr = {1, 2, 3, 4, 5};  // Fixed size array
    
    cout << arr[0] << endl;            // Access element (no bounds checking)
    cout << arr.at(0) << endl;         // Access with bounds checking
    cout << arr.front() << endl;       // First element
    cout << arr.back() << endl;        // Last element
    cout << arr.size() << endl;        // Size of array
    
    arr.fill(10);                      // Fill array with value
    
    // Get raw pointer to data
    int* data = arr.data();
    
    // Swap two arrays of same type and size
    array<int, 5> arr2 = {6, 7, 8, 9, 10};
    arr.swap(arr2);
}

// DEQUE (Double-ended Queue)
void deques() {
    deque<int> dq;
    dq.push_back(1);                   // Insert at back
    dq.push_front(2);                  // Insert at front
    dq.emplace_back(3);                // Faster back insertion
    dq.emplace_front(4);               // Faster front insertion
    
    cout << dq[0] << endl;             // Access element
    cout << dq.at(0) << endl;          // Access with bounds checking
    cout << dq.front() << endl;        // First element
    cout << dq.back() << endl;         // Last element
    
    dq.pop_back();                     // Remove from back
    dq.pop_front();                    // Remove from front
    dq.insert(dq.begin()+1, 5);        // Insert at position
    dq.erase(dq.begin());              // Erase element
    dq.erase(dq.begin(), dq.begin()+2); // Erase range
    
    cout << dq.size() << endl;         // Size of deque
    cout << dq.empty() << endl;        // Check if empty
    dq.clear();                        // Clear deque
    dq.resize(10);                     // Resize
}

// LIST (Doubly Linked List)
void lists() {
    list<int> lst;
    lst.push_back(1);                  // Insert at back
    lst.push_front(2);                 // Insert at front
    lst.emplace_back(3);               // Faster back insertion
    lst.emplace_front(4);              // Faster front insertion
    
    cout << lst.front() << endl;       // First element
    cout << lst.back() << endl;        // Last element
    
    auto it = lst.begin();
    advance(it, 2);                    // Move iterator forward
    lst.insert(it, 5);                 // Insert at position
    lst.erase(lst.begin());            // Erase from beginning
    
    lst.pop_back();                    // Remove from back
    lst.pop_front();                   // Remove from front
    lst.remove(5);                     // Remove all instances of value
    
    list<int> lst2 = {5, 2, 9, 1, 8};
    lst2.sort();                       // Sort the list
    lst2.unique();                     // Remove consecutive duplicates
    lst2.reverse();                    // Reverse the list
    
    list<int> lst3 = {100, 200};
    lst.splice(lst.begin(), lst3);     // Move elements from lst3 to lst
    
    cout << lst.size() << endl;        // Size of list
    lst.clear();                       // Clear list
    cout << lst.empty() << endl;       // Check if empty
}

// FORWARD_LIST (Singly Linked List)
void forward_lists() {
    forward_list<int> fl = {1, 2, 3};
    fl.push_front(0);                  // Insert at front
    fl.emplace_front(-1);              // Faster front insertion
    
    cout << fl.front() << endl;        // First element
    
    fl.insert_after(fl.begin(), 4);    // Insert after position
    fl.erase_after(fl.begin());        // Erase element after position
    
    fl.remove(2);                      // Remove all instances of value
    fl.remove_if([](int x) { return x < 0; }); // Remove based on predicate
    
    fl.sort();                         // Sort the list
    fl.unique();                       // Remove consecutive duplicates
    fl.reverse();                      // Reverse the list
    
    forward_list<int> fl2 = {10, 20};
    fl.splice_after(fl.begin(), fl2);  // Move elements after pos from fl2
    
    // No size() function in forward_list
    fl.clear();                        // Clear list
    cout << fl.empty() << endl;        // Check if empty
}
```

### Associative Containers

```cpp
// SETS
void sets() {
    set<int> s;                      // Ordered unique elements
    s.insert(1);                     // Insert element
    s.emplace(2);                    // Insert element
    s.insert({3, 4, 5});             // Insert multiple elements

    auto it = s.find(1);             // Find element (iterator)
    if(it != s.end()) cout << *it << endl;
    
    s.erase(1);                      // Erase by value
    s.erase(it);                     // Erase by iterator
    s.erase(s.begin(), s.find(4));   // Erase range
    
    cout << s.count(1) << endl;      // Count occurrences (0 or 1)
    
    auto lb = s.lower_bound(3);      // First element >= value
    auto ub = s.upper_bound(3);      // First element > value
    auto range = s.equal_range(3);   // Pair of lb and ub
    
    cout << s.size() << endl;        // Size of set
    cout << s.empty() << endl;       // Check if empty
    s.clear();                       // Clear set
    
    // Comparator
    set<int, greater<int>> desc_set; // Descending order

    // Multiset allows duplicates
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);                   // Contains two 1's
    ms.erase(1);                    // Erases all 1's
    ms.erase(ms.find(1));           // Erases only one occurrence
    
    cout << ms.count(1) << endl;    // Count occurrences
}

// MAPS
void maps() {
    map<int, string> mp;             // Ordered key-value pairs
    mp.insert({1, "one"});           // Insert pair
    mp.insert(make_pair(2, "two"));  // Another way
    mp[3] = "three";                 // Another way to insert/update
    mp.emplace(4, "four");           // Construct in-place
    
    cout << mp[1] << endl;           // Access by key (inserts default if not exists)
    cout << mp.at(1) << endl;        // Access by key (throws if not exists)
    
    for(auto &pr : mp) {
        cout << pr.first << " " << pr.second << endl;
    }
    
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    auto it = mp.find(1);            // Find by key
    if(it != mp.end()) cout << it->second << endl;
    
    cout << mp.count(1) << endl;     // Check if key exists
    mp.erase(1);                     // Remove by key
    mp.erase(it);                    // Remove by iterator
    
    auto lb = mp.lower_bound(3);     // First key >= value
    auto ub = mp.upper_bound(3);     // First key > value
    auto range = mp.equal_range(3);  // Pair of lb and ub
    
    cout << mp.size() << endl;       // Size of map
    cout << mp.empty() << endl;      // Check if empty
    mp.clear();                      // Clear map
    
    // Multimap allows duplicate keys
    multimap<int, string> mmp;
    mmp.insert({1, "one"});
    mmp.insert({1, "first"});       // Both entries exist
    
    // Count entries with key=1
    cout << mmp.count(1) << endl;
    
    // Iterate over all entries with key=1
    auto range = mmp.equal_range(1);
    for(auto it = range.first; it != range.second; ++it) {
        cout << it->second << endl;
    }
}
```

### Unordered Containers

```cpp
// UNORDERED_SET (Hash Set)
void unordered_sets() {
    unordered_set<int> us;          // Hash-based unique elements
    us.insert(1);                   // Insert element
    us.emplace(2);                  // Insert element
    
    auto it = us.find(1);           // Find element (constant time avg)
    us.erase(1);                    // Erase by value
    us.erase(it);                   // Erase by iterator
    
    cout << us.count(1) << endl;    // Check if exists
    
    cout << us.size() << endl;      // Size of unordered_set
    cout << us.empty() << endl;     // Check if empty
    us.clear();                     // Clear unordered_set
    
    // Performance tuning
    us.reserve(1000);               // Reserve buckets for elements
    cout << us.load_factor() << endl; // Average elements per bucket
    cout << us.max_load_factor() << endl; // Max load factor before rehash
    us.max_load_factor(0.7);        // Set max load factor
    us.rehash(100);                 // Set minimum number of buckets
    cout << us.bucket_count() << endl; // Number of buckets
    
    // Multiset version
    unordered_multiset<int> ums;
    ums.insert(1);
    ums.insert(1);                  // Contains two 1's
    
}

// UNORDERED_MAP (Hash Map)
void unordered_maps() {
    unordered_map<string, int> um;   // Hash-based key-value pairs
    um.insert({"apple", 5});
    um["banana"] = 3;                // Insert or update
    um.emplace("cherry", 10);        // Construct in-place
    
    cout << um["apple"] << endl;     // Access by key
    cout << um.at("banana") << endl; // Access (throws if not exists)
    
    auto it = um.find("apple");      // Find by key (constant time avg)
    if(it != um.end()) cout << it->second << endl;
    
    cout << um.count("apple") << endl; // Check if key exists
    
    um.erase("apple");               // Remove by key
    um.erase(it);                    // Remove by iterator
    
    cout << um.size() << endl;       // Size of unordered_map
    cout << um.empty() << endl;      // Check if empty
    um.clear();                      // Clear unordered_map
    
    
    // Multimap version
    unordered_multimap<string, int> umm;
    umm.insert({"apple", 1});
    umm.insert({"apple", 2});        // Both entries exist
    
    // Count entries with key
    cout << umm.count("apple") << endl;
    
    // Iterate over all entries with key
    auto range = umm.equal_range("apple");
    for(auto it = range.first; it != range.second; ++it) {
        cout << it->second << endl;
    }
}
```

### Container Adaptors

```cpp
// STACK (LIFO)
void stacks() {
    stack<int> st;
    st.push(1);                      // Add element
    st.emplace(2);                   // Construct in-place
    
    cout << st.top() << endl;        // View top element
    st.pop();                        // Remove top element
    
    cout << st.size() << endl;       // Size of stack
    cout << st.empty() << endl;      // Check if empty
    
    // Stack with deque as underlying container
    stack<int, deque<int>> st_deque;
    
    // Stack with list as underlying container
    stack<int, list<int>> st_list;
}

// QUEUE (FIFO)
void queues() {
    queue<int> q;
    q.push(1);                       // Add element
    q.emplace(2);                    // Construct in-place
    
    cout << q.front() << endl;       // First element
    cout << q.back() << endl;        // Last element
    q.pop();                         // Remove first element
    
    cout << q.size() << endl;        // Size of queue
    cout << q.empty() << endl;       // Check if empty
    
    // Queue with list as underlying container
    queue<int, list<int>> q_list;
}

// PRIORITY_QUEUE
void priority_queues() {
    // Max heap (default)
    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(5);
    pq.emplace(4);                   // Construct in-place
    
    cout << pq.top() << endl;        // Get max element (5)
    pq.pop();                        // Remove top element
    
    cout << pq.size() << endl;       // Size of priority_queue
    cout << pq.empty() << endl;      // Check if empty
    
    // Min heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(3);
    min_pq.push(1);
    min_pq.push(5);
    
    cout << min_pq.top() << endl;    // Get min element (1)
    
    custom_pq.push({1, 5});
    custom_pq.push({2, 3});
    custom_pq.push({3, 4});
    
    cout << custom_pq.top().first << endl;  // 2, because it has lowest second value
}
```

## Iterators

```cpp
void iterators_demo() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // Forward iterators
    auto it = v.begin();              // Iterator to first element
    auto end = v.end();               // Iterator past the last element
    
    cout << *it << endl;              // Dereference iterator
    cout << *(it + 2) << endl;        // Random access (only for random access iterators)
    it++;                             // Move to next element
    advance(it, 2);                   // Move forward by 2
    
    // Reverse iterators
    auto rit = v.rbegin();            // Reverse iterator (points to last element)
    auto rend = v.rend();             // End of reverse iteration
    cout << *rit << endl;             // Last element
    rit++;                            // Move backward
    
    // Const iterators
    auto cit = v.cbegin();            // Const iterator (can't modify elements)
    auto cend = v.cend();             // End of const iteration
    
    // Iterator functions
    auto next_it = next(it);          // Return iterator to next element
    auto prev_it = prev(it);          // Return iterator to previous element
    
    vector<int> v2;
    copy(v.begin(), v.end(), back_inserter(v2)); // Copy using back_inserter
    
    // Iterator adapters
    auto insert_it = inserter(v2, v2.begin() + 2); // Insert iterator
    *insert_it = 10;                  // Insert at position
    
    // Iterator categories:
    // - Input iterators: read only, forward moving
    // - Output iterators: write only, forward moving
    // - Forward iterators: read/write, forward moving
    // - Bidirectional iterators: read/write, forward/backward
    // - Random access iterators: read/write, arbitrary access
}
```

## Algorithms

```cpp
void algorithms() {
    vector<int> v = {4, 2, 5, 1, 3};
    
    // Non-modifying sequence operations
    all_of(v.begin(), v.end(), [](int x){ return x > 0; });  // Check if all elements satisfy condition
    any_of(v.begin(), v.end(), [](int x){ return x % 2 == 0; }); // Check if any element satisfies condition
    none_of(v.begin(), v.end(), [](int x){ return x < 0; }); // Check if no elements satisfy condition
    
    for_each(v.begin(), v.end(), [](int& x){ x *= 2; });     // Apply function to each element
    
    count(v.begin(), v.end(), 1);                            // Count occurrences
    count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; }); // Count elements satisfying condition
    
    auto it = find(v.begin(), v.end(), 1);                   // Find element
    auto it2 = find_if(v.begin(), v.end(), [](int x){ return x > 3; }); // Find first element satisfying condition
    
    // Modifying sequence operations
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));  // Copy elements
    vector<int> v2(v.size());
    copy_if(v.begin(), v.end(), v2.begin(), [](int x){ return x % 2 == 0; }); // Copy elements satisfying condition
    
    replace(v.begin(), v.end(), 1, 10);                      // Replace all 1's with 10's
    replace_if(v.begin(), v.end(), [](int x){ return x < 3; }, 0); // Replace elements satisfying condition
    
    fill(v.begin(), v.end(), 7);                             // Fill range with value
    generate(v.begin(), v.end(), []{ return rand() % 10; });  // Fill range with generated values
    
    remove(v.begin(), v.end(), 3);                           // Remove all 3's
    auto new_end = remove_if(v.begin(), v.end(), [](int x){ return x < 5; }); // Remove elements satisfying condition
    v.erase(new_end, v.end());                               // Erase the "removed" elements
    
    unique(v.begin(), v.end());                              // Remove consecutive duplicates
    
    reverse(v.begin(), v.end());                             // Reverse range
    rotate(v.begin(), v.begin() + 2, v.end());               // Rotate elements
    
    random_shuffle(v.begin(), v.end());                      // Shuffle elements randomly
    shuffle(v.begin(), v.end(), default_random_engine());    // C++11 shuffling
    
    // Sorting operations
    sort(v.begin(), v.end());                                // Sort ascending
    sort(v.begin(), v.end(), greater<int>());                // Sort descending
    stable_sort(v.begin(), v.end());                         // Stable sort
    
    partial_sort(v.begin(), v.begin() + 3, v.end());         // Sort only first 3 elements
    nth_element(v.begin(), v.begin() + 2, v.end());          // Position the nth element correctly
    
    // Binary search operations (on sorted ranges)
    binary_search(v.begin(), v.end(), 3);                    // Check if element exists
    
    auto lb = lower_bound(v.begin(), v.end(), 3);            // First element >= value
    auto ub = upper_bound(v.begin(), v.end(), 3);            // First element > value
    auto eq_range = equal_range(v.begin(), v.end(), 3);      // Pair of lower_bound and upper_bound
    
    // Numeric operations
    int mini = *min_element(v.begin(), v.end());             // Find minimum element
    int maxi = *max_element(v.begin(), v.end());             // Find maximum element
    auto [min_it, max_it] = minmax_element(v.begin(), v.end()); // Find min and max elements
    
    int sum = accumulate(v.begin(), v.end(), 0);             // Sum of elements
    int product = accumulate(v.begin(), v.end(), 1, multiplies<int>()); // Product of elements
    
    partial_sum(v.begin(), v.end(), v2.begin());             // Compute partial sums
    adjacent_difference(v.begin(), v.end(), v2.begin());     // Compute adjacent differences
    
    inner_product(v.begin(), v.end(), v2.begin(), 0);        // Inner product
    
    iota(v.begin(), v.end(), 1);                             // Fill with increasing values
    
    // Set operations (on sorted ranges)
    vector<int> a = {1, 2, 3, 5, 7};
    vector<int> b = {2, 4, 5, 6, 8};
    vector<int> result(10);
    
    auto it_end = set_union(a.begin(), a.end(), b.begin(), b.end(), result.begin()); // Union
    result.resize(it_end - result.begin());
    
    it_end = set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin()); // Intersection
    it_end = set_difference(a.begin(), a.end(), b.begin(), b.end(), result.begin());   // Difference
    it_end = set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), result.begin()); // Symmetric difference
    
    // Heap operations
    vector<int> h = {9, 1, 4, 7, 3};
    make_heap(h.begin(), h.end());                           // Create a max heap
    cout << h.front() << endl;                               // Get max element
    
    pop_heap(h.begin(), h.end());                            // Move max to end
    h.pop_back();                                            // Remove last (max) element
    
    h.push_back(8);                                          // Add new element
    push_heap(h.begin(), h.end());                           // Heapify with new element
    
    sort_heap(h.begin(), h.end());                           // Sort heap
    
    // Permutation operations
    vector<int> p = {1, 2, 3};
    do {
        for(int x : p) cout << x << " ";
        cout << endl;
    } while (next_permutation(p.begin(), p.end()));          // Generate all permutations
    
    prev_permutation(p.begin(), p.end());                    // Previous permutation
}
```

## Strings

```cpp
void strings() {
    string s = "hello world";
        string s2("hello");                  // Constructor
        string s3 = s2;                      // Copy
        string s4 = move(s3);                // Move
        string s5(10, 'a');                  // 10 copies of 'a'
        string s6 = s.substr(0, 5);          // Substring
        
        s.push_back('!');                    // Add char at end
        s.pop_back();                        // Remove last char
        s.append(" there");                  // Append string
        s.append(3, '!');                    // Append multiple copies
        s += " and more";                    // Another way to append
        
        s.insert(6, "beautiful ");           // Insert at position
        s.erase(6, 10);                      // Erase characters
        s.replace(0, 5, "hi");               // Replace substring
        
        cout << s.length() << endl;          // Length of string
        cout << s.size() << endl;            // Same as length
        cout << s.empty() << endl;           // Check if empty
        s.clear();                           // Clear string
        
        cout << s.find("lo") << endl;        // Find substring
        cout << s.rfind("lo") << endl;       // Find substring from right
        cout << s.find_first_of("aeiou") << endl; // Find first of these chars
        cout << s.find_last_of("aeiou") << endl;  // Find last of these chars
        cout << s.find_first_not_of("aeiou") << endl; // First char not in set
        
        cout << s.compare("hello") << endl;  // Compare strings
        
        // Character classification
        char ch = 'A';
        cout << isalnum(ch) << endl;         // Check if alphanumeric (a-z, A-Z, 0-9)
        cout << isdigit(ch) << endl;         // Check if digit (0-9)
        cout << isalpha(ch) << endl;         // Check if alphabetic (a-z, A-Z)
        cout << islower(ch) << endl;         // Check if lowercase
        cout << isupper(ch) << endl;         // Check if uppercase
        cout << isspace(ch) << endl;         // Check if whitespace
        cout << ispunct(ch) << endl;         // Check if punctuation
        
        // Character conversion
        cout << tolower(ch) << endl;         // Convert to lowercase
        cout << toupper(ch) << endl;         // Convert to uppercase
        
        // String to number
        string num = "123";
        int n = stoi(num);                   // String to int
        long ln = stol(num);                 // String to long
        long long lln = stoll(num);          // String to long long
        float f = stof("3.14");              // String to float
        double d = stod("3.14159");          // String to double
        
        // Number to string
        string str = to_string(123);         // Int to string
        string str2 = to_string(3.14159);    // Double to string
        
        // C-style strings
        const char* cstr = s.c_str();        // Get C string
        char buffer[20];
        strcpy(buffer, s.c_str());           // Copy to buffer
        
        // String stream
        stringstream ss;
        ss << "Value: " << 42 << " and PI: " << 3.14159;  // Write to stream
        string result = ss.str();            // Get string from stream
        cout << result << endl;              // Outputs: "Value: 42 and PI: 3.14159"
        
        // Parsing with stringstream
        stringstream parser("123 3.14 Hello");
        int i;
        double d2;
        string word;
        parser >> i >> d2 >> word;           // Extract values
        cout << i << " " << d2 << " " << word << endl;  // Outputs: "123 3.14 Hello"
        
        // Using stringstream for type conversion
        stringstream converter;
        converter << 42;                     // Insert int
        string str_val = converter.str();    // "42"
        
        converter.str("");                   // Clear the stream
        converter.clear();                   // Reset error flags
        
        converter << "3.14159";              // Insert string
        double pi;
        converter >> pi;                     // Extract as double
        cout << "PI: " << pi << endl;        // Outputs: "PI: 3.14159"
        
        // String concatenation
        stringstream concat;
        concat << "Combining " << "multiple " << "strings " << "efficiently";
        string combined = concat.str();      // More efficient than + for many strings
        cout << combined << endl;            // Outputs: "Combining multiple strings efficiently"
}
```

## Utility Components

```cpp
void utility_components() {
    // PAIR
    pair<int, string> p = {1, "one"};
    cout << p.first << " " << p.second << endl;
    
    auto p2 = make_pair(2, "two");
    p2.swap(p);                          // Swap pairs
    
    // TUPLE
    tuple<int, string, double> t = {1, "one", 1.1};
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    
    int n;
    string s;
    double d;
    tie(n, s, d) = t;                    // Unpack tuple
    
    auto t2 = make_tuple(2, "two", 2.2);
    t2.swap(t);                          // Swap tuples
    
    // SMART POINTERS
    unique_ptr<int> uptr = make_unique<int>(10);  // Only one owner
    cout << *uptr << endl;
    
    shared_ptr<int> sptr = make_shared<int>(20);  // Reference counted
    shared_ptr<int> sptr2 = sptr;                 // Both point to same object
    cout << *sptr << " " << *sptr2 << endl;
    cout << sptr.use_count() << endl;             // Reference count
    
    weak_ptr<int> wptr = sptr;                   // Doesn't affect reference count
    if(auto sp = wptr.lock()) {                  // Check if object still exists
        cout << *sp << endl;
    }
    
    // BITSET
    bitset<8> bits("10101010");
    cout << bits[0] << endl;                      // Access bit
    cout << bits.count() << endl;                 // Count set bits
    bits.set(1);                                  // Set bit to 1
    bits.reset(2);                                // Set bit to 0
    bits.flip();                                  // Flip all bits
    cout << bits.to_string() << endl;             // To string
    cout << bits.to_ulong() << endl;              // To unsigned long

     // Lambda expressions (C++11)
    auto lambda = [](int x) { return x * x; };
    cout << lambda(5) << endl;         // 25
}
```

