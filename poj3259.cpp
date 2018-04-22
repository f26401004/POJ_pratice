#include <iostream>
#include <cstring>
#define INF 20000000
using namespace std;

typedef struct Edge {
	int start;
	int end;
	int cost;
} edge;

int N, M, W;
int dist[1005];
edge edges[2750];

bool Relax(int j, int k, int cost)
{
	if (dist[j] + cost < dist[k])
	{
		dist[k] = dist[j] + cost;
		return true;
	}
	return false;
}

bool bellmanFord()
{
	for (int i = 0 ; i < 1005 ; ++i)
		dist[i] = INF;
	for (int i = 0 ; i < N - 1 ; ++i)
		for (int j = 0 ; j < M + W ; ++j)
		{
			if (j < M)
			{
				Relax(edges[j].start, edges[j].end, edges[j].cost);
				Relax(edges[j].end, edges[j].start, edges[j].cost);
			}
			else
				Relax(edges[j].start, edges[j].end, edges[j].cost);
		}
	for (int j = 0 ; j < N ; ++j)
		for (int k = 0 ; k < M + W ; ++k)
		{
			if (k < M)
				if (Relax(edges[k].start, edges[k].end, edges[k].cost) || Relax(edges[k].end, edges[k].start, edges[k].cost))
					return true;
			else
				if (Relax(edges[k].start, edges[k].end, edges[k].cost))
					return true;
		}
	return false;

}

int main()
{
	int F;
	cin >> F;
	while(F--)
	{
		cin >> N >> M >> W;
		for (int i = 0 ; i < M + W ; ++i)
		{
			int S, E, T;
			cin >> S >> E >> T;
			edges[i].start = S;
			edges[i].end = E;
			if (i < M)
				edges[i].cost = T;
			else
				edges[i].cost = -T;
		}
		if (bellmanFord())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
