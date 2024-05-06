#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
		int count = 0;

		//统计空格的数量
		for(int i = 0; s[i] != '\0'; i++){
			if(s[i] == ' ')		count++;
		}

		int old_size = s.size();
		int new_size = s.size() + count * 2;
		//扩容
		s.resize(new_size);

		//使用双指针直接扩容老的
		//注意for的判断条件，这个 > 写的就很妙
		for(int new_p = new_size - 1, old_p = old_size - 1; 
			new_p > old_p; new_p--, old_p--) 
		{
			if(s[old_p] != ' ')	{
				s[new_p] = s[old_p];
			}else{
				s[new_p] = '0';
				s[new_p - 1] = '2';
				s[new_p - 2] = '%';
				new_p -= 2;
			}
		}

		return s;
	}
};


int main(void){
	Solution s;
	string a = "We are happy.";
	cout<<s.replaceSpace(a)<<endl;
	return 0;
}
