#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED

#include <queue>
#include <vector>

using namespace std;

void traverse_BFS(int **graph, queue<int>& q, int visited[], vector<int>& v, int vertices, int current_node);
void traverse_BFS_helper(int **graph, vector<int>& v_track, int vertices, int root);


#endif // BFS_H_INCLUDED
