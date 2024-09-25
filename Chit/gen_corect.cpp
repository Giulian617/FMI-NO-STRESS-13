// Mity
#include<testlib.h>
#include<algorithm>
#include<cmath>
#include<cstdio>

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	int min_N=opt<int>("min-n");
	int max_N=opt<int>("max-n");
	int min_M=opt<int>("min-m");
	int max_M=opt<int>("max-m");
	bool small_cycles=opt<bool>("small-cycles");

	int N, M, len, start, curr, next, i;
	N=rnd.next(min_N, max_N);
	M=rnd.next(min_M, max_M);
	if(M==1)
		++M;

	printf("%d %d\n", N, M);
	while(M)
	{
		if(small_cycles)
			len=std::min(M, rnd.next(1, (int)sqrt(max_M)));
		else
			len=rnd.wnext(1, M, 4);

		if(len==1)
			++len;
		if(len+1==M)
			++len;

		M-=len;
		start=rnd.next(1, N);
		for(curr=start, i=1;i<len;++i)
		{
			do next=rnd.next(1, N); while(next==curr || (i+1==len && next==start));
			printf("%d %d\n", curr, next);
			curr=next;
		}
		printf("%d %d\n", curr, start);
	}

	return 0;
}
