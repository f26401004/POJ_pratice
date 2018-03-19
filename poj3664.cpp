#include <cstdio>
#include <algorithm>
using namespace std;

struct cow
{
	int A;
	int B;
	int id;
};

bool compare(struct cow a, struct cow b)
{
	return a.A > b.A;
}

bool compare2(struct cow a, struct cow b)
{
	return a.B > b.B;
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	struct cow cow_data[N];
	for (int i = 0 ; i < N ; ++i)
	{
		scanf("%d%d", &cow_data[i].A, &cow_data[i].B);
		cow_data[i].id = i + 1;
	}
	sort(cow_data, cow_data + N, compare);
	sort(cow_data, cow_data + K, compare2);
	printf("%d\n", cow_data[0].id);
}
