#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    long long x=1, y=0; 
    long long px=0, py=1;
    long long p=b;
    long long g=a;
    
    while(p){
        long long q = g/p;
        
        long long n_x = x-px*q;
        long long n_y = y-py*q;
        x = px; px = n_x;
        y = py; py = n_y;
        
        long long n_p = g%p;
        g = p;
        p = n_p;
    }
    return g;
}

int main(){
    int n;
    vector<long long> a(n);

    cin>>n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long ans=0;

    for (int i=0; i<n/2; i++) {
        long long diff = abs(a[i]-a[n-1-i]);
        ans = gcd(ans, diff);
    }

    cout<<ans<<endl;
}