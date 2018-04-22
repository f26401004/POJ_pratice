#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2000000
using namespace std;

int cost[105][105];
int dist[105];
int case_num;

void Floyd()
{
	for (int i = 0 ; i < case_num ; ++i)
		for (int j = 0 ; j < case_num ; ++j)
			for (int k = 0 ; k < case_num ; ++k)
				if (cost[j][i] + cost[i][k] < cost[j][k])
					cost[j][k] = cost[j][i] + cost[i][k];
}

void init()
{
	for (int i = 0 ; i < 105 ; ++i)
		for(int j = 0 ; j < 105 ; ++j)
		{
			if (i != j)
				cost[i][j] = INF;
			else
				cost[i][j] = 0;
		}
}

int main()
{
	while(cin >> case_num)
	{
		if (case_num == 0)
			break;
		init();
		for (int i = 0 ; i < case_num ; ++i)
		{
			int pair_num;
			cin >> pair_num;
			for (int j = 0 ; j < pair_num ; ++j)
			{
				int num, t;
				cin >> num >> t;
				cost[i][num-1] = t;
			}
		}
		Floyd();
		int max; 
		vector<int> value;
		for (int i = 0 ; i < case_num ; ++i)
		{
			max = 0;
			for (int j = 0 ; j < case_num ; ++j)
				if (max < cost[i][j])
					max = cost[i][j];
			value.push_back(max);
		}
		if (*min_element(value.begin(), value.end()) >= INF)
			cout << "disjoint" << endl;
		else
			cout << min_element(value.begin(), value.end()) - value.begin() + 1 << " " << *min_element(value.begin(), value.end()) << endl;
	}	
	return 0;
}
