#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> A(n), B(n);
    unordered_map<int, int> freqA, freqB;

    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    for (int i = 0; i < n; i++){
        if (freqA.find(A[i]) == freqA.end())
            freqA[A[i]] = 1;
        else
            freqA[A[i]]++;
    }
    for (int i = 0; i < n; i++){
        if (freqB.find(B[i]) == freqB.end())
            freqB[B[i]] = 1;
        else
            freqB[B[i]]++;
    }

    bool pas = true;
    for (int i = 0; i < n; i++){
        if (freqA.find(A[i]) != freqA.end() && freqB.find(A[i]) != freqB.end()){
            if (freqA[A[i]] + freqB[A[i]] > n){
                pas = false;
                break;
            }
        }
    }

    if (!pas){
        cout << "No" << endl;
        return 0;
    }


    return 0;
}