// Mity
#include<cstdio>

int main()
{
	int N, x, i, d, e, wanted, total=0;

	scanf("%d", &N);
	for(i=0;i<N;++i)
	{
		scanf("%d", &x);
		for(d=2, wanted=0;d*d<=x && wanted!=-1;++d)
		{
			for(e=0;x%d==0;++e, x/=d);
			if(e && wanted && e!=wanted)
				wanted=-1;
			else if(!wanted)
				wanted=e;
		}

		if(wanted>1 && x>1)
			wanted=-1;

		total+=(wanted!=-1);
	}

	printf("%d\n", total*100/N);
	return 0;
}
