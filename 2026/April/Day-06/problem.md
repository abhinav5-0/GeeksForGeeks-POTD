# Huffman Encoding

## 🧠 Problem Statement

Given a string `s` of distinct characters and an array of frequencies `f[]`, where each character `s[i]` has frequency `f[i]`, build a **Huffman Tree** and return all Huffman Codes in preorder traversal of the tree.

### 📌 Note

* While merging two nodes with the same value, the node which occurs first will be placed on the **left**.
* Otherwise, the node with smaller value goes to the **left**, and the larger to the **right**.

---

## 📥 Example

**Input:**

```
s = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
```

**Output:**

```
[0, 100, 101, 1100, 1101, 111]
```

---

## 📝 Explanation

The Huffman Tree is constructed by repeatedly combining the two nodes with the smallest frequencies.

Generated Huffman Codes:

```
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
```

---

## ⚙️ Approach

1. Use a **min-heap (priority queue)** to store nodes based on frequency.
2. Create a leaf node for each character and push it into the heap.
3. While there is more than one node in the heap:

   * Extract the two nodes with the smallest frequencies.
   * Create a new internal node with their sum.
   * Assign left and right children accordingly.
   * Push the new node back into the heap.
4. Traverse the constructed tree:

   * Assign `0` for left and `1` for right.
   * Store codes for all leaf nodes.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n log n)`
* **Space Complexity:** `O(n)`

---

## 💻 Function Signature (C++)

```cpp
class Solution {
public:
    vector<string> huffmanCodes(string s, vector<int> f) {
        // Code here
    }
};
```

---

## 📌 Key Points

* Huffman Encoding is a **greedy algorithm**.
* It is used for **data compression**.
* Ensures **minimum weighted path length**.

---

## 🚀 Applications

* File compression (ZIP, GZIP)
* Image formats (JPEG)
* Audio compression (MP3)

---

✍️ *Tip: Focus on priority queue + tree traversal for solving this efficiently.*
