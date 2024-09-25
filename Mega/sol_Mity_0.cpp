// Mity
// O(N*logM)
#include<cstdio>
#include<queue>

int main()
{
	std::priority_queue<long long, std::vector<long long>, std::greater<long long> > pq;
	int i, N, M, x;

	scanf("%d%d", &N, &M);
	if(M>N)
	{
		for(i=0;i<N;++i)
			scanf("%d", &x);
		printf("0\n");
	}
	else
	{
		for(i=0;i<M;++i)
		{
			scanf("%d", &x);
			pq.push(x);
		}
		for(;i<N;++i)
		{
			scanf("%d", &x);
			pq.push(x+pq.top());
			pq.pop();
		}
		printf("%lld\n", pq.top());
	}

	return 0;
}
