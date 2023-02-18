#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void rb(int c, unordered_set<int> used, vector<int>& curr, int sz, vector<vector<int>>& perms){
    if (sz == c){
        perms.push_back(curr);
        return;
    }

    for (int i = 0; i < 10; i++){
        if (used.find(i) != used.end()) continue;
        used.insert(i);
        curr.push_back(i);
        rb(c, used, curr, sz+1, perms);
        curr.pop_back();
        used.erase(i);
    }
}

bool operate(int a, char op, int b, int c){
    if (a == 0 || b == 0 || c == 0) return false;
    else if (op == '+') return a + b == c;
    else if (op == '-' && a > b) return a - b == c;
    else if (op == '/') return a / b == c;
    else if (op == '*') return a * b == c;
    else return false;
}

void solve(){
    int c;
    cin >> c;
    string s; cin >> s;
    vector<vector<int>> perms;
    // build all permutations. 10!
    unordered_set<int> temps;
    vector<int> tempv;
    rb(c, temps, tempv, 0, perms);

    // for (auto p : perms){
    //     for (auto e : p) cout << e << " ";
    //     cout << endl;
    // }

    unordered_set<char> ops = {'-', '+', '*', '/', '='};
    map<char, int> letters; 

    for (auto e : s){
        if (ops.find(e) == ops.end()) letters[e] = 0;
    }

    for (auto p : perms){
        // for (auto e : p) cout << e << " ";
        // cout << endl;
        // for (auto let : letters) cout << let.first << " ";
        // cout << endl;
        int i = 0;
        for (auto let : letters){
            letters[let.first] = p[i];
            // cout << let.first << " : " << p[i] << "   ";
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
            for (auto let : letters){
                cout << let.first << " " << let.second << endl;
            }
            return;
        }
    }
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