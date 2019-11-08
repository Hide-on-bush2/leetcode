#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    void PrintContainer(vector<int>& vec){
        for(int item : vec){
            cout << item << " ";
        }
        cout << endl;
    }
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            make_heap(stones.begin(), stones.end());
            pop_heap(stones.begin(), stones.end());
            int first = stones.back();
            stones.pop_back();
            pop_heap(stones.begin(), stones.end());
            int second = stones.back();
            stones.pop_back();
            if(first != second){
                int differ = abs(first - second);
                stones.push_back(differ);
                push_heap(stones.begin(), stones.end());
            }
            if(stones.size() == 0){
                stones.push_back(0);
            }
            PrintContainer(stones);
        }
        return stones[0];
    }
};
typename std::__1::vector<int> vec;
int main(){
    Solution so;
    std::__1::vector<int> vec{2, 2};
    cout << so.lastStoneWeight(vec);
    return 0;

}