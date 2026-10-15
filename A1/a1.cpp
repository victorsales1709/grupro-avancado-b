#include <iostream>
#include <vector>
#include <set>

using namespace std;



int main(){
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int a, n_primes=0;
        cin>>a;
        if(a==1){
            cout<<0<<endl;
        }
        else{ 
            for(long long j=2; j*j<=a; j++){
                if(a%j==0){
                    n_primes++;
                }

                while(a%j==0){
                    a/=j;
                }
            }

            if (a > 1) {
                n_primes++;
            }

            cout<<n_primes<<endl;
        }
    }
}