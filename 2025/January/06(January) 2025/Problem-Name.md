# Sum Pair Closest Target

## Problem Description
Given a list of integers and a target number, find two numbers from the list whose sum is closest to the target.

## Approach

1. **Sort the Array**: Start by sorting the array for easier manipulation.
2. **Two Pointers**: Use two pointers, one at the beginning (`left`) and one at the end (`right`) of the sorted array.
3. **Loop**: Calculate the sum of the numbers at these pointers and update the closest sum if necessary.
4. **Adjust Pointers**: If the sum is smaller than the target, move the `left` pointer right; if it's larger, move the `right` pointer left.
5. **End Condition**: The process ends when the pointers meet.

## Example

Given the array `[-1, 2, 1, -4]` and target `1`:
- The closest sum pair is `(1, -1)`.

## Code Implementation

```python
def two_sum_closest(nums, target):
    nums.sort()
    left, right = 0, len(nums) - 1
    closest_sum = float('inf')
    while left < right:
        current_sum = nums[left] + nums[right]
        if abs(current_sum - target) < abs(closest_sum - target):
            closest_sum = current_sum
        if current_sum < target:
            left += 1
        else:
            right -= 1
    return closest_sum
