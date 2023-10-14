#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int MAX = 1000;
int c, n;
int arr[1001];
int good[2][1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> c >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {cin >> arr[i]; mx += arr[i];}

    good[0][0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int a = 0; a <= c; a++){
            for (int b = 0; b <= c; b++){
                good[i%2][a][b] |= good[1 - (i%2)][a][b];
                if (arr[i] <= a)
                    good[i%2][a][b] |= good[1 - (i%2)][a-arr[i]][b];
                if (arr[i] <= b)
                    good[i%2][a][b] |= good[1 - (i%2)][a][b-arr[i]];
            }
        }
    }

    int besta = 0, bestb = 0;
    for (int a = 0; a <= c; a++){
        for (int b = 0; b <= c; b++){
            if (!good[n%2][a][b] || a + b > mx)
                continue;
            if (a + b > besta + bestb || (a+b==besta+bestb && abs(a-b) < abs(besta-bestb))){
                besta = a;
                bestb = b;
            }
        }
    }
    
    if (bestb > besta) swap(besta, bestb);
    cout << besta << " " << bestb << endl;
    return 0;
}