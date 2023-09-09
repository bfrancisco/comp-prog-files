#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> cardfreq(14, 4);

    int jack = 0, mary = 0;
    int c1,c2,c3,c4; cin >> c1 >> c2 >> c3 >> c4;

    jack += (c1 > 10 ? 10 : c1) + (c2 > 10 ? 10 : c2);
    mary += (c3 > 10 ? 10 : c3) + (c4 > 10 ? 10 : c4);
    cardfreq[c1]--;
    cardfreq[c2]--;
    cardfreq[c3]--;
    cardfreq[c4]--;

    for (int i = 0; i < n; i++){
        int val; cin >> val;
        int trueval = (val > 10 ? 10 : val);
        jack += trueval;
        mary += trueval;
        cardfreq[val]--;
    }
    // cout << mary << " " << jack << endl;
    int ans = -1;
    for (int i = 1; i <= 13; i++){
        if (cardfreq[i] <= 0) continue;
        int toadd = (i > 10 ? 10 : i);
        int jackval = (jack + toadd > 23 ? 0 : jack + toadd);
        int maryval = (mary + toadd > 23 ? 0 : mary + toadd);
        if ((jackval == 0 && maryval > 0) || (maryval == 23 && maryval >= jackval)){
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}