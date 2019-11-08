#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct cmp{
        bool operator()(int a, int b){
            return a > b;
        }
    }myCmp;
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end(), myCmp);
        int j = 0;
        for(int i = 1;i < temp.size();i += 2, j++){
            nums[i] = temp[j];
        }
        for(int i = 0;i < temp.size();i += 2, j++){
            nums[i] = temp[j];
        }
    }
};

