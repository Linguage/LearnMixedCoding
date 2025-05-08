
#include <iostream>

using namespace std;

class Solution {
public:
  int Hello(int n) {

    for (int i = 0; i < n; i++) {
      cout << "Hello,LeetCode !" << i << endl;
    }

    if (n < 5) {
      cout << n << "?" << endl;
      cout << "It's a small number" << endl;
    }else {
    cout<<"Fuck!,It's rather large"<<endl;
    }
    // 请在这里实现您的解决方案
    cout << "Hello,LeetCode !" << endl;
    return 0;
  }
};

// 用于本地测试
int main() {
  Solution sol;

  sol.Hello(6);

  // 测试用例
  // 添加测试用例

  // 输出结果
  // 打印结果

  return 0;
}