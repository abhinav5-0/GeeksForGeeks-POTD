# Minimum Cost to Reach Last Stair

Given an integer array `height[]` where `height[i]` represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair.  
From any stair, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair.  
The cost of a jump is the absolute difference in height between the two stairs.  
Determine the minimum total cost required for the frog to reach the last stair.

---

## Example

**Input:**  
height[] = [20, 30, 40, 20]  
**Output:**  
20  

**Explanation:**  
Minimum cost is incurred when the frog jumps from stair 0 to 1:  
Cost = |30 - 20| = 10  
Jump from stair 1 to 3:  
Cost = |20 - 30| = 10  
Total cost = 10 + 10 = 20

---

**Input:**  
height[] = [10, 20, 10, 40, 10]  
**Output:**  
30  

**Explanation:**  
Minimum cost will be incurred when frog jumps from stair 0 to 1 (cost = 10), then to 2 (cost = 10), then to 4 (cost = 10):  
Total cost = 10 + 10 + 10 = 30

---

## Constraints

- 1 ≤ height.size() ≤ 10⁵  
- 0 ≤ height[i] ≤ 10⁴

---

## Function Signature
