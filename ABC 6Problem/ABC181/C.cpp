#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
vector<pair<int, int>> a;
string ans;
float f(pair<int, int> q, pair<int, int> r){
    return ((float)r.second-(float)q.second)/((float)r.first-(float)q.first);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        int z, x; cin >> z >> x;
        a[i] = {z, x};
    }
    string ans = "No";
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                // cout <<  i << " " << j << " " << k << endl;
                // cout << fabs(f(a[i], a[j])) - fabs(f(a[j], a[k])) << endl;
                if (f(a[i], a[j]) == f(a[j], a[k]))
                    ans = "Yes";
            }
        }
    }
    cout << ans << endl;

    return 0;
}