//Marius
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct Point 
{
    double x, y, z;
};
vector<Point>stele;

bool isStarVisible(const Point& stea, const Point& dir, double psi) 
{
    double cp=stea.x * dir.x + stea.y * dir.y + stea.z * dir.z;
    double steaMag = std::sqrt(stea.x * stea.x + stea.y * stea.y + stea.z * stea.z);
    double dirMag = std::sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    double cosTheta = cp / (steaMag * dirMag);
    double theta = std::acos(cosTheta); 
    return theta < psi;
}

int main() 
{
    int N,L;
    scanf("%d\n",&N);
    for(int i=1;i<=N;i++)
    {
        double x,y,z;
        scanf("%lf %lf %lf\n",&x,&y,&z);
        stele.push_back(Point{x,y,z});
    }
    scanf("%d\n",&L);
    for(int i=1;i<=L&&stele.size()>0;i++)
    {
        Point lan;
        double angle;
        scanf("%lf %lf %lf %lf",&lan.x,&lan.y,&lan.z, &angle);
        vector<Point>temp_stele;
        temp_stele.clear();
        for(int j=0;j<stele.size();j++)
        {
            if(!isStarVisible(stele[j],lan,angle))
                temp_stele.push_back(stele[j]);
        }
        stele=temp_stele;
    }
    printf("%d\n",N-stele.size());
    //for(int i=0;i<stele.size();i++)
   // {
   //   printf("%lf %lf %lf\n",stele[i].x,stele[i].y,stele[i].z);
   // }
    return 0;
}
