#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void UP(){cout << "right\n";}
void DO(){cout << "left\n";}
void LE(){cout << "down\n";}
void RI(){cout << "up\n";}
int N = 30;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int r, c, dr, dc;
    cin >> c >> r >> dc >> dr;

    for (int i = 0; i < n; i++){
        int XX, YY; cin >> XX >> YY;
    }

    // go outside
    for(int i = 0; i <= r; i++){
        UP();
    }

    // go to the top of pushed skoots
    LE();
    for (int i = 0; i <= r; i++)
        UP();
    RI();

    // push down skoots
    for (int i = 0; i <= r; i++)
        DO();

    // go (-1, 0)
    for (int i = 0; i < c; i++)
        LE();

    // sweep all to row of dump
    for (int i = 0; i < dr; i++){
        for (int j = 0; j <= N; j++){
            DO(); UP(); RI();
        }
        // we now at (-1, 31)
        for (int j = 0; j <= N; j++){
            LE();
        }
        // (-1, 0)
        DO();
    }

    // now at (dr-1, 0)
    // sweep from LE()ft to dump, RI()ght to dump
    LE();
    DO();
    for (int i = 0; i < dc; i++)
        RI();
    
    UP();
    for (int i = 0; i < N - dc + 2; i++)
        RI();
    
    DO();

    // go left again, to (dr, -1). you also sweep the skoots at the RI()ght
    for (int i = 0; i <= N+1; i++)
        LE();

    // go down (dr+N+1, 0)
    for (int i = 0; i <= N; i++){
        DO();
    }
    RI();

    for (int k = 0; k < N; k++){
        // sweep one row up
        for (int j = 0; j <= N; j++){
            UP(); DO(); RI();
        }

        // go to dr, sweep to dump from right
        for (int i = 0; i <= N-k; i++)
            UP();

        for (int j = 0; j < N-dc; j++)
            LE();
        
        UP();
        for (int j = 0; j < dc+2; j++)
            LE();
        DO();
        // now at (dr, -1)

        // sweep to dump from left
        for (int j = 0; j < dc; j++)
            RI();
        
        // go to (dr, -1) again
        for (int j = 0; j < dc; j++)
            LE();

        // go down, at column 0, row minus 1 of before
        for (int i = 0; i < N-k; i++)
            DO();
        
        RI();
    }

    return 0;
}