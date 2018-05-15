#include <iostream>
#include <cstring>
#define INF 2000000
using namespace std;

int N;
int adjacent[105][105];
int dist[105];
bool visited[105];
int cost;

void prim()
{
	memset(visited, false, sizeof(visited));
	cost = 0;
	for(int i = 0 ; i < 105 ; ++i)
		dist[i] = INF;
	dist[0] = 0;
	for(int i = 0 ; i < N ; ++i)
	{
		int min_index;
		int min_value = INF;
		for(int j = 0 ; j < N ; ++j)
		{
			if (min_value > dist[j] && !visited[j])
			{
				min_index = j;
				min_value = dist[j];
			}
		}
		visited[min_index] = true;
		cost = cost + min_value;
		for(int j = 0 ; j < N ; ++j)
		{
			if (dist[j] > adjacent[min_index][j] && !visited[j])
				dist[j] = adjacent[min_index][j];
		}
	}
}

int main()
{
	while(cin >> N)
	{
		if (N == 0)
			break;
		for(int i = 0 ; i < N ; ++i)
			for(int j = 0 ; j < N ; ++j)
				cin >> adjacent[i][j];
		
		prim();
		cout << cost << endl;
	}	
	return 0;
}
