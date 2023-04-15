#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int t = 0;
    for (int i = 0; i < n; i++) {cin >> a[i]; t += a[i];}

    double x = 1.0/(4.0*(double)m);
    int c = 0;
    for (auto val : a)
        if (val >= t * x) c++;

    if (c >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}   