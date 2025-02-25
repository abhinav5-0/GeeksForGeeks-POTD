# Largest Rectangular Area in a Histogram

## Problem Statement
You are given a histogram represented by an array `arr`, where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

Your task is to find the **largest rectangular area** possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

### **Examples**
#### **Example 1**
**Input:**  
`arr[] = [60, 20, 50, 40, 10, 50, 60]`  
**Output:**  
`100`  
**Explanation:**  
We get the maximum area by picking bars **50 and 60**. The area is calculated as:
```
(Smallest height) * (Number of picked bars) = 50 * 2 = 100
```

#### **Example 2**
**Input:**  
`arr[] = [3, 5, 1, 7, 5, 9]`  
**Output:**  
`15`  
**Explanation:**  
We get the maximum area by picking bars **7, 5, and 9**:
```
(Smallest height) * (Number of picked bars) = 5 * 3 = 15
```

#### **Example 3**
**Input:**  
`arr[] = [3]`  
**Output:**  
`3`  
**Explanation:**  
In this example, the largest area would be **3** (height 3 and width 1).

### **Constraints**
- `1 ≤ arr.size() ≤ 10^5`
- `0 ≤ arr[i] ≤ 10^4`

---

## **Approach**
1. **Use a monotonic stack:**
   - Maintain a stack to keep track of histogram bar indices in **increasing order** of height.
   - If a **smaller height** is encountered, process the previous taller bars.
2. **Compute the area:**
   - The **height** is the popped element.
   - The **width** is determined using `(i - st.top() - 1)`.
   - Compute the area as `height × width` and update `maxArea`.
3. **Process remaining elements** in the stack after iteration.

---

## **C++ Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMaxArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // Monotonic increasing stack
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after test cases input

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        cout << obj.getMaxArea(arr) << endl;
        cout << "~" << endl; // Separator for multiple test cases
    }
    return 0;
}
```

---

## **Time & Space Complexity**
- **Time Complexity:** `O(n)` (Each element is pushed and popped at most once)
- **Space Complexity:** `O(n)` (Stack storage for at most `n` elements)

---

## **Example Walkthrough**
### **Input:**
```
arr[] = [60, 20, 50, 40, 10, 50, 60]
```
### **Stack Operations:**
| Index | Element | Stack | Popped Elements | Max Area Calculation |
|--------|--------|-------|----------------|----------------------|
| 0      | 60     | [0]   | -              | -                    |
| 1      | 20     | [1]   | 60             | `60 * 1 = 60`        |
| 2      | 50     | [1, 2]| -              | -                    |
| 3      | 40     | [1, 3]| 50             | `50 * 1 = 50`        |
| 4      | 10     | [4]   | 40, 20         | `40 * 2 = 80`, `20 * 4 = 80` |
| 5      | 50     | [4, 5]| -              | -                    |
| 6      | 60     | [4, 5, 6]| -           | -                    |
| End    | -      | -     | 60, 50, 10     | `60 * 1 = 60`, `50 * 2 = 100`, `10 * 7 = 70` |

**Final Max Area:** `100`

---

## **Test Cases**
#### **Input:**
```
2
60 20 50 40 10 50 60
3 5 1 7 5 9
```
#### **Output:**
```
100
~
15
~
```

---

## **Summary**
✅ **Efficient** `O(n)` approach using **monotonic stack**.  
✅ **Handles edge cases** (single element, decreasing/increasing order).  
✅ **Uses stack for optimal width calculation**.  

This is the **best solution** for finding the **largest rectangular area in a histogram**. 🚀

