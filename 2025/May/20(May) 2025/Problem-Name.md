# Burning Tree

## Problem Statement

Given a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

### Note
- The tree contains unique values.

## Input
- `root[]`: The binary tree represented as a list or constructed using a Node structure.
- `target`: The node value where the fire starts.

## Output
- Return the **minimum number of seconds** required to burn the entire tree.

## Constraints
- `1 <= number of nodes <= 10^5`
- `1 <= node->data <= 10^5`

## Node Structure
```cpp
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
```

## Examples

### Example 1:
```text
Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2
Output: 3
Explanation:
Time 0: Node 2 is burning
Time 1: Nodes 1, 4, 5 catch fire
Time 2: Node 3 catches fire
Time 3: Nodes 6, 7 catch fire
```

### Example 2:
```text
Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10
Output: 5
Explanation:
Time 0: Node 10 is burning
Time 1: Node 5 catches fire
Time 2: Node 2 catches fire
Time 3: Nodes 1 and 4 catch fire
Time 4: Nodes 3 and 8 catch fire
Time 5: Node 7 catches fire
```

## Solution Outline
1. **Map Each Node to Its Parent**: Use BFS to traverse the tree and create a parent pointer map.
2. **Find the Target Node**.
3. **Simulate Fire Spread Using BFS** from the target node, marking nodes as visited to avoid cycles.
4. **Count Time** as each level of BFS represents a second.

## Time and Space Complexity
- **Time Complexity**: `O(N)` — Each node is visited once.
- **Space Complexity**: `O(N)` — For the parent map, visited map, and queues.

## C++ Function Signature
```cpp
class Solution {
  public:
    int minTime(Node* root, int target);
};
