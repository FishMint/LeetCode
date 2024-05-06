#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
	  if(matrix.size() == 0)	return vector<int>();
    int row = matrix.size(), col = matrix[0].size(), round_time;
    vector<int> ans;

    //取最小值,完成最外圈的for的次数
    round_time = min(row, col);
    round_time = (round_time >> 1);

    int i, j, t;
    //开始循环
    for (t = 1; t <= round_time; t++) {
      i = t - 1;
      j = t - 1;

      //最上方填充
      for (; j < col - t; j++) {
        ans.push_back(matrix[i][j]);
      }

      //最右边
      for (; i < row - t; i++) {
        ans.push_back(matrix[i][j]);
      }

      //最下面
      for (; j > t - 1; j--) {
        ans.push_back(matrix[i][j]);
      }

      //最左边
      for (; i > t - 1; i--) {
        ans.push_back(matrix[i][j]);
      }
    }

	//如果这里是row是最小值且最小值是基数,那就把 横着的那段加进来
    if (row <= col && row % 2 == 1) {
      i = t -1;
      j = t -1;
      for (; j <= col - t; j++) {
        ans.push_back(matrix[i][j]);
      }
    }

	//如果这里是col是最小值且最小值是基数,那就把 竖着的那段加进来
	if (row > col && col % 2 == 1) {
		i = t -1;
		j = t -1;
		for (; i <= row - t; i++) {
			ans.push_back(matrix[i][j]);
		}
	}


    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<vector<int>> test2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> test3 = {{1, 2, 3}};
  vector<vector<int>> test4 = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};

  vector<int> v = s.spiralOrder(test4);

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
  return 0;
}
