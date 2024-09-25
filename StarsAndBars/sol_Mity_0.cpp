// Mity
// Atentie, codul urmator este foarte "neobisnuit".
// Avertizam pe cei ce se stiu bolnavi/slabi de inima.
// O(N*L)
#include<cmath>
#include<cstdio>
#include<vector>
typedef long long ll;

struct pct
{
	ll x, y, z;

	pct() : x(), y(), z() {}
	pct(ll x, ll y, ll z) : x(x), y(y), z(z) {}
	auto operator*(pct p) const -> decltype(x*p.x+y*p.y+z*p.z) {return x*p.x+y*p.y+z*p.z;}
	long double len() const {return sqrtl(*this**this);}
	long double operator^(pct p) const {return *this*p/len()/p.len();}
};

struct lantern
{
	pct c;
	ll r;

	bool operator<(pct p) const {return r/sqrtl(c*c+r*r)<=(p^c);}
};

int main()
{
	int L, N, i, j, cnt=0;
	std::vector<lantern> l;
	std::vector<pct> stele;
	std::vector<bool> vis;

	scanf("%d", &N);
	stele.resize(N);
	for(i=0;i<N;++i)
		scanf("%lld%lld%lld", &stele[i].x, &stele[i].y, &stele[i].z);
	scanf("%d", &L);
	l.resize(L);
	for(i=0;i<L;++i)
		scanf("%lld%lld%lld%lld", &l[i].c.x, &l[i].c.y, &l[i].c.z, &l[i].r);

	vis.resize(N);
	for(i=0;i<N;++i)
	{
		for(j=0;j<L && !vis[i];++j)
			if(l[j]<stele[i])
				vis[i]=1;
		cnt+=vis[i];
	}

	printf("%d\n", cnt);
	// Se poate scoate ce urmeaza daca se vrea doar numarul de stele
	for(i=0;i<N;++i)
		if(vis[i])
			printf("%d ", i+1);
	printf("\n");

	return 0;
}
