// Mity
// O(Q*32)
#include<cstdio>
#include<cstdlib>
#define assert(cond, msg) do if(!(cond)) { printf("%s", msg); abort(); } while(0)

struct net
{
	unsigned int mask;
	int sz;

	net() : mask(0), sz(0) {}
	net(const char* ip) : mask(0)
	{
		int i;
		unsigned int x;

		for(i=3;i>-1;--i)
		{
			for(x=0;*ip>='0' && *ip<='9';++ip)
				x=x*10+*ip-'0';
			mask|=x<<(i<<3);
			++ip;
		}
		if(ip[-1]!='/')
			return;
		for(sz=0;*ip>='0' && *ip<='9';++ip)
			sz=sz*10+*ip-'0';

		assert(sz<31, "Subnet size prea mare. Ar trebui sa fie cel mult 30");
		sz=32-sz;
	}
};

struct trie
{
	bool isNet;
	trie* next[2];

	trie() : isNet(0)
	{
		next[0]=next[1]=0;
	}
	~trie()
	{
		delete next[0];
		delete next[1];
	}
};

void insert(trie*& T, net N, int bit=31)
{
	if(T==0)
		T=new trie();

	assert(!T->isNet, "Una dintre retele e o subretea a unei retele");

	if(bit<N.sz)
		T->isNet=1;
	else
		insert(T->next[(bool)(N.mask&(1u<<bit))], N, bit-1);
}

void erase(trie*& T, net N, int bit=31)
{
	if(T->isNet)
	{
		delete T;
		T=0;
	}
	else
	{
		erase(T->next[(bool)(N.mask&(1u<<bit))], N, bit-1);
		if(!T->isNet && !T->next[0] && !T->next[1])
		{
			delete T;
			T=0;
		}
	}
}

bool query(trie* T, net N, int bit=31)
{
	if(!T)
		return 0;
	if(T->isNet)
		return 1;
	return query(T->next[(bool)(N.mask&(1u<<bit))], N, bit-1);
}

const int BUFSZ=32;
char ip[BUFSZ];

int main()
{
	trie* T=0;
	int _;

	scanf("%d", &_);
	fgets(ip, BUFSZ, stdin);
	do
	{
		fgets(ip, BUFSZ, stdin);
		if(ip[0]=='I')
			insert(T, net(ip+2));
		else if(ip[0]=='R')
			erase(T,  net(ip+2));
		else if(ip[0]=='Q')
			printf("%c\n", "NY"[query(T, net(ip+2))]);
		else
		{
			printf("Operatie nedefinita.\n");
			abort();
		}
	}while(--_);

	return 0;
}
