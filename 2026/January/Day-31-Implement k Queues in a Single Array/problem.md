# Implement K Queues in a Single Array

**Difficulty:** Hard
**Accuracy:** 70.86%
**Points:** 8

---

## Problem Statement

You are given two integers **n** and **k**. Your task is to implement a class **kQueues** that uses a **single array of size n** to simulate **k independent queues**.

---

## Operations to Support

The class should support the following operations:

* **enqueue(x, i)**
  Adds the element `x` into the `i`-th queue.

* **dequeue(i)**
  Removes and returns the front element from the `i`-th queue.
  Returns **-1** if the queue is empty.

* **isEmpty(i)**
  Returns **true** if the `i`-th queue is empty, otherwise **false**.

* **isFull()**
  Returns **true** if the array is completely full and no more elements can be inserted, otherwise **false**.

---

## Query Format

Each query is represented as:

* `1 x i` → enqueue(x, i)
* `2 i` → dequeue(i)
* `3 i` → isEmpty(i)
* `4` → isFull()

The driver code will process these queries and print the results of `dequeue`, `isEmpty`, and `isFull` operations.

---

## Example 1

**Input:**

```
n = 4, k = 2, q = 8
queries = [[1, 5, 0], [1, 3, 0], [1, 1, 1], [2, 0], [1, 4, 1], [1, 1, 0], [3, 1], [4]]
```

**Output:**

```
[5, false, true]
```

**Explanation:**

* enqueue(5, 0) → queue0 = [5]
* enqueue(3, 0) → queue0 = [5, 3]
* enqueue(1, 1) → queue1 = [1]
* dequeue(0) → returns 5, queue0 = [3]
* enqueue(4, 1) → queue1 = [1, 4]
* enqueue(1, 0) → queue0 = [3, 1]
* isEmpty(1) → false
* isFull() → true

---

## Example 2

**Input:**

```
n = 6, k = 3, q = 4
queries = [[1, 3, 2], [2, 0], [1, 2, 1], [3, 2]]
```

**Output:**

```
[-1, false]
```

**Explanation:**

* enqueue(3, 2) → queue2 = [3]
* dequeue(0) → queue0 empty → returns -1
* enqueue(2, 1) → queue1 = [2]
* isEmpty(2) → false

---

## Constraints

* 1 ≤ q ≤ 10⁵
* 1 ≤ k ≤ n ≤ 10⁵
* 0 ≤ values on the queues ≤ 10⁹

---

## Key Idea (Conceptual)

* Use **one main array** of size `n` to store all elements
* Maintain:

  * `front[k]` → front index of each queue
  * `rear[k]` → rear index of each queue
  * `next[n]` → next index (for linking elements & free list)
  * `freeSpot` → start of free indices list

This allows all operations to work in **O(1)** time.

---

> ⚠️ Note: Only the logic of these four functions is required. Driver code is already provided in the platform.
