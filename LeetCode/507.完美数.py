#
# @lc app=leetcode.cn id=507 lang=python3
#
# [507] 完美数
#

# @lc code=start
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        import math
        i = 2
        sum = 0
        
        while(i*i < num):
            if num % i == 0:
                sum += i+num/i
            i += 1
        if i*i == num:sum += i
        if num == 1: 
            return False
        elif num == sum+1:return True
        else: return False

# @lc code=end

