#include <iostream>
#include <queue>
#include <vector>
#include "BFS.h"


void traverse_BFS(int **graph, queue<int>& q_bfs, int visited[], vector<int>& v_track, int vertices, int current_node){
    if(!q_bfs.empty()){
        if(visited[current_node]==0){
            v_track.push_back(current_node);
        }
        visited[current_node] = 1;
        q_bfs.pop();
        for(int i=0; i<vertices; i++){
            if(graph[current_node][i]==1){
                if(visited[i]==0){
                    q_bfs.push(i);
                }
            }
        }
        //print track
        cout<<"Track : ";
        for(int i=0; i<v_track.size(); i++){
            cout<<v_track[i]<<" ";
        }
        cout<<endl;

        //print visited
        cout<<"Visited : ";
        for(int i=0; i<vertices; i++){
            cout<<visited[i]<<" ";
        }
        cout<<endl;

        //print que
        if(!q_bfs.empty()){
            cout<<"Queue front : "<<q_bfs.front();
        }
        cout<<endl<<endl;
        traverse_BFS(graph, q_bfs, visited, v_track, vertices, q_bfs.front());
    }


}
void traverse_BFS_helper(int **graph, vector<int>& v_track, int vertices, int root){
    queue<int> q_bfs;
    int visited[vertices];
    for(int i=0; i<vertices; i++){
        visited[i]=0;
    }

    int current = root;
    q_bfs.push(current);
    visited[current] = 1;
    v_track.push_back(current);
    for(int i=0; i<vertices; i++){
        if(graph[current][i]==1){
            if(visited[i]==0){
                q_bfs.push(i);
            }
        }
    }
    q_bfs.pop();

    //print track
    cout<<"Track : ";
    for(int i=0; i<v_track.size(); i++){
        cout<<v_track[i]<<" ";
    }
    cout<<endl;

    //print que
    cout<<"Queue front : "<<q_bfs.front();
    cout<<endl<<endl;

    traverse_BFS(graph, q_bfs, visited, v_track, vertices, q_bfs.front());

}
