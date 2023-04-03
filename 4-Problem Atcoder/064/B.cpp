#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int a[101];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cout << a[n-1] - a[0];
    
    return 0;
}   