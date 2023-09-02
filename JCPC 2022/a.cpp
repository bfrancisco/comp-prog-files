#include<bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long int ll;

ifstream fin("Round1.in");

int main(){
    ios_base::sync_with_stdio(false);
    fin.tie(NULL); cout.tie(NULL);
    
    int t; fin >> t;
    while (t--){
        int n; fin >> n;
        
        cout << (n <= 26 ? "Yes" : "No") << endl;
    }

    return 0;
}