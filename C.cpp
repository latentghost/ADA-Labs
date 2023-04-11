using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>



int shuffle(string *x, string *y, int n){
    string a = *x;
    string b = *y;
    if(n%2==1){
        int out = 0;
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]){
                b[i] = '0' + (1-(b[i]-'0'));
                out++;
            }
        }
        *y = b;
        return out;
    }

    string a11 = a.substr(0,n/2);
    string a21 = a.substr(n/2,n/2);
    string b11 = b.substr(0,n/2);
    string b21 = b.substr(n/2,n/2);
    string a12 = a.substr(0,n/2);
    string a22 = a.substr(n/2,n/2);
    string b12 = b.substr(0,n/2);
    string b22 = b.substr(n/2,n/2);

    int c1 = shuffle(&a11,&b11,n/2) + shuffle(&a21,&b21,n/2);
    int c2 = shuffle(&a12,&b22,n/2) + shuffle(&a22,&b12,n/2);

    if(c1<=c2) b = b11 + b21;
    else b = b12 + b22;

    *y = b;

    return min(c1,c2);
    
}



void solve(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;

    cout << shuffle(&a,&b,n) << endl << b << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}