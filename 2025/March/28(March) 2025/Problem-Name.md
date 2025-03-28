# Activity Selection Problem

## Problem Statement
You are given a set of activities, each with a start time and a finish time, represented by the arrays `start[]` and `finish[]`, respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.

### Examples
#### Input 1:
```cpp
start[] = [1, 3, 0, 5, 8, 5]
finish[] = [2, 4, 6, 7, 9, 9]
```
#### Output 1:
```cpp
4
```
#### Explanation:
A person can perform at most four activities. The maximum set of activities that can be executed is `{0, 1, 3, 4}`.

#### Input 2:
```cpp
start[] = [10, 12, 20]
finish[] = [20, 25, 30]
```
#### Output 2:
```cpp
1
```
#### Explanation:
A person can perform at most one activity.

## Approach
1. **Pair Activities:** Store activities as `(finish time, start time)` pairs in a vector.
2. **Sort Activities:** Sort the activities based on **finish times** in ascending order.
3. **Select Activities:**
   - Initialize a counter for selected activities.
   - Always select the first activity.
   - For the rest of the activities, pick one only if its start time is **greater than or equal to** the last selected finish time.

## Time Complexity
- **Sorting:** `O(N log N)`
- **Selecting Activities:** `O(N)`
- **Overall Complexity:** `O(N log N)`

## C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> activities;
        for (int i = 0; i < start.size(); i++) activities.push_back({finish[i], start[i]});
        sort(activities.begin(), activities.end());
        int count = 1, end = activities[0].first;
        for (int i = 1; i < activities.size(); i++) {
            if (activities[i].second > end) {
                count++;
                end = activities[i].first;
            }
        }
        return count;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        ss.str(input);
        vector<int> finish;
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
```

## Explanation with Example Walkthrough
### Given Input:
```cpp
start[] = [1, 3, 0, 5, 8, 5]
finish[] = [2, 4, 6, 7, 9, 9]
```
### Sorted Activities Based on Finish Time:
```
[(2,1), (4,3), (6,0), (7,5), (9,8), (9,5)]
```
### Selected Activities:
1. Select **(2,1)** → Finish = **2**
2. Select **(4,3)** → Finish = **4**
3. Select **(7,5)** → Finish = **7**
4. Select **(9,8)** → Finish = **9**

### Output:
```cpp
4
```

## Key Points
✅ **Greedy Algorithm** ensures optimal activity selection.
✅ **Efficient Sorting** in `O(N log N)`, suitable for large `N` (up to `2 * 10^5`).
✅ **Simple Iteration** for selecting activities in `O(N)`. 🚀

