#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define NUM_VERTS 4
#define GET_SIZE(x) sizeof(x) / sizeof(x[0])
#define INF (INT_MAX / 2)

using namespace std;

int main(int argc, char** argv)
{
	// init adjacency matrix
	//
	// note: INF value is half of INT_MAX because once any number is added to INT_MAX, it becomes a 
	// negative value which will show up as a very small value instead of an infinitely large value
	// which breaks the algorithm.
	int r0[] = {  0, 4, 5, INF };
	int r1[] = {  4, 0, 2, INF };
	int r2[] = {  5, 2, 0, 3   };
	int r3[] = { INF, 6, 3, 0  };

	vector< vector<int> > _vGraph(NUM_VERTS, vector<int>(NUM_VERTS, -1));

	_vGraph[0].assign(r0, r0 + GET_SIZE(r0));
	_vGraph[1].assign(r1, r1 + GET_SIZE(r1));
	_vGraph[2].assign(r2, r2 + GET_SIZE(r2));
	_vGraph[3].assign(r3, r3 + GET_SIZE(r3));

	// run floyd-warshall
	for(int k = 0; k < NUM_VERTS; ++k)
	{
		for(int i = 0; i < NUM_VERTS; ++i)
		{
			for(int j = 0; j < NUM_VERTS; ++j)
			{
				// choose the best option between using and not using the k-th vertex for 
				// the path from i to j
				_vGraph[i][j] = min(_vGraph[i][j], _vGraph[i][k] + _vGraph[k][j]);
			}
		}
	}

	cin.get();
	return 0;
}