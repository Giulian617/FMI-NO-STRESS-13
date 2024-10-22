#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

double randreal(double a, double b) {
    return uniform_real_distribution<double>(a, b)(rng);
}

const int VALMAX = 10000;

int main() {
    int N = randint(1, VALMAX);
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        double x = randreal(0, VALMAX);
        double y = randreal(0, VALMAX);
        double z = randreal(0, VALMAX);
        cout << fixed << setprecision(1) << x << " " << y << " " << z << endl;
    }
    int L = randint(1, 100);
    cout << L << endl;
    for (int i = 0; i < L; i++) {
        double x = randreal(0, VALMAX);
        double y = randreal(0, VALMAX);
        double z = randreal(0, VALMAX);
        double phi = randreal(0, M_PI / 2);
        cout << fixed << setprecision(2) << x << " " << y << " " << z << " ";
        cout << fixed << setprecision(4) << phi << endl;
    }
    return 0;
}
