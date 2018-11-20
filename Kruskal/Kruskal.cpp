#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include "Kruskal.h"

vector<vector<int> > union_find_algorithm(vector<vector<int> > v_multi_edges, int vertices){
    int edge_counter = 0;
    vector<vector<int> > v_kruskal_edges;
    vector<vector<int> > v_multi_groups;
    cout<<"==Union find algorithm==\n";
    for(int i=0; i<v_multi_edges.size(); i++){
        vector<int> v_edge;
        int source = v_multi_edges[i][1];
        int dest = v_multi_edges[i][2];
        int weight = v_multi_edges[i][0];
        cout<<"s="<<source<<" "<<"d="<<dest<<endl;
        //if the groups are empty, just add it
        if(v_multi_groups.empty()){
            vector<int> v_group;
            v_group.push_back(source);
            v_group.push_back(dest);
            v_multi_groups.push_back(v_group);

            v_edge.push_back(weight);
            v_edge.push_back(source);
            v_edge.push_back(dest);
            v_kruskal_edges.push_back(v_edge);
            edge_counter++;
        }
        else if(edge_counter==(vertices-1)){
            cout<<"edge count = "<<edge_counter<<endl;
            break;
        }
        else{
            //check if edge is already in groups, a single node can ONLY be in a single group
            //if both are found within the same group, then it is a cycle, don't add to final vector;
            //else if both are found in different groups, then it is not a cycle, merge group, add to final vector;
            //else if both are not found in the groups, then create new group, add to final vector;
            //else if only one of them is within a group, add the rest to the same group, add to final vector;
            //-1 means not found
            int idx_s_found = -1;
            int idx_d_found = -1;
            for(int j=0; j<v_multi_groups.size(); j++){
                bool s_found = find(v_multi_groups[j].begin(), v_multi_groups[j].end(), source) != v_multi_groups[j].end();
                bool d_found = find(v_multi_groups[j].begin(), v_multi_groups[j].end(), dest) != v_multi_groups[j].end();
                //set the index of both source and destination
                if(s_found==true){
                    idx_s_found = j;
                }
                if(d_found==true){
                    idx_d_found = j;
                }
            }
            //if idx_s and f = -1, means both not found
            if((idx_s_found == -1) && (idx_d_found==-1)){
                vector<int> v_group;
                v_group.push_back(source);
                v_group.push_back(dest);
                v_multi_groups.push_back(v_group);

                v_edge.push_back(weight);
                v_edge.push_back(source);
                v_edge.push_back(dest);
                v_kruskal_edges.push_back(v_edge);
                edge_counter++;
            }
            //both found at the same group
            else if(idx_s_found==idx_d_found){
                cout<<"Cycle is found !! : "<<source<<" "<<dest<<endl;
            }
            //both found at different group, merge into the group which is found first
            else if((idx_s_found>-1) && (idx_d_found>-1) && (idx_s_found!=idx_d_found)){
                cout<<"Different group !! : "<<source<<" "<<dest<<endl;
                v_multi_groups[idx_s_found].insert(v_multi_groups[idx_s_found].end(), v_multi_groups[idx_d_found].begin(), v_multi_groups[idx_d_found].end());
                v_multi_groups.erase(v_multi_groups.begin() + idx_d_found);

                v_edge.push_back(weight);
                v_edge.push_back(source);
                v_edge.push_back(dest);
                v_kruskal_edges.push_back(v_edge);
                edge_counter++;
            }
            //only found one within the groups either s or d
            else if((idx_s_found>-1)||(idx_d_found>-1)){
                //source is found
                if(idx_s_found>-1){
                    v_multi_groups[idx_s_found].push_back(dest);
                }
                //destination is found
                else if(idx_d_found>-1){
                    v_multi_groups[idx_d_found].push_back(source);
                }
                v_edge.push_back(weight);
                v_edge.push_back(source);
                v_edge.push_back(dest);
                v_kruskal_edges.push_back(v_edge);
                edge_counter++;
            }

        }
        //print groups
        cout<<"formed groups : ";
        for(int j=0; j<v_multi_groups.size(); j++){
            for(int k=0; k<v_multi_groups[j].size(); k++){
                cout<<v_multi_groups[j][k]<<" ";
            }
            cout<<"--";
        }
        cout<<endl;
        cout<<endl;
    }
    return v_kruskal_edges;
}

vector<vector<int> > MST_kruskal(int **graph, int vertices){
    vector<vector<int> > v_multi_lines;
    for(int i=0; i<vertices; i++){
        //line is a pair of <weight, source, dest>
        for(int j=0; j<vertices; j++){
            vector<int> line;
            int arr_pair[3] = {graph[i][j], i, j};
            line.insert(line.end(), arr_pair, arr_pair + 3);
            v_multi_lines.push_back(line);
        }
    }

    //sort the vector
    sort(v_multi_lines.begin(), v_multi_lines.end());

    //filter the 0 weighted edges
    vector<vector<int> > v_multi_edges;
    for(int i=0; i<v_multi_lines.size(); i++){
        if(v_multi_lines[i][0]>0){
            vector<int> v_edge;
            v_edge.push_back(v_multi_lines[i][0]);
            v_edge.push_back(v_multi_lines[i][1]);
            v_edge.push_back(v_multi_lines[i][2]);
            v_multi_edges.push_back(v_edge);
            v_edge.clear();
        }
    }
    v_multi_lines.clear();

    cout<<"After sort & zeros weights filter : \n";
    for(int i=0; i<v_multi_edges.size(); i++){
        cout<<"s="<<v_multi_edges[i][1]<<", d="<<v_multi_edges[i][2]<<", w="<<v_multi_edges[i][0];
        cout<<endl;
    }
    cout<<endl;

    vector<vector<int> > v_kruskal_edges;
    v_kruskal_edges = union_find_algorithm(v_multi_edges, vertices);
    return v_kruskal_edges;
}
