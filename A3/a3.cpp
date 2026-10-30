#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    long long px = 0, py = 1;
    long long p = b, g = a;
    x = 1; y = 0;
    
    while (p) {
        long long q = g / p;
        
        long long n_x = x - px * q;
        long long n_y = y - py * q;
        x = px; px = n_x;
        y = py; py = n_y;
        
        long long n_p = g % p;
        g = p;
        p = n_p;
    }
    return g;
}

int main(){
    long long a, b, n;
    cin >> a >> b >> n;

    long long x0, y0;
    long long g = ext_gcd(a, b, x0, y0); 
    if (n % g != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long x_b = x0 * (n / g); 
    long long y_b = y0 * (n / g); 

    long long s_x = b / g;
    long long s_y = a / g;

    double min_k_double = (double)(-x_b) / s_x;
    long long k_min = ceil(min_k_double);

    double max_k_double = (double)(y_b) / s_y;
    long long k_max = floor(max_k_double);

    if (k_min <= k_max) {
        cout << (k_max - k_min + 1) << endl;
    } else {
        cout << 0 << endl;
    }
}