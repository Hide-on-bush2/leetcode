#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


class Solution {
public:
    /*pair<int, int> findMin(vector<int> dis){
        vector<int>::iterator smallest = min_element(dis.begin(), dis.end());
        int val = *smallest;
        int index = distance(dis.begin(), smallest);
        return make_pair(val, index);
    }*/
    bool notIn(int val, vector<int>& temp){
        for(int item : temp){
            if(item == val){return false;}
        }
        return true;
    }
    struct cmp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        }
    }myCmp;
    int findCheapestPrice(int n, vector< vector<int> >& flights, int src, int dst, int K) {
        vector<int> dis(n, 1000000);
        for(vector<int> item : flights){
            if(item[0] == src){dis[item[1]] = item[2];}
        }
        dis[src] = 0;
        //for(int item : dis){cout << item << " ";}
        //cout << endl;
        while(K--){
            vector< pair<int, int> > temp;
            for(int i = 0;i < dis.size();i++){
                if(dis[i] != 1000000 && dis[i] != 0){
                    temp.push_back(make_pair(i, dis[i]));
                }
            }
            sort(temp.begin(), temp.end(), myCmp);
            vector<int> beDeleted;
            for(pair<int, int> pos : temp){
                for(vector<int> flight : flights){
                    if(notIn(pos.first, beDeleted) && flight[0] == pos.first && flight[2] + dis[pos.first] < dis[flight[1]]){
                        dis[flight[1]] = flight[2] + pos.second;
                        beDeleted.push_back(flight[1]);
                        //cout << flight[1] << ":" << flight[2] + pos.second << endl;
                    }
                }
            }
            //for(int item : dis){cout << item << " ";}
            //cout << endl;
        }
        if(dis[dst] == 1000000){return -1;}
        else{return dis[dst];}
    }
};