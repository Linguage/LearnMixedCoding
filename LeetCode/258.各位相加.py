#
# @lc app=leetcode.cn id=258 lang=python3
#
# [258] 各位相加
#

# @lc code=start
class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            sum = 0
            while num > 9:
                sum += num%10
                num = int(num/10)
            sum += num
            num = sum
        return num

# @lc code=end

