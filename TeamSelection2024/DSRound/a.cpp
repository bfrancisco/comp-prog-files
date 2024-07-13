#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<tuple<int, int, pair<int, int>, pair<int, int>, pair<int, int>>, 
    null_type, 
    less<tuple<int, int, pair<int, int>, pair<int, int>, pair<int, int>>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int n;
vector<vector<pair<int, int>>> RGB;
// id -> index of R,G,B in RGB
map<int, vector<int>> idtoRGB;

int cyc(int ind){
    if (ind < 0) return n+ind;
    if (ind >= n) return n-ind;
    return ind;
}

int main(){

    
    cin >> n;
    RGB.resize(3);

    for (int i = 0; i < n; i++){
        int r,g,b,id;
        cin >> r >> g >> b >> id;
        id = -id;
        RGB[0].push_back({r, id});
        RGB[1].push_back({g, id});
        RGB[2].push_back({b, id});
        idtoRGB[id].resize(3);
    }

    sort(RGB[0].begin(), RGB[0].end());
    sort(RGB[1].begin(), RGB[1].end());
    sort(RGB[2].begin(), RGB[2].end());

    // print rgb
    for (int i = 0; i < n; i++){
        for (int c = 0; c < 3; c++){
            cout << "( " << RGB[c][i].first << " " << RGB[c][i].second << ")\t";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++){
        for (int c = 0; c < 3; c++){
            idtoRGB[RGB[c][i].second][c] = i;
        }
    }

    // print IDtoRGB
    for (auto [k, v] : idtoRGB){
        cout << "ID: " << k << endl;
        for (int c = 0; c < 3; c++){
            cout << v[c] << " ";
        }
        cout << endl;
    }


    // val, id, RGB le ri id
    ordered_set db;

    for (auto [id, v] : idtoRGB){
        vector<pair<int, int>> LR(3); // left and right cards of curr card via id
        for (int c = 0; c < 3; c++){
            LR[c].first = cyc(v[c]-1);  // left
            LR[c].second = cyc(v[c]+1); // right
        }
    }
    
    return 0;
}