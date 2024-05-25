#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        //为了好分离
        path += "/";
        vector<string> st;
        string dir = "";

        for(char c : path) {
            if(c != '/') {
               dir += c; 
            }else if(dir != "") {
                //弹出栈顶元素, 根目录就不返回了
                //返回上一级
                if(dir == ".." ) {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                    dir = "";
                    continue;
                }else if(dir == ".") {
                //如果表示的是.当前目录的话，就不管了
                    dir = "";
                    continue;
                }

                st.push_back(dir);
                dir = "";
            }
        }
        
        string ret =  "";
        for(auto it : st) {
            ret += "/";
            ret += it;
        }

        return (ret == "") ? "/" : ret;
    }
};

int main()
{
    Solution s;
    cout<<s.simplifyPath("/home/")<<endl;
    return 0;
}
