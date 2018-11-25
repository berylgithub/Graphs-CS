#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

void floyd_warshall(int **graph, int vertices){
    //floyd warshall algorithm
    for(int k=1; k<=vertices; k++){
        for(int i=1; i<=vertices; i++){
            for(int j=1; j<=vertices; j++){
                cout<<k<<" "<<i<<" "<<j<<" ij="<<graph[i][j]<<" ik+kj="<<(graph[i][k]+graph[k][j])<<" "<<(graph[i][j] > (graph[i][k]+graph[k][j])) <<endl;
                if(graph[i][j] > (graph[i][k]+graph[k][j])){
                    graph[i][j] = (graph[i][k]+graph[k][j]);
                }
            }
        }
    }
}


int main()
{

    //vertices
    int vertices = 4;

    //set limit
    int limit = 99999;

    //initialize graph 2D array
    int **graph;
    graph = new int *[vertices];
    for(int i = 1; i <= vertices; i++)
        graph[i] = new int[vertices];

    //initialize graph
    for(int i=1; i <= vertices; i++){
        for(int j=1; j <= vertices; j++){
            if(i==j){
                graph[i][j] = 0;
            }
            else{
                graph[i][j]=limit;
            }
        }
    }
    graph[1][3]=-2;
    graph[2][1]=4;
    graph[2][3]=3;
    graph[3][4]=2;
    graph[4][2]=-1;

    cout<<"Default Graph :\n";
    for(int i=1; i<=vertices; i++){
        for(int j=1; j<=vertices; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Floyd-Warshall algorithm : \n";
    floyd_warshall(graph, vertices);

    //print graph
    cout<<endl;
    cout<<"Floyd Warshall Graph :\n";
    for(int i=1; i<=vertices; i++){
        for(int j=1; j<=vertices; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
