#include <iostream>
#include <deque>
#include <stack>

#include "dfs.h"

using namespace std;

void showdq(deque <int> g)
{
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); it++)
        cout << '\t' << *it;
    cout << '\n';
}

void f1(stack<int>& s){
    s.pop();
    cout<<"f1="<<s.top();
    cout<<endl;

}

void f2(stack<int>& s){
    s.pop();
    cout<<"f2="<<s.top();
    cout<<endl;
}

void traverse_DFS(int **graph, int visited[], int vertices, int current_node, int traverse_node){
    current_node = traverse_node;
    visited[current_node] = 1;
    for(int i=0; i<vertices; i++){
        if(graph[current_node][i]==1){
            if(visited[i]==0){
                traverse_node = i;
                break;
            }
        }
    }



}


//global vars



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

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }

    //init stack & visited array
    int visited[vertices];
    for(int i=0; i<vertices; i++){
        visited[i] = 0;
    }
    stack<int> s_dfs;

    //DFS traverse
    int current = root;
    int traverse_node;
    s_dfs.push(current);
    for(int i=0; i<vertices; i++){
        if(graph[current][i]==1){
            if(visited[i]==0){
                traverse_node=i;
                break;
            }
        }
    }
    cout<<"traverse node "<<traverse_node<<endl;
    cout<<"before "<<graph[vertices-1][vertices-1]<<endl;
    traverse_DFS(graph, visited, vertices, current, traverse_node);
    cout<<"after "<<graph[vertices-1][vertices-1]<<endl;
    return 0;
}
