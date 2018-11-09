#include <iostream>
#include <queue>
#include <vector>
#include "BFS.h"

using namespace std;

int main()
{

    //BFS - example 1
    cout<<"(BFS) Example - 1\n";
    int vertices = 6;
    int root = 0;

    int **graph;
    graph = new int *[vertices];
    for(int i = 0; i <vertices; i++)
        graph[i] = new int[vertices];

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    //undirected graph initialization
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;
    graph[4][5] = 1;

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            if(graph[i][j]==1){
                graph[j][i]=1;
            }
        }
    }

    //print graph
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            if(graph[i][j]==1){
                cout<<i<<" "<<j<<endl;
            }
        }
    }

    vector<int> v_track;
    traverse_BFS_helper(graph, v_track, vertices, root);

    cout<<"BFS Track : ";
    for(int i=0; i<v_track.size(); i++){
        cout<<v_track[i]<<" ";
    }
    cout<<endl;



    return 0;
}
