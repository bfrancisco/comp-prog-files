#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int prime[5000001];
int freq[5000001];
set<int> s;
vector<int> b;

void sieve(int n){
    for (auto p : s) {
        if (p == 1) continue;
        prime[p] += freq[p] - 1;
        for (int i = p + p; i <= n; i += p)
            prime[i] += freq[p];
    }
}

int main(){
    int n; cin >> n;
    b.resize(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> b[i];
        s.insert(b[i]);
        freq[b[i]]++;
        mx = max(mx, b[i]);
    }
    
    sieve(mx);

    for (auto x : b){
        if (x == 1) cout << freq[1] - 1 << " ";
        else{
            cout << prime[x] + freq[1] << " ";
        }
    }
    cout << endl;
    return 0;
}