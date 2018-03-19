#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N;
	int database[N];
	for (int i = 0 ; i < N ; ++i)
		cin >> database[i];
	sort(database, database + N);
	char temp[16];
	cin >> temp;
	cin >> K;
	int query[K];
	for (int i = 0 ; i < K ; ++i)
		cin >> query[i];
	for (int i = 0 ; i < K ; ++i)
		cout << database[query[i] - 1] << endl;
	return 0;
}
