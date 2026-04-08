# Segregate 0s and 1s

## 🧩 Problem Statement

Given an array `arr[]` consisting only of `0`s and `1`s. Modify the array **in-place** to segregate `0`s onto the left side and `1`s onto the right side of the array.

---

## 📥 Examples

### Example 1

```
Input:  arr[] = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
```

**Explanation:**
After segregation, all the `0`s are on the left and `1`s are on the right.

---

### Example 2

```
Input:  arr[] = [1, 1]
Output: [1, 1]
```

**Explanation:**
There are no `0`s in the array.

---

## 📌 Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `0 ≤ arr[i] ≤ 1`

---

## 💡 Approach (Two-Pointer Method)

* Use two pointers:

  * `left` starting from the beginning
  * `right` starting from the end
* If `arr[left] == 0`, move `left++`
* If `arr[right] == 1`, move `right--`
* If `arr[left] == 1` and `arr[right] == 0`, swap them

### ⏱️ Time Complexity

* `O(n)`

### 🧠 Space Complexity

* `O(1)` (in-place)

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            if (arr[left] == 0) {
                left++;
            } else if (arr[right] == 1) {
                right--;
            } else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};
```

---

## ☕ Java Solution

```java
class Solution {
    void segregate0and1(int[] arr) {
        int left = 0, right = arr.length - 1;

        while (left < right) {
            if (arr[left] == 0) {
                left++;
            } else if (arr[right] == 1) {
                right--;
            } else {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
    }
}
```

---

## 🐍 Python Solution

```python
class Solution:
    def segregate0and1(self, arr):
        left, right = 0, len(arr) - 1

        while left < right:
            if arr[left] == 0:
                left += 1
            elif arr[right] == 1:
                right -= 1
            else:
                arr[left], arr[right] = arr[right], arr[left]
                left += 1
                right -= 1
```

---

## 🚀 Key Takeaways

* Efficient in-place solution using two pointers
* No extra memory required
* Works in linear time
# Segregate 0s and 1s

## 🧩 Problem Statement

Given an array `arr[]` consisting only of `0`s and `1`s. Modify the array **in-place** to segregate `0`s onto the left side and `1`s onto the right side of the array.

---

## 📥 Examples

### Example 1

```
Input:  arr[] = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
```

**Explanation:**
After segregation, all the `0`s are on the left and `1`s are on the right.

---

### Example 2

```
Input:  arr[] = [1, 1]
Output: [1, 1]
```

**Explanation:**
There are no `0`s in the array.

---

## 📌 Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `0 ≤ arr[i] ≤ 1`

---

## 💡 Approach (Two-Pointer Method)

* Use two pointers:

  * `left` starting from the beginning
  * `right` starting from the end
* If `arr[left] == 0`, move `left++`
* If `arr[right] == 1`, move `right--`
* If `arr[left] == 1` and `arr[right] == 0`, swap them

### ⏱️ Time Complexity

* `O(n)`

### 🧠 Space Complexity

* `O(1)` (in-place)

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            if (arr[left] == 0) {
                left++;
            } else if (arr[right] == 1) {
                right--;
            } else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};
```

---

## ☕ Java Solution

```java
class Solution {
    void segregate0and1(int[] arr) {
        int left = 0, right = arr.length - 1;

        while (left < right) {
            if (arr[left] == 0) {
                left++;
            } else if (arr[right] == 1) {
                right--;
            } else {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
    }
}
```

---

## 🐍 Python Solution

```python
class Solution:
    def segregate0and1(self, arr):
        left, right = 0, len(arr) - 1

        while left < right:
            if arr[left] == 0:
                left += 1
            elif arr[right] == 1:
                right -= 1
            else:
                arr[left], arr[right] = arr[right], arr[left]
                left += 1
                right -= 1
```

---

## 🚀 Key Takeaways

* Efficient in-place solution using two pointers
* No extra memory required
* Works in linear time
