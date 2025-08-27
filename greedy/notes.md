# Greedy Algorithms

Greedy Algorithms are approached to solve problems by making the current best choice at each stage with the hope of getting the best answer overall as well. At each step of the algorithm, we choose the best possible option available without considering the consequences of the choice in future steps.

## Key Characteristics

- Make the best choice at each step (locally optimal)
- Do not reconsider previous choices
- Fast and simple to implement
- May not always yield the global optimum, but work well for many problems

### Limitations

- Not all problems can be solved using greedy algorithms. For some problems, dynamic programming or other approaches are required to guarantee an optimal solution.
- Greedy approach can not be applied if there is no uniformity in the problem structure or if future consequences of current choices are significant.

---

## Classic Greedy Problems

### 1. Activity Selection Problem

Given start and end times of activities, select maximum number of non-overlapping activities.

```cpp
class Solution {
public:
    int activitySelection(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> activities;
        
        for (int i = 0; i < n; i++) {
            activities.push_back({end[i], start[i]});
        }
        
        // Sort by end time
        sort(activities.begin(), activities.end());
        
        int count = 1;
        int lastEndTime = activities[0].first;
        
        for (int i = 1; i < n; i++) {
            if (activities[i].second >= lastEndTime) {
                count++;
                lastEndTime = activities[i].first;
            }
        }
        
        return count;
    }
};
```

### 2. Fractional Knapsack

Maximize value by taking fractions of items within weight capacity.

```cpp
struct Item {
    int value, weight;
    double ratio;
    
    Item(int v, int w) : value(v), weight(w) {
        ratio = (double)value / weight;
    }
};

class Solution {
public:
    double fractionalKnapsack(int capacity, vector<Item>& items) {
        // Sort by value-to-weight ratio in descending order
        sort(items.begin(), items.end(), [](Item& a, Item& b) {
            return a.ratio > b.ratio;
        });
        
        double totalValue = 0.0;
        int currentWeight = 0;
        
        for (auto& item : items) {
            if (currentWeight + item.weight <= capacity) {
                // Take the whole item
                currentWeight += item.weight;
                totalValue += item.value;
            } else {
                // Take fractional part
                int remainingCapacity = capacity - currentWeight;
                totalValue += item.value * ((double)remainingCapacity / item.weight);
                break;
            }
        }
        
        return totalValue;
    }
};
```

### 3. Job Scheduling (Maximum Profit)

Schedule jobs with deadlines to maximize profit.

```cpp
struct Job {
    int id, deadline, profit;
    
    Job(int i, int d, int p) : id(i), deadline(d), profit(p) {}
};

class Solution {
public:
    vector<int> jobScheduling(vector<Job>& jobs) {
        // Sort by profit in descending order
        sort(jobs.begin(), jobs.end(), [](Job& a, Job& b) {
            return a.profit > b.profit;
        });
        
        int maxDeadline = 0;
        for (auto& job : jobs) {
            maxDeadline = max(maxDeadline, job.deadline);
        }
        
        vector<int> schedule(maxDeadline + 1, -1); // -1 means free slot
        int totalProfit = 0;
        int jobsScheduled = 0;
        
        for (auto& job : jobs) {
            // Find a free slot for this job (latest possible)
            for (int i = job.deadline; i >= 1; i--) {
                if (schedule[i] == -1) {
                    schedule[i] = job.id;
                    totalProfit += job.profit;
                    jobsScheduled++;
                    break;
                }
            }
        }
        
        return {jobsScheduled, totalProfit};
    }
};
```

### 4. Minimum Coins (Greedy Version)

Find minimum coins needed for a given amount (works for standard coin systems).

```cpp
class Solution {
public:
    int minCoins(vector<int>& coins, int amount) {
        // Sort coins in descending order
        sort(coins.rbegin(), coins.rend());
        
        int coinCount = 0;
        
        for (int coin : coins) {
            if (amount >= coin) {
                int numCoins = amount / coin;
                coinCount += numCoins;
                amount %= coin;
            }
        }
        
        return (amount == 0) ? coinCount : -1;
    }
};
```

### 5. Minimum Number of Platforms

Find minimum platforms needed for train schedule.

```cpp
class Solution {
public:
    int findPlatform(vector<int>& arrival, vector<int>& departure) {
        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());
        
        int platforms = 1;
        int maxPlatforms = 1;
        int i = 1, j = 0;
        
        while (i < arrival.size() && j < departure.size()) {
            if (arrival[i] <= departure[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }
            
            maxPlatforms = max(maxPlatforms, platforms);
        }
        
        return maxPlatforms;
    }
};
```

### 6. Jump Game II (Minimum Jumps)

Find minimum jumps to reach the end of array.

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int currentReach = 0;
        int maxReach = 0;
        
        for (int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            
            if (i == currentReach) {
                jumps++;
                currentReach = maxReach;
                
                if (currentReach >= n - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};
```

### 7. Assign Cookies

Maximize satisfied children with given cookies.

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookies) {
        sort(greed.begin(), greed.end());
        sort(cookies.begin(), cookies.end());
        
        int child = 0;
        int cookie = 0;
        
        while (child < greed.size() && cookie < cookies.size()) {
            if (cookies[cookie] >= greed[child]) {
                child++;
            }
            cookie++;
        }
        
        return child;
    }
};
```

### 8. Minimum Number of Meeting Rooms II

Find minimum meeting rooms needed.

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        
        for (auto& interval : intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int rooms = 0;
        int maxRooms = 0;
        int i = 0, j = 0;
        
        while (i < start.size()) {
            if (start[i] < end[j]) {
                rooms++;
                i++;
            } else {
                rooms--;
                j++;
            }
            
            maxRooms = max(maxRooms, rooms);
        }
        
        return maxRooms;
    }
};
```

## When to Use Greedy Algorithms

1. **Optimization Problems**: When looking for minimum/maximum values
2. **Choice Property**: When locally optimal choice leads to globally optimal solution
3. **Greedy Choice**: When we can make choice that looks best at the moment
4. **No Backtracking**: When we don't need to reconsider previous decisions

## Common Greedy Strategies

1. **Sort by End Time**: Activity selection, interval scheduling
2. **Sort by Ratio**: Fractional knapsack (value/weight)
3. **Sort by Deadline/Priority**: Job scheduling
4. **Two Pointers**: After sorting, use two pointers for efficient traversal
5. **Priority Queue**: For dynamic selection of optimal elements
