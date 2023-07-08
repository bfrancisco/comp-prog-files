#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= n; i++){
        if (a[i] != 1) {cout << "No" << endl; return 0;}
    }
    cout << "Yes" << endl;
    return 0;
}