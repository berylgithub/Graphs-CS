#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>

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

int sum_visited(int visited[], int vertices){
    int sum=0;
    for(int i=0; i<vertices; i++){
        if(visited[i]==1){
            sum++;
        }
    }
    return sum;

}


void MST_prim(int **graph){




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

    //load graph
    load_graph_from_file(graph, "graph.txt");

    //init visited array
    int visited[vertices];
    for(int i=0; i<vertices; i++){
        visited[i]=0;
    }


    //do prim algorithm
    //start with arbitrary node
    int start_node = 0;
    vector<int> v_visited_node;
    vector<vector<int> > v_multi_neighbors;
    vector<vector<int> > v_multi_edges;
    //do prim until all of the vertices are visited (minimum spanning tree)
    //int x=0;
    //while(x<=1){
    while(sum_visited(visited, vertices)<=vertices){
        //if the vector is empty, add starting node & its neighbors
        if(v_visited_node.empty()){
            visited[start_node] = 1;
            v_visited_node.push_back(start_node);
            for(int i=0; i<vertices; i++){
                if(graph[start_node][i]>=1){
                    vector<int> v_neighbor;
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
            v_multi_neighbors.erase(v_multi_neighbors.begin() + 0);
        }
        else{
            //for each visited node, push their neighbors, we must also remove duplicates ((w,s,d) -> (w,d,s))
            for(int i=0; i<v_visited_node.size(); i++){
                for(int j=0; j<vertices; j++){
                    if(graph[i][j]>=1){
                        vector<int> v_neighbor;
//                        bool s_found = find(v_multi_groups[j].begin(), v_multi_groups[j].end(), source) != v_multi_groups[j].end();
//                        bool d_found = find(v_multi_groups[j].begin(), v_multi_groups[j].end(), dest) != v_multi_groups[j].end();
//                        if(graph[])
                        v_neighbor.push_back(graph[i][j]);
                        v_neighbor.push_back(i);
                        v_neighbor.push_back(j);
                        v_multi_neighbors.push_back(v_neighbor);
                    }
                }
            }
            sort(v_multi_neighbors.begin(), v_multi_neighbors.end());
            //visited[]

        }




        //x++;

    }

    for(int i=0; i<v_multi_neighbors.size(); i++){
        for(int j=0; j<v_multi_neighbors[i].size(); j++){
            cout<<v_multi_neighbors[i][j]<<" ";
        }
        cout<<"--";
    }

    return 0;
}
