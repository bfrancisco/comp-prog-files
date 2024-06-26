#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void SieveOfEratosthenes(int n, int x)
{
    // Create a boolean array a"prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 11; p <= n; p+=10){
        if (prime[p]){
            cout << p << " ";
            x--;
        }
        if (x == 0) break;
    }
    return;
}


 
int main(){
    int x; cin >> x;
    int limit = 1000000;
    SieveOfEratosthenes(limit, x);
    
    return 0;
}