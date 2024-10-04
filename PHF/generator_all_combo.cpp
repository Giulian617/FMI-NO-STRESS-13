// Ilie "The-Winner" Dumitru
#include"testlib.h"
#include<cstdio>

int pow3(int N)
{
	if(N == 0)
		return 1;
	if(N == 1)
		return 3;
	int x = pow3(N >> 1);
	x *= x;
	if(N & 1)
		x *= 3;
	return x;
}

int N;
const char modes[4] = "PHF";
bool inc[15];
int curr[15];

void gray(int step)
{
	if(step == N + 1)
		return;

	int stop = 0, add = -1;

	if(inc[step])
		stop = 2, add = 1;

	while(curr[step] != stop)
	{
		bool print=curr[step]>-1 && curr[step]<3;
		curr[step] += add;
		if(print)
			printf("%d %c\n", step, modes[curr[step]]);
		gray(step + 1);
	}
	curr[step] += add;
	inc[step] = !inc[step];
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);
	int i;

	N=opt<int>("N");

	printf("%d %d\n", N, pow3(N) - 1);
	for(i = 0;i < N;++i)
	{
		printf("P");
		inc[i + 1] = 1;
		curr[i + 1] = -1;
	}
	printf("\n");

	gray(1);

	return 0;
}
