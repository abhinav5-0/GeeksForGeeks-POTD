# K Sum Paths

## Problem Statement
Given a binary tree and an integer `k`, determine the number of downward-only paths where the sum of the node values in the path equals `k`. A path can start and end at any node within the tree but must always move downward (from parent to child).

### **Constraints**
- `1 ≤ number of nodes ≤ 10^4`
- `-100 ≤ node value ≤ 100`
- `-10^9 ≤ k ≤ 10^9`

## **Examples**
### **Example 1:**
**Input:**  
```
       1
      / \
     2   3
k = 3
```
**Output:** `2`

**Explanation:**
- Path 1: `1 -> 2` (Sum = 3)
- Path 2: `3` (Sum = 3)

---

### **Example 2:**
**Input:**  
```
       1
      / \
     2   3
    /   / \
   1   1   2
k = 4
```
**Output:** `3`

**Explanation:**
- Path 1: `1 -> 2 -> 1` (Sum = 4)
- Path 2: `3 -> 1` (Sum = 4)
- Path 3: `2 -> 2` (Sum = 4)

---

## **Approach**
The solution uses **prefix sum and a hashmap** to efficiently find all downward paths with sum equal to `k`.

### **Steps:**
1. Use a **hashmap** (`unordered_map<int, int>`) to store prefix sums and their frequencies.
2. Perform **DFS traversal** to maintain the running sum.
3. Check if `(current_sum - k)` exists in the hashmap (indicating a valid path sum).
4. If `current_sum == k`, count it as a valid path.
5. Recur for left and right subtrees.
6. **Backtrack** by removing the current sum from the hashmap after returning from recursion.

---

## **C++ Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) { data = val; left = right = NULL; }
};

class Solution {
  public:
    int countPaths(Node* root, int k, unordered_map<int, int>& prefixSum, int currSum) {
        if (!root) return 0;

        currSum += root->data;
        int count = 0;

        if (prefixSum.find(currSum - k) != prefixSum.end())
            count += prefixSum[currSum - k];
        
        if (currSum == k) count++;

        prefixSum[currSum]++;
        count += countPaths(root->left, k, prefixSum, currSum);
        count += countPaths(root->right, k, prefixSum, currSum);
        prefixSum[currSum]--; // Backtrack

        return count;
    }

    int sumK(Node* root, int k) {
        unordered_map<int, int> prefixSum;
        return countPaths(root, k, prefixSum, 0);
    }
};
```

---

## **Time Complexity:**
- **O(N)**: Each node is visited once.
- **O(N) Space (Auxiliary HashMap)**: Stores at most `N` unique prefix sums.

---

## **Why This Approach?**
- **Optimized:** Avoids recomputation compared to naive DFS (`O(N^2)`).
- **Efficient Backtracking:** Uses a prefix sum approach to maintain minimal space usage.
- **Handles Large Inputs:** Works efficiently for trees with up to `10^4` nodes.

---

## **GitHub Repository Instructions**
To add this to your Git repository:
```sh
git add K_Sum_Paths.md
git commit -m "Added solution for K Sum Paths problem"
git push origin main
```

