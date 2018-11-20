#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include "Kruskal.h"

using namespace std;


void load_graph_from_file(int **graph, string file_name){
    string line;
    ifstream myfile (file_name);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            int source = (int)line[0]-48;
            int destination = (int)line[2]-48;
            int weight;
            if(line.length()<=5){
                weight = (int)line[4]-48;
            }
            else{
                stringstream caster(line.substr(4, 2));
                caster >> weight;
            }
            graph[source][destination] = weight;
        }
        myfile.close();
    }
}



int main()
{
    //jumlah vertices
    int vertices = 9;

    //initialize graph 2D array
    int **graph;
    graph = new int *[vertices];
    for(int i = 0; i <vertices; i++)
        graph[i] = new int[vertices];

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    //assign graph with values from file
    load_graph_from_file(graph, "graph.txt");

    //print graph
    cout<<"Default Graph : \n";
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            cout<<"source = "<<i<<", dest="<<j<<", weight = "<<graph[i][j]<<endl;
        }
    }
    cout<<endl;



    //init kruskal final graph, optional (only if the edges are returned back to the graph)
    int **kruskal_graph;
    kruskal_graph = new int *[vertices];
    for(int i = 0; i <vertices; i++)
        kruskal_graph[i] = new int[vertices];

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            kruskal_graph[i][j] = 0;
        }
    }

    vector<vector<int> >v_kruskal_edges = MST_kruskal(graph, vertices);

    //print final edge vector
    cout<<"\n==MST edges from Kruskal Algorithm==\n";
    for(int i=0; i<v_kruskal_edges.size(); i++){
        cout<<"source="<<v_kruskal_edges[i][1]<<" dest="<<v_kruskal_edges[i][2]<<" weight="<<v_kruskal_edges[i][0]<<endl;
    }


    //print graph
//    cout<<"Kruskal Graph :\n";
//    for(int i=0; i<vertices; i++){
//        for(int j=0; j<vertices; j++){
//            cout<<"source = "<<i<<", dest="<<j<<", weight = "<<kruskal_graph[i][j]<<endl;
//        }
//    }


    return 0;
}
