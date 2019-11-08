#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    typedef unsigned long long int ull;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int res;
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(1);
        while(!pq.empty()){
            res = pq.top();
            cout << "res:" << res << endl;
            if(n == 1){
                break;
            }
            pq.pop();
            for(int p : primes){
                ull a = (ull)res * p;
                if(a > INT_MAX){
                    break;
                }
                if(a != pq.top()){
                    pq.push(a);
                    cout << a << "push in;" << endl;
                }
            }
            while(!pq.empty() && pq.top() == res){
                cout << pq.top() << "pop;" << endl;
                pq.pop();
            }
            n--;
        }
        cout << "return " << res << endl;
        return res;
    }
};


int main(){
    vector<int> input(4);
    for(int i = 0;i < 4;i++){
        int inputNumber;
        cin >> inputNumber;
        input.push_back(inputNumber);
    }
    int n = 12;
    Solution so;
    so.nthSuperUglyNumber(n, input);
    return 0;
}