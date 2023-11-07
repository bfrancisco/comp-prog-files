#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<pair<int, char>> points;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        r++;
        points.push_back({l, 'S'});
        points.push_back({r, 'E'});
    }
    sort(points.begin(), points.end());

    int cur = 0;
    vector<pair<int, int>> ans;
    int left = -1e9;
    int prev = -1e9;
    for (auto& [x, c] : points) {
        prev = cur;
        if (c == 'S') cur++;
        else if (c== 'E') cur--;

        if (prev == k-1 && cur == k) {
            left = x;
        }
        else if (prev == k && cur == k-1) {
            ans.push_back({left, x-1});
        }
    }

    cout << ans.size() << '\n';
    for (auto& [l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
    return 0;
}