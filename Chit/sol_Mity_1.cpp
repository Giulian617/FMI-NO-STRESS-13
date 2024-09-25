// Mity
// O(N+M)
#include<cstdio>
const int NMAX=100005;

struct node
{
	int x;
	node* next;

	node() : x(0), next(0) {}
	node(int x, node* next) : x(x), next(next) {}
	~node()
	{
		delete next;
	}
};

void insert(node*& head, int x)
{
	head=new node(x, head);
}

void remove(node*& head)
{
	node* n=head;
	head=head->next;
	n->next=0;
	delete n;
}

node* adj[NMAX];

void comprima(int start)
{
	int x;

	while(adj[start])
	{
		x=adj[start]->x;
		if(!adj[x])
			return;
		if(adj[x]->x!=start)
			adj[start]->x=adj[x]->x;
		else
			remove(adj[start]);
		remove(adj[x]);
	}
}

int main()
{
	int N, i, a, b;

	scanf("%d%d", &N, &i);
	while(i--)
	{
		scanf("%d%d", &a, &b);
		insert(adj[--a], --b);
	}

	for(i=0;i<N;++i)
	{
		comprima(i);
		if(adj[i])
			for(;i<N;++i)
				delete adj[i];
	}
	if(i==N)
		printf("Chit\n");
	else
		printf("Datorii\n");

	return 0;
}
