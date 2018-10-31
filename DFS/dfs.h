#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include <iostream>
#include <deque>
#include <stack>
#include <vector>


using namespace std;
void traverse_DFS(int **graph, stack<int>& s_dfs, int visited[], vector<int>& v_track, int vertices, int current_node);
void traverse_DFS_helper(int **graph, stack<int>& s_dfs, int visited[], vector<int>& v_track, int vertices, int root);


#endif // DFS_H_INCLUDED
