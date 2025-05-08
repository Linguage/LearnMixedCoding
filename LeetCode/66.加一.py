#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#

# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1] += 1
        for i in range(len(digits)-1):
            if digits[-i-1] == 10:
                digits[-i-1] = 0            
                digits[-i-2] += 1
        if digits[0] == 10:
            new_digits = [list()]*(len(digits)+1)
            new_digits[0:1] = [1,0]
            new_digits[2:] = digits[1:]
            digits = new_digits
        return digits
# @lc code=end

