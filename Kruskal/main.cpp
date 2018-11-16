#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
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
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            cout<<"source = "<<i<<", dest="<<j<<", weight = "<<graph[i][j]<<endl;
        }
    }

    vector<vector<int> > v_multi_lines;
    for(int i=0; i<vertices; i++){
        //line is a pair of <weight, source, dest>
        vector<int> line;
        for(int j=0; j<vertices; j++){
            cout<<graph[i][j]<<" "<<i<<" "<<j<<endl;
            int arr_pair[3] = {graph[i][j], i, j};
            line.insert(line.end(), arr_pair, arr_pair + 3);
        }
        v_multi_lines.push_back(line);
    }

    cout<<v_multi_lines[0].size();


//    cout<<"before sort :\n";
//    for(int i=0; i<v_multi_lines.size(); i++){
//        cout<<"s="<<v_multi_lines[i][1]<<", d="<<v_multi_lines[i][2]<<", w="<<v_multi_lines[i][0];
//        cout<<endl;
//    }

//    sort(v_multi_lines.begin(), v_multi_lines.end());
//    cout<<"after sort :\n";
//    for(int i=0; i<v_multi_lines.size(); i++){
//        cout<<"s="<<v_multi_lines[i][1]<<", d="<<v_multi_lines[i][2]<<", w="<<v_multi_lines[i][0];
//        cout<<endl;
//    }

    return 0;
}
