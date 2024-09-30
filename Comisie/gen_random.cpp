// Ilie "The-Winner" Dumitru
#include"testlib.h"
#include<cstdio>

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	int N=opt<int>("N");
	int M=opt<int>("M");
	int maxVal=opt<int>("VMAX");

	int i, j;

	printf("%d %d\n", N, M);
	for(i=0;i<N;++i)
	{
		for(j=0;j<M;++j)
		{
			printf("%d", rnd.next(0, maxVal+1));
			if(j+1!=M)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
