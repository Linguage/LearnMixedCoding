#
# @lc app=leetcode.cn id=26 lang=python3
#
# [26] 删除有序数组中的重复项
#

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        ind = []
        for i in range(n-1):
            if nums[i] != nums[i+1]:
                ind.append(i+1)
        # n_ind = len(ind)
        return len(ind)+1
        # nums[:n_ind] = nums[ind]
        # for i in range(n-n_ind):
        #     nums.pop()
        # return n_ind


# @lc code=end

