// Mity
#include<cstdio>
const int NMAX=128;

int mat[NMAX][NMAX];

int main()
{
	int N, M, i, j, s, maxSum, minSum, maxLin, minLin;

	scanf("%d%d", &N, &M);
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			scanf("%d", mat[i]+j);

	for(i=0, maxSum=-1, minSum=NMAX*NMAX;i<N;++i)
	{
		for(j=s=0;j<M;++j)
			s+=mat[i][j];
		if(s<minSum)
		{
			minSum=s;
			minLin=i;
		}
		if(s>maxSum)
		{
			maxSum=s;
			maxLin=i;
		}
	}

	printf("%d %d\n", minLin+1, maxLin+1);

	return 0;
}
