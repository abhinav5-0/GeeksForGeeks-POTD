# AND In Range

## Difficulty

Medium

## Accuracy

50.0%

## Points

4

---

## **Problem Statement**

You are given two integers `l` and `r`. Your task is to compute the result of performing **bitwise AND** (`&`) on every number from `l` to `r` (inclusive).

Formally:

```
l & (l+1) & (l+2) & ... & r
```

---

## **Examples**

### **Example 1**

**Input:** `l = 8`, `r = 13`

Binary:

```
8  = 1000
9  = 1001
10 = 1010
11 = 1011
12 = 1100
13 = 1101
```

All ANDed:

```
8 & 9 & 10 & 11 & 12 & 13 = 8
```

**Output:** `8`

---

### **Example 2**

**Input:** `l = 2`, `r = 3`

```
2 = 10
3 = 11
```

```
2 & 3 = 2
```

**Output:** `2`

---

## **Constraints**

* `1 ≤ l ≤ r ≤ 10^9`

---

## **Intuition**

The AND of a range of numbers keeps only the bits that **never change** across all numbers.

Whenever a bit flips from **1 → 0** or **0 → 1** in the range, that bit becomes **0** in the final AND.

Thus, the AND of the entire range equals the **common left prefix** of `l` and `r`.

---

## **Key Logic**

Keep right-shifting both `l` and `r` until they become equal. The number of shifts gives how many bits differ.

Then left-shift the result back to restore the prefix.

---

## **Algorithm**

1. Initialize `shift = 0`.
2. While `l != r`:

   * Right-shift both.
   * Increment `shift`.
3. Left-shift `l` by `shift` to reconstruct the final AND.
4. Return result.

---

## **Time Complexity**

* **O(log(max(l, r)))**

## **Space Complexity**

* **O(1)**

---

## **C++ Solution**

```cpp
class Solution {
  public:
    int andInRange(int l, int r) {
        int shift = 0;

        // Keep shifting until l and r become equal
        while(l != r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }

        // Shift back to restore the common prefix
        return l << shift;
    }
};
```
