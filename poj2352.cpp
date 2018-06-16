#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 150005
using namespace std;

int N;
int BIT[MAX];
int level[MAX];


int low_bit(int value)
{
	return value & (-value);
}

int get_sum(int i)
{
	int ans = 0;
	while(i > 0)
	{
		ans += BIT[i];
		i -= low_bit(i);
	}
	return ans;
}

void add(int i, int value)
{
	while(i < MAX)
	{
		BIT[i] += value;
		i += low_bit(i);
	}
}

int main()
{
	int x, y;
	while(~scanf("%d", &N))
	{
		memset(BIT, 0, sizeof(BIT));
		memset(level, 0, sizeof(level));
		for(int i = 0 ; i < N ; ++i)
		{
			scanf("%d%d", &x, &y);
			x++;
			level[get_sum(x)]++;
			add(x, 1);
		}
		for(int i = 0 ; i < N ; ++i)
			cout << level[i] << endl;
	}	
	return 0;
}
