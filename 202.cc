#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  //就是普通的取各个位上的数字的平方和
  int getSum(int n) {
    int sum = 0;
    int v;
    while (n) {
      v = n % 10;
      sum += v * v;
      n /= 10;
    }
    return sum;
  }

  bool isHappy(int n) {
    unordered_set<int> set;
    int sum = n;

    //每次取和在set里面找，有重复就退出，没有就继续
    while (set.find(sum) == set.end()) {
      if (sum == 1) return true;  //如果算出来是1，就退出
      set.insert(sum);
      sum = getSum(sum);
    }
    return false;
  }
};

int main(void) { return 0; }
