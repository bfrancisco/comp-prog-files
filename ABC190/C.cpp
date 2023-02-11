#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int freq[101];
    int ball[101];
    pair<int, int> cons[101];
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        freq[a]++; freq[b]++;
        cons[i] = {a, b};
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++){
        int c, d; cin >> c >> d;
        if (ball[c] == 0 && ball[d] == 0){
            if (freq[c] >= freq[d]){
                ball[c]++;
            }
            else
                ball[d]++;
        }
        else if (ball[c] > 0)
            ball[d] = 1;
        else
            ball[c] = 1;
    }

    int ans = 0;
    for (auto p : cons){
        if (ball[p.first] >= 1 && ball[p.second] >= 1)
            ans++;
    }

    cout << ans;
    return 0;
    
}