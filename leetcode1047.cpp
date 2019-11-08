#include<algorithm>
#include<string>
#include<stack>

using std::stack;
using std::string;

class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        stack<char> myStack;
        for(int i = 0;i < S.size();i++){
            if(myStack.empty()){myStack.push(S[i]);}
            else if(myStack.top() == S[i]){myStack.pop();}
            else{myStack.push(S[i]);}
        }
        while(!myStack.empty()){
            res += myStack.top();
            myStack.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};