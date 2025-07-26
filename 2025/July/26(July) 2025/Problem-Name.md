## Majority Element - More Than n/3

**Difficulty:** Medium  
**Accuracy:** 48.1%  
**Submissions:** 181K+  
**Points:** 4  
**Average Time:** 15m

---

### **Problem Statement**

Given an array `arr[]` consisting of `n` integers, the task is to find all the array elements which occur more than `floor(n/3)` times.

> **Note:** The returned array of majority elements should be **sorted**.

---

### **Examples**

**Input:** `arr[] = [2, 2, 3, 1, 3, 2, 1, 1]`  
**Output:** `[1, 2]`  
**Explanation:** The frequency of 1 and 2 is 3, which is more than `floor(n/3)` (8/3 = 2).

**Input:** `arr[] = [-5, 3, -5]`  
**Output:** `[-5]`  
**Explanation:** The frequency of -5 is 2, which is more than `floor(n/3)` (3/3 = 1).

**Input:** `arr[] = [3, 2, 2, 4, 1, 4]`  
**Output:** `[]`  
**Explanation:** There is no majority element.

---

### **Constraints**
- `1 ≤ arr.size() ≤ 10^6`  
- `-10^5 ≤ arr[i] ≤ 10^5`

---

### **Optimized Solution Using Extended Boyer-Moore Voting Algorithm**

```cpp
class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int num1 = 0, num2 = 1;  // Initialize to different values
        int count1 = 0, count2 = 0;

        // First pass to find potential candidates
        for (int num : arr) {
            if (num == num1)
                count1++;
            else if (num == num2)
                count2++;
            else if (count1 == 0) {
                num1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                num2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Second pass to confirm the candidates
        count1 = count2 = 0;
        for (int num : arr) {
            if (num == num1) count1++;
            else if (num == num2) count2++;
        }

        vector<int> result;
        if (count1 > n / 3) result.push_back(num1);
        if (count2 > n / 3) result.push_back(num2);

        sort(result.begin(), result.end());
        return result;
    }
};
```

---

### **Time and Space Complexity**
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

### **Follow-Up**
Would you like to solve this using a hash map for better clarity but more space?
