````md
# Minimum Multiplications to Reach End

## Problem Statement

Given two integers `start` and `end`, along with an array of integers `arr[]`.

In one operation:

- Multiply the current value by any element from `arr[]`
- Take the result modulo `1000`

Formally:

```cpp
next = (current * arr[i]) % 1000
````

Find the **minimum number of multiplications** required to reach `end` starting from `start`.

If it is not possible to reach `end`, return `-1`.

---

## Examples

### Example 1

```txt
Input:
arr[] = [2, 5, 7]
start = 3
end = 30

Output:
2
```

### Explanation

```txt
Step 1:
3 * 2 = 6 % 1000 = 6

Step 2:
6 * 5 = 30 % 1000 = 30
```

Minimum multiplications = `2`

---

### Example 2

```txt
Input:
arr[] = [3, 4, 65]
start = 7
end = 175

Output:
4
```

### Explanation

```txt
Step 1:
7 * 3 = 21 % 1000 = 21

Step 2:
21 * 3 = 63 % 1000 = 63

Step 3:
63 * 65 = 4095 % 1000 = 95

Step 4:
95 * 65 = 6175 % 1000 = 175
```

Minimum multiplications = `4`

---

### Example 3

```txt
Input:
arr[] = [2, 4]
start = 3
end = 5

Output:
-1
```

### Explanation

Starting from `3`, multiplying by `2` or `4` always produces even numbers after the first step.

Since `5` is odd, it can never be reached.

---

# Approach

This problem can be solved using **Breadth First Search (BFS)**.

---

## Key Observation

Since every result is taken modulo `1000`, there are only:

```txt
0 to 999
```

possible states.

Each number can be considered as a node in a graph.

From a node `x`, we can move to:

```cpp
(x * arr[i]) % 1000
```

for every element in `arr[]`.

Since every operation costs `1` step, BFS gives the minimum operations.

---

# Algorithm

1. If `start == end`, return `0`
2. Create a distance array of size `1000`
3. Initialize all distances with infinity
4. Push `start` into queue
5. Perform BFS:

   * Pop current node
   * Try multiplying with every element
   * Generate next node
   * If a shorter path is found:

     * Update distance
     * Push into queue
6. If `end` is reached, return steps
7. Otherwise return `-1`

---

# Time Complexity

```txt
O(1000 * N)
```

Where:

* `1000` = maximum states
* `N` = size of array

---

# Space Complexity

```txt
O(1000)
```

---

# C++ Solution

```cpp
class Solution {
public:

    int minimumMultiplications(vector<int>& arr,
                               int start,
                               int end) {

        // Edge Case
        if(start == end) {
            return 0;
        }

        // Distance array
        vector<int> steps(1000, 1e9);

        queue<int> q;

        steps[start] = 0;
        q.push(start);

        while(!q.empty()) {

            int curr = q.front();
            q.pop();

            // Try every multiplication
            for(int &val : arr) {

                int next = (curr * val) % 1000;

                // Better path found
                if(steps[curr] + 1 < steps[next]) {

                    steps[next] = steps[curr] + 1;

                    // Reached destination
                    if(next == end) {
                        return steps[next];
                    }

                    q.push(next);
                }
            }
        }

        return -1;
    }
};
```

---

# Dry Run

## Input

```txt
arr[] = [2, 5, 7]
start = 3
end = 30
```

---

## BFS Traversal

### Initial State

```txt
Queue = [3]
steps[3] = 0
```

---

### Process 3

```txt
3 * 2 = 6
3 * 5 = 15
3 * 7 = 21
```

Queue:

```txt
[6, 15, 21]
```

---

### Process 6

```txt
6 * 5 = 30
```

Destination reached.

Answer = `2`

---

# Important Notes

* BFS guarantees minimum steps because every edge has equal weight.
* Modulo `1000` limits total states.
* Similar to shortest path in an unweighted graph.

---

# Topics Used

* Graph
* BFS
* Shortest Path
* Queue
* Modular Arithmetic

```
```
