#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "Prim.h"

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
    //vertices
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

    ////////////////////////////////
    //Default Graph
    cout<<"====Default Graph====\n";
    //load graph
    load_graph_from_file(graph, "graph.txt");

    vector<vector<int> > v_multi_edges = MST_prim(graph, vertices);

    //print the final edge vectors
    cout<<"MST edges : \n";
    for(int i=0; i<v_multi_edges.size(); i++){
        cout<<"source="<<v_multi_edges[i][1]<<" destination="<<v_multi_edges[i][2]<<" weight="<<v_multi_edges[i][0]<<endl;
    }

    cout<<endl<<endl;
    //////////////////////////////////
    cout<<"====Graph No.1====\n";
    //Graph No. 1
    //load graph
    load_graph_from_file(graph, "graph1.txt");
    v_multi_edges.clear();
    v_multi_edges = MST_prim(graph, vertices);

    //print the final edge vectors
    cout<<"MST edges : \n";
    for(int i=0; i<v_multi_edges.size(); i++){
        cout<<"source="<<v_multi_edges[i][1]<<" destination="<<v_multi_edges[i][2]<<" weight="<<v_multi_edges[i][0]<<endl;
    }


    cout<<endl<<endl;
    //////////////////////////////////
    //Graph No. 2
    cout<<"====Graph No.2====\n";
    //load graph
    load_graph_from_file(graph, "graph2.txt");
    v_multi_edges.clear();
    v_multi_edges = MST_prim(graph, vertices);

    //print the final edge vectors
    cout<<"MST edges : \n";
    for(int i=0; i<v_multi_edges.size(); i++){
        cout<<"source="<<v_multi_edges[i][1]<<" destination="<<v_multi_edges[i][2]<<" weight="<<v_multi_edges[i][0]<<endl;
    }

    cout<<endl<<endl;
    //////////////////////////////////
    //Graph No. 3
    cout<<"====Graph No.3====\n";
    //load graph
    load_graph_from_file(graph, "graph3.txt");
    v_multi_edges.clear();
    v_multi_edges = MST_prim(graph, vertices);

    //print the final edge vectors
    cout<<"MST edges : \n";
    for(int i=0; i<v_multi_edges.size(); i++){
        cout<<"source="<<v_multi_edges[i][1]<<" destination="<<v_multi_edges[i][2]<<" weight="<<v_multi_edges[i][0]<<endl;
    }
    return 0;
}
