#include<string>
#include<stack>

// using namespace std;

class Solution {
public:
    int minAddToMakeValid(std::string S) {
    	std::stack<char> m_s;
        for(auto s_ : S){
        	if(s_ == '('){
        		m_s.push('(');
        	}
        	else{
        		if(!m_s.empty() && m_s.top() == '('){
        			m_s.pop();
        		}
        		else{
        			m_s.push(')');
        		}
        	}
        }
        int res = 0;
        while(!m_s.empty()){
        	m_s.pop();
        	res += 1;
        }
        return res;
    }
};


