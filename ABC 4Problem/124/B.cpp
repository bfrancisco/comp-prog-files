#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int high = a[0];
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (a[i] >= high){
            high = a[i];
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}