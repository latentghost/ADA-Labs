using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>

#define ll long long


int main()
{
    int n;
    cin >> n;

    vector<int> a,b;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    int mod = 998244353;

    ll dp[n][2];
    dp[0][0] = dp[0][1] = 1;

    for(int i=0; i<n-1; i++){
        ll x = dp[i][0] + dp[i][1];
        if(a[i+1]!=a[i] && a[i+1]!=b[i])
            dp[i+1][0] = (int) (x%mod);
        
        else if(a[i+1]==a[i] && a[i+1]!=b[i])
            dp[i+1][0] = (dp[i][1])%mod;

        else if(a[i+1]!=a[i] && a[i+1]==b[i])
            dp[i+1][0] = (dp[i][0])%mod;

        else
            dp[i+1][0] = 0;


        if(b[i+1]!=b[i] && b[i+1]!=a[i])
            dp[i+1][1] = (int) (x%mod);

        else if(b[i+1]!=a[i] && b[i+1]==b[i])
            dp[i+1][1] = (dp[i][0])%mod;

        else if(b[i+1]==a[i] && b[i+1]!=b[i])
            dp[i+1][1] = (dp[i][1])%mod;
        
        else
            dp[i+1][1] = 0;

        
        if(dp[i+1][0]==0 && dp[i+1][1]==0){
            cout << 0 << endl;
            return 0;
        }
    }

    // for(int i=0; i<n; i++){
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }

    int out = (int) ((dp[n-1][0] + dp[n-1][1])%mod);

    cout << out << endl;

    return 0;
}