//Stefan

#include <bits/stdc++.h>

using namespace std;

struct Pct{
    long double x, y, z;
    Pct(long double x = 0, long double y = 0, long double z = 0): x(x), y(y), z(z){}
    long double len(){
        return sqrt(x*x + y*y + z*z);
    }
    long double operator*(const Pct &p){
        return x*p.x + y*p.y + z*p.z;
    }
    Pct norm(){
        long double l = len();
        return Pct(x/l, y/l, z/l);
    }
};

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<Pct> v(n);
    for(auto &p : v){
        cin >> p.x >> p.y >> p.z;
        p = p.norm();
    }
    int l;
    cin >> l;
    int ans = 0;
    set<int> can_be_seen;
    for(int i = 0; i < l; i++){
        Pct p;
        long double alpha;
        cin >> p.x >> p.y >> p.z >> alpha;
        p = p.norm();

        for(int j = 0; j < n; j++){
            if(v[j] * p > cos(alpha)){
                can_be_seen.insert(j);
            }
        }
    }
    cout << (int)can_be_seen.size() << "\n";
    return 0;
}
