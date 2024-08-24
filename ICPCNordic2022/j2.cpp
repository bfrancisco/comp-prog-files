    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;

    void UP(){cout << "up\n";}
    void DO(){cout << "down\n";}
    void LE(){cout << "left\n";}
    void RI(){cout << "right\n";}
    int N = 30;
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        
        int n; cin >> n;
        int x, y, dx, dy;
        cin >> x >> y >> dx >> dy;
        for (int i = 0; i < n; i++){
            int aaa, bbb;
            cin >> aaa >> bbb;
        }

        for (int i = 1; i <= y+1; i++)
            DO();

        LE();
        for (int i = 1; i <= y+1; i++)
            DO();
        
        RI();

        for (int i = 1; i <= y+1; i++)
            UP();
        
        // go 0, -1
        for (int i = 1; i <= x; i++)
            LE();
        
        for (int i = 1; i <= dy; i++){
            for (int j = 1; j <= N+1; j++){
                UP(); DO(); RI();
            }
            UP();
            for (int j = 1; j <= N+1; j++){
                LE();
            }
        }

        LE();
        UP();
        for (int k = 0; k < N; k++){
            // sweep
            for (int i = 1; i <= dx; i++)
                RI();
            DO();
            for (int i = dx-1; i <= N; i++)
                RI();
            UP();

            for (int i = N+1; i >= dx+2; i--)
                LE();
            for (int i = dx+1; i <= N; i++)
                RI();
            
            for (int i = 1; i <= N - k; i++)
                UP();
            
            LE();
            for (int i = N; i >= 0; i--){
                DO(); UP(); LE();
            }
            for (int i = 1; i <= N - k; i++)
                DO();
        
        }
        return 0;
    }