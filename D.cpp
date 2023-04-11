using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>



bool shuffle(string a, string b, int n){
    if(n%2==1){
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }

    string a1 = a.substr(0,n/2);
    string a2 = a.substr(n/2,n/2);
    string b1 = b.substr(0,n/2);
    string b2 = b.substr(n/2,n/2);

    return ((shuffle(a1,b1,n/2) && shuffle(a2,b2,n/2)) || (shuffle(a1,b2,n/2) && shuffle(a2,b1,n/2)));
}

void solve(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;

    if(shuffle(a,b,n)) cout << "yes" << endl;
    else cout << "no" << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}