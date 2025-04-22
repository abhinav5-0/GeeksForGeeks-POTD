# Problem: Unique Number I

**Difficulty:** Easy  
**Accuracy:** 71.38%  
**Submissions:** 7K+  
**Points:** 2

## Problem Statement
Given an unsorted array `arr[]` of positive integers where all numbers occur exactly twice, except for one number which occurs only once. Find and return the number that occurs only once.

### Examples
**Input:**
```
arr[] = [1, 2, 1, 5, 5]
```
**Output:**
```
2
```
**Explanation:** 2 occurs once, all others occur twice.

**Input:**
```
arr[] = [2, 30, 2, 15, 20, 30, 15]
```
**Output:**
```
20
```
**Explanation:** 20 occurs once, all others occur twice.

## Constraints
- 1 ≤ arr.size() ≤ 10⁶
- 0 ≤ arr[i] ≤ 10⁹

## Efficient Approach
Use XOR to find the unique number:
- XOR of a number with itself is 0 (a ^ a = 0)
- XOR of a number with 0 is the number itself (a ^ 0 = a)
- XOR is commutative and associative

### Time Complexity
- **O(n)**

### Space Complexity
- **O(1)**

## C++ Code
```cpp
class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num;
        }
        return result;
    }
};
```

## Driver Code
```cpp
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.findUnique(arr);
        cout << ans << endl;
    }
    return 0;
}
```

