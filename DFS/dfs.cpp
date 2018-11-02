#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <algorithm>
#include "dfs.h"


using namespace std;

void traverse_DFS(int **graph, stack<int>& s_dfs, int visited[], vector<int>& v_track, int vertices, int parent, int current_node,
                  bool backtrack){
    if(!s_dfs.empty()){
        //parent will ONLY be used if a cycle is found
        int traverse_node = -1;
        visited[current_node] = 1;

        for(int i=0; i<vertices; i++){
            if(graph[current_node][i]==1){
                if(visited[i]==0){
                    traverse_node = i;
                    s_dfs.push(traverse_node);
                    v_track.push_back(traverse_node);
                    break;
                }
                //cycle probability checking, if it is already visited AND is not the stack's previous top (parent), then a cycle is found
                else if(visited[i]==1 && i!=parent && backtrack==false){
                    cout<<"advance node = "<<i<<endl;
                    is_cycle=true;
                    cout<<"Cycle is found !!!"<<endl;

                }
            }
        }
        cout<<"parent = "<<parent<<endl;
        cout<<"stack top = "<<s_dfs.top()<<endl;
        cout<<"traverse node= "<<traverse_node<<endl;
        cout<<"track = ";
        for(int i=0; i<v_track.size(); i++){
            cout<<v_track[i]<<" ";
        }
        cout<<endl;
        //backtrack
        if(traverse_node<=-1){
            backtrack=true;
            s_dfs.pop();
            if(!s_dfs.empty()){
                cout<<endl;
                traverse_node = s_dfs.top();
                traverse_DFS(graph, s_dfs, visited, v_track, vertices, current_node, traverse_node, backtrack);
            }
        }
        //advance
        else if(traverse_node>-1){
            backtrack=false;
            cout<<endl;
            traverse_DFS(graph, s_dfs, visited, v_track, vertices, current_node, traverse_node, backtrack);
        }
    }

}

void traverse_DFS_helper(int **graph, vector<int>& v_track, int vertices, int root){
    //init stack, visited array
    stack<int> s_dfs;
    int visited[vertices];
    for(int i=0; i<vertices; i++){
        visited[i] = 0;
    }

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
    cout<<"stack top = "<<s_dfs.top()<<endl;
    cout<<"traverse node= "<<traverse_node<<endl;
    cout<<"track = ";
    for(int i=0; i<v_track.size(); i++){
        cout<<v_track[i]<<" ";
    }
    cout<<endl<<endl;

    traverse_DFS(graph, s_dfs, visited, v_track, vertices, current, traverse_node, false);
}
