# 🧩 Sort 0s, 1s and 2s

**Difficulty:** Medium  
**Accuracy:** 50.58%  
**Points:** 4  

---

## 📄 Problem Statement

Given an array `arr[]` containing only **0s, 1s, and 2s**, sort the array in ascending order.

🔒 **Note:** You are not allowed to use the built-in sort function.

---

## 💡 Approach / Explanation

We use the **Dutch National Flag Algorithm**, which sorts the array in **one pass** using **constant extra space**.

### Key Idea:
- Maintain three regions:
  - Left → all 0s
  - Middle → all 1s
  - Right → all 2s
- Use three pointers: `low`, `mid`, and `high`

---

## ⚙️ Algorithm Steps

1. Initialize `low = 0`, `mid = 0`, `high = n - 1`
2. While `mid <= high`:
   - If `arr[mid] == 0` → swap with `arr[low]`, increment both
   - If `arr[mid] == 1` → increment `mid`
   - If `arr[mid] == 2` → swap with `arr[high]`, decrement `high`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## 🧠 Key Takeaways

- Classic array + pointer problem
- Dutch National Flag algorithm is optimal
- Frequently asked in interviews

---

## 🔗 Reference
- GeeksforGeeks Problem of the Day

---

⭐ *If this explanation helped you, consider starring the repository!*
