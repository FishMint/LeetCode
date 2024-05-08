#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    //删除s中多出来的空格
    void remove_ext_spcaes(string &s){
        int  fast_p = 0, slow_p = 0;

        //1,首先移除前面的空格
        //其实就是fast_p向后移动
        for(; s[fast_p] == ' '; fast_p++);

        //2,使用双指针法移除多余的空格
        //去掉中间多余空格
        //形式(- 代表空格) w-w-w-w or w-w-w-w-
        for (; fast_p < s.size(); fast_p++) {
            //判断fast_p是不是多余空格
            if(s[fast_p] == ' '
            && s[fast_p] == s[fast_p - 1]) {
                continue;
            }

            s[slow_p++] = s[fast_p];
        }
        
        //3,移除最后的空格
        if(s[slow_p - 1] != ' ')
            s.resize(slow_p);
        else
            s.resize(slow_p - 1);
    }

    string reverseWords(string s) {
        remove_ext_spcaes(s);
        reverse(s.begin(), s.end());
        
        int start = 0;

        //反转中间的words
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        //反转最后一个word
        reverse(s.begin() + start, s.end());

        return s;
    }
};

int main(void) {
    Solution s;
    string str = "  hello  world  ";
    //s.remove_ext_spcaes(str);
    str = s.reverseWords(str);
    cout<<"--"<<str<<"--"<<endl;

    return 0;
}