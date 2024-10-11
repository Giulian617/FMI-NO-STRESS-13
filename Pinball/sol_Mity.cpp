// Mity
// O(N*N*N*logK)
#include<cstdio>
#include<vector>
const int NMAX=105;
const int MOD=1000000007;
typedef long long ll;

struct mint
{
	int x;

	mint() : x(0) {}
	mint(int x) : x(x-MOD*(x>=MOD)+MOD*(x<0)) {}

	mint exp(int e) const
	{
		if(e<0)
			return inv().exp(-e);
		if(e==0)
			return 1;
		if(e==1)
			return *this;

		mint y=exp(e/2);
		y=y*y;
		if(e%2)
			y=y**this;
		return y;
	}

	mint inv() const
	{
		return exp(MOD-2);
	}

	mint operator+(mint o) const
	{
		return x+o.x;
	}

	friend mint operator+(int x, mint m)
	{
		return mint(x)+m;
	}

	mint operator-(mint o) const
	{
		return x-o.x;
	}

	friend mint operator-(int x, mint m)
	{
		return mint(x)-m;
	}

	mint operator*(mint o) const
	{
		return x*(ll)o.x%MOD;
	}

	friend mint operator*(int x, mint m)
	{
		return mint(x)*m;
	}

	mint operator/(mint o) const
	{
		return *this*o.inv();
	}

	friend mint operator/(int x, mint m)
	{
		return mint(x)/m;
	}

	operator int() const
	{
		return x;
	}

	mint& operator+=(mint o)
	{
		x+=o.x;
		if(x>=MOD)
			x-=MOD;
		return *this;
	}
};

int N;

struct mat
{
	mint m[NMAX][NMAX];

	mat() : m()
	{
		int i, j;

		for(i=0;i<NMAX;++i)
			for(j=0;j<NMAX;++j)
				m[i][i].x=0;
	}

	mat operator*(const mat& o) const
	{
		mat a;
		int i, j, k;

		for(i=0;i<N;++i)
			for(k=0;k<N;++k)
				for(j=0;j<N;++j)
					a.m[i][j]+=m[i][k]*o.m[k][j];

		return a;
	}
};

struct edge
{
	int u, w;
};

std::vector<edge> G[NMAX];

void dfs(int node, mint prob, int tt, mint* save, int started)
{
	if(G[node].size()==1u && started!=node)
	{
		save[node]=prob;
		return;
	}

	mint total;
	for(edge e : G[node])
		if(e.u!=tt)
			total+=e.w;
	total=total.inv();
	for(edge e : G[node])
		if(e.u!=tt)
			dfs(e.u, prob*mint(e.w)*total, node, save, started);
}

ll K;
mat tranz;
mat ans;

mat fastExp(ll pow)
{
	if(pow==1)
		return tranz;
	ans=fastExp(pow/2);
	ans=ans*ans;
	if(pow%2)
		return ans*tranz;
	return ans;
}

int main()
{
	int i, a, b, w;

	scanf("%d%lld", &N, &K);
	for(i=1;i<N;++i)
	{
		scanf("%d%d%d", &a, &b, &w);
		G[--a].push_back({--b, w});
		G[b].push_back({a, w});
	}

	for(i=0;i<N;++i)
		if(i==0 || G[i].size()==1u)
			dfs(i, 1, -1, tranz.m[i], i);

	// for(i=0;i<N;++i)
	// {
		// for(int j=0;j<N;++j)
			// fprintf(stderr, "%d ", tranz.m[i][j].x);
		// fprintf(stderr, "\n");
	// }

	ans=fastExp(K+1);

	for(i=0;i<N;++i)
		if(G[i].size()==1u)
			printf("%d\n", ans.m[0][i].x);

	return 0;
}
