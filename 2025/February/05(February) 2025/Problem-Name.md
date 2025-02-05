# Mirror Tree

This repository contains a function to convert a binary tree into its mirror tree.

## Code Implementation

```cpp
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == nullptr) {
            return;
        }
        
        // Swap left and right child
        swap(node->left, node->right);
        
        // Recursively call mirror on left and right subtree
        mirror(node->left);
        mirror(node->right);
    }
};
```

## Prerequisites

Ensure you have the following installed:
- C++ Compiler (e.g., GCC, Clang, MSVC)
- Git (for cloning the repository)

## Contributing

We welcome contributions! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit (`git commit -m "Your message"`).
4. Push to your branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is open-source and available under the MIT License.

