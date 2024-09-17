// Mity - initial source
// O(N*logM)
#include<cstdio>
#include<queue>

int main()
{
    std::priority_queue<long long, std::vector<long long>, std::greater<long long> > pq;
    int i, N, M, x;

    scanf("%d%d", &N, &M);
    for(i=0;i<N;++i)
    {
        scanf("%d", &x);
        pq.push(x);
    }
    for(;i<M;++i)
    {
        scanf("%d", &x);
        pq.push(x+pq.top());
        pq.pop();
    }
    printf("%lld\n", pq.top());

    return 0;
}
