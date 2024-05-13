#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    //还是KMP算法的next数组
    void getNext(string &s, int *next) {
        int left = 0, right = 1;
        next[left] = 0;

        for(; right < s.size(); right++) {
            //1,先考虑不一样的
            while(left != 0 && s[left] != s[right]) {
                left = next[left - 1];
            }

            //2,一样的话
            if(s[left] == s[right]) {
                left++;
                next[right] = left;
                continue;
            }

            //left == 0 ; s[left] != s[right]的情况
            next[right] = 0;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        int next[s.size()];
        getNext(s, next);

        //有最长相同前后缀
        if(next[len - 1] != 0 
        && len % (len - next[len - 1]) == 0) {
            return true;
        }
        
        return false;
    }
};

int main()
{
    
    return 0;
}
