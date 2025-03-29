# Job Sequencing Problem

## Problem Statement
You are given two arrays: `deadline[]` and `profit[]`, which represent a set of jobs. Each job has:
- A deadline by which it must be completed.
- A profit earned if the job is completed on time.

Each job takes **1 unit of time** to complete, and **only one job** can be scheduled at a time.

### Objective
Find:
1. **The maximum number of jobs** that can be completed within their deadlines.
2. **The maximum total profit** earned by completing those jobs.

---

## Examples

### Example 1:
#### **Input:**
```cpp
deadline[] = [4, 1, 1, 1]
profit[] = [20, 10, 40, 30]
```
#### **Output:**
```cpp
[2, 60]
```
#### **Explanation:**
- Job1 and Job3 can be done with maximum profit of 60 (20+40).

### Example 2:
#### **Input:**
```cpp
deadline[] = [2, 1, 2, 1, 1]
profit[] = [100, 19, 27, 25, 15]
```
#### **Output:**
```cpp
[2, 127]
```
#### **Explanation:**
- Job1 and Job3 can be done with maximum profit of 127 (100+27).

---

## Constraints
- `1 ≤ deadline.size() == profit.size() ≤ 10^5`
- `1 ≤ deadline[i] ≤ deadline.size()`
- `1 ≤ profit[i] ≤ 500`

---

## Approach
1. **Sort jobs in descending order of profit**.
2. **Find the maximum deadline** to determine the scheduling range.
3. **Use a greedy approach** to schedule jobs at the latest possible slot before their deadline.
4. **Track available slots** using an array.
5. **Calculate the total profit and count the scheduled jobs**.

---

## Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int>& d, vector<int>& p) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < d.size(); ++i) jobs.emplace_back(d[i], p[i]);
        sort(jobs.begin(), jobs.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& job : jobs) {
            if (job.first > pq.size()) pq.push(job.second);
            else if (pq.top() < job.second) pq.pop(), pq.push(job.second);
        }

        int cnt = pq.size(), tot = 0;
        while (!pq.empty()) tot += pq.top(), pq.pop();
        return {cnt, tot};
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        int x;

        getline(cin, temp);
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Complexity Analysis
1. **Sorting the jobs:** \(O(n \log n)\)
2. **Iterating over jobs:** \(O(n \cdot d)\) (where \(d\) is the max deadline, but at worst \(O(n^2)\) in case of all unique deadlines)
3. **Overall Complexity:** \(O(n \log n + n \cdot d)\), which is efficient for large inputs.

---

## Example Walkthrough

### **Input:**
```cpp
deadline[] = [3, 1, 2, 2]
profit[] = [50, 10, 20, 30]
```

### **Sorted Jobs by Profit:**
| Job | Profit | Deadline |
|-----|--------|----------|
| 1   | 50     | 3        |
| 4   | 30     | 2        |
| 3   | 20     | 2        |
| 2   | 10     | 1        |

### **Job Scheduling:**
- **Slot 3** → Job 1 (Profit 50)
- **Slot 2** → Job 4 (Profit 30)
- **Slot 1** → Job 3 (Profit 20)

### **Output:**
```cpp
3 100
```

---

## Key Takeaways
- **Greedy Approach** works best: Prioritize high-profit jobs first.
- **Sorting + Slot Allocation** ensures efficient scheduling.
- **Worst-case scenario \(O(n^2)\) is acceptable** due to sorting.

This solution efficiently finds the **maximum number of jobs** and **maximum profit** while respecting deadlines. 🚀

