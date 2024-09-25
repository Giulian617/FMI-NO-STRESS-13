// Mity
#include<testlib.h>
#include<cstdio>

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	int min_N=opt<int>("min-n");
	int max_N=opt<int>("max-n");
	int min_M=opt<int>("min-m");
	int max_M=opt<int>("max-m");

	int N, M, x, y;
	N=rnd.next(min_N, max_N);
	M=rnd.next(min_M, max_M);

	printf("%d %d\n", N, M);
	while(M--)
	{
		x=rnd.next(1, N);
		do y=rnd.next(1, N); while(x==y);
		printf("%d %d\n", x, y);
	}

	return 0;
}
