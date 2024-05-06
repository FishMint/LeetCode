#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralArray(vector<vector<int>>& array) {
    int row = array.size(), col = array[0].size(), round_time;
    vector<int> ans;

    //行列最小值
    round_time = (min(row, col) >> 1);
    int i, j, t;

    for (t = 1; t <= round_time; t++) {
      i = t - 1;
      j = t - 1;

      //最上面
      for (; j < col - t; j++) {
        ans.push_back(array[i][j]);
      }

      //最右边
      for (; i < row - t; i++) {
        ans.push_back(array[i][j]);
      }

      //最下面
      for (; j > t - 1; j--) {
        ans.push_back(array[i][j]);
      }

      //最左边
      for (; i > t - 1; i--) {
        ans.push_back(array[i][j]);
      }
    }

    //如果最小的是row且为基数
    if (row <= col && row % 2 == 1) {
      i = t - 1;
      j = t - 1;
      for (; j <= col - t; j++) {
        ans.push_back(array[i][j]);
      }
    }

    if (col < row && col % 2 == 1) {
      i = t - 1;
      j = t - 1;
      for (; i <= row - t; i++) {
        ans.push_back(array[i][j]);
      }
    }

    return ans;
  }
};

int main() {
  vector<vector<int>> test1;
  vector<vector<int>> test2;
  return 0;
}
