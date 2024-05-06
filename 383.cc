#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char,int> u_map;
		for(char m : magazine){
			u_map[m]++;
		}

		for(char r : ransomNote){
			u_map[r]--;
			if(u_map[r] < 0)	return false;
		}
		
		return true;
    }
};

int main(void){

	return 0;
}
