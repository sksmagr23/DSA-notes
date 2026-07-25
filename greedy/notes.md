# Greedy Algorithms

A **Greedy Algorithm** builds up a solution piece by piece, always choosing the next piece that offers the most immediate and local benefit (local optimum) with the hope of finding a global optimum.

### Key Characteristics
- **Greedy Choice Property**: A globally optimal solution can be reached by making locally optimal choices.
- **Optimal Substructure**: An optimal solution to the overall problem contains optimal solutions to sub-problems.
- **No Backtracking**: Once a decision is made, it is never reversed.

---

## 1. Assign Cookies

- **Problem**: Match children's greed factor `g[i]` with cookie size `s[j]`. Give child `i` a cookie `j` such that `s[j] >= g[i]` to maximize happy children.
- **Intuition**: Sort both `g` and `s`. Always give the smallest cookie that satisfies the child with the smallest greed.
- **TC**: $O(N \log N + M \log M)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0, r = 0;
        while (l < g.size() && r < s.size()) {
            if (s[r] >= g[l]) {
                l++; // Child satisfied
            }
            r++; // Try next cookie
        }
        return l;
    }
};
```

---

## 2. Fractional Knapsack Problem

- **Problem**: Given items with values and weights, and a knapsack of max capacity $W$, pick items (fractions allowed) to maximize total value.
- **Intuition**: Calculate `value / weight` ratio for each item. Sort items in descending order of ratio and greedily take as much of the highest ratio item as possible.
- **TC**: $O(N \log N)$, **SC**: $O(1)$.

```cpp
struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool comp(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, comp);

        double totalValue = 0.0;
        int currentWeight = 0;

        for (int i = 0; i < n; i++) {
            if (currentWeight + arr[i].weight <= w) {
                currentWeight += arr[i].weight;
                totalValue += arr[i].value;
            } else {
                int remain = w - currentWeight;
                totalValue += ((double)arr[i].value / (double)arr[i].weight) * (double)remain;
                break; // Knapsack is full
            }
        }
        return totalValue;
    }
};
```

---

## 3. N Meetings in One Room / Non-overlapping Intervals

- **Problem**: Maximum number of meetings that can be accommodated in a single meeting room.
- **Intuition**: Sort meetings by their **end time**. Always pick the meeting that finishes earliest so that the room becomes free as soon as possible.
- **TC**: $O(N \log N)$, **SC**: $O(N)$.

```cpp
struct Meeting {
    int start;
    int end;
    int pos;
};

class Solution {
public:
    static bool comparator(Meeting m1, Meeting m2) {
        if (m1.end < m2.end) return true;
        else if (m1.end > m2.end) return false;
        else if (m1.pos < m2.pos) return true;
        return false;
    }

    int maxMeetings(int start[], int end[], int n) {
        vector<Meeting> meet(n);
        for (int i = 0; i < n; i++) {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        sort(meet.begin(), meet.end(), comparator);

        int count = 1;
        int limit = meet[0].end;

        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                count++;
            }
        }
        return count;
    }
};
```

---

## 4. Minimum Platforms Required for Trains

- **Problem**: Minimum number of platforms required for the railway station so that no train waits.
- **Intuition**: Sort arrival and departure times independently. Use two pointers (`i` for arrivals, `j` for departures). If `arr[i] <= dep[j]`, a new platform is needed (`plat++`). Otherwise, a platform frees up (`plat--`).
- **TC**: $O(N \log N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int plat_needed = 1, result = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            } else {
                plat_needed--;
                j++;
            }
            result = max(result, plat_needed);
        }
        return result;
    }
};
```

---

## 5. Job Sequencing Problem

- **Problem**: Given jobs with deadlines and profits, earn max profit by scheduling 1 job at a time before its deadline.
- **Intuition**: Sort jobs in descending order of profit. For each job, schedule it on the latest possible available slot before or on its deadline day.
- **TC**: $O(N \log N + N \times \text{max\_deadline})$, **SC**: $O(\text{max\_deadline})$.

```cpp
struct Job {
    int id;
    int dead;
    int profit;
};

class Solution {
public:
    static bool comparison(Job a, Job b) {
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comparison);

        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        vector<int> slot(maxi + 1, -1);

        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countJobs, jobProfit};
    }
};
```

---

## 6. Jump Game I & II

### Jump Game I (Can reach end?)
- **Intuition**: Maintain `maxReach`. At index `i`, if `i > maxReach`, return `false`. Update `maxReach = max(maxReach, i + nums[i])`.
- **TC**: $O(N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIndex) return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};
```

### Jump Game II (Minimum jumps to reach end)
- **Intuition**: BFS-like greedy approach with range `[l, r]`. Find the farthest index reachable from `[l, r]`, then set `l = r + 1` and `r = farthest`, incrementing `jumps`.
- **TC**: $O(N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, l = 0, r = 0;

        while (r < nums.size() - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
```

---

## 7. Gas Station (Circuit Completion)

- **Problem**: Find starting gas station index to complete a full circular tour.
- **Intuition**: If total gas < total cost, return -1. Otherwise, iterate through stations accumulating `currentGas += gas[i] - cost[i]`. If `currentGas < 0`, reset `currentGas = 0` and set `startNode = i + 1`.
- **TC**: $O(N)$, **SC**: $O(1)$.

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) return -1; // Impossible

        int start = 0, currGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            currGas += (gas[i] - cost[i]);
            if (currGas < 0) {
                currGas = 0;
                start = i + 1; // Cannot start anywhere from current start to i
            }
        }
        return start;
    }
};
```

---

## 8. Candy (Distribution)

- **Problem**: $N$ children standing in line. Each child must get at least 1 candy. Children with higher rating than neighbor get more candies than neighbor. Minimize total candies.
- **Intuition**: Two passes:
  1. Left-to-Right: If `ratings[i] > ratings[i-1]`, `candy[i] = candy[i-1] + 1`.
  2. Right-to-Left: If `ratings[i] > ratings[i+1]`, `candy[i] = max(candy[i], candy[i+1] + 1)`.
- **TC**: $O(N)$, **SC**: $O(N)$.

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int c : candies) totalCandies += c;
        return totalCandies;
    }
};
```
