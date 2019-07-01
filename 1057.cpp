#include<bits/stdc++.h>
 
using namespace std;
 
#define maxn 100005
#define ll long long int
#define db(x) cout<<#x<<" -> "<<x<<endl
#define db2(x,y) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++){cout<<*it<<" " ;}cout<<endl
#define IN freopen("input.txt","r",stdin)
int n,m;
char xD[25][25];
vector< pair< int , int > > V ;
int dp[20][(1<<16)+5];
int cnt = 0 ;
 
int dist(int i,int j){
    int x = abs(V[i].first-V[j].first);
    int y = abs(V[i].second-V[j].second);
    return max(x,y);
}
 
int solve(int Prev , int mask){
    if(mask==( (1<<cnt)-1) ) { return dist(0,Prev) ; }
    if(dp[Prev][mask]!=-1){
        return dp[Prev][mask];
    }
    int ret = 1<<29;
    for(int i=0; i<V.size(); i++){
        if(mask&(1<<i)){ continue ; }
        ret = min( ret , dist(i,Prev)+solve(i,mask|(1<<i)));
    }
    return dp[Prev][mask] = ret;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN ;
    int tc,cs=0;
    cin>>tc ;
    while(tc--){
        cin>>n>>m;
        V.clear() ;
        pair< int , int > Prev ;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>xD[i][j];
                if(xD[i][j]=='x'){
                    V.push_back({i,j});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
//                cin>>xD[i][j];
                if(xD[i][j]=='g'){
                    V.push_back({i,j});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        cnt = V.size();
        int cost = solve(0,1);
        cout<<"Case "<<++cs<<": "<<(cost)<<endl;
    }
    return 0;
}

