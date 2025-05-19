 #include<bits/stdc++.h>
 #define LL long long
 using namespace std;
 int main(){

        int n,k;cin>>n>>k;
        int a[n] ;
        vector<int>v ;
        map<int,int>m;
        int zro = 0 ;
        for(int i = 0;i<n;i++){
            cin>>a[i] ;
            v.push_back(a[i]%k);
        }
        map<int,int>mm ;
        for(auto i = 0;i<n;i++){
            m[v[i]]++ ;
            mm[v[i]] = i ;
            if(!v[i])zro++ ;
        };
        sort(v.begin(),v.end()) ;
        int c,kk;
        c = (zro*(zro-1)) ;
        c/=2 ;
        for(int i = 0;i<n;i++){
                if(v[i] == 0)continue ;
                int x = k-v[i] ;
                if(m[x] && mm[v[i]]<mm[x] && x!=v[i])
                    c+=m[x] ;
                else if(m[x] && x==v[i]){
                    int kk = m[x] ;
                    int cc = (kk*(kk-1))/2 ;
                    c+=cc ;
                    m[x] = 0 ;
                }
        }
        cout<<c;

}
