#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int num;
	vector<int> data;
	cin >> num;
	int target;
	for (int i = 0 ; i < num ; ++i)
	{
		cin >> target;
		data.push_back(target);	
	}
	sort(data.begin(), data.end());
	if (num % 2 == 0)
		cout << (data[num / 2] + data[num / 2 + 1]) / 2 << endl;
	else
		cout << data[num / 2] << endl;

	return 0;
}
