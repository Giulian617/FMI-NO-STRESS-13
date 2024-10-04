// Ilie "The-Winner" Dumitru
#include"testlib.h"
#include<cstdio>
const int NMAX=1000005;

int N, Q;
char v[NMAX];

int randIdx()
{
	return rnd.next(N);
}

char randPlay()
{
	return "PHF"[rnd.next(3)];
}

void init()
{
	for(int i=0;i<N;++i)
		v[i]=randPlay();
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	N=opt<int>("N");
	Q=opt<int>("Q");

	printf("%d %d\n", N, Q);
	init();
	printf("%s\n", v);
	do
	{
		int i=randIdx();
		char p;
		do
		{
			p=randPlay();
		}while(v[i]==p);
		printf("%d %c\n", i+1, p);
	}while(--Q);

	return 0;
}
