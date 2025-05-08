#
# @lc app=leetcode.cn id=13 lang=python3
#
# [13] 罗马数字转整数
#

# @lc code=start
class Solution:
    def romanToInt(self, s: str) -> int:
        n = 0
        temp0 = 1001
        d = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500,'M':1000}
        for i in range(len(s)):
            temp1 = d[s[i]]
            n += temp1
            if temp0 < temp1: 
                n -= 2*temp0
            temp0 = temp1    
        return n


# @lc code=end

