#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
		stack<char> st;

		for(char c : s) {
			//是空的就push
			if(st.empty() || st.top() != c) {
				st.push(c);
			}else if(st.top() == c) {
			//不是空就直接且匹配就pop
				st.pop();
			}
		}

		//把栈里的字符串拿出来,注意反一下
		string ret = "";
		while(!st.empty()) {
			ret += st.top();
			st.pop();
		}
		reverse(ret.begin(), ret.end());

		return ret;
    }
};

int main() { return 0; }
