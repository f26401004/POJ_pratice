#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, S;
	cin >> N >> S;
	int cow[N];
	for (int i = 0 ; i < N ; ++i)
		cin >> cow[i];
	sort(cow, cow + N);
	int pair_num = 0;
	int temp = N;
        for (int i = 0 ; i < temp ; ++i)
        {
            for (int j = i + 1; j < temp; ++j)
            {
                if (cow[i] + cow[j] <= S)
                    ++pair_num;
                else
                {
                    temp = j;
                    break;
                }
            }
        }
	cout << pair_num << endl;
	return 0;
}
