// Mity
#include<cstdio>
const char ALB='W', NEGRU='B', SPATIU='.';

char mat[16][16];

int main()
{
    int i, cnt=0;
    char player;
    scanf("%c\n", &player);
    for(i=0;i<8;++i)
        fgets(mat[i], 16, stdin);

    for(i=0;i<8;++i)
    {
        if(player==NEGRU && mat[1][i]==NEGRU && mat[2][i]==SPATIU && mat[3][i]==SPATIU && ((i && mat[3][i-1]==ALB) || (i<7 && mat[3][i+1]==ALB)))
            ++cnt;
        if(player==ALB && mat[6][i]==ALB && mat[5][i]==SPATIU && mat[4][i]==SPATIU && ((i && mat[4][i-1]==NEGRU) || (i<7 && mat[4][i+1]==NEGRU)))
            ++cnt;
    }
    printf("%d\n", cnt);
}
