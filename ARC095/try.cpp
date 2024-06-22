#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

    int cnt = 0;
    for (int i = 0; i < 5; i++){
        cout << i << endl;
        if (i == 2 && cnt == 0){
            i--;
            cnt++;
        }
    }
    return 0;
}