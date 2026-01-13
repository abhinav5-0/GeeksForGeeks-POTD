# Bus Ticket Change

## Problem Statement

You are given an array `arr[]` representing passengers in a queue. Each bus ticket costs **5 coins**.

* `arr[i]` can be **5, 10, or 20**, representing the note used by the i-th passenger.
* You must serve passengers **in order**.
* You must always give **correct change** so that each passenger effectively pays exactly **5 coins**.

Your task is to determine whether it is possible to serve **all passengers** without ever running out of change.

---

## Key Idea (Greedy)

* Keep track of how many **5-coin** and **10-coin** notes you have.
* A **20-coin** note needs **15 coins** change → prefer giving **10 + 5** if possible (better for future).

### Rules

* If passenger pays **5** → just collect it.
* If passenger pays **10** → must give **one 5** as change.
* If passenger pays **20** →

  * Prefer **one 10 + one 5**
  * Else give **three 5s**
  * If neither possible → return `false`

This greedy strategy always works because smaller notes are more flexible.

---

## Algorithm

1. Initialize `five = 0`, `ten = 0`
2. Traverse the array:

   * If `5` → `five++`
   * If `10` → need `five >= 1`
   * If `20` → need `(ten >= 1 && five >= 1)` OR `(five >= 3)`
3. If at any step change is not possible → return `false`
4. If all passengers are served → return `true`

---

## Time & Space Complexity

* **Time:** O(n)
* **Space:** O(1)

---

## C++ Solution

```cpp
class Solution {
public:
    bool canServe(vector<int> &arr) {
        int five = 0, ten = 0;

        for (int bill : arr) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
```

---

## Example Walkthrough

**Input:** `[5, 5, 5, 10, 20]`

* Collect three `5`s
* `10` → give one `5`
* `20` → give `10 + 5`

✔ All passengers served → `true`

---

## Final Note

This is a **classic greedy + simulation problem**. Focus on managing change carefully, especially for `20` notes.

Happy Coding 🚍💰
