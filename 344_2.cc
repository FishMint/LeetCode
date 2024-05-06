#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
		int len = s.size();

		/*
		char tmp; 
		for(int i = 0; i < len / 2; i++){
			tmp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = tmp;
		}
		*/

		for(int i = 0, j = len - 1; i < len /2; i++, j--){
			swap(s[i], s[j]);
		}

    }
};

int main() { return 0; }
