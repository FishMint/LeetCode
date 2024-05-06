#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string pathEncryption(string path) {
		for(int i =0; path[i] != '\0'; i++){
			if(path[i] == '.'){
				path[i] = ' ';
			}
		}

		return path;
    }
};

int main(void){
	return 0;
}
