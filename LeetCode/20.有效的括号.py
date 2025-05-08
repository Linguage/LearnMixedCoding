#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        dict = {'(':')','[':']','{':'}'}
        stack = []
        for i in s:
            if i in dict: 
                stack.append(i)
            elif stack == []: 
                return False
                break
            elif i == dict[stack[-1]]:
                stack.pop()
            else: 
                return False
                break

        return not stack



# @lc code=end

