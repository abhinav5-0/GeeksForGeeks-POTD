class Solution:
    def findLargest(self, arr):
        
        # Convert integers to strings
        nums = list(map(str, arr))
        
        # Custom sort
        nums.sort(key=lambda x: x*10, reverse=True)
        
        # Edge case: if largest is "0"
        if nums[0] == "0":
            return "0"
        
        # Concatenate result
        return ''.join(nums)
