#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 2000000
using namespace std;

typedef struct Node {
	int val;
	int max_value;
	int min_value;
	int left, right;
} node;


int N, Q;
int data[50005 * 5];
node tree[50005 * 5];

void build(int current, int left, int right)
{
	tree[current].left = left;
	tree[current].right = right;
	if (left == right) 
	{
		tree[current].val = tree[current].max_value = tree[current].min_value = data[left - 1];
		return;
	}
	int mid = (left + right) >> 1;
	build(current * 2, left, mid);
	build(current * 2 + 1, mid + 1, right);
	tree[current].max_value = max(tree[current * 2].max_value, tree[current * 2 + 1].max_value);
	tree[current].min_value = min(tree[current * 2].min_value, tree[current * 2 + 1].min_value);
}

int query_max(int current, int left, int right, int bx, int by)
{
	if (left < bx || right > by)
		return 0;
	if (tree[current].left == left && tree[current].right == right)
		return tree[current].max_value;
	int mid = (tree[current].left + tree[current].right) >> 1;
	if (left > mid)
		return query_max(current * 2 + 1, left, right, bx, by);
	else if (right <= mid)
		return query_max(current * 2, left, right, bx, by);
	return max(query_max(current * 2, left, mid, bx, by), query_max(current * 2 + 1, mid + 1, right, bx, by));
}

int query_min(int current, int left, int right, int bx, int by)
{
	if (left < bx || right > by)
		return 0;
	if (tree[current].left == left && tree[current].right == right)
		return tree[current].min_value;
	int mid = (tree[current].left + tree[current].right) >> 1;
	if (left > mid)
		return query_min(current * 2 + 1, left, right, bx, by);
	else if (right <= mid)
		return query_min(current * 2, left, right, bx, by);
	return min(query_min(current * 2, left, mid, bx, by), query_min(current * 2 + 1, mid + 1, right, bx, by));
}

int main()
{
	while(~scanf("%d%d", &N, &Q)) 
	{
		memset(tree, 0, sizeof(tree));
		for(int i = 0 ; i < N ; ++i)
			scanf("%d", &data[i]);	
		build(1, 1, N);
		for(int i = 0 ; i < Q ; ++i)
		{
			int left, right;
			scanf("%d%d", &left, &right);
			int max_value = query_max(1, left, right, 1, N);
			int min_value = query_min(1, left, right, 1, N);
			printf("%d\n", max_value - min_value);
		}
	}
	return 0;
}
