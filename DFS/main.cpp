#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <map>

#include "dfs.h"

using namespace std;

//global vars

bool is_cycle;


int main()
{
    //soal Bantu Aufa
    cout<<"(DFS) Soal 'Bantu Aufa' \n";
    int N=6;
    int vertices = N;
    int root=0;

    //graph init, graph[x][y] = 0 means x->y is not connected
//    int graph[vertices][vertices];
//    for(int i=0; i<vertices; i++){
//        for(int j=0; j<vertices; j++){
//            graph[i][j] = 0;
//        }
//    }

    int **graph;
    graph = new int *[vertices];
    for(int i = 0; i <vertices; i++)
        graph[i] = new int[vertices];

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    //graph[0][1] = 1, means node 1->2 is connected, for undirected graph, means graph[1][0] = 1 (reverse direction) also
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[1][4] = 1;
    graph[1][5] = 1;

    graph[1][0] = 1;
    graph[2][0] = 1;
    graph[3][0] = 1;
    graph[4][1] = 1;
    graph[5][1] = 1;

    //init gadis
    int n_gadis = 4;
    int gadis[n_gadis];
    gadis[0]=3;
    gadis[1]=4;
    gadis[2]=5;
    gadis[3]=2;

    //print info
    cout<<"Vertices = "<<N<<endl;
    cout<<"Root = "<<root<<endl;
    cout<<"Graph Connections : "<<endl;
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            if(graph[i][j]==1){
                cout<<i<<"-"<<j<<endl;
            }
        }
    }
    //print graph
    cout<<"Graph : "<<endl;
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    //init track
    vector<int> v_track;

    //DFS traverse
    cout<<"DFS Traversal :"<<endl;
    traverse_DFS_helper(graph, v_track, vertices, root);

    //print track
    cout<<"DFS Track on 'Bantu Aufa' problem is : ";
    for(int i=0; i<v_track.size(); i++){
        cout<<v_track[i]<<" ";
    }
    cout<<endl;

    /////////////////////////////////////////////////////////////////////
    cout<<"\n---------------------------------------------------------\n";
    cout<<"Test cyclic graph \n";
    N=5;
    vertices = N;
    root=0;

    graph = new int *[vertices];
    for(int i = 0; i <vertices; i++)
        graph[i] = new int[vertices];

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    graph[1][0] = 1;
    graph[2][0] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[4][3] = 1;

    //print graph
    cout<<"Graph : "<<endl;
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    //init track
    v_track.clear();

    //DFS traverse
    cout<<"DFS Traversal :"<<endl;
    traverse_DFS_helper(graph, v_track, vertices, root);
    cout<<"is_cycle = "<<is_cycle<<endl;
    return 0;
}
