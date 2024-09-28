#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
ll MOD = 37;

unordered_map<char, ll> um =
{
    {'A', 0},
    {'B', 1},
    {'C', 2},
    {'D', 3},
    {'E', 4},
    {'F', 5},
    {'G', 6},
    {'H', 7},
    {'I', 8},
    {'J', 9},
    {'K', 10},
    {'L', 11},
    {'M', 12},
    {'N', 13},
    {'O', 14},
    {'P', 15},
    {'Q', 16},
    {'R', 17},
    {'S', 18},
    {'T', 19},
    {'U', 20},
    {'V', 21},
    {'W', 22},
    {'X', 23},
    {'Y', 24},
    {'Z', 25},
    {'0', 26},
    {'1', 27},
    {'2', 28},
    {'3', 29},
    {'4', 30},
    {'5', 31},
    {'6', 32},
    {'7', 33},
    {'8', 34},
    {'9', 35},
    {' ', 36}
};

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
unordered_map<ll, char> db;


ll mod(ll x){
    return (x%MOD+MOD) % MOD;
}

vvll multiply(vvll& A, vvll& B){
    int p = A.size(), q = A[0].size(), r = B[0].size();
    vvll AB(p, vll(r));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < r; k++){
                AB[i][k] += mod(A[i][j] * B[j][k]);
                AB[i][k] = mod(AB[i][k]);
            }
    return AB;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll x = 0;
    for (auto c : abc){
        db[x++] = c;
    }

    int n; cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    // vector<string> words;
    // while (true) {
    //     string s;
    //     if (!(cin >> s)) break;

    //     words.push_back(s);
    // }
    string S;
    getline(cin, S);
    cout << "SADASD " << S << endl; 
    vector<ll> conv;
    // for (int i = 0; i < (int)words.size(); i++) {
    //     for (int j = 0; j < (int)words[i].size(); j++) {
    //         conv.push_back(um[words[i][j]]);
    //     }
    //     if (i+1 != (int)words.size()) {
    //         conv.push_back(um[' ']);
    //     }
    // }

    for (auto c : S){
        conv.push_back(um[c]);
    }

    
    while ((int)conv.size()%n != 0) {
        conv.push_back(36);
    }

    for (ll num : conv) {
        cout << num << " ";
    }
    cout << "\n";

    vector<vector<ll>> vecs;
    vector<ll> curr = {};
    for (int i = n-1; i <= (int)conv.size(); i += n) {
        curr.clear();
        for (int j = i-(n-1); j <= i; j++) {
            curr.push_back(conv[j]);
        }
        vecs.push_back(curr);
    }

    // for (int i = 0; i < (int)vecs.size(); i++) {
    //     for (int j = 0; j < (int)vecs[i].size(); j++) {
    //         cout << vecs[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<vector<ll>>> fa;
    for (int i = 0; i < (int)vecs.size(); i++) {
        vector<vector<ll>> p;
        for (int j = 0; j < n; j++){
            p.push_back({vecs[i][j]});
        }
        fa.push_back(multiply(v, p));
    }

    // cout << (int)fa.size() << "\n";

    for (vvll vla : fa) {
        for (vll vlb : vla) {
            for (ll num : vlb) {
                // cout << num << " ";
                cout << db[num];
            }
        }
    }
    cout << endl;


    
    return 0;
}