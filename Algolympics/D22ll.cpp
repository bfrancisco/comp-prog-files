#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
unordered_set<char> ops = {'-', '+', '*', '/', '='};
string s;
ll c;
bool ex;

ll powt(ll x){
    ll val = 1;
    while(x--){
        val *= 10;
    }
    return val;
}

bool operate(ll a, char op, ll b, ll d){
    if (a == 0 || b == 0 || d == 0) return false;
    else if (op == '+') return a + b == d;
    else if (op == '-' && a > b) return a - b == d;
    else if (op == '/') return (a / b == d);
    else if (op == '*') return a * b == d;
    else return false;
}
 
void rb(bitset<10>& used, vector<char>& letters, unordered_map<char, ll>& li_val, ll sz, char& operation, vector<ll>& opsz, vector<ll>& vals, vector<unordered_map<char, ll>>& operandset){
    if (sz == c){
        // if (li_val['E'] == 2 && li_val['L'] == 0 && li_val['M'] == 3 && li_val['O'] == 4 && li_val['U'] == 9 && li_val['V'] == 1){
        //     for (ll i = 0; i < 3; i++) cout << vals[i] << endl;
        // }

        if (operate(vals[0], operation, vals[1], vals[2])){
            for (auto& let : letters){
                cout << let << " " << li_val[let] << "\n";
            }
            ex = true;
        }
 
        return;
    }
 
    for (ll i = 0; i < 10; ++i){
        if (used[i]) continue;
        used[i] = true;
        li_val[letters[sz]] = i;
 
        for (ll si = 0; si < 3; ++si){
            if (operandset[si].find(letters[sz]) != operandset[si].end()){
                vals[si] += (i * operandset[si][letters[sz]]);
            }
        }
 
        rb(used, letters, li_val, sz+1, operation, opsz, vals, operandset);
        
        if (ex) return;
 
        for (ll si = 0; si < 3; ++si){
            if (operandset[si].find(letters[sz]) != operandset[si].end()){
                vals[si] -= (i * operandset[si][letters[sz]]);
            }
        }
 
        li_val[letters[sz]] = 0;
        used[i] = false;
    }
}
 
void solve(){
    cin >> c;
    cin >> s;
    ex = false;
 
    set<char> lexi;
 
    vector<ll> opsz(3, 0);
 
    ll si = 0;
    char operation;
    for (auto &ch : s){
        if (ops.find(ch) == ops.end()){
            lexi.insert(ch);
            opsz[si]++;
        }
        else{
            if (si == 0) operation = ch;
            si++;
        }
    }
 
    vector<unordered_map<char, ll>> operandset(3);
    ll pv_inv = 1;
    si = 0;
    for (auto &ch : s){
        if (ops.find(ch) == ops.end()){
            if (operandset[si].find(ch) == operandset[si].end())
                operandset[si][ch] = powt(opsz[si] - pv_inv);
            else
                operandset[si][ch] += powt(opsz[si] - pv_inv);
            pv_inv++;
        }
        else{
            si++;
            pv_inv = 1;
        }
    }
 
    bitset<10> used{0b0000000000};
    vector<char> letters; // lexicographic ordering
    unordered_map<char, ll> li_val; //letter : value in perm
 
    for (auto &ch : lexi) {
        letters.push_back(ch);
        li_val[ch] = 0;
    }
 
    vector<ll> vals(3, 0);
    
    rb(used, letters, li_val, 0, operation, opsz, vals, operandset);
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll t; cin >> t;
    while(t--) solve();
 
 
    return 0;
}