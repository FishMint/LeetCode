#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    //判断是不是符号
    bool ifOp(string op) {
        return (op == "+" ||
                op == "-" ||
                op == "*" ||
                op == "/"  );
    }

    int calculate(string op, int num1, int num2) {
        if(op == "+")       return num1 + num2;
        else if(op == "-")  return num2 - num1;
        else if(op == "*")  return num1 * num2;
        else                return num2 / num1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        string tmp;

        for(int i =0; i < tokens.size(); i++) {
            if(ifOp(tokens[i])) {
                int num1, num2;
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                //弹出来两个计算
                //然后把计算结果push进去
                st.push(calculate(tokens[i], num1, num2));
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        int ret = st.top();
        return ret;
    }
};

// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<int> st;
//         for (int i = 0; i < tokens.size(); i++) {
//             if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
//                 int num1 = st.top();
//                 st.pop();
//                 int num2 = st.top();
//                 st.pop();
//                 if (tokens[i] == "+") st.push(num2 + num1);
//                 if (tokens[i] == "-") st.push(num2 - num1);
//                 if (tokens[i] == "*") st.push(num2 * num1);
//                 if (tokens[i] == "/") st.push(num2 / num1);
//             } else {
//                 st.push(stoi(tokens[i]));
//             }
//         }
//         int result = st.top();
//         st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
//         return result;
//     }
// };

int main(void) {
    return 0;
}