#
# @lc app=leetcode.cn id=342 lang=python3
#
# [342] 4的幂
#

# @lc code=start
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <=0:return False
        while n % 4 == 0:
            n /= 4
        if n == 1: return True
        else: return False
# @lc code=end

