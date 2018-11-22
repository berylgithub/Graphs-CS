#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED
#include <vector>

using namespace std;
vector<vector<int> > union_find_algorithm(vector<vector<int> > v_doublet, int vertices);
vector<vector<int> > MST_kruskal(int **graph, int vertices);



#endif // KRUSKAL_H_INCLUDED
