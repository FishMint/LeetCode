#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string dynamicPassword(string password, int target) {
		reverse(password.begin(), password.end());
		reverse(password.begin(), password.end() - target);
		reverse(password.end() - target, password.end());
		return password;
    }
};


int main(void){
	Solution s;
	cout<< s.dynamicPassword("s3cur1tyC0d3", 4)<<endl;
	return 0;
}
