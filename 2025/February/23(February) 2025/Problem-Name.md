# **🔹 Next Greater Element**  

**Difficulty:** Medium  
**Accuracy:** 32.95%  
**Points:** 4  

## **📌 Problem Statement**  
Given an array `arr[]` of integers, find the **next greater element** for each element in the array in order of their appearance.  

The **next greater element** of an element in the array is the nearest element **on the right** which is **greater** than the current element.  
If there is no next greater element, return `-1` for that position.  

---

## **📝 Examples**  

### **Example 1**  
#### **Input:**  
```cpp
arr[] = [1, 3, 2, 4]
[3, 4, 4, -1]


###💻 Code Implementation
##C++ Solution


**Explanation:**  
All elements have no greater element to their right.  

---

## Constraints  
- \( 1 \leq arr.size() \leq 10^6 \)  
- \( 0 \leq arr[i] \leq 10^9 \)  

---

## Optimized Approach (Using Stack)
**Time Complexity:** \( O(N) \)  
**Space Complexity:** \( O(N) \)  

We use a **monotonic stack** (decreasing order) to efficiently find the next greater element.

### Algorithm
1. Traverse the array **from right to left**.  
2. Use a **stack** to keep track of elements.  
3. For each element:  
   - Pop elements from the stack **until** you find a greater element.  
   - If the stack is empty, store `-1` in the result.  
   - Otherwise, the top of the stack is the next greater element.  
   - Push the current element onto the stack.  
4. Return the result.  

---

## Code Implementation  
### C++ Solution  
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }

            if (!s.empty()) {
                result[i] = s.top();
            }

            s.push(arr[i]);
        }
        return result;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;

        while (ss >> num)
            a.push_back(num);

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        for (int i = 0; i < result.size(); i++) {
            if (i != 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}

