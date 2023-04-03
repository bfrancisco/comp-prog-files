#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> vals(3, 0);
    vector<unordered_map<char, int>> a(3);

    a[0]['A'] = 1;
    a[0]['D'] = 4;
    a[1]['B'] = 2;
    a[1]['E'] = 5;
    a[2]['C'] = 3;
    a[2]['F'] = 6;

    vals[0] += 5;
    vals[1] += 7;
    vals[2] += 9;

    for (int i = 0; i < 3; i++){
        for (auto& mp : a[i])
            cout << mp.first << " : " << mp.second << "   ";
        cout << endl;
    }
    cout << endl << endl;

    swap(a[0], a[1]);

    for (int i = 0; i < 3; i++){
        for (auto& mp : a[i])
            cout << mp.first << " : " << mp.second << "   ";
        cout << endl;
    }
    cout << endl << endl;

    swap(a[1], a[2]);

    for (int i = 0; i < 3; i++){
        for (auto& mp : a[i])
            cout << mp.first << " : " << mp.second << "   ";
        cout << endl;
    }
    cout << endl << endl;

    int b = 5 / 7;

    cout << b << endl;
    cout << (1-2)%10 << endl;

    cout << 0 % 10 << endl;
    cout << 0 / 10 << endl;
    return 0;
}