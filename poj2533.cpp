#include <iostream>
#include <algorithm>
using namespace std;


void LIS(int *array, int* length,int n)
{
	for(int i = 0 ; i < n ; ++i)
		length[i] = 1;
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < i ; ++j)
		{
			if (array[j] < array[i])
				length[i] = max(length[i], length[j] + 1);
		}
	}
}

int main()
{
	int N;
	while(cin >> N)
	{
		int array[N];
		for(int i = 0 ; i < N ; ++i)
			cin >> array[i];
		int length[N];
		LIS(array, length, N);
		cout << *max_element(length, length + N) << endl;
	
	}
	return 0;
}
