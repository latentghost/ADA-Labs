using namespace std;

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string.h>

#define ll long long


bool csort(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}


ll cross_inv(int left[], int right[], int l1, int r1){
    ll i=0,j=0;
    ll l = (ll) l1;
    ll r = (ll) r1;
    ll out=0;
    while(i<l && j<r){
        if(left[i]>right[j]){
            out += l-i;
            j++;
        }
        else i++;
    }
    return out;
}


void merge(int arr[], int left[], int right[], int n){
    int l = n/2;
    int r = n-l;
    int a=0,b=0;
    for(int i=0; i<n; i++){
        if(a<l && b<r){    
            if(left[a]<=right[b]){
                arr[i] = left[a++];
                if(a==l){
                    while(b<r){
                        arr[++i] = right[b++];
                    }
                    return;
                }
            }
            else{
                arr[i] = right[b++];
                if(b==r){
                    while(a<l){
                        arr[++i] = left[a++];
                    }
                    return;
                }
            }
        }
    }
}


ll mergesort(int arr[], int n){
    if(n==1) return 0;
    int l = n/2;
    int r = n-l;

    int left[l];
    int right[r];

    for(int i=0; i<l; i++){
        left[i] = arr[i];
        right[i] = arr[l+i];
    }
    right[r-1] = arr[n-1];

    ll linv = mergesort(left,l);
    ll rinv = mergesort(right,r);

    ll crinv = cross_inv(left,right,l,r);

    merge(arr,left,right,n);

    return linv + rinv + crinv;
}


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

    if(arr.size()>1) sort(arr.begin(),arr.end(),csort);
    int sarr[n];
    for(int i=0; i<n; i++){
        sarr[i] = arr[i].second;
    }

    cout << mergesort(sarr,n) << endl;
    
}