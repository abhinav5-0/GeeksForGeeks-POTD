# Game of XOR

## Difficulty

Medium

## Accuracy

50.77%

## Points

4

---

## **Problem Statement**

You are given an integer array `arr[]`. The value of a subarray is defined as the **bitwise XOR** of all elements in that subarray.

Your task is to compute the **bitwise XOR of the values of all possible subarrays** of `arr[]`.

---

## **Examples**

### **Example 1**

**Input:** `arr = [1, 2, 3]`

All subarray XORs:

* xor[1] = 1
* xor[1, 2] = 3
* xor[2, 3] = 1
* xor[1, 2, 3] = 0
* xor[2] = 2
* xor[3] = 3

**Result:** `1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2`

**Output:** `2`

---

### **Example 2**

**Input:** `arr = [1, 2]`

All subarray XORs:

* xor[1] = 1
* xor[1, 2] = 3
* xor[2] = 2

**Result:** `1 ^ 3 ^ 2 = 0`

**Output:** `0`

---

## **Constraints**

* `1 ≤ arr.size() ≤ 10^5`
* `0 ≤ arr[i] ≤ 10^9`

---

## **Intuition & Key Insight**

Each element `arr[i]` appears in multiple subarrays.
The number of subarrays that include index `i` is:

```
(i + 1) * (n - i)
```

### **Important XOR Property**

* If an element appears **even** number of times → it gets cancelled out.
* If an element appears **odd** number of times → it contributes to final XOR.

So we only XOR elements whose frequency of appearance is **odd**.

---

## **Algorithm**

1. Let `n` be the length of the array.
2. For each index `i`:

   * Compute `freq = (i + 1) * (n - i)`.
   * If `freq` is odd → include `arr[i]` in final XOR.
3. Return the final XOR.

---

## **Time Complexity**

* **O(n)**

## **Space Complexity**

* **O(1)**

---

## **C++ Solution**

```cpp
class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long freq = (long long)(i + 1) * (n - i);

            if(freq % 2 == 1)
                ans ^= arr[i];
        }
        return ans;
    }
};
```
