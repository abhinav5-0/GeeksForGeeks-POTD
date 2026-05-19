````md
# Minimum Multiplications to Reach End

## Problem Statement

Given two integers `start` and `end`, along with an array of integers `arr[]`.

In one operation, you can:

- Multiply the current value by any element from `arr[]`
- Take the result modulo `1000`

The new value becomes:

```cpp
newValue = (current * arr[i]) % 1000
````

Your task is to find the **minimum number of multiplications** required to reach `end` starting from `start`.

If it is not possible to reach `end`, return `-1`.

---

## Examples

### Example 1

#### Input

```cpp
arr[] = {2, 5, 7}
start = 3
end = 30
```

#### Output

```cpp
2
```

#### Explanation

```text
Step 1: 3 * 2 = 6 % 1000 = 6
Step 2: 6 * 5 = 30 % 1000 = 30
```

So, minimum steps = `2`.

---

### Example 2

#### Input

```cpp
arr[] = {3, 4, 65}
start = 7
end = 175
```

#### Output

```cpp
4
```

#### Explanation

```text
Step 1: 7 * 3 = 21 % 1000 = 21
Step 2: 21 * 3 = 63 % 1000 = 63
Step 3: 63 * 65 = 4095 % 1000 = 95
Step 4: 95 * 65 = 6175 % 1000 = 175
```

So, minimum steps = `4`.

---

### Example 3

#### Input

```cpp
arr[] = {2, 4}
start = 3
end = 5
```

#### Output

```cpp
-1
```

#### Explanation

Starting from `3`, multiplying by `2` or `4` always produces even numbers after the first step.

Since `5` is odd, it can never be reached.

---

## Constraints

```cpp
1 <= arr.size() <= 10^3
1 <= arr[i] <= 10^3
0 <= start, end < 10^3
```

---

# Approach

This problem can be solved using **Breadth First Search (BFS)**.

Since every multiplication operation costs exactly **1 step**, BFS guarantees the shortest path.

We treat every number from `0` to `999` as a node.

From a current node:

```cpp
node -> (node * arr[i]) % 1000
```

We use:

* A queue for BFS traversal
* A distance array to store minimum steps

---

# Algorithm

1. Create a distance array of size `1000` initialized with `INT_MAX`
2. Push `start` into queue
3. Set `dist[start] = 0`
4. Perform BFS:

   * Pop current number
   * Multiply with every element of `arr`
   * Take modulo `1000`
   * If new node gives smaller distance:

     * Update distance
     * Push into queue
5. If `end` is reached, return steps
6. Otherwise return `-1`

---

# Time Complexity

```cpp
O(1000 * N)
```

Where:

* `1000` = maximum possible states
* `N` = size of array

---

# Space Complexity

```cpp
O(1000)
```

---

# C++ Solution

```cpp
class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {

        vector<int> dist(1000, INT_MAX);

        queue<pair<int,int>> q;

        q.push({start, 0});
        dist[start] = 0;

        while(!q.empty()) {

            int node = q.front().first;
            int steps = q.front().second;

            q.pop();

            for(int i = 0; i < arr.size(); i++) {

                int num = (node * arr[i]) % 1000;

                if(steps + 1 < dist[num]) {

                    dist[num] = steps + 1;

                    if(num == end)
                        return steps + 1;

                    q.push({num, steps + 1});
                }
            }
        }

        return -1;
    }
};
```

---

# Key Insight

Because modulo `1000` is used, there are only `1000` possible states (`0` to `999`).

This makes BFS highly efficient for finding the shortest number of multiplications.

```
```
