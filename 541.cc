#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
		int begin = 0, len = s.size();

		while(begin < len){
			//判断 前k个是不是在s.size()中,
			if(begin + k <= len){
				reverse(s.begin() + begin, s.begin() + begin + k);
			}else{
			//如果不是，剩下来的<k，那就反转begin - s.end()
				reverse(s.begin() + begin, s.end());
			}

			begin += (2 * k);
		}

		return s;
    }
};

int main(void){
	return 0;
}
