#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, D;
    cin >> n >> D;
    vector<int> j(n);
    vector<int> pj(n+1);
    vector<int> c(n), canclean(n);
    vector<int> d(D);
    for (int i = 0; i < n; i++){
        cin >> j[i] >> c[i];
    }
    pj[0] = 0;
    for (int i = 1; i < n+1; i++){
        pj[i] = pj[i-1] + j[i-1]; 
    }

    

    for (int i = 0; i < n; i++){
        canclean[i] = min(pj[i+1], c[i]);
    }

    cout << "PJ" << endl;
    for (auto x : pj) cout << x << " ";
    cout << endl;
    cout << "canclean" << endl;
    for (auto x : canclean) cout << x << " ";
    cout << endl;

    for (int i = 0 ; i < D; i++) cin >> d[i];

    int prevdind = 0;
    int ans = 0;
    for (int i = 0; i < D; i++){
        int curjunk = pj[d[i]] - pj[prevdind];
        cout << "curjunk: " << curjunk << endl;
        vector<int> addends; 
        for (int k = d[i]-1; k > prevdind-1; k--){
            addends.push_back(canclean[k]);
        }
        sort(addends.begin(), addends.end(), greater<int>());
        for (int z = 0; z < addends.size(); z++){
            curjunk -= addends[z];
            ans++;
            if (curjunk <= 0) break;
        }
        if (curjunk > 0){
            ans = -1;
            break;
        }
        prevdind = d[i];
        cout << "ans: " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}