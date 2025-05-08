#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根 
#

# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1: return x

        a, b = 1, x
        c = (a+b)//2
        # 构建(a,b)区间，b = a+1
        # 灯下黑情形：x恰为完全平方数
        while (b-a) != 1:
            if  x/c == c:return c
            elif x/c < c:
                b = c
                c = (a+b)//2
            else:
                a = c
                c = (a+b)//2
        if b**2 ==x: return b
        else:return int(c)
# @lc code=end

