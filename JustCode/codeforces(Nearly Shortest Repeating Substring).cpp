#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define yes cout<<"yes\n"
#define no cout<<"no\n"
using namespace std ;
const ll m = 1e9+7 ;
const ll x = 1e9 ;
int main(){
      std::ios::sync_with_stdio(false);
     std::cin.tie(nullptr);
      vector<pair<int,tuple<int,int,int>>>v ;
        int tc;cin>>tc;
        while(tc--){
                int n;cin>>n ;
                string s;cin>>s ;
                set<int>st ;
                vector<int>v ;
                for(int i = 1;i<=sqrt(n);i++){
                    if(n%i == 0){
                        st.insert({i,n/i}) ;
                    }
                }
                for(auto u : st)v.pb(u) ;
                for(int i = 0;i<v.size();i++){

                    map<string,int>m ;
                    for(int k = 0;k<n;k+=v[i]){
                        string ab = s.substr(k,v[i]) ;
                        m[ab]++ ;
                    }
                    int mx = 0;
                    string p ,pp;
                    for(auto u : m){
                        if(u.second>mx){
                            mx = u.second ;
                            p = u.first ;
                        }
                    }
                    for(int j = 1;j<=(n/v[i]);j++){
                        pp+=p ;
                    }int x = 0 ;
                    for(int l = 0;l<pp.size();l++){
                        if(s[l]!=pp[l])x++ ;
                    }

                    if(x<=1){
                        cout<<v[i]<<endl ;
                        break ;
                    }
                }


        }



     return 0;

}
