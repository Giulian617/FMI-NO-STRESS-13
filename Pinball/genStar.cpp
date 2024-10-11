// Mity
#include"testlib.h"
#include<cstdio>

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	int N=rnd.next(opt<int>("min-N"), opt<int>("max-N"));
	if(N<2)
		N=2;
	long long K=rnd.next(opt<long long>("min-K"), opt<long long>("max-K"));
	bool root1=opt<bool>("root1");
	int mw=opt<int>("min-W"), Mw=opt<int>("max-W");

	std::vector<int> mp(N);
	int i;
	for(i=0;i<N;++i)
		mp[i]=i;
	shuffle(mp.begin(), mp.end());

	if(root1)
	{
		if(mp[0])
		{
			for(i=1;i<N && mp[i];++i);
			std::swap(mp[0], mp[i]);
		}
	}
	else if(!mp[0])
	{
		i=rnd.next(1, N-1);
		mp[0]=mp[i];
		mp[i]=0;
	}

	for(i=0;i<N;++i)
		++mp[i];

	printf("%d %lld\n", N, K);
	for(i=1;i<N;++i)
		if(rnd.next(2)==0)
			printf("%d %d %d\n", mp[i], mp[0], rnd.next(mw, Mw));
		else
			printf("%d %d %d\n", mp[0], mp[i], rnd.next(mw, Mw));

	return 0;
}
