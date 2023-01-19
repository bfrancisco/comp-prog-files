#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w; cin >> h >> w;
    int cost[10][10];
    int A[200][200];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> cost[i][j];

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> A[i][j];
    
    // do a bruteforce for each number converted to 
    return 0;
}   