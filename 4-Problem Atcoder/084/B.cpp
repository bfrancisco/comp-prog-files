#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b;
    string s;
    cin >> a >> b >> s;
    // cout << s; 
    for (int i = 0; i < s.size(); i++){
        if (i == a){
            if (s[i] != '-')
                {cout << "No"; return 0;}
        }
        else if (s[i] == '-')
            {cout << "No"; return 0;}
    }
    cout << "Yes";
    return 0;
}