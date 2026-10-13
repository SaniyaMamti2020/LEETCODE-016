class Solution:
    def arrayPairSum(self, nums: list[int]) -> int:
        # Sort the array in ascending order
        nums.sort()

        total = 0

        # Sum every second element (indices: 0, 2, 4, ...)
        for i in range(0, len(nums), 2):
            total += nums[i]

        return total