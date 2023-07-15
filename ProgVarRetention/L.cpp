#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n;i++) cin >> a[i];

    
    vector<vector<int>> out;
    out.push_back({a[0]});

    for (int i = 1; i < n; i++){
        int d = a[i];
        int l = 0, r = out.size();
        while (r-l > 1){
            int m = (l+r)/2;
            if (d > out[m].back()) r = m;
            else l = m;
        }

        if (out[l].back() < d) out[l].push_back(d);
        else if (r == out.size()){
            out.push_back({d});
        }
        else if (out[r].back() < d) out[r].push_back(d);
    
    }

    cout << out.size() << endl;
    for (int r = 0; r < out.size(); r++){
        for (int c = 0; c < out[r].size(); c++){
            cout << out[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}