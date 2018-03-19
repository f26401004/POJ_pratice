#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	long long int sum = 0;
	cin >> N;
	long long int loc[N];
	for (int i = 0 ; i < N ; ++i)
		cin >> loc[i];
	sort(loc, loc + N);
	for (int i = 0 ; i < N ; ++i)
		sum += (loc[i + 1] - loc[i]) * (N - i - 1) * (i + 1);
	cout << sum * 2 << endl;
	return 1;
}
