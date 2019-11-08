#include<utility>
#include<map>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    const int Alex = 0;
    const int Lee = 1;
    map<pair<int, int>, int> stoneAlex, stoneLee;
    void dp(int left, int right, int player, vector<int>& piles, int& stoneOfAlex, int& stoneOfLee){
        if(player == Alex){
            cout << "Alex : " << left << "," << right << endl;
            if(stoneAlex.find(make_pair(left, right)) != stoneAlex.end()){
                stoneOfAlex = stoneAlex[make_pair(left, right)];
                stoneOfLee = stoneLee[make_pair(left, right)];
                return;
            }
            if(left == right){
                stoneOfAlex = piles[left];
                stoneAlex[make_pair(left, right)] = stoneOfAlex;
                stoneLee[make_pair(left, right)] = stoneOfLee;
                return;
            }
            int leftLee = stoneOfLee, leftAlex = stoneOfAlex;
            dp(left + 1, right, Lee, piles, leftAlex, leftLee);
            int rightLee = stoneOfLee, rightAlex = stoneOfAlex;
            dp(left, right - 1, Lee, piles, leftAlex, rightLee);
            if(piles[left] + leftAlex - leftLee > piles[right] + rightAlex - rightLee){
                stoneOfAlex = piles[left] + leftAlex;
                stoneOfLee = leftLee;
            }
            else{
                stoneOfAlex = piles[right] + rightAlex;
                stoneOfLee = rightLee;
            }
            stoneAlex[make_pair(left, right)] = stoneOfAlex;
            stoneLee[make_pair(left, right)] = stoneOfLee;
            return;
        }
        else{
            cout << "Lee : " << left << "," << right << endl;
            if(stoneLee.find(make_pair(left, right)) != stoneLee.end()){
                stoneOfLee = stoneLee[make_pair(left, right)];
                stoneOfAlex = stoneAlex[make_pair(left, right)];
                return;
            }
            if(left == right){
                stoneOfLee = piles[left];
                stoneLee[make_pair(left, right)] = stoneOfLee;
                stoneAlex[make_pair(left, right)] = stoneOfAlex;
                return;
            }
            int leftLee = stoneOfLee, leftAlex = stoneOfAlex;
            dp(left + 1, right, Alex, piles, leftAlex, leftLee);
            int rightLee = stoneOfLee, rightAlex = stoneOfAlex;
            dp(left, right - 1, Alex, piles, leftAlex, rightLee);
            if(piles[left] + leftLee - leftAlex > piles[right] + rightLee - rightAlex){
                stoneOfLee = piles[left] + leftLee;
                stoneOfAlex = leftAlex;
            }
            else{
                stoneOfLee = piles[right] + rightLee;
                stoneOfAlex = rightAlex;
            }
            stoneLee[make_pair(left, right)] = stoneOfLee;
            stoneAlex[make_pair(left, right)] = stoneOfAlex;
            return;
        }
    }
    bool stoneGame(vector<int>& piles) {
        int stoneOfAlex  = 0, stoneOfLee = 0;
        dp(0, piles.size() - 1, Alex, piles, stoneOfAlex, stoneOfLee);
        cout << endl << endl;
        cout << "Alex:" << endl;
        for(map<pair<int, int>, int>::iterator it = stoneAlex.begin();it != stoneAlex.end();it++){
            cout << "(" << it->first.first << "," << it->first.second << ")" << " " << it->second  << endl;
        }
        cout << "Lee:" << endl;
        for(map<pair<int, int>, int>::iterator it = stoneLee.begin();it != stoneLee.end();it++){
            cout << "(" << it->first.first << "," << it->first.second << ")" << " " << it->second  << endl;
        }
        cout << stoneOfAlex << " " << stoneOfLee << endl;
        return stoneOfAlex > stoneOfLee;
    } 
};