#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "Prim.h"

using namespace std;

int sum_visited(int visited[], int vertices){
    int sum=0;
    for(int i=0; i<vertices; i++){
        if(visited[i]==1){
            sum++;
        }
    }
    return sum;

}


vector<vector<int> > MST_prim(int **graph, int vertices){
    //init visited array
    int visited[vertices];
    for(int i=0; i<vertices; i++){
        visited[i]=0;
    }

    //start with arbitrary node
    int start_node = 0;
    vector<int> v_visited_node;
    vector<vector<int> > v_multi_neighbors;
    vector<vector<int> > v_multi_edges;
    //do prim until all of the vertices are visited (minimum spanning tree)
    while(sum_visited(visited, vertices)<(vertices)){
        //if the vector is empty, add starting node & its neighbors
        if(v_visited_node.empty()){
            visited[start_node] = 1;
            v_visited_node.push_back(start_node);
            for(int i=0; i<vertices; i++){
                if(graph[start_node][i]>=1){
                    vector<int> v_neighbor;
                    cout<<"w="<<graph[start_node][i]<<" s="<<start_node<<" d="<<i<<endl;
                    v_neighbor.push_back(graph[start_node][i]);
                    v_neighbor.push_back(start_node);
                    v_neighbor.push_back(i);
                    v_multi_neighbors.push_back(v_neighbor);
                }
            }
            sort(v_multi_neighbors.begin(), v_multi_neighbors.end());

            //push only the destination at index 2 & delete the edge from neighbor vector
            visited[v_multi_neighbors[0][2]] = 1;
            v_visited_node.push_back(v_multi_neighbors[0][2]);

            //print minimum
            cout<<"minimum : s="<<v_multi_neighbors[0][1]<<" d="<<v_multi_neighbors[0][2]<<endl;

            //print visited node
            cout<<"visited node :";
            for(int i=0; i<v_visited_node.size(); i++){
                cout<<v_visited_node[i]<<" ";
            }
            cout<<endl;
            cout<<endl;

            //push the minimum neighbor to final edge vector
            vector<int> v_edge;
            v_edge.push_back(v_multi_neighbors[0][0]);
            v_edge.push_back(v_multi_neighbors[0][1]);
            v_edge.push_back(v_multi_neighbors[0][2]);
            v_multi_edges.push_back(v_edge);

            //clear neighbors
            v_multi_neighbors.clear();
        }
        else{
            //for each visited node, push their neighbors, we must also remove duplicates ((w,s,d) -> (w,d,s))
            for(int i=0; i<v_visited_node.size(); i++){
                for(int j=0; j<vertices; j++){
                    if((graph[v_visited_node[i]][j]>=1) && (visited[j]==0)){
                        vector<int> v_neighbor;
                        cout<<"w="<<graph[v_visited_node[i]][j]<<" s="<<v_visited_node[i]<<" d="<<j<<endl;
                        v_neighbor.push_back(graph[v_visited_node[i]][j]);
                        v_neighbor.push_back(v_visited_node[i]);
                        v_neighbor.push_back(j);
                        v_multi_neighbors.push_back(v_neighbor);
                    }
                }
            }
            sort(v_multi_neighbors.begin(), v_multi_neighbors.end());

            visited[v_multi_neighbors[0][2]] = 1;
            v_visited_node.push_back(v_multi_neighbors[0][2]);

            //print minimum
            cout<<"minimum : s="<<v_multi_neighbors[0][1]<<" d="<<v_multi_neighbors[0][2]<<endl;

            //print visited node
            cout<<"visited node :";
            for(int i=0; i<v_visited_node.size(); i++){
                cout<<v_visited_node[i]<<" ";
            }
            cout<<endl;
            cout<<endl;

            //push the minimum neighbor to final edge vector
            vector<int> v_edge;
            v_edge.push_back(v_multi_neighbors[0][0]);
            v_edge.push_back(v_multi_neighbors[0][1]);
            v_edge.push_back(v_multi_neighbors[0][2]);
            v_multi_edges.push_back(v_edge);

            //clear neighbors
            v_multi_neighbors.clear();
        }
    }
    return v_multi_edges;
}
