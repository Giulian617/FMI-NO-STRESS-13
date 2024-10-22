// Mity
#include<algorithm>
#include<cassert>
#include<cstdio>
#include<numeric>
#include<vector>
typedef long long ll;
const int PRECIZIE=100, NMAX=500, VALMAX=5000, QMAX=1000;

struct pct
{
	ll i, j;

	pct(ll i=0, ll j=0) : i(i), j(j) {}

	bool operator!=(pct o) const
	{
		return i!=o.i || j!=o.j;
	}
};

struct frac
{
	ll t, b;

	frac(ll x=0) : t(x), b(1) {}
	frac(ll numarator, ll numitor)
	{
		ll d=std::gcd(numarator, numitor);
		t=numarator/d;
		b=numitor/d;
	}

	operator ll() const
	{
		return t/b;
	}

	frac operator*(frac o) const
	{
		return frac(t*o.t, b*o.b);
	}

	frac operator+(frac o) const
	{
		ll d=std::gcd(b, o.b);
		return frac(o.b/d*t+b/d*o.t, b/d*o.b);
	}
};

int N, M;
int mat[NMAX][NMAX];
bool vis[NMAX][NMAX];
std::vector<pct> F;
ll score;

ll readDouble()
{
	ll intreg=0, real=0, frac=1;
	char c;

	do
	{
		scanf("%c", &c);
	}while(c<'0' || c>'9');

	do
	{
		intreg=intreg*10+c-'0';
		scanf("%c", &c);
	}while(c>='0' && c<='9');

	if(c=='.')
	{
		for(scanf("%c", &c);c>='0' && c<='9' && frac<=PRECIZIE;frac*=10, scanf("%c", &c))
			real+=PRECIZIE/10/frac*(c-'0');
		//assert(frac<=PRECIZIE);
	}

	return intreg*PRECIZIE+real;
}

typedef void(*PF)(int, int);

void orizontal(pct A, pct B, PF f)
{
	if(A.j%PRECIZIE && A.i%PRECIZIE)
		f(A.i/PRECIZIE, A.j/PRECIZIE);
	if(B.j%PRECIZIE && B.i%PRECIZIE)
		f(B.i/PRECIZIE, B.j/PRECIZIE);
	if(A.i%PRECIZIE)
		for(int j=A.j/PRECIZIE+1;j<B.j/PRECIZIE;++j)
			f(A.i/PRECIZIE, j);
}

void vertical(pct A, pct B, PF f)
{
	if(A.i%PRECIZIE && A.j%PRECIZIE)
		f(A.i/PRECIZIE, A.j/PRECIZIE);
	if(B.i%PRECIZIE && B.j%PRECIZIE)
		f(B.i/PRECIZIE, B.j/PRECIZIE);
	if(A.j%PRECIZIE)
		for(int i=A.i/PRECIZIE+1;i<B.i/PRECIZIE;++i)
			f(i, A.j/PRECIZIE);
}

void runBetween(pct A, pct B, PF f)
{
	assert(A.i<=B.i && A.j<=B.j);

	if(A.i==B.i)
		return orizontal(A, B, f);
	if(A.j==B.j)
		return vertical(A, B, f);

	int di=B.i-A.i, dj=B.j-A.j, i, j;
	int dd=std::gcd(di, dj);

	di/=dd;
	dj/=dd;
	frac a(di, dj), b;

	if(di>dj)
		std::swap(a.t, a.b);

	for(int _=0;_<dd;++_, A=B)
	{
		B.i=A.i+di;
		B.j=A.j+dj;

		if(B.i%PRECIZIE && B.j%PRECIZIE)
			f(B.i/PRECIZIE, B.j/PRECIZIE);

		i=A.i/PRECIZIE;
		j=A.j/PRECIZIE;
		f(i, j);

		if(di>dj)
		{
			for(i=A.i/PRECIZIE+1;i<=B.i/PRECIZIE;++i)
			{
				b=a*frac(i*PRECIZIE-A.i, 1);
				j=(A.j*b.b+b.t)/b.b/PRECIZIE;
				if(i!=B.i/PRECIZIE || B.i%PRECIZIE)
					f(i-1, j);
				else
					f(i-1, j-1);
				if(i!=B.i/PRECIZIE || B.i%PRECIZIE)
					f(i, j);
			}
		}
		else
		{
			for(j=A.j/PRECIZIE+1;j<=B.j/PRECIZIE;++j)
			{
				b=a*frac(j*PRECIZIE-A.j, 1);
				i=(A.i*b.b+b.t)/b.b/PRECIZIE;
				if(j!=B.j/PRECIZIE || B.j%PRECIZIE)
					f(i, j-1);
				else
					f(i-1, j-1);
				if(j!=B.j/PRECIZIE || B.j%PRECIZIE)
					f(i, j);
			}
		}
	}
}

void addAnswer(int i, int j)
{
	if(i>-1 && j>-1 && i<N && j<M && !vis[i][j])
	{
		vis[i][j]=1;
		score+=mat[i][j];
	}
}

void clearPath(int i, int j)
{
	if(i>-1 && j>-1 && i<N && j<M)
	{
		// if(vis[i][j])
			// printf("(%d, %d)", i, j);
		vis[i][j]=0;
	}
}

ll getScore()
{
	pct curr;

	score=0;
	for(pct next : F)
	{
		runBetween(curr, next, addAnswer);
		curr=next;
	}

	curr=pct();
	for(pct next : F)
	{
		runBetween(curr, next, clearPath);
		curr=next;
	}
	// printf("\n");

	return score;
}

/*
5 5
2 8 4 8 -1
9 5 3 1 4
10 0 10 6 7
11 -1 7 10 9
5 0 20 -15 8
4
3.8 1.2 4.6 3.66 5 5
1.2 1.7 2.1 3.75 5 5
0.0 4.0 3.0 4.0 3.0 5.0 5 5
3 3 5 5
*/

int main()
{
	int i, j, Q, _, best;
	ll max=-NMAX*NMAX*(ll)VALMAX, aux;

	scanf("%d %d", &N, &M);
	assert(N<=NMAX);
	assert(M<=NMAX);
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
		{
			scanf("%d", mat[N-i-1]+j);
			assert(std::abs(mat[N-i-1][j])<=VALMAX);
		}

	scanf("%d", &Q);
	assert(Q<=QMAX);
	for(_=0;_<Q;++_)
	{
		const pct topRight(M*PRECIZIE, N*PRECIZIE);
		for(F.clear();F.empty() || F.back()!=topRight;)
		{
			j=readDouble();
			i=readDouble();
			F.push_back(pct(i, j));
		}

		if(F.size()==1u)
			printf("PROBLEMA LINIA %d\n", N+_+2);

		aux=getScore();
		// printf("%d->%lld\n", _, aux);
		if(aux>max)
		{
			max=aux;
			best=_ + 1;
		}
	}

	printf("%d %lld\n", best, max);
}
