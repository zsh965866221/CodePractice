//
// Created by zsh96 on 2018/2/26.
//
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        bool dp[s.size()][s.size()];
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                dp[i][j]=false;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j] && (j-i<2 || dp[i+1][j-1]==true)){
                    dp[i][j] = true;
                    if(j-i+1>=res.size()){
                        res = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return res;
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
        string s = (line);

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
