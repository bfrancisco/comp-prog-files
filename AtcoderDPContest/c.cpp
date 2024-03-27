#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int abc[100001][3];
int n;

int rec(int k, int A, int B, int C){
    
    if (k == n){
        return max({A,B,C});
    }

    vector<int> ABC(3);
    ABC[0] = A, ABC[1] = B, ABC[2] = C;
    vector<int> nABC(3, -1);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i==j) continue;
            nABC[j] = max(nABC[j], ABC[i] + abc[k][j]);
        }
    }

    // for (int i = 0; i < 3; i++) cout << nABC[i] << " "; cout << endl;

    return rec(k+1, nABC[0], nABC[1], nABC[2]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> abc[i][0] >> abc[i][1] >> abc[i][2]; 
    }
    
    cout << rec(1, abc[0][0], abc[0][1], abc[0][2]) << endl;

    return 0;
}