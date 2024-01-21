#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int ceil(int a, int b){
    return (a+b-1) / b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, a, b;
    cin >> n >> a >> b;
    if ((a == 1 && b != n) || (b==1 && a != n)){
        cout << -1 << endl; return 0;
    }
    if (a==1){
        for (int i = n; i; i--) cout << i << " ";
        cout << endl;
        return 0;
    }
    else if (b==1){
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return 0;
    }

    vector<int> p;
    int hi_bnd = n-a+1;
    if (hi_bnd <= 0) { cout << -1 << endl; return 0; } 
    for (int i = hi_bnd; i <= n; i++) p.push_back(i);
    int lo_bnd = b-1;
    if (lo_bnd >= hi_bnd) { cout << -1 << endl; return 0; }
    for (int i = lo_bnd; i > 0; i--) p.push_back(i);

    // remaining: lo_bnd+1 -- hi_bnd-1
    int remn = hi_bnd-lo_bnd-1;
    int to_add = ceil(remn, b-1);
    // cout << remn << " " << to_add << endl;
    if (1+to_add > a) { cout << -1 << endl; return 0; }
    for (int i = lo_bnd+1; ; i += b-1){
        int pushed = 0;
        for (int j = i+b-1-1; j >= i; j--){
            if (j < hi_bnd){
                p.push_back(j);
                pushed = 1;
            }
        }
        if (!pushed) break;
    }
    
    // cout << 1 << endl;
    for (auto e : p) cout << e << " "; cout << endl;
    return 0;
}