# Allocate Minimum Pages

**Difficulty:** Medium  
**Accuracy:** 35.51%  
**Submissions:** 322K+  
**Points:** 4  
**Average Time:** 35m  

---

## Problem Statement
You are given an array `arr[]` of integers, where each element `arr[i]` represents the number of pages in the i-th book. You also have an integer `k` representing the number of students.  

The task is to allocate books to each student such that:

1. Each student receives at least one book.  
2. Each student is assigned a contiguous sequence of books.  
3. No book is assigned to more than one student.  

The objective is to **minimize the maximum number of pages assigned to any student**. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

If it is not possible to allocate books to all students, return `-1`.

---

## Examples

### Example 1
**Input:**  
