#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s, p; cin >> n >> s >> p;

    for (int z = 0; z < p; z++){
        int m; cin >> m;
        bool keep = false;
        for (int i = 0; i < m; i++){
            int c; cin >> c;
            if (c == s) keep = true;
        }
        cout << (keep ? "KEEP" : "REMOVE") << endl;
    }
    return 0;
}