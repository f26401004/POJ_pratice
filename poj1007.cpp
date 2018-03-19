#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		string data;
		map<int, string> time_data;
		int count[m];
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> data;
			count[i] = 0;
			for (int j = 0 ; j < n ; ++j)
				for (int k = j + 1 ; k < n ; ++k)
					if (data[j] > data[k])
						++count[i];
			time_data[count[i]] = data; 
		}
		sort(count, count + m);
		for (int i = 0 ; i < m ; ++i)
			cout << time_data[count[i]] << endl;
	}
	return 0;
}
