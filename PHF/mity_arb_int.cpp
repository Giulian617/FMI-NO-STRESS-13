// Ilie "The-Winner" Dumitru
#include<cstdio>
#include<algorithm>
const int NMAX = 1000005;

struct fct
{
	char P, H, F;

	fct(char P = 'P', char H = 'H', char F = 'F') : P(P), H(H), F(F) {}

	char operator()(char x)
	{
		if(x == 'P')
			return P;
		if(x == 'H')
			return H;
		return F;
	}

	// Compunere, nu am gasit un operator mai apropiat de un cerc
	friend fct operator*(fct f, fct g)
	{
		return fct(f(g.P), f(g.H), f(g.F));
	}
};

fct P = fct('P', 'H', 'P'), H = fct('H'), F = fct('P', 'F');

fct Func(char c)
{
	return (c == 'P' ? P : (c == 'H' ? H : F));
}

struct segTree
{
	int N;
	fct v[NMAX << 1];

	void init(int _N, char* _v)
	{
		N = _N;
		init(0, 0, N - 1, _v);
	}
	void init(int node, int l, int r, char* _v)
	{
		if(l == r)
			v[node] = Func(_v[l]);
		else
		{
			int mid = l + ((r - l) >> 1);

			init(node + 1, l, mid, _v);
			init(node + (mid - l) * 2 + 2, mid + 1, r, _v);

			v[node] = v[node + 1] * v[node + (mid - l) * 2 + 2];
		}
	}

	void update(int pos, fct f)
	{
		update(0, 0, N - 1, pos, f);
	}
	void update(int node, int l, int r, int pos, fct f)
	{
		if(l == r)
			v[node] = f;
		else
		{
			int mid = l + ((r - l) >> 1);

			if(pos <= mid)
				update(node + 1, l, mid, pos, f);
			else
				update(node + (mid - l) * 2 + 2, mid + 1, r, pos, f);

			v[node] = v[node + 1] * v[node + (mid - l) * 2 + 2];
		}
	}

	fct query()
	{
		return v[0];
	}
};

int N;
char s[NMAX];
segTree S;

int main()
{
	int i, x, _;
	char last;

	scanf("%d%d", &N, &_);
	fgets(s, NMAX, stdin);
	fgets(s, NMAX, stdin);
	for(i = 0;i < N - 1 - i;++i)
		std::swap(s[i], s[N - 1 - i]);
	last = s[N];
	S.init(N - 1, s);

	printf("%c", S.query()(last));
	do
	{
		fgets(s, NMAX, stdin);
		for(i = x = 0;s[i] != ' ';++i)
			x = x * 10 + s[i] - '0';
		++i;

		if(x == 1)
			last = s[i];
		else
			S.update(N - x, Func(s[i]));
		printf("%c", S.query()(last));
	}while(--_);

	return 0;
}
