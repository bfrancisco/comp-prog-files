#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n); // a[0] is garbage
    for (int i = 1; i < n; i++){
        a[i] = n-i;
    }

    for (int r = y-((y-x-1)/2); r <= n; r++){
        for (int v = 1; v <= x; v++){
            // cout << "num: " << v << " " << r << endl;
            // cout << "ind: " << r-v << " " << x-v+(y-r+1) << endl;
            a[r-v]--;
            a[x-v + (r-y+1)]++;
        }
    }
    
    for (int v = 1; v < n; v++){
        cout << a[v] << endl;
    } 

    return 0;
}