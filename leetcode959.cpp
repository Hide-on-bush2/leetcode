#include<iostream>
#include<vector>

using namespace std;

class Dsu{
private:
    vector<int>* p;
    int count;
public:
    Dsu(int N){
        p = new vector<int>(N, -1);
        count = N;
    }
    ~Dsu(){
        delete p;
    }
    int find(int root){
        if((*p)[root] < 0){
            return root;
        }
        else{
            return (*p)[root] = find((*p)[root]);
        }
    }
    void myUnion(int root1, int root2){
        int f1 = find(root1), f2 = find(root2);
        if((*p)[f1] < (*p)[f2]){(*p)[f2] = f1;}
        else if((*p)[f2] < (*p)[f1]){(*p)[f1] = f2;}
        else{
            (*p)[f1]--;
            (*p)[f2] = f1;
        }
        count--;
    }
    int numOfparent(){
        return count;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        Dsu myDsu(N * N * 4);
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                int start = 4 * (i * N + j);
                if(grid[i][j] == ' '){
                    myDsu.myUnion(start + 0, start + 1);
                    myDsu.myUnion(start + 1, start + 2);
                    myDsu.myUnion(start + 2, start + 3);
                }
                else if(grid[i][j] == '/'){
                    myDsu.myUnion(start + 0, start + 3);
                    myDsu.myUnion(start + 1, start + 2);
                }
                else if(grid[i][j] == '\\'){
                    myDsu.myUnion(start + 0, start + 1);
                    myDsu.myUnion(start + 2, start + 3);
                }
                if(i > 0){myDsu.myUnion(start - N * 4+ 2, start);}
                if(j > 0){myDsu.myUnion(start - 3, start + 3);}
            }
        }
        return myDsu.numOfparent();
    }
};