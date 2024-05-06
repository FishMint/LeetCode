#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
		int i = 0, j = s.size() - 1;

		//用双指针法，前后对换
		for(;i < j; i++, j--){
			swap(s[i], s[j]);
		}
    }
};

int main() { return 0; }
