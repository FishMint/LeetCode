#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    //计算next表
    void get_next(string &s, int *next) {
        int left = 0, right = 1;

        //初始化这俩因为 idx = 0 or 1 错了,都要回到第0个开始比较
        next[0] = 0;
        for(; right < s.size(); right++) {
            // 分两种情况：相同，不同

            //1,不同,通过while，找到比当前后缀小一点的继续比较
            while (left > 0 && s[left] != s[right])
            {
                left = next[left - 1];
            }

            // 2,相等,最长前后缀+1
            if(s[left] == s[right]) {
                left++;
                next[right] = left;
                continue;
            }

            //这里是如果 不同的while出来， left = 0 且 两个还是不同
            //直接给0
            next[right] = 0;
        }
    }

    int strStr(string haystack, string needle) {
        int next[needle.size()];
        int i = 0, j = 0;
        get_next(needle, next);

        for(; i < haystack.size(); i++) {
            //如果不一样，就回退到next[j - 1],
            //在不一样再回退
            while(j != 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }

            //相同就j++后移
            if(haystack[i] == needle[j]) {
                j++;
            }

            //如果匹配完了
            if(j == needle.size()) {
                return i - j + 1;
            }
        }

        //到这里说明一直是没有跳到for里面的匹配上的地方的
        return -1;

    }
};


int main(void) {
    Solution s;
    string str = "sadbutsad";
    string needle = "sad";
    cout<<s.strStr(str, needle);

    return 0;
}
