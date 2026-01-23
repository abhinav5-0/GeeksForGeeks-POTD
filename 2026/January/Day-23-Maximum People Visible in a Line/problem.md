## Maximum People Visible in a Line

### Problem Statement

You are given an array `arr[]` where `arr[i]` represents the height of the `i-th` person standing in a line.

A person `i` can see another person `j` **if and only if**:

1. `height[j] < height[i]`
2. There is **no person `k` between `i` and `j`** such that `height[k] ≥ height[i]`

Each person can see in **both directions** (left and right).

Your task is to find the **maximum number of people** that **any one person can see**, **including themselves**.

---

### Key Observation

For a given person:

* They can see **continuous shorter people** on the left **until a person of equal or greater height blocks the view**.
* Same logic applies on the right.

This can be efficiently solved using a **Monotonic Stack** technique.

---

### Approach (Using Stack)

For every person `i`:

1. Count how many people they can see on the **left**
2. Count how many people they can see on the **right**
3. Add `1` to include the person themselves

We do this in **O(N)** time using stacks.

---

### Algorithm

#### Step 1: Count visible people on the left

* Traverse from left to right
* Maintain a stack of decreasing heights
* Pop all shorter people (they are visible)
* Stop when a taller or equal height person is found

#### Step 2: Count visible people on the right

* Traverse from right to left
* Apply the same logic

#### Step 3: Calculate maximum visibility

* For each index `i`:

```
visible = left[i] + right[i] + 1
```

---

### C++ Implementation

```cpp
class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> st;

        // Count visible people on the left
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                left[i]++;
                st.pop();
            }
            if(!st.empty()) left[i]++;  // blocked by taller/equal person
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Count visible people on the right
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                right[i]++;
                st.pop();
            }
            if(!st.empty()) right[i]++;
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, left[i] + right[i] + 1);
        }

        return ans;
    }
};
```

---

### Example Walkthrough

**Input:**

```
arr = [6, 2, 5, 4, 5, 1, 6]
```

* Person with height `6` at index `0` can see 5 others + himself → **6**
* Person with height `6` at index `6` can also see **6**

**Output:**

```
6
```

---

### Complexity Analysis

* **Time Complexity:** `O(N)`
* **Space Complexity:** `O(N)` (stack + arrays)

---

### Summary

✔ Uses Monotonic Stack
✔ Efficient for large inputs
✔ Clean and intuitive logic

Perfect problem to practice **stack-based visibility problems** 🚀
