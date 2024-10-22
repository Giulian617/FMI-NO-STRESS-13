#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    char cine_joaca;
    cin >> cine_joaca;
    vector<string> tabla(8);
    for(auto &x: tabla)
        cin >> x;
    if(cine_joaca == 'W'){
        reverse(tabla.begin(), tabla.end());
    }
    char cine_sta = 'W' ^ 'B' ^ cine_joaca;
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        if(tabla[1][i] == cine_joaca && tabla[2][i] == '.' && tabla[3][i] == '.'){
            if((i > 0 && tabla[3][i - 1] == cine_sta) || (i < 7 && tabla[3][i + 1] == cine_sta)){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}
