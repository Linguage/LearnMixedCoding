#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#

# @lc code=start
class Solution:
    def fib(self, n: int) -> int:
        if n == 0 or n == 1:
            fn = n
        else: 
            i = 1
            f0 = 0
            f1 = 1
            while(i < n):
                fn = f0 +f1
                f0 = f1
                f1 = fn
                i += 1
        return fn



            
# @lc code=end

