// Mity
// O(N+M)
#include<cstdio>
const int NMAX=100005;

int deg[NMAX];

int main()
{
	int N, i, a, b;

	scanf("%d%d", &N, &i);
	while(i--)
	{
		scanf("%d%d", &a, &b);
		++deg[--a];
		--deg[--b];
	}

	for(i=0;i<N;++i)
		if(deg[i])
			i=N;
	if(i==N)
		printf("Chit\n");
	else
		printf("Datorii\n");

	return 0;
}
