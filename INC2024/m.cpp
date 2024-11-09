#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(3*n);
    for (int i = 0; i < 3*n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = 1;
    for (int i = 3*n-2; i >= 0; i -= 2) {
        if (ans == n) {
            cout << v[i] << "\n";
            return 0;
        }
        ans++;
    }

    return 0;
}