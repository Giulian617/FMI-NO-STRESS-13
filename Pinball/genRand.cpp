// Mity
#include"testlib.h"
#include<cstdio>
#include<algorithm>

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	int N=rnd.next(opt<int>("min-N"), opt<int>("max-N"));
	if(N<2)
		N=2;
	long long K=rnd.next(opt<long long>("min-K"), opt<long long>("max-K"));
	int delta=opt<int>("delta");
	int mw=opt<int>("min-W"), Mw=opt<int>("max-W");

	std::vector<int> mp(N);
	int i;
	for(i=0;i<N;++i)
		mp[i]=i+1;
	shuffle(mp.begin(), mp.end());

	printf("%d %lld\n", N, K);
	for(i=1;i<N;++i)
		printf("%d %d %d\n", mp[i], mp[rnd.next(std::max(0, i-delta), i-1)], rnd.next(mw, Mw));

	return 0;
}
