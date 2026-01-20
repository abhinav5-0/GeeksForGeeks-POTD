# Implement UNDO & REDO

## Problem Statement

You are given a text document that is initially empty. You need to support **UNDO** and **REDO** functionality for append operations.

The following operations must be implemented:

* `append(char x)` → Append character `x` at the end of the document
* `undo()` → Undo the most recent append operation
* `redo()` → Redo the most recently undone append operation
* `read()` → Return the current content of the document

The queries are given in numeric form:

| Query | Meaning              |
| ----- | -------------------- |
| `1 x` | Append character `x` |
| `2`   | Undo                 |
| `3`   | Redo                 |
| `4`   | Read                 |

The driver code will execute these operations and print the output of every `read()` call.

---

## Key Observations

* Only **append** operations modify the document.
* `undo()` removes the **last appended character**.
* `redo()` restores the **last undone character**.
* If a new append is done after undo, **redo history must be cleared**.

---

## Approach (Using Two Stacks)

We use **two stacks**:

1. **mainStack** → stores the current document characters
2. **redoStack** → stores characters removed by undo (for redo operation)

### Operation Handling

#### append(x)

* Push `x` into `mainStack`
* Clear `redoStack` (redo history becomes invalid)

#### undo()

* If `mainStack` is not empty:

  * Pop the top character
  * Push it into `redoStack`

#### redo()

* If `redoStack` is not empty:

  * Pop the top character
  * Push it back into `mainStack`

#### read()

* Convert `mainStack` into a string and return it

---

## Example Walkthrough

### Input

```
[ [1 'A'], [1 'B'], [1 'C'], [2], [4], [3], [4] ]
```

### Execution

| Step | Operation | Document |
| ---- | --------- | -------- |
| 1    | Append A  | A        |
| 2    | Append B  | AB       |
| 3    | Append C  | ABC      |
| 4    | Undo      | AB       |
| 5    | Read      | AB       |
| 6    | Redo      | ABC      |
| 7    | Read      | ABC      |

### Output

```
["AB", "ABC"]
```

---

## Time & Space Complexity

* **Time Complexity:** `O(1)` per operation
* **Space Complexity:** `O(q)` for storing characters

---

## Notes

* Multiple undo operations can be done consecutively
* Redo works only if no new append occurs after undo
* Reading an empty document returns an empty string

---

This approach is efficient, simple, and perfectly matches the behavior of real-world text editors.
