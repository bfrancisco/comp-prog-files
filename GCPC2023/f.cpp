#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int w, h;
    cin >> w >> h;
    vector<int> a(w);
    for (int i = 0; i < w; i++){
        cin >> a[i];
        if (a[i] > h){
            cout << "impossible" << endl;
            return 0;
        }
    }

    set<int> blocks = {h+1};
    if ((h - a[0]) % 2){
        blocks.insert(h);
    }
    for (int i = 1; i < w; i++){
        int prev = a[i];
        set<int> newblocks = {h+1};
        for (auto b : blocks){
            if (b <= prev){
                cout << "impossible" << endl;
                return 0;
            }
            int space = b - prev - 1;
            if (space%2){
                newblocks.insert(b-1);
            }
            prev = b;
        }
        blocks = newblocks;
    }
    if (blocks.size() > 1){
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;

    return 0;
}