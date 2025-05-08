#
# @lc app=leetcode.cn id=14 lang=python3
#
# [14] 最长公共前缀
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_len = min(len(i) for i in strs)


        pre = ""
        j = 0
        strs_len = len(strs)
        while(j < min_len):
            p = strs[0][j]
            break_out_flag = False
            for i in range(strs_len-1):
                if p != strs[i+1][j]:
                    break_out_flag = True   #Python中无法直接跳出嵌套循环
                    break
            if break_out_flag:
                break
            pre += p
            j += 1
        return pre

# @lc code=end

