#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a(n+1);
    for (int i = 0; i < n-1; i++){
        int x; cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= n; i++){
        if (a[i] == 0) {cout << i << endl; return 0;}
    }

    return 0;
}