#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    map<char, int> freq;
    for (int i = 0; i < n; i++){
        char x; cin >> x;
        if (s.find(x) == s.end()){
            freq[x] = 0;
        }
        else freq[x]++;
    }

    int score = 0;

    map<char, int> val;
    string ranks = "123456789";
    for (auto r : ranks){
        val[r] = r-'0';
    }
    val['T'] = 10; val['J'] = 10; val['Q'] = 10; val['K'] = 10;

    // 15
    for (auto [rank, f] : freq){
        for (auto [rank, f] : freq){
            for (auto [rank, f] : freq){
                if (val[rank])
            }
        }
    }

    return 0;
}