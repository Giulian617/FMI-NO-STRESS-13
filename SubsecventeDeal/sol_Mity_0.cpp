// Mity
// O(N)
#include<cstdio>
const int NMAX=100005;

int p[NMAX];

int main()
{
	int i, N, j;
	long long ans=1;

	scanf("%d", &N);
	for(i=0;i<N;++i)
		scanf("%d", p+i);

	for(i=0;i<N-1;i=j)
	{
		for(j=i;j<N-1 && p[j+1]>p[j];++j);
		for(;j<N-1 && p[j+1]<p[j];++j);
		ans+=(j-i+2LL)*(long long)(j-i+1LL)/2-1;
	}

	printf("%lld\n", ans);
	return 0;
}
