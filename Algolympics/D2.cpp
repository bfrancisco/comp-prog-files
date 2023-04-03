#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

unordered_set<char> ops = {'-', '+', '*', '/', '='};

void rb(int c, bitset<10> used, vector<int>& curr, int sz, vector<vector<int>>& perms){
    if (sz == c){
        perms.push_back(curr);
        return;
    }

    for (int i = 0; i < 10; i++){
        if (used[i]) continue;
        used[i] = true;
        curr.push_back(i);
        rb(c, used, curr, sz+1, perms);
        curr.pop_back();
        used[i] = false;
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
    
    vector<vector<int>> oplets(3);
    int opc = 0;
    char operation;
    for (int i = 0; i < s.size(); i++){
        if (ops.find(s[i]) != ops.end()){
            opc++;
            operation = s[i];
            continue;
        }
        oplets[opc].push_back(s[i]);
    }

    // count unique letters from operand2 and result

    // bitset<10> tempb{0b0000000000};
    // vector<int> tempv;
    // rb(c, tempb, tempv, 0, perms);


    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) solve();


    return 0;
}