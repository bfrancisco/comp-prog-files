#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct spell{
    int dmg;
    int mana_cost;
    long double ratio;
    spell(int dmg, int mana){
        this->dmg = dmg;
        this->mana_cost = mana;
        this->ratio = (long double)dmg/(long double)mana;
    }

    void update_dmg_ratio(int h){
        this->dmg = h;
        this->ratio = (long double)dmg/(long double)mana_cost;
    }
};

bool ratio_comp(spell const & a, spell const & b){
    if (fabsl(a.ratio - b.ratio) < __LDBL_EPSILON__){
        return a.mana_cost < b.mana_cost;
    }
    return a.ratio > b.ratio;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H, n; cin >> H >> n;
    vector<spell> v;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if (a > H) a = H;
        v.push_back(spell(a, b));
    }

    cout.precision(20);
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << fixed << v[i].ratio << endl;
    }

    int ans = 0;
    cout << endl;
    while (H > 0){
        sort(v.begin(), v.end(), ratio_comp);

        ans += v[0].mana_cost*(H/v[0].dmg);
        H -= v[0].dmg*(H/v[0].dmg);
        cout << H << " " << v[0].dmg << endl;
        for (int i = 0; i < n; i++){
            if (v[i].dmg <= H) break;
            v[i].update_dmg_ratio(H);
        }
    }

    cout << ans;
    return 0;
}   