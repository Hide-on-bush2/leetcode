#include<stack>
#include<iostream>
#include<string>

class Solution {
public:
    std::string removeOuterParentheses(std::string S) {
        std::string res = "";
        int i = 0, start = 0;
        std::stack<char> s;
        while(i < S.size()){
            if(S[i] == '('){s.push(S[i]);}
            else{
                while(!s.empty() && s.top() != '('){
                    s.pop();
                }
                s.pop();
                if(s.empty()){
                    res += S.substr(start + 1, i - start - 1);
                    start = i + 1;
                }
            }
            i++;
        }
        return res;
    }
};