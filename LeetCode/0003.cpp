//
// Created by zsh_o on 2018/2/25.
//
#include <iostream>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> D(256,-1);
        int start = -1, maxL = 0;
        for(int i=0;i<s.length();i++){
//            cout<<i<<":"<<s[i]<<","<<D[s[i]]<<endl;
            start = max(D[s[i]], start);
            D[s[i]]=i;
            maxL = max(maxL, i - start);
        }
        return maxL;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {

        int ret = Solution().lengthOfLongestSubstring(line);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}