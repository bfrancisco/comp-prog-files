#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int,int>> a;
    a.push_back({0, 0});
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        while (a.back().first >= x){
            a.pop_back();
        }
        auto it = lower_bound(a.begin(), a.end(), make_pair(x, 0));
        it--;
        cout << (*it).second << " ";
        a.push_back({x, i});
    }
    cout << endl;


    return 0;
}

// 0 2 5 1 4 8 3 2 5
//   2 5 
//       1 4 8
//           1 3
//             1 2 

                
