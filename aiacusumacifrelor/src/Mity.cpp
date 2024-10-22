// Mity
#include<cstdio>

int main()
{
	int _, ans;
	long long x;

	scanf("%d", &_);
	do
	{
		scanf("%lld", &x);
		switch(x%9)
		{
			case 0:
				ans=0;
			break;

			case 2:
			case 3:
			case 4:
			case 6:
			case 7:
				ans=1;
			break;

			case 1:
			case 5:
			case 8:
				ans=2;
			break;
		}

		printf("%d\n", ans);
	}while(--_);

	return 0;
}
