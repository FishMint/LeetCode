#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    //比较函数,换成小顶堆
    class cmp {
        public:
        bool operator()(const pair<int, int> left, const pair<int, int> right) {
            return left.second > right.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //直接使用优先队列，就是堆,(我懒得搓一次了)
        //——屁股push，头pop
        //直接使用大顶堆
        //这里指明使用自己的排序的时候，一定要声明pri que底层的容器是什么
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri_que;
        unordered_map<int, int> map;

        //map的填充
        for(int it : nums) map[it] ++;

        //直接使用map把map对应的值按照 count 排序
        for(auto it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if(pri_que.size() > k)  pri_que.pop();
        }

        vector<int> ret(k);
        for(int i = 0; i < k; i++) {
            ret[i] = pri_que.top().first;
            pri_que.pop();
        }

        return  ret;
    }
};

int main()
{
    
    return 0;
}
