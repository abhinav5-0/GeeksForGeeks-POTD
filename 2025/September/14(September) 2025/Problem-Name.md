# Gas Station Problem

### Problem Statement

There are `n` gas stations along a circular tour. You are given two integer arrays `gas[]` and `cost[]`, where:

* `gas[i]` is the amount of gas available at station `i`
* `cost[i]` is the gas needed to travel from station `i` to station `(i+1)`

You have a car with an unlimited gas tank and start with an empty tank at some station. Your task is to return the index of the starting station if it is possible to travel once around the circular route clockwise without running out of gas at any station; otherwise, return `-1`.

**Note**: If a solution exists, it is guaranteed to be unique.

---

### Examples

**Input:**

```
gas[] = [4, 5, 7, 4]
cost[]= [6, 6, 3, 5]
```

**Output:**

```
2
```

**Explanation:**

* Start at station 2 with 7 gas → tank = 7
* Travel to station 3 → tank = 7 - 3 + 4 = 8
* Travel to station 0 → tank = 8 - 5 + 4 = 7
* Travel to station 1 → tank = 7 - 6 + 5 = 6
* Return to station 2 → tank = 6 - 6 = 0 ✅

**Input:**

```
gas[] = [3, 9]
cost[] = [7, 6]
```

**Output:**

```
-1
```

**Explanation:** Total gas < Total cost, so it is impossible.

---

### Constraints

* 1 ≤ n ≤ 10^6
* 1 ≤ gas\[i], cost\[i] ≤ 10^3

---

### Approach

1. **Feasibility Check:**

   * If total gas < total cost, return `-1`.

2. **Greedy Strategy:**

   * Traverse stations keeping track of:

     * `total` → overall net gas.
     * `tank` → current tank balance.
     * `start` → potential starting station.
   * If `tank` becomes negative, reset `tank = 0` and set `start = i+1`.
   * At the end, if `total >= 0`, return `start`; else return `-1`.

---

### Pseudocode

```
function startStation(gas, cost):
    n = length(gas)
    total = 0
    tank = 0
    start = 0

    for i in range(0, n):
        total += gas[i] - cost[i]
        tank += gas[i] - cost[i]

        if tank < 0:
            start = i + 1
            tank = 0

    if total >= 0:
        return start
    else:
        return -1
```

---

### C++ Implementation

```cpp
class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int total = 0, tank = 0, start = 0;

        for(int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            tank += gas[i] - cost[i];

            if(tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return (total >= 0) ? start : -1;
    }
};
```

---

### Complexity

* **Time Complexity:** O(n) → single pass through the array.
* **Space Complexity:** O(1) → constant extra space.

---

### Dry Run Example

**Input:**

```
gas = [4, 5, 7, 4]
cost = [6, 6, 3, 5]
```

| i | gas\[i] | cost\[i] | tank change | tank | start |
| - | ------- | -------- | ----------- | ---- | ----- |
| 0 | 4       | 6        | -2          | -2   | 0 → 1 |
| 1 | 5       | 6        | -1          | -1   | 1 → 2 |
| 2 | 7       | 3        | +4          | 4    | 2     |
| 3 | 4       | 5        | -1          | 3    | 2     |

Total = 0 ≥ 0 → Answer = 2 ✅
