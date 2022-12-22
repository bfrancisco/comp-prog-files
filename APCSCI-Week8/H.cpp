#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h, w, k;
vector<string> grid;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> h >> w >> k;
    grid.resize(h);
    for (int i = 0; i < h; i++){
        cin >> grid[i];
    }

    vector<int> psum;
    int sum = 0;
    for (int r = 0; r < h; r++){
        for (int c = 0; c < w; c++){
            if (grid[r][c] == '1')
                sum++;
        }
        psum.push_back(sum);
    }
    for (auto x : psum)
        cout << x << " ";
    cout << endl; 
    int ans = 1e9;
    for (int mask = 0; mask < (1<<(h-1)); mask ++){
        vector<int> cuts;
        vector<int> rows;
        int divisions = 0;
        int total = sum;
        for (int i = 0; i < h-1; i++){
            if (mask & (1<<i)){
                divisions ++;
                cuts.push_back(total - psum[h-i-2]);
                rows.push_back(h-i-2);
                total = psum[h-i-2];
            }
        }
        cuts.push_back(total);
        cout << "cuts: ";
        for (auto x : cuts) cout << x << " ";
        cout << endl;
        cout << "rows: ";
        for (auto x : rows) cout << x << " ";
        cout << endl;
        bool pas = true;
        for (auto x : cuts)
            if (x > k) pas = false;
        if (pas)
            ans = min(ans, divisions);
    }
    cout << "ans: ";
    cout << ans;
    return 0;
}