#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n), pa(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {cin >> a[i]; mx += a[i];}
    sort(a.begin(), a.end());
    pa[0] = a[0];
    for (int i = 1; i < n; i++) pa[i] = pa[i-1] + a[i];

    int mid = (mx + 2 - 1) / 2;
    
    while (true){
        int val = (mid >= a[n-1] ? a[n-1] : *lower_bound(a.begin(), a.end(), mid));
        

        mid++;
    }

    // 138
    // 3 5 9 14 15 26 35 79 89

    return 0;
}