# Binary Tree Serialization and Deserialization

## Overview
This project provides an implementation for **serializing and deserializing a binary tree** in C++. The serialization converts a binary tree into a list representation, and deserialization reconstructs the tree from that list.

## Features
- Uses **level-order traversal (BFS)** for serialization.
- Efficient **queue-based reconstruction** for deserialization.
- Handles large trees up to **10⁴ nodes**.
- Supports trees with multiple NULL nodes.
- Preserves the structure of the original tree.
## Code
```cpp
class Solution {
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node) {
                result.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            } else {
                result.push_back(-1); // Representing NULL node
            }
        }
        return result;
    }

    // Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int> &arr) {
        if (arr.empty()) return NULL;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size()) {
            Node* curr = q.front();
            q.pop();

            if (arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;

            if (i < arr.size() && arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};
```

## Usage
### Serialization
The `serialize` function converts the tree into a list representation.
```cpp
vector<int> serialize(Node *root);
```
### Deserialization
The `deSerialize` function reconstructs the tree from the list.
```cpp
Node* deSerialize(vector<int> &arr);
```

## Example
### Input Tree
```
        10
       /  \
      20   30
     /  \
    40   60
```
### Serialized Output
```cpp
[10, 20, 30, 40, 60, -1, -1, -1, -1, -1, -1]
```
### Inorder Traversal After Deserialization
```cpp
40 20 60 10 30
```

## Contributing
Feel free to fork the repository and submit pull requests for improvements.


---
**Author:** Abhinav Kumar
**GitHub:** https://github.com/abhinav5-0

