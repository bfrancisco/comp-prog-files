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
    // for (auto x : psum)
    //     cout << x << " ";
    // cout << endl; 
    int ans = 1e9;
    for (int mask = 0; mask < (1<<(h-1)); mask ++){
        // cout << "mask: " << mask << endl;
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
        sort(rows.begin(), rows.end());
        rows.push_back(h-1);

        // print cuts
        // for (auto x : cuts) cout << x << " ";
        // cout << endl;

        // without vertical cuts
        bool pas = true;
        for (auto x : cuts){
            if (x > k) pas = false;
        }
        if (pas){
            ans = min(ans, divisions);
            continue;
        }
        // with vertical cuts, greedy
        vector<int> groupcount(divisions + 1, 0);
        bool possible = true;
        int widthbar = 0;
        for (int c = 0; c < w; c++){
            widthbar ++;
            int group = 0;
            for (int r = 0; r < h; r++){
                if (r > rows[group])
                    group ++;
                if (grid[r][c] == '1'){
                    groupcount[group] += 1;
                }
            }
            bool isCut = false;
            for (auto count : groupcount){
                if (count > k){
                    if (widthbar == 1)
                        possible = false;
                    else
                        isCut = true;
                    break;
                }
            }
            if (!possible) continue;
            if (isCut){
                for (int i = 0; i < groupcount.size(); i++)
                    groupcount[i] = 0;
                divisions ++;
                c--;
                widthbar = 0;
            }
        }
        if (possible)
            ans = min(ans, divisions);
        
    }

    
    // cout << "ans: ";
    cout << ans;
    return 0;
}