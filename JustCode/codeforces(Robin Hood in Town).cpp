#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
       int tc;cin>>tc;
       while(tc--){
        int n;cin>>n ;
        int a[n],mx = 0,s = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i] ;
            s+=a[i] ;
        }
        sort(a,a+n) ;
        mx = a[n-1] ;
        int l = 0,h = 1e18,ans = -1 ;
        while(l<=h){
            int m = (l+h)/2 ;
            s+=m ;
            int av = n*2 ;
            av = s/av + (s%av!=0) ;
            a[n-1]+=m ;
            int cnt = 0 ;
            for(int i = 0;i<n;i++){
                if(a[i]<av)cnt++ ;
            }
            int tot = (n)/2 ;
            if(cnt>tot){
                ans = m ;
                h = m-1 ;
            }
            else l = m+1 ;
            a[n-1]-=m ;
            s-=m ;
        }
        cout<<ans<<endl ;

       }

    return 0;
}
