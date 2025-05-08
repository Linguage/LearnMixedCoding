#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> numMap; // value -> index

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];

      if (numMap.find(complement) != numMap.end()) {
        return {numMap[complement], i};
      }

      numMap[nums[i]] = i;
    }

    return {}; // No solution found
  }
};

// 用于本地测试
int main() {
  Solution sol;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  // 测试用例
  vector<int> result = sol.twoSum(nums, target);

  // 输出结果
  if (!result.empty()) {
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
  } else {
    cout << "No solution found." << endl;
  }

  return 0;
}