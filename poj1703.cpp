#include <iostream>
#include <cstdio>
using namespace std;

int parent[100005];
int check[100005];

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int X = Find(x);
	int Y = Find(y);
	if (X == Y)
		return;
	parent[X] = Y; 
}


int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 1 ; i <= N ; ++i)
		{
			parent[i] = i;
			check[i] = 0;
		}
		for (int i = 0 ; i < M ; ++i)
		{
			char type;
			int n1, n2;
			scanf(" %c %d %d", &type, &n1, &n2);
			if (type == 'A')
			{
				if (Find(n1) == Find(n2))
					printf("In the same gang.\n");
				else if (Find(n1) == Find(check[n2]))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");

			}
			else if (type == 'D')
			{
				if (check[n1] == 0 && check[n2] == 0)
				{
					check[n1] = n2;
					check[n2] = n1;
				}
				else if (check[n1] == 0)
				{
					check[n1] = n2;
					Union(n1, check[n2]);
				}
				else if (check[n2] == 0)
				{
					check[n2] = n1;
					Union(n2, check[n1]);
				}
				else
				{
					Union(n1, check[n2]);
					Union(n2, check[n1]);
				}
			}
		}
	}
	return 0;
}
