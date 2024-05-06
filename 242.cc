#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    //如果个数都不一样直接返回false
    if (s.size() != t.size()) return false;
    map<char, int> s_map;

    //简单的hash表，来填充s_map
    for (char c : s) {
      s_map[c]++;
    }

    //把s_map给-回去
    for (char c : t) {
      s_map[c]--;
    }

    //检查一下所有的元素是不是为0
    for (auto it = s_map.begin(); it != s_map.end(); it++) {
      if (it->second != 0) return false;
    }

    return true;
  }
};

int main(void) { return 0; }
