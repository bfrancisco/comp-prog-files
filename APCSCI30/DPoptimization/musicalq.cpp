#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int c, n;
int a = -1e8, b = -1e7;
int arr[1000];
void rec(int i, int c1, int c2){
    if (i == n){
        if (c1 + c2 > a + b || (c1+c2==a+b && abs(c1-c2) < abs(a-b))){
            a = c1; b = c2;
        }
        return;
    }

    if (c1 + arr[i] <= c)
        rec(i+1, c1 + arr[i], c2);
    if (c2 + arr[i] <= c)
        rec(i+1, c1, c2 + arr[i]);
    rec(i+1, c1, c2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> c >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    rec(0, 0, 0);
    cout << a << " " << b << endl;

    return 0;
}