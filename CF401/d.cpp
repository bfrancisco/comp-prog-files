#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    for (int i = n-2; i >= 0; i--){
        string l, r;
        l = words[i];
        r = words[i+1];
        
        string newl = "";
        bool retain = false;
        for (int j = 0; j < min(l.size(), r.size()); j++){
            if (l[j] > r[j]) break;
            else if (l[j] < r[j]) retain = true;
            newl.push_back(l[j]);
        }

        if (!retain) words[i] = newl;
    }

    for (auto w : words){
        cout << w << endl;
    }

    return 0;
}