#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 计算向量的总和
int calculateSum(const vector<int> &numbers) {
  return accumulate(numbers.begin(), numbers.end(), 0);
}

// 查找向量中的最大值和最小值
pair<int, int> findMinMax(const vector<int> &numbers) {
  auto [minIt, maxIt] = minmax_element(numbers.begin(), numbers.end());
  return {*minIt, *maxIt};
}

// 处理字符串并分割成单词
vector<string> splitString(const string &input, char delimiter = ' ') {
  vector<string> result;
  stringstream ss(input);
  string token;

  while (getline(ss, token, delimiter)) {
    if (!token.empty()) {
      result.push_back(token);
    }
  }

  return result;
}

int main() {
  // 设置输入输出流的同步
  ios::sync_with_stdio(false);
  cin.tie(0);

  // 收集多个整数
  vector<int> numbers;
  string input;

  cout << "请输入若干整数 (用空格分隔): ";
  getline(cin, input);

  // 解析输入的数字
  stringstream ss(input);
  int num;
  while (ss >> num) {
    numbers.push_back(num);
  }

  // 对数字进行处理
  if (numbers.empty()) {
    cout << "您没有输入任何数字!" << endl;
    return 0;
  }

  // 计算和显示统计信息
  cout << "您输入的数字: ";
  for (size_t i = 0; i < numbers.size(); ++i) {
    cout << numbers[i];
    if (i < numbers.size() - 1)
      cout << ", ";
  }
  cout << endl;

  // 排序并去重
  vector<int> sortedNumbers = numbers;
  sort(sortedNumbers.begin(), sortedNumbers.end());
  auto last = unique(sortedNumbers.begin(), sortedNumbers.end());
  sortedNumbers.erase(last, sortedNumbers.end());

  // 显示排序和去重后的结果
  cout << "排序并去重后: ";
  for_each(sortedNumbers.begin(), sortedNumbers.end(),
           [&](int n) { cout << n << " "; });
  cout << endl;

  // 计算统计信息
  int sum = calculateSum(numbers);
  auto [minVal, maxVal] = findMinMax(numbers);
  double average = static_cast<double>(sum) / numbers.size();

  cout << "总和: " << sum << endl;
  cout << "平均值: " << average << endl;
  cout << "最小值: " << minVal << endl;
  cout << "最大值: " << maxVal << endl;

  // 演示字符串处理
  cout << "\n请输入一段文字: ";
  string text;
  getline(cin, text);

  // 分割文字为单词并统计
  vector<string> words = splitString(text);
  cout << "您输入了 " << words.size() << " 个单词" << endl;

  // 转换成大写
  transform(words.begin(), words.end(), words.begin(), [](string &s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
  });

  // 显示转换后的单词
  cout << "单词转换成大写: ";
  for (size_t i = 0; i < words.size(); ++i) {
    cout << words[i];
    if (i < words.size() - 1)
      cout << " ";
  }
  cout << endl;

  return 0;
}