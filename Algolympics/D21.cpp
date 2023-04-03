#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
unordered_set<char> ops = {'-', '+', '*', '/', '='};
string s;
// int pw[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

bool operate(int a, char op, int b, int c){
    if (a == 0 || b == 0 || c == 0) return false;
    else if (op == '+') return a + b == c;
    else if (op == '-' && a > b) return a - b == c;
    else if (op == '/') return a / b == c;
    else if (op == '*') return a * b == c;
    else return false;
}
 
void rb(int c, bitset<10>& used, vector<char>& letters, unordered_map<char, int>& li_val, int sz, vector<vector<char>>& operands, char operation, bool& ex, vector<int>& opsz){
    if (sz == c){
        
        vector<int> vals(3, 0);
        for (int i = 0; i < 3; i++){
            int pv = 1;
            for (int j = opsz[i] - 1; j >= 0; j--){
                vals[i] += (li_val[operands[i][j]] * pv);
                pv *= 10;
            }
        }
 
        if (operate(vals[0], operation, vals[1], vals[2])){
            for (auto& let : letters){
                cout << let << " " << li_val[let] << "\n";
            }
            ex = true;
        }
 
        return;
    }
 
    for (int i = 0; i < 10; i++){
        if (used[i]) continue;
        used[i] = true;
        li_val[letters[sz]] = i;
        rb(c, used, letters, li_val, sz+1, operands, operation, ex, opsz);
        
        if (ex) return;
 
        li_val[letters[sz]] = 0;
        used[i] = false;
    }
}
 
void solve(){
    int c;
    cin >> c;
    cin >> s;
 
    set<char> lexi;
    vector<vector<char>> operands(3);
    vector<int> opsz(3, 0);
    int si = 0;
    char operation;
    for (auto &ch : s){
        if (ops.find(ch) == ops.end()){
            lexi.insert(ch);
            opsz[si]++;
            operands[si].push_back(ch);
        }
        else{
            if (si == 0) operation = ch;
            si++;
        }
    }
 
    bitset<10> tempb{0b0000000000};
    vector<char> letters; // lexicographic ordering
    unordered_map<char, int> li_val; //letter : value in perm
 
    for (auto &ch : lexi) {
        letters.push_back(ch);
        li_val[ch] = 0;
    }

    bool ex = false;
    rb(c, tempb, letters, li_val, 0, operands, operation, ex, opsz);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}