# https://leetcode.com/problems/powx-n/

class Solution:
    def myPow(self, x: float, n: int) -> float:
        l=0
        if n<0:
            l=-1
            n=-1*n
        ans=1
        while n>0:
            if n%2==1:
                ans=ans*x
                n-=1
            else:
                x=x*x
                n=n/2
            #print(ans)
        if l<0:
            ans=1/ans
        return ans
