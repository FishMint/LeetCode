#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;

        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }else {
                if(st.empty())  return false;
                if(c == ')' && st.top() == '(')         st.pop();
                else if(c == ']' && st.top() == '[')    st.pop();
                else if(c == '}' && st.top() == '{')    st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


int main(void) {
    Solution s;
    cout<<s.isValid("){")<<endl;
     return 0; }