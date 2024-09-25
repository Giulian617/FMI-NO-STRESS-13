// Mity
#include<algorithm>
#include<cassert>
#include<cstdio>
#include<numeric>
#include<vector>
typedef long long ll;
const int PRECIZIE=100, NMAX=300, VALMAX=1000, QMAX=100;

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
		assert(frac<=PRECIZIE);
	}

	return intreg*PRECIZIE+real;
}

typedef void(*PF)(int, int);

void runBetween(pct A, pct B, PF f)
{
	if((A.i==B.i && A.i%PRECIZIE==0) || (A.j==B.j && A.j%PRECIZIE==0))
		return;

	int di=B.i-A.i, dj=B.j-A.j, i, j;
	int dd=std::gcd(di, dj);

	di/=dd;
	dj/=dd;
	frac a(di, dj);
	frac b(A.i*B.j-A.j*B.i, B.j-A.j);

	for(int _=0;_<dd;++_, A=B)
	{
		B.i=A.i+di;
		B.j=A.j+dj;

		if(A.i==B.i)
		{
			while(A.j/PRECIZIE!=B.j/PRECIZIE)
			{
				f(A.i/PRECIZIE, A.j/PRECIZIE);
				A.j+=PRECIZIE;
			}
		}
		else if(A.j==B.j)
		{
			while(A.i/PRECIZIE!=B.i/PRECIZIE)
			{
				f(A.i/PRECIZIE, A.j/PRECIZIE);
				A.i+=PRECIZIE;
			}
		}
		else
		{
			i=A.i/PRECIZIE;
			j=A.j/PRECIZIE;
			f(i, j);
			while(i!=B.i/PRECIZIE || j!=B.j/PRECIZIE)
			{
				/*
				di=B.i-A.i
				dj=B.j-A.j
				aj+b=i

				A.j*a+b=A.i
				B.j*a+b=B.i
				a=(B.i-A.i)/(B.j-A.j)
				b=(A.i*B.j-A.j*B.i)/(B.j-A.j)
				*/

				if(j==B.j/PRECIZIE)
				{
					for(;i!=B.i/PRECIZIE;++i)
						f(i, j);
					A=B;
				}
				else
				{
					frac nextI=a*frac(PRECIZIE)*frac(j+1)+b;
					if(nextI.b!=1)
						nextI.t+=nextI.b;
					int i1=nextI/PRECIZIE;

					for(;i<i1;++i)
						f(i, j);
					++j;
				}
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
		vis[i][j]=0;
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

	return score;
}

int main()
{
	int i, j, Q, _, best;
	ll max=-NMAX*NMAX*(ll)VALMAX, aux;

	scanf("%d", &N);
	M=N;
	assert(N<=NMAX);
	assert(M<=NMAX);
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
		{
			scanf("%d", mat[i]+j);
			assert(std::abs(mat[i][j])<=VALMAX);
		}

	scanf("%d", &Q);
	assert(Q<=QMAX);
	for(_=0;_<Q;++_)
	{
		const pct topRight(N*PRECIZIE, M*PRECIZIE);
		for(F.clear();F.empty() || F.back()!=topRight;)
		{
			i=readDouble();
			j=readDouble();
			F.push_back(pct(i, j));
		}

		aux=getScore();
		// printf("%d->%lld\n", _, aux);
		if(aux>max)
		{
			max=aux;
			best=_;
		}
	}

	printf("%d %lld\n", best, max);
}
