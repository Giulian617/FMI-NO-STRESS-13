// Ilie "The-Winner" Dumitru
#include"testlib.h"
#include<cstdio>
const int NMAX=1000005;

int N, Q;
char v[NMAX];

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);
	N=opt<int>("N");
	Q=opt<int>("Q");
	int maxRep=opt<int>("maxRep");
	int probInc=opt<int>("probInc");

	int i, k, currRep;
	int currPlay=rnd.next(0, 2);
	const char plays[4]="PFH";

	printf("%d %d\n", N, Q);

	for(i=currRep=0;i<N;++i)
	{
		if(currRep==maxRep)
		{
			currPlay=(currPlay+1)%3;
			currRep=0;
		}

		printf("%c", v[i]=plays[currPlay]);
		++currRep;
	}

	printf("\n");

	for(;Q;)
	{
		k=rnd.next(0, N-1);
		while(k && v[k-1]==v[k])
			--k;

		if(k+maxRep<N && v[k+maxRep]==v[k] && k+maxRep*2<N && v[k+maxRep*2]==v[k] && rnd.next(0, 99)<probInc)
		{
			currPlay=(v[k]=='P'?1:(v[k]=='F'?2:0));
			for(i=0;i<maxRep && Q && k+i+maxRep<N;++i)
			{
				// fprintf(stderr, "%d %c %c\n", i+1, v[i], plays[currPlay]);
				v[k+maxRep+i]=plays[currPlay];
				printf("%d %c\n", k+1+maxRep+i, v[k+maxRep+i]);
				--Q;

				if(Q && i+k+maxRep*2<N)
				{
					// fprintf(stderr, "%d\n", 100000-Q);
					v[k+maxRep*2+i]=plays[(currPlay+1)%3];
					printf("%d %c\n", k+1+maxRep*2+i, v[k+maxRep*2+i]);
					--Q;
				}
			}
		}
		else
		{
			currPlay=(v[k]=='P'?2:(v[k]=='F'?0:1));
			for(i=k;i<N && v[i]!=plays[currPlay] && Q;++i, --Q)
			{
				// fprintf(stderr, "%d %c %c\n", i+1, v[i], plays[currPlay]);
				v[i]=plays[currPlay];
				printf("%d %c\n", i+1, plays[currPlay]);
			}
		}
	}

	return 0;
}
