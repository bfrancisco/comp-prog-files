#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    vector<vector<int>> db(26);

    for (int i = 0; i < s.size(); i++){
        db[s[i]-'a'].push_back(i+1);
    }

    for (int i = 0; i < 26; i++){
        for (int j = 0; j+1 < db[i].size(); j++){
            if (db[i][j+1] - db[i][j] <= 2){
                cout << db[i][j] << " " << db[i][j+1] << endl;
                return 0; 
            }
        }
    }
    cout << "-1 -1" << endl;

    return 0;
}