#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int c, n;
int arr[1001];
int good[1001][1001];

int rec(int i, int c1, int c2){
    if (good[c1][c2] != -1)
        return good[c1][c2];

    if (c1 == 0 && c2 == 0)
        return 1;
    if (i < 0)
        return 0;

    if (arr[i] > c1 && arr[i] > c2){
        good[c1][c2] = rec(i-1, c1, c2);
    }
    else if (arr[i] <= c1 && arr[i] > c2){
        good[c1][c2] = rec(i-1, c1, c2) |  rec(i-1, c1 - arr[i], c2);
    }
    else if (arr[i] > c1 && arr[i] <= c2){
        good[c1][c2] = rec(i-1, c1, c2) | rec(i-1, c1, c2 - arr[i]);
    }
    else{
        good[c1][c2] = rec(i-1, c1, c2) | rec(i-1, c1 - arr[i], c2) | rec(i-1, c1, c2 - arr[i]);
    }

    return good[c1][c2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> c >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {cin >> arr[i]; mx += arr[i];}

    memset(good, -1, sizeof(good));
    for (int i = c; i >= 0; i--){
        for (int j = c; j >= 0; j--){
            rec(n, i, j);
        }
    }
    // cout << rec(n, 100, 95) << endl;
    // cout << good[100][95] << endl;
    cout << mx << endl;
    int a = 0, b = 0;
    for (int i = 0; i <= c; i++){
        for (int j = 0; j <= c; j++){
            if (!good[i][j] || i+j > mx)
                continue;
            if (i + j > a + b || (i+j == a+b && abs(i-j) < abs(a-b))){
                a = i; b = j;
            }
            // cout << a << " " << b << endl;
        }
    }
    cout << a << " " << b << endl;

    return 0;
}