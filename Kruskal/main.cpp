#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "../DFS/dfs.h"


using namespace std;

bool is_cycle;

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
                //weight = (int)line.substr(4, 2);
            }
            graph[source][destination] = weight;
        }
        myfile.close();
    }
}


int main()
{
    int vertices = 9;

    int **graph;
    graph = new int *[vertices];
    for(int i = 0; i <vertices; i++)
        graph[i] = new int[vertices];

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    load_graph_from_file(graph, "graph.txt");

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            cout<<"source = "<<i<<", dest="<<j<<", weight = "<<graph[i][j]<<endl;
        }
    }

    return 0;
}
