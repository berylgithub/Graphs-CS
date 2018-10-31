#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include "dfs.h"


using namespace std;
void traverse_DFS(int **graph, stack<int>& s_dfs, int visited[], vector<int>& v_track, int vertices, int current_node){
    if(!s_dfs.empty()){
        int traverse_node = -1;
        visited[current_node] = 1;
        //visited[4] = 1;
        //visited[5] = 1;

        //v_track.push_back(current_node);
        for(int i=0; i<vertices; i++){
            if(graph[current_node][i]==1){
                if(visited[i]==0){
                    traverse_node = i;
                    s_dfs.push(traverse_node);
                    v_track.push_back(traverse_node);
                    break;
                }
            }
        }
        cout<<"stack top = "<<s_dfs.top()<<endl;
        cout<<"traverse node= "<<traverse_node<<endl;
        for(int i=0; i<v_track.size(); i++){
            cout<<v_track[i]<<" ";
        }
        cout<<endl<<endl;
        if(traverse_node<=-1){
            s_dfs.pop();
            if(!s_dfs.empty()){
                traverse_node = s_dfs.top();
                traverse_DFS(graph, s_dfs, visited, v_track, vertices, traverse_node);
            }
        }
        else if(traverse_node>-1){
            traverse_DFS(graph, s_dfs, visited, v_track, vertices, traverse_node);
        }

    }
}

void traverse_DFS_helper(int **graph, stack<int>& s_dfs, int visited[], vector<int>& v_track, int vertices, int root){
    int current = root;
    //-1 means no any other travel route which has not been visited
    int traverse_node = -1;
    //push root to stack
    s_dfs.push(current);
    //set visited root = 1 (already visited)
    visited[current]=1;
    //push root to track
    v_track.push_back(current);
    for(int i=0; i<vertices; i++){
        if(graph[current][i]==1){
            if(visited[i]==0){
                traverse_node=i;
                s_dfs.push(traverse_node);
                v_track.push_back(traverse_node);
                break;

            }
        }
    }
    traverse_DFS(graph, s_dfs, visited, v_track, vertices, traverse_node);
}
