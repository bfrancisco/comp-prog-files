#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    double avg = 0;
    vector<float> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        avg += a[i];
    }
    avg /= n;
    int r = (avg - (int)avg < 0.5 ? (int)avg : (int)(avg) + 1);
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += ((int)a[i] - r)*((int)a[i] - r);
    }
    cout << ans << endl;

    return 0;
}