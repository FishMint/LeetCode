#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    //定义s_map滑动窗口 ， t_map目标的哈希表
    unordered_map<char, int> s_map, t_map;
    int left = 0, right = 0, current = 0;
    string result = s;

    // t_map填充
    for (char &c : t) t_map[c]++;

    // right开始遍历
    for (; right < s.size(); right++) {
      s_map[s[right]]++;

      //如果当前字符是目标字符，那计数器就++,不是的话1 !<= 0，=是因为先++的
      if (s_map[s[right]] <= t_map[s[right]]) current++;

      //开始滑动窗口，这里的滑动是个体的滑动，
      //就是left所在的字符，如果在s_map里的数量比t_map的多
      //就直接把left向后移动
      //直到left字符的数量 ==
      // t_map里的数量，因为这样就不可能在滑动窗口减少长度了
      //或者一开始就没有满足要滑动的条件
      while (left < right && s_map[s[left]] > t_map[s[left]]) {
        s_map[s[left++]]--;
      }

      //开始判断是不是满足条件
      if (t.size() == current) {
        if (result.size() > right - left + 1) {
          result = s.substr(left, right - left + 1);
        }
      }
    }

    return t.size() == current ? result : "";
  }
};

int main() {
  Solution s;
  string s1 = "ADOBECODEBANC", t = "ABC";
  cout << s.minWindow(s1, t) << endl;
  return 0;
}
