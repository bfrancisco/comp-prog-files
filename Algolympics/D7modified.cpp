#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
unordered_set<char> ops = {'-', '+', '*', '/', '='};
string s;
bool ex;
int c;
char operation;
 
int powt(int x){
    int val = 1;
    while(x--){
        val *= 10;
    }
    return val;
}
 
// bool operate(int a, char op, int b, int r){
//     if (a == 0 || b == 0 || r == 0) return false;
//     else if (op == '+') return a + b == r;
//     else if (op == '-' && a > b) return a - b == r;
//     else if (op == '/') return a / b == r;
//     else if (op == '*') return a * b == r;
//     else return false;
// }
 
int computeR(int a, char op, int b){
    if (a == 0 || b == 0) return -1;
    else if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '/') return a / b;
    else if (op == '*') return a * b;
    else return -1;
}
 
void rb(int lc, bitset<10>& used, vector<char>& letters, unordered_map<char, int>& li_val, int sz, vector<unordered_map<char, int>>& operandset, vector<vector<char>>& operands, vector<int>& opsz, vector<int>& vals, unordered_set<char>& allocated_lets, bool& ex){
    if (sz == lc){
        
        int result = computeR(vals[0], operation, vals[1]);
        // if (vals[0] == 34 && vals[1] == 12) cout << result << "\n";
        if (result <= 0) return;

        // if (li_val['E'] == 2 && li_val['L'] == 0 && li_val['M'] == 3 && li_val['O'] == 4 && li_val['U'] == 9 && li_val['V'] == 1){
        //     for (int i = 0; i < 3; i++) cout << vals[i] << "\n";
        // }

        bool good = true;
        unordered_map<char, int> goodlets;
        bitset<10> used2{0b0000000000};
        int cres = result;
        int buildres = 0;
        int pv = 1;
        for (int in = opsz[2] - 1; in >= 0; in--){
            
            if (allocated_lets.find(operands[2][in]) != allocated_lets.end()){
                buildres += (li_val[operands[2][in]] * pv);
            }
            else if (goodlets.find(operands[2][in]) != goodlets.end()){
                buildres += (goodlets[operands[2][in]] * pv);
            }
            else{
                int digit = cres%10;
                if (used[digit] || used2[digit]){
                    good = false; break;
                }
                goodlets[operands[2][in]] = digit;
                used2[digit] = true;
                buildres += (digit * pv);
            }   
            pv *= 10;
            cres /= 10;

        }
        if (good && buildres == result) {
            for (int ci = 0; ci < c; ci++){
                if (ci < lc)
                cout << letters[ci] << " " << li_val[letters[ci]] << "\n";
            else
                cout << letters[ci] << " " << goodlets[letters[ci]] << "\n";
            }
            ex = true;
        }
        return;
    }
 
    for (int i = 0; i < 10; i++){
        if (used[i]) continue;
        used[i] = true;
        li_val[letters[sz]] = i;
 
        for (int si = 0; si < 3; si++){
            if (operandset[si].find(letters[sz]) != operandset[si].end()){
                vals[si] += (i * operandset[si][letters[sz]]);
            }
        }
 
        rb(lc, used, letters, li_val, sz+1, operandset, operands, opsz, vals, allocated_lets, ex);
        if (ex) return;
 
        for (int si = 0; si < 3; si++){
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
    operation = 'x'; // placeholder
 
    // iterating lexi is lexicograpic
    // build set of letters for each operand
    set<char> lexi;
    vector<vector<char>> operands(3);
    vector<int> opsz(3, 0);
    int si = 0;
    
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
 
    vector<unordered_map<char, int>> operandset(3); // {letter : Eplaceval}
    int pv_inv = 1;
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
 
    // iterate lexicographically until operands is filled up
    vector<int> fill(2, 0);
    unordered_set<char> allocated_lets; 
    int lessc = 0; // 10 P lessc

    for (auto &letter : lexi){
        allocated_lets.insert(letter);
        lessc++;
        for (int i = 0; i < 2; i++){
            for (auto& le : operands[i]){
                if (le == letter){
                    fill[i]++;
                }
            }
        }
        int cnt[2] = {0, 0};
        for (int i = 0; i < 2; i++){
            if (fill[i] == opsz[i])
                cnt[i]++;
        }
 
        if (cnt[0] && cnt[1]) break;
 
    }
 
    bitset<10> used{0b0000000000};
    vector<char> letters; // lexicographic ordering
    
    unordered_map<char, int> li_val; //letter : value in perm
 
    for (auto &ch : lexi) {
        letters.push_back(ch);
        li_val[ch] = 0;
    }
    
    vector<int> vals(3, 0);
 
    rb(lessc, used, letters, li_val, 0, operandset, operands, opsz, vals, allocated_lets, ex);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int t; cin >> t;
    while(t--) solve();
 
 
    return 0;
}