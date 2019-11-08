#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector< vector<int> >& rooms) {
        vector<bool> known(rooms.size(), false);
        queue<int> box;
        box.push(0);
        while(!box.empty()){
            int tempRoom = box.front();
            box.pop();
            known[tempRoom] = true;
            for(int item : rooms[tempRoom]){
                if(known[item] != true){
                    box.push(item);
                }
            }
        }
        for(bool condition : known){
            if(condition == false){return false;}
        }
        return true;
    }
};