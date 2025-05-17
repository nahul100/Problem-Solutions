#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
          int n,m;cin>>n>>m ;

          int a[n][m] ;
          for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)cin>>a[i][j] ;
          }
          int x = max(n,m) ;
          int pref[x][x] ,suf[x][x] ;
          for(int i = 0;i<n;i++)pref[i][0] = a[i][0] ;
          for(int i = 0;i<n;i++)suf[m-1][i] = a[i][m-1];
          for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                    pref[i][j] = pref[i][j-1]+a[i][j] ;
            }
            for(int j = m-2;j>=0;j--){
                suf[j][i] = suf[j+1][i]+a[i][j] ;
            }
          }
          int p[x][x],s[x][x] ;
          for(int i = 0;i<m;i++)p[i][0] = a[0][i] ;
          for(int i = 0;i<m;i++)s[n-1][i] = a[n-1][i] ;
          for(int i = 0;i<m;i++){
            for(int j = 1;j<n;j++){
                 p[i][j] = p[i][j-1]+a[j][i] ;
            }
            for(int j = n-2;j>=0;j--){
                s[j][i] = s[j+1][i]+a[j][i] ;
            }
          }
          int c = 0 ;
          for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(a[i][j] == 0){
                    if(j && pref[i][j-1]>=1)c++ ;
                    if(j!=m-1 && suf[j+1][i]>=1)c++ ;
                }
            }
          }
          for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
              if(a[j][i] == 0){
                  if(j && p[i][j-1]>=1)c++ ;
                  if(j!=n-1 && s[j+1][i]>=1)c++ ;

              }
            }
          }
          cout<<c<<endl;


          return 0 ;
}
