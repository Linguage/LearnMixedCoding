#
# @lc app=leetcode.cn id=326 lang=python3
#
# [326] 3 的幂
#

# @lc code=start
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <=0:return False
        while n % 3 == 0:
            n /= 3
        if n == 1: return True
        else: return False
# @lc code=end

