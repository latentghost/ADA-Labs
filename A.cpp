using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>



int main(){

    int t;
    cin >> t;
    int n = t;

    vector<pair<int,int>> arr;
    while(t--){
        int x,y;
        cin >> x >> y;
        arr.push_back({x,y});
    }

    int out = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1;j<n;j++){
            if((arr[i].first<arr[j].first && arr[i].second>arr[j].second) || (arr[i].first>arr[j].first && arr[i].second<arr[j].second)){
                out++;
            }
        }
    }

    cout << out << endl;

}