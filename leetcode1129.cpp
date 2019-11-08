#include<iostream>
#include<vector>

using namespace std;
//这个问题用Dijktra算法不合适，应该用BFS。
class Solution {
public:

    bool inT(int node, vector<int>& T){
        for(int i = 0;i < T.size();i++){
            if(T[i] == node){return true;}
        }
        return false;
    }
    int find_min(vector<int>& dis, vector<int>& T){
        vector<int> temp;
        for(int i = 0;i < dis.size();i++){
            if(!inT(i, T) && dis[i] != -1){temp.push_back(i);}
        }
        if(temp.size() == 0){return -1;}
        int idx = temp[0];
        int min_element = dis[idx];
        for(int i = 1;i < temp.size();i++){
            if(dis[temp[i]] < min_element){
                min_element = dis[temp[i]];
                idx = temp[i];
            }
        }
        return idx;
    }
    void print(vector<int>& vec){
        for(int item : vec){cout << item << " ";}
        cout << endl;
    }
    vector<int> shortestAlternatingPaths(int n, vector< vector<int> >& red_edges, vector< vector<int> >& blue_edges) {
        //T为顶点集，dis为距离集，in_edges为入度边的种类集（1表示红边，-1表示蓝边，0表示没有入度）
        vector<int> T, dis(n, -1), in_edges(n, 0);
        dis[0] = 0;
        T.push_back(0);
        //遍历红边和蓝边，找出与0直接相连的顶点，并记录入度的边种类。
        for(vector<int> item : red_edges){
            if(item[0] == 0){
                dis[item[1]] = 1;
                in_edges[item[1]] = 1;
            }
        }
        for(vector<int> item : blue_edges){
            if(item[0] == 0){
                dis[item[1]] = 1;
                in_edges[item[1]] = -1;
            }
        }
        int count = 0;
        for(int item : dis){
            if(item != 0 && item != -1){count += 1;}
        }//记录还没有加入顶点集且能够到达的顶点数
        while(count > 0){
            cout << "T: " << endl;
            print(T);
            cout << "dis: " << endl;
            print(dis);
            int node = find_min(dis, T);//找到最小的不在T上并且能后达到的顶点，放入顶点集
            cout << "node: " << node << endl;
            T.push_back(node);
            count--;
            int in_color = in_edges[node];
            vector<int> out_node;
            //在相反的颜色集里面找出度
            if(in_color == 1){
                for(vector<int> item : blue_edges){
                    if(item[0] == node){out_node.push_back(item[1]);}
                }
            }
            if(in_color == -1){
                for(vector<int> item : red_edges){
                    if(item[0] == node){out_node.push_back(item[1]);}
                }
            }
            //更新到结点的长度
            for(int oNode : out_node){
                if(dis[oNode] == -1 || dis[node] + 1 < dis[oNode]){
                    if(dis[oNode] == -1){count++;}
                    dis[oNode] = dis[node] + 1;
                    if(in_color == 1){in_edges[oNode] = -1;}
                    if(in_color == -1){in_edges[oNode] = 1;}
                }
            }
        }
        return dis;
    }
};