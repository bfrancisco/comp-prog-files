#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int s=0;
    for (int i = 0; i < n; i++){
        if (s + a[i] > k) break;
        s += a[i];
    }
    cout << s << endl;
    return 0;
}