#include <iostream>
#include <vector>

using namespace std;

int max_a=1000000;

vector<int> prime_factors(max_a+1, 0);

void factor_count_sieve(){
    for (int i = 2; i <= max_a; i++) {
        if (prime_factors[i] == 0) {
            for (int j = i; j <= max_a; j += i) {
                prime_factors[j]++;
            }
        }
    }
}

int main(){
    factor_count_sieve();
    int q;
    
    cin>>q;
    for(int i=0; i<q; i++){
        int a, n_primes=0;
        cin>>a;
        if(a==1){
            cout<<0<<endl;
        }
        else{ 
            cout<<prime_factors[a]<<endl;
        }
    }
}