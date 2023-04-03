#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

unordered_set<char> ops = {'-', '+', '*', '/', '='};
string s;

bool operate(int a, char op, int b, int c){
    if (a == 0 || b == 0 || c == 0) return false;
    else if (op == '+') return a + b == c;
    else if (op == '-' && a > b) return a - b == c;
    else if (op == '/') return a / b == c;
    else if (op == '*') return a * b == c;
    else return false;
}

void rb(int c, bitset<10> used, vector<int>& curr, int sz, bool& ex){
    if (sz == c){
        
        map<char, int> letters; 

        for (auto e : s){
            if (ops.find(e) == ops.end()) letters[e] = 0;
        }

        int i = 0;
        for (auto let : letters){
            letters[let.first] = curr[i];
            i++;
        }
        // cout << endl;

        vector<stack<int>> operands(3);
        char operation;
        int si = 0;
        int sz = s.size();
        for (int i = 0; i < sz; i++){
            
            if (ops.find(s[i]) != ops.end()){
                if (si == 0) operation = s[i];
                si++;
                continue;
            }
            operands[si].push(letters[s[i]]);
        }

        vector<int> vals(3, 0);

        for (int i = 0; i < 3; i++){
            int pv = 1;
            while(!operands[i].empty()){
                vals[i] += operands[i].top() * pv;
                pv *= 10;
                operands[i].pop();
            }
        }
        // cout << vals[0] << " " << vals[1] << " " << vals[2] << endl;

        if (operate(vals[0], operation, vals[1], vals[2])){
            // for (auto e : p){
            //     cout << e << " ";
            // } cout << endl;
            for (auto &let : letters){
                cout << let.first << " " << let.second << endl;
            }
            ex = true;
        }
        return;
    }

    for (int i = 0; i < 10; i++){
        if (used[i]) continue;
        used[i] = true;
        curr.push_back(i);
        rb(c, used, curr, sz+1, ex);

        if (ex) return;

        curr.pop_back();
        used[i] = false;
    }
}

void solve(){
    int c;
    cin >> c;
    cin >> s;
    // build all permutations. 10P9
    bitset<10> tempb{0b0000000000};
    vector<int> tempv;
    bool ex = false;
    rb(c, tempb, tempv, 0, ex);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // permutations
    // assign values to each letter
    // construct the equation
    // check equality

    int t; cin >> t;
    while(t--) solve();


    return 0;
}