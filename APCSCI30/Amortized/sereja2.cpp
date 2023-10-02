#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> qs;
    map<int, int> bmap;
    for (int i = 0; i < m; i++){
        if (bmap.find(b[i]) == bmap.end())
            bmap[b[i]] = 1;
        else
            bmap[b[i]]++;
    }

    for (int pad = 0; pad < p; pad++){
        if ((ll)pad + (m-1)*p >= n) continue;
        // cout << "pad: " << pad << endl;
        map<int, int> curmap;
        int count = 0; // # of connections
        
        for (auto& [k, v] : bmap)
            curmap[k] = 0;
        // preprocess first m elements
        for (int i = pad; i < pad + m*p; i += p){
            if (bmap.find(a[i]) != bmap.end()){
                curmap[a[i]]++;
                if (bmap[a[i]] == curmap[a[i]]){
                    count++;
                }
            }
        }
        if (count == bmap.size()) qs.push_back(pad+1);
        
        // cout << "\tcount : " << count << endl;
        // cout << "curmap" << endl;
        // for (auto& [k, v] : curmap){
        //     cout << k << " : " << v << endl;
        // }

        // slide
        for (int i = pad, j = pad+m*p; j < n; i += p, j += p){
            // cout << "\ti : " << i+1 << endl;
            // addright
            if (bmap.find(a[j]) != bmap.end()){
                curmap[a[j]]++;
                if (bmap[a[j]] == curmap[a[j]]){
                    count++;
                }
            }
            // popleft
            if (bmap.find(a[i]) != bmap.end()){
                curmap[a[i]]--;
                if (bmap[a[i]] - 1 == curmap[a[i]]){
                    count--;
                }
            }

            if (count == bmap.size()) qs.push_back(i+p+1);
        }
    }

    sort(qs.begin(), qs.end());

    cout << qs.size() << endl;
    for (auto e : qs) cout << e << " "; cout << endl;

    return 0;
}