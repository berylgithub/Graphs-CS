#ifndef PRIM_H_INCLUDED
#define PRIM_H_INCLUDED
#include <vector>

using namespace std;

int sum_visited(int visited[], int vertices);
vector<vector<int> > MST_prim(int **graph, int vertices);

#endif // PRIM_H_INCLUDED
