#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }

    vector<int> ans(n+1);
    for (int x = 1; x <= n; x++){
        int p = x;
        for (int i = 0; i < m; i++){
            if (p == a[i]){
                p = a[i]+1;
            }
            else if (p == a[i]+1){
                p = a[i];
            }
        }
        ans[p] = x;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;


    
    return 0;
}

// 7 6
// 6
// 4
// 2
// 1
// 3
// 5


// 1   2    3    4     5     6    7
//                              -
//                  -
//       -
//   -
//            -
//                        -