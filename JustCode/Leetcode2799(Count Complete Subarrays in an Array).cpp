#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7 ;
int countCompleteSubarrays(vector<int>&a) {
       map<int,int>m;
       for(auto u : a)m[u]++ ;
       int sz = m.size(),n = a.size() ;
       int l = 0,r = -1,tot = 0 ;
       m.clear() ;
       while(r<n){
          if(m.size()==sz){
            int x = n-l ;
            x-=(r-l+1) ;
            tot+=(x+1) ;
            m[a[l]]-- ;
            if(m[a[l]] == 0)m.erase(a[l]) ;
            l++ ;
          }
          else {
            r++ ;
            if(r<n)m[a[r]]++ ;
          }


       }
       return tot ;
    }
int main() {
        int n;cin>>n ;
        vector<int>a(n) ;
        for(int &i : a)cin>>i ;
        cout<<countCompleteSubarrays(a)<<endl ;

    return 0;
}
