#include<bits/stdc++.h>
using namespace std;

int dr[2][5] = {{0, 0, 1, -1, 0}, {1, -1, 0, 0, 0}};
int dc[2][5] = {{1, -1, 0, 0, 0}, {0, 0, 1, -1, 0}};
int n;

bool valid(int r, int c){
    return (0 < r && r <= n && 0 < c && c <= n);
}

int get_dist(int a, int b, int c, int d){
    return (abs(a-c) + abs(b-d));
}

int main(){
    cin >> n;
    int ar, ac, br, bc, xr, xc;
    cin >> ar >> ac;
    cin >> br >> bc;
    cin >> xr >> xc;

    int Adist, Bdist, Ak, Bk;
    int j = 0;
    while (xr != 0 && xc != 0){
        Adist = Bdist = 1e9;
        Ak = Bk = -1;
        for (int k = 0; k < 5; k++){
            int nar, nac;
            nar = ar + dr[0][k];            
            nac = ac + dc[0][k];
            if (valid(nar, nac) && get_dist(nar, nac, xr, xc) < Adist){
                Adist = get_dist(nar, nac, xr, xc);
                Ak = k;
            }

            int nbr, nbc;
            nbr = br + dr[1][k];            
            nbc = bc + dc[1][k];
            if (valid(nbr, nbc) && get_dist(nbr, nbc, xr, xc) < Bdist){
                Bdist = get_dist(nbr, nbc, xr, xc);
                Bk = k;
            }
        }

        ar += dr[0][Ak];
        ac += dc[0][Ak];
        br += dr[1][Bk];
        bc += dc[1][Bk];

        assert(valid(ar, ac) && valid(br, bc));
        assert(j < 595);
        cout << ar << " " << ac << " " << br << " " << bc << endl;
        
        if ((ar == xr && ac == xc) || (br == xr && bc == xc)){
            break;
        }

        cin >> xr >> xc;

        j++;
    }
    return 0;
}