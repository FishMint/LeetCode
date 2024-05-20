#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class MyStack {
public:
    queue<int> queueIn;
    queue<int> queueTmp;

    MyStack() {

    }
    
    void push(int x) {
        queueIn.push(x);
    }
    
    int pop() {
        int ret = queueIn.back();

        //把前面的元素都移动到tmp里,剩下最后一个
        while (queueIn.size() > 1) {
            queueTmp.push(queueIn.front());
            queueIn.pop();
        }
        //最后一个弹出去
        queueIn.pop();

        //放回去
        while (!queueTmp.empty()) {
            queueIn.push(queueTmp.front());
            queueTmp.pop();
        }

        return ret;
    }
    
    int top() {
        return queueIn.back();
    }
    
    bool empty() {
        return queueIn.empty();
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


int main(void) { return 0; }