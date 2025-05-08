#
# @lc app=leetcode.cn id=9 lang=python3
#
# [9] 回文数
#

# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        x_str = str(x)
        for i in range(len(x_str)):
            if x_str[i] != x_str[len(x_str)-i-1]:
                return False
                break    
        return True


# @lc code=end

