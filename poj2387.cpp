#include <iostream>
#include <cstring>
#define INF 20000000
using namespace std;

typedef struct Edge {
	int start;
	int end;
	int cost;
} edge;

int T, N;
int dist[1005];
edge edges[2005];

void Relax(int j, int k, int cost)
{
	if (dist[j] + cost < dist[k])
		dist[k] = dist[j] + cost;
}

void bellmanFord()
{
	for (int i = 0 ; i < 1005 ; ++i)
		dist[i] = INF;
	dist[N-1] = 0;
	for (int i = 0 ; i < N - 1 ; ++i)
		for (int j = 0 ; j < T ; ++j) {
			Relax(edges[j].start, edges[j].end, edges[j].cost);
			Relax(edges[j].end, edges[j].start, edges[j].cost);
		}
}

int main()
{
	cin >> T >> N;
	for (int i = 0 ; i < T ; ++i)
	{
		int n1, n2;
		int c;
		cin >> n1 >> n2 >> c;
		edges[i].start = n1 - 1;
		edges[i].end = n2 - 1;
		edges[i].cost = c;
	}
	bellmanFord();
	cout << dist[0] << endl;
	return 0;
}
