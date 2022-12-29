#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << (H-h)*(W-w);
    return 0;
}   