#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Dsu{
private:
    int* p;
public:
    Dsu(int N){
        p = new int[N];
        for(int i = 0;i < N;i++){
            p[i] = -1;
        }
    }
    ~Dsu(){delete [] p;}
    int find(int root){
        if(p[root] < 0){
            return root;
        }
        else{
            return p[root] = find(p[root]);
        }
    }
    void myUnion(int root1, int root2){
        int f1 = find(root1);
        int f2 = find(root2);
        if(p[f1] < p[f2]){p[f2] = f1;}
        else{
            if(p[f1] == p[f2]){p[f2]--;}
            p[f1] = f2;
        }
    }
};

class Solution {
public:
    vector<double> calcEquation(vector< vector<string> >& equations, vector<double>& values, vector< vector<string> >& queries) {
        vector<double> dis(26, -1);
        Dsu myDsu(26);
        int size = equations.size();
        for(int i = 0;i < size;i++){
            int first = equations[i][0][0] - 'a';
            int second = equations[i][1][0] - 'a';
            if(dis[first] == -1){dis[first] = 1;}
            dis[second] = dis[first] * values[i];
            myDsu.myUnion(first, second);
        }
        vector<double> res(queries.size());
        for(int i = 0;i < queries.size();i++){
            int first = queries[i][0][0] - 'a';
            int second = queries[i][1][0] - 'a';
            if(first == second){res[i] = 1;}
            else{
                if(myDsu.find(first) == myDsu.find(second)){res[i] = dis[second] / dis[first];}
                else{res[i] = -1;}
            }
        }
        return res;
    }
};