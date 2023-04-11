#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    char c; cin >> c;
    map<char, char> db;
    db['A'] = 'T';
    db['T'] = 'A';
    db['C'] = 'G';
    db['G'] = 'C';

    cout << db[c] << endl; 

    return 0;
}