🔍 Word Search (DFS + Backtracking)

📘 Problem Statement

You are given a 2D matrix mat of size n × m containing English alphabets and a string word.

Your task is to check whether the given word exists in the matrix or not.

✅ Rules

The word can be constructed using letters from adjacent cells only.

Adjacent means horizontal or vertical (not diagonal).

One cell can be used only once while forming the word.



---

🧪 Examples

Example 1

Input:

mat = [
  ['T','E','E'],
  ['S','G','K'],
  ['T','E','L']
]
word = "GEEK"

Output: true


---

Example 2

Input:

mat = [
  ['T','E','U'],
  ['S','G','K'],
  ['T','E','L']
]
word = "GEEK"

Output: false


---

Example 3

Input:

mat = [
  ['A','B','A'],
  ['B','A','B']
]
word = "AB"

Output: true


---

💡 Approach (Simple Language)

1. Traverse every cell of the matrix.


2. If the character matches the first letter of the word, start DFS from there.


3. Move in 4 directions: up, down, left, right.


4. Mark the cell as visited so it is not reused.


5. If all characters are matched → return true.


6. If no path matches → return false.



This technique is called Backtracking.


---

⏱️ Expected Complexity

Time Complexity: O(n × m × 4^L) where L is word length

Space Complexity: O(L) (recursion stack)



---

🧠 Key Notes

Word length ≤ 15

Grid size ≤ 6 × 6

Case-sensitive (uppercase ≠ lowercase)



---

🧩 Pseudocode

for each cell in grid:
    if cell == word[0]:
        if dfs(cell, index=0): return true
return false


---

🚀 Interview Tip

This problem is a classic DFS + Backtracking question. If you master this, similar problems become easy.


---

✨ End of Notes
