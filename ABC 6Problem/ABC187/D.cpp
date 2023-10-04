#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int taka = 0;
    int aoki = 0;
    vector<int> A(n);
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        A[i] = a;
        taka += b;
        aoki += a;
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = n-1; i >= 0; i--){
        cout << taka << " " << aoki << endl;
        if (taka > aoki) break;
        taka += A[i];
        aoki -= A[i];
        ans++;
    }

    cout << ans << endl;
    return 0;
}