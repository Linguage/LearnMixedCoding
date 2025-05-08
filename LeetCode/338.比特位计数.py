#
# @lc app=leetcode.cn id=338 lang=python3
#
# [338] 比特位计数
#

# @lc code=start
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0]*(n+1)
        for i in range(n+1):
            j = i
            while j >= 1:
                if j % 2 == 1:
                    ans[i] += 1
                j //= 2
        return ans

# @lc code=end

