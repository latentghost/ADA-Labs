using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>


#define pb emplace_back
#define ll long long


ll djikstra(vector<vector<pair<ll,pair<ll,ll>>>> &adj, ll n){
    vector<ll> lens(n,LLONG_MAX);
    vector<int> vis(n,0);
    lens[0] = 0;

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        ll a = pq.top().second;
        pq.pop();

        if(vis[a-1]==0){   
            for(auto &v: adj[a-1]){
                ll w = 0;
                
                if(lens[a-1]>=((ll) floor(sqrt(v.second.second))))
                    w = v.second.first + (v.second.second/(1 + lens[a-1]));
                
                else
                    w = ((ll) floor(sqrt(v.second.second))) - lens[a-1] + v.second.first + v.second.second/(1 + ((ll) floor(sqrt(v.second.second))));
                
                if(lens[a-1] + w < lens[v.first-1]){
                    lens[v.first-1] = lens[a-1] + w;
                    pq.push({lens[v.first-1],v.first});
                }
            }
        }
        vis[a-1] = 1;
    }

    return lens[n-1];
}


int main()
{
    ll n,m;
    cin >> n >> m;

    // vector<vector<pair<int,int>>> wts(n,vector<pair<int,int>>(n,make_pair(1e9+5,1e9+5)));

    vector<vector<pair<ll,pair<ll,ll>>>> adjl(n);

    for(int i=0; i<m; i++){
        ll a,b;
        ll c,d;
        cin >> a >> b >> c >> d;
        
        adjl[a-1].pb(b,make_pair(c,d));
        adjl[b-1].pb(a,make_pair(c,d));
        
        // int a1 = min(a,b);
        // int b1 = max(a,b);
        
        // if((wts[a1-1][b1-1].first==INT_MAX) || (c+d < wts[a1-1][b1-1].first + wts[a1-1][b1-1].second)){
        //     wts[a1-1][b1-1] = {c,d};
        // }
    }

    ll out = djikstra(adjl,n);
    if(out==LLONG_MAX){
        cout << -1 << endl;
    }
    else{
        cout << out << endl;
    }
}