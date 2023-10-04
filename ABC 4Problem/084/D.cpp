#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool prime[100005];

void SieveOfEratosthenes(int n)
{
    for (int i = 0; i < n; i++){
        prime[i] = true;
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p] == true) {
            
            for (int i = p+p; i <= n; i += p)
                prime[i] = false;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    

    int prefix[100005];
    SieveOfEratosthenes(100000);

    for (int i = 3; i <= 100000; i++){
        prefix[i] = prefix[i-1];
        if (i%2 == 0){
            continue;
        }
        int j = (i+1)/2;
        if (prime[i] && prime[j]){
            prefix[i]++;
        }
    }
    
    // for (int i = 1; i <= 10; i++){
    //     cout << i << ": " << prefix[i] << " " << prime[i] << endl;
    // }

    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;

        cout << prefix[r] - prefix[l-1] << endl; 
    }


    return 0;
}