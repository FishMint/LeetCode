#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class MyQueue {
public:
    stack<int> stackIn;
    stack<int> stackOut;

    MyQueue() {

    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        int ret;

        //out空了再从in导入数据
        //不然会出现，out里还有数据，
        //新push进来的那批数据会跑到旧的前面去
        if (stackOut.empty()) {
            while (!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }

        ret = stackOut.top();
        stackOut.pop();
        return ret;
    }
    
    int peek() {
        int ret;
        ret = this->pop();
        stackOut.push(ret);
        return ret;
    }
    
    bool empty() {
        /*
        if(stackIn.size() + stackOut.size() > 0) 
            return false;
        return true;
        */
       return stackIn.empty() && stackOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main(void) { return 0; }