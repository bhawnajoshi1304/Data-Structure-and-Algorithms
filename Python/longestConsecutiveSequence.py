# https://leetcode.com/problems/longest-consecutive-sequence/

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n=len(nums)
        n1=set(nums)
        ans=0
        for i in range(n):
            if (nums[i]-1) not in n1:
                g=nums[i]
                k=1
                while g+1 in n1:
                    k+=1
                    g+=1
                ans=max(ans,k)
        return ans
