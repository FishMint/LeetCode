#include <climits>
#include<cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    int num = words.size(), min;
    int map[26][num];
    vector<string> result;

	//初始化，头文件cstring
	memset(map,0,sizeof(map));

    //开始统计各个字母在各个word中出现的频率
    for (int i = 0; i < words.size(); i++) {
      for (char c : words[i]) {
        map[c -97][i]++;
      }
    }

    //每个单词本拿出最小的
	for(int i =0; i<26;i++){
		min = INT_MAX;
		for(int j =0; j<num;j++){
			if(min > map[i][j]) min = map[i][j];
		}
		while(min--)	result.push_back(string(1,'a'+i));
	}

          return result;
  }
};

int main() { return 0; }
