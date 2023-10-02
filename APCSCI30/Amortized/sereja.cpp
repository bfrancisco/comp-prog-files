#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// for p == 1 only

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    map<int, int> valtoinds;
    map<int, int> bmap;
    int count = 0;
    vector<int> qs;
    for (int i = 0; i < m; i++){
        valtoinds[b[i]] = 0;
        if (bmap.find(b[i]) == bmap.end())
            bmap[b[i]] = 1;
        else
            bmap[b[i]]++;
    }

    for (int i = 0; i < m; i++){
        if (bmap.find(a[i]) != bmap.end()){
            valtoinds[a[i]]++;
            if (bmap[a[i]] == valtoinds[a[i]]){
                count++;
            }
        }
    }
    if (count == m) qs.push_back(1);

    for (int i = 0, j = m; j < n; i++, j++){
        // addr
        if (bmap.find(a[j]) != bmap.end()){
            valtoinds[a[j]]++;
            if (bmap[a[j]] == valtoinds[a[j]]){
                count++;
            }
        }

        // popl
        if (bmap.find(a[i]) != bmap.end()){
            valtoinds[a[i]]--;
            if (valtoinds[a[i]] == bmap[a[i]] - 1){
                count--;
            }
        }

        if (count == m) qs.push_back(i+2);
    }

    cout << qs.size() << endl;
    for (auto e : qs) cout << e << " "; cout << endl;

    return 0;
}

// 1 2 3 4 5 6 7 8 9 10
// 1 2 3 4 5 
