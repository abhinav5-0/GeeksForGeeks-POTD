# Police and Thieves (Greedy)

## Problem Summary

You are given an array `arr[]` consisting of:

* `'P'` → Policeman
* `'T'` → Thief

Each policeman can catch **at most one thief**, and only if the distance between them is **≤ k**.

Your task is to find the **maximum number of thieves** that can be caught.

---

## Key Idea (Greedy + Two Pointers)

1. Store **indices of policemen** in one list.
2. Store **indices of thieves** in another list.
3. Use **two pointers** to match the nearest possible policeman and thief.

### Why Greedy Works?

* To maximize catches, always match the **closest valid policeman–thief pair**.
* If distance is too large, move the pointer that helps reduce the distance.

---

## Algorithm Steps

1. Traverse the array and record positions of `'P'` and `'T'`.
2. Initialize two pointers `i` (policemen) and `j` (thieves).
3. While both lists have elements:

   * If `|police[i] - thief[j]| ≤ k` → catch thief, increment count and both pointers.
   * Else if `police[i] < thief[j]` → move policeman pointer.
   * Else → move thief pointer.

---

## Time & Space Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

---

## C++ Solution

```cpp
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> police, thief;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') police.push_back(i);
            else thief.push_back(i);
        }
        
        int i = 0, j = 0, count = 0;
        
        while (i < police.size() && j < thief.size()) {
            if (abs(police[i] - thief[j]) <= k) {
                count++;
                i++;
                j++;
            }
            else if (police[i] < thief[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        
        return count;
    }
};
```

---

## Java Solution

```java
class Solution {
    public int catchThieves(char[] arr, int k) {
        ArrayList<Integer> police = new ArrayList<>();
        ArrayList<Integer> thief = new ArrayList<>();
        
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 'P') police.add(i);
            else thief.add(i);
        }
        
        int i = 0, j = 0, count = 0;
        
        while (i < police.size() && j < thief.size()) {
            if (Math.abs(police.get(i) - thief.get(j)) <= k) {
                count++;
                i++;
                j++;
            }
            else if (police.get(i) < thief.get(j)) i++;
            else j++;
        }
        
        return count;
    }
}
```

---

## Python Solution

```python
def catchThieves(arr, k):
    police = []
    thief = []

    for i in range(len(arr)):
        if arr[i] == 'P':
            police.append(i)
        else:
            thief.append(i)

    i = j = count = 0

    while i < len(police) and j < len(thief):
        if abs(police[i] - thief[j]) <= k:
            count += 1
            i += 1
            j += 1
        elif police[i] < thief[j]:
            i += 1
        else:
            j += 1

    return count
```

---

## Example Walkthrough

**Input:** `['P','T','T','P','T'], k = 1`

* Policemen → `[0, 3]`
* Thieves → `[1, 2, 4]`

Matches:

* P(0) ↔ T(1)
* P(3) ↔ T(2)

**Output:** `2`

---

### ✅ This greedy approach is optimal and passes all constraints.
