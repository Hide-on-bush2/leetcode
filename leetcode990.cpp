#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Dsu{
private:
    int* dsu;
public:
    Dsu(int N){
        dsu = new int[N];
        for(int i = 0;i < N;i++){dsu[i] = i;}
    }
    int find(int root){
        if(dsu[root] == root){return root;}
        else{return dsu[root] = find(dsu[root]);}
    }
    void myUnion(int root1, int root2){
        int f1 = find(root1), f2 = find(root2);
        dsu[f1] = f2;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Dsu myDsu(26);
        for(string str : equations){
            if(str[1] == '='){myDsu.myUnion(str[0] - 'a', str[3] - 'a');}
        }
        for(string str : equations){
            if(str[1] == '!'){
                if(myDsu.find(str[0] - 'a') == myDsu.find(str[3] - 'a')){return false;}
            }
        }
        return true;
    }
};