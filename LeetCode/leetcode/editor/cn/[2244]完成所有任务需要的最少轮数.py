# 给你一个下标从 0 开始的整数数组 tasks ，其中 tasks[i] 表示任务的难度级别。在每一轮中，你可以完成 2 个或者 3 个 相同难度级别 的任
# 务。 
# 
#  返回完成所有任务需要的 最少 轮数，如果无法完成所有任务，返回 -1 。 
# 
#  
# 
#  示例 1： 
# 
#  输入：tasks = [2,2,3,3,2,4,4,4,4,4]
# 输出：4
# 解释：要想完成所有任务，一个可能的计划是：
# - 第一轮，完成难度级别为 2 的 3 个任务。 
# - 第二轮，完成难度级别为 3 的 2 个任务。 
# - 第三轮，完成难度级别为 4 的 3 个任务。 
# - 第四轮，完成难度级别为 4 的 2 个任务。 
# 可以证明，无法在少于 4 轮的情况下完成所有任务，所以答案为 4 。
#  
# 
#  示例 2： 
# 
#  输入：tasks = [2,3,3]
# 输出：-1
# 解释：难度级别为 2 的任务只有 1 个，但每一轮执行中，只能选择完成 2 个或者 3 个相同难度级别的任务。因此，无法完成所有任务，答案为 -1 。
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= tasks.length <= 10⁵ 
#  1 <= tasks[i] <= 10⁹ 
#  
# 
#  Related Topics 贪心 数组 哈希表 计数 👍 47 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution(object):
    def minimumRounds(self, tasks):
        """
        :type tasks: List[int]
        :rtype: int
        """
# leetcode submit region end(Prohibit modification and deletion)
