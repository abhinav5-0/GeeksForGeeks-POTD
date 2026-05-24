# Last Coin in a Game of Alternates

## Problem Statement

Given an array `arr[]` representing the values of coins arranged in a row.

Two players play a game by picking coins alternately under the following rules:

- A player can pick a coin only from either end of the array.
- Both players always follow a greedy strategy.
- They always choose the larger-valued coin between the two available ends.
- The game continues until only one coin remains.

Your task is to find the value of the last remaining coin.

---

## Examples

### Example 1

**Input:**
```text
arr[] = [5, 3, 1, 6, 9]
```

**Output:**
```text
1
```

### Explanation

Step-by-step process:

- Compare `5` and `9` → pick `9`
  Remaining: `[5, 3, 1, 6]`

- Compare `5` and `6` → pick `6`
  Remaining: `[5, 3, 1]`

- Compare `5` and `1` → pick `5`
  Remaining: `[3, 1]`

- Compare `3` and `1` → pick `3`
  Remaining: `[1]`

Final remaining coin = `1`

---

### Example 2

**Input:**
```text
arr[] = [5, 9, 2, 5]
```

**Output:**
```text
2
```

### Explanation

- Compare `5` and `5` → pick left `5`
  Remaining: `[9, 2, 5]`

- Compare `9` and `5` → pick `9`
  Remaining: `[2, 5]`

- Compare `2` and `5` → pick `5`
  Remaining: `[2]`

Final remaining coin = `2`

---

### Example 3

**Input:**
```text
arr[] = [11]
```

**Output:**
```text
11
```

### Explanation

Only one coin exists, so it remains unchanged.

---

## Constraints

```text
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^6
```

---

# Approach

We use the **Two Pointer Technique**.

## Idea

- Initialize:
  - `left = 0`
  - `right = n - 1`

- While more than one coin exists:
  - Compare `arr[left]` and `arr[right]`
  - Remove the larger one
  - Move the corresponding pointer

- When `left == right`, only one coin remains.

---

# Time Complexity

```text
O(n)
```

Each move removes one coin.

---

# Space Complexity

```text
O(1)
```

Only pointers are used.

---

# Java Solution

```java
class Solution {
    public int coin(int[] arr) {

        int left = 0;
        int right = arr.length - 1;

        // Continue until one coin remains
        while (left < right) {

            if (arr[left] >= arr[right]) {
                left++;   // Remove left coin
            } else {
                right--;  // Remove right coin
            }
        }

        // Last remaining coin
        return arr[left];
    }
}
```

---

# Dry Run

## Input

```text
arr[] = [5, 3, 1, 6, 9]
```

| Left Value | Right Value | Removed | Remaining Array |
|------------|-------------|----------|------------------|
| 5 | 9 | 9 | [5, 3, 1, 6] |
| 5 | 6 | 6 | [5, 3, 1] |
| 5 | 1 | 5 | [3, 1] |
| 3 | 1 | 3 | [1] |

Final Answer = `1`

---

# Key Observation

At every step:

- Larger end coin is removed.
- Smaller coin survives longer.
- Simulation with two pointers is sufficient.
