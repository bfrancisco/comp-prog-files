#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    set<tuple<int, pair<int, int>, char>> open;
    
    open.insert({3, {6, 5}, 'X'});
    open.insert({0, {5, 1}, 'X'});

    pair<int, int> cur = get<1>(*open.begin());
    // cout << cur.first << endl;

    open.erase(open.begin());

    // cout << get<1>(*open.begin()).first << endl;

    map<tuple<int, pair<int, int>, char>, int> open2;
    open2[{3, {6, 5}, 'X'}] = 3;
    open2[{0, {5, 1}, 'X'}] = 0;

    cout << get<0>(open2.begin()->first) << endl;

    string b = "B";
    cout << b.back() << endl;

    char x = 'A';
    string a = "B";
    cout << a.back() << endl;
    cout << a.back() + x << endl;

    if (a.back() == 'B') cout << "yes";

    return 0;
}