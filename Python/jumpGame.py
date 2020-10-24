# https://leetcode.com/problems/jump-game/

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # greedy solution
        i=len(nums)-1
        last=i
        while i>=0:
            if nums[i]+i>=last:
                last=i
            i-=1
        return last==0
