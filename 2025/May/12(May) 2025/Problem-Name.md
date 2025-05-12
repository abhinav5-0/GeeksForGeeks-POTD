## Problem: Meeting Rooms III

**Difficulty:** Hard
**Accuracy:** 59.33%
**Submissions:** 11K+
**Points:** 8

### Problem Statement

You are given an integer `n` representing the number of rooms numbered from `0` to `n - 1`. Additionally, you are given a 2D integer array `meetings[][]` where `meetings[i] = [starti, endi]` indicates that a meeting is scheduled during the half-closed time interval `[starti, endi)`. All `starti` values are unique.

### Meeting Allocation Rules:

1. When a meeting starts, assign it to the available room with the **smallest number**.
2. If **no rooms are free**, delay the meeting until the **earliest room becomes available**. The delayed meeting retains its original duration.
3. When a room becomes free, assign it to the **delayed meeting with the earliest original start time**.

### Goal:

Determine the **room number that hosts the most meetings**. If multiple rooms have the same highest number of meetings, return the **smallest room number among them**.

### Examples

#### Example 1:

**Input:**

```
n = 2
meetings = [[0, 6], [2, 3], [3, 7], [4, 8], [6, 8]]
```

**Output:**

```
1
```

**Explanation:**

* Time 0: \[0,6] starts in room 0.
* Time 2: Room 1 is available. \[2,3] starts in room 1.
* Time 3: \[3,7] starts in room 1.
* Time 4: \[4,8] delayed.
* Time 6: Room 0 free. \[4,8] starts at 6 in room 0.
* Time 6: \[6,8] delayed.
* Time 7: Room 1 free. \[6,8] starts at 7 in room 1.
* Meeting counts: \[2, 3]

#### Example 2:

**Input:**

```
n = 4
meetings = [[0, 8], [1, 4], [3, 4], [2, 3]]
```

**Output:**

```
2
```

**Explanation:**

* Room 0 gets \[0,8]
* Room 1 gets \[1,4]
* Room 2 gets \[2,3] then \[3,4]
* Meeting counts: \[1, 1, 2, 0]

### Constraints:

* `1 ≤ n ≤ 10^4`
* `1 ≤ meetings.length ≤ 10^4`
* `meetings[i].length == 2`
* `0 ≤ starti < endi ≤ 10^4`
* All `starti` are unique
