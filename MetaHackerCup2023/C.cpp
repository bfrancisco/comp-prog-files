#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(int t){
    int n; cin >> n;
    vector<int> a(2*n-1);
    for (int i = 0; i < 2*n-1; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    unordered_set<int, int> posi;
    for (int i = 0, j = 2*n-2; i < n; i++, j--){
        j = max(n, j);
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);

    return 0;
}