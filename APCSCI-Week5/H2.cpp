#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool bfscheck(char a, char b, unordered_map<char, vector<char>> & gr){
    queue<char> q;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    vector<string> words;
    for (int i = 0; i < n; i++){
        string in;
        cin >> in;
        words.push_back(in);
    }

    unordered_map<char, vector<char>> gr;
    for (char c : alpha){
        gr[c];
    }

    queue<vector<int>> query;
    vector<int> tmp = {0, n-1, 0};
    query.push(tmp);
    vector<char> firstchars;
    
    while (!query.empty()){
        int l, r, c;
        
        tmp = query.front(); query.pop();
        l = tmp[0];
        r = tmp[1];
        c = tmp[2];
        vector<int> toq = {l, 0, c+1};
        bool isfirst = false;

        for (int i = l; i < l+r; i++){
            string fi = words[i];
            string se = words[i+1];
            if (se.size() <= c && fi.size() > c){
                cout << "Impossible" << endl;
                return 0;
            }
            if (fi.size() <= c){
                continue;
            }

            if (fi[c] == se[c]){
                toq[0] ++;
                continue;
            }
            else if (fi[c] != se[c]){
                if (toq[1] > 0){
                    query.push(toq);
                }
                toq = {i+1, 0, c+1};
            }

            if (bfscheck(se[c], fi[c], gr)){
                gr[fi[c]].push_back(se[c]);
                isfirst = true;
            }
        }
    }
   
    return 0;
}