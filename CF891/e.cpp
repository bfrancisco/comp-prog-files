#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    int m = 0;
    vector<ll> a(n), srt;
    unordered_map<int, ll> freq, score;
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];

        if (freq.find(a[i]) == freq.end()){
            freq[a[i]] = 1;
            score[a[i]] = 0;
            srt.push_back(a[i]);
            m += 1;
        }
        else
            freq[a[i]]++;
    }

    sort(srt.begin(), srt.end());

    vector<ll> prefreq(m, 0);
    prefreq[0] = freq[srt[0]];
    for (int i = 1; i < m; i++){
        prefreq[i] = prefreq[i-1] + freq[srt[i]];
    }

    vector<ll> scores(m, 0); // changing
    // build score of leftmost value
    ll points = n;
    scores[0] = points;
    score[srt[0]] = scores[0];
    for (int i = 1; i < m; i++){
        points -= freq[srt[i-1]];
        scores[i] = points * (srt[i]-srt[i-1]);
        score[srt[0]] += scores[i];
    }


    for (int i = 1; i < m; i++){
        score[srt[i]] = score[srt[i-1]];
        // change x score to total points
        score[srt[i]] += n - scores[i];
        scores[i] = n;
        // cout << srt[i] << " " << score[srt[i]] << endl;

        // change x score of prev
        score[srt[i]] += (prefreq[i-1] * (srt[i]-srt[i-1])) - n;
    }

    for (auto x : a){
        cout << score[x] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}