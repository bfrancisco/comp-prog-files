#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n; i++) cin >> a[i];
    
    int ans = -1, num = -1;
    for (int i = 2; i <= 1000; i++){
        if (i == 1) continue;
        int z = 0;
        for (int j = 0; j < n; j++){
            if (a[j] % i == 0) z++;
        }
        if (ans < z){ans = z; num = i;}
    }
    cout << num << endl;

    return 0;
}