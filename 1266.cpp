#include<bits/stdc++.h>
 
using namespace std;
 
#define maxn 1000005
#define ll long long int
#define db(x) cout<<#x<<" -> "<<x<<endl
#define db2(x,y) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++){cout<<*it<<" " ;}cout<<endl
#define IN freopen("input.txt","r",stdin)
int BIT[1005][1005];
int mx = 1005;
void Update(int x, int y,int val){
    while(x<=mx){
        int y1 = y;
        while(y1<=mx){
            BIT[x][y1]+=val;
            y1+=(y1 & -y1);
        }
        x+=(x & -x);
    }
}
 
int Query(int x,int y){
    int sum = 0 ;
    while(x > 0){
        int y1 = y;
        while( y1 > 0 ){
            sum+=BIT[x][y1] ;
            y1-=(y1 & -y1);
        }
        x-=(x & -x);
    }
    return sum ;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN ;
    int tc;
    cin>>tc;
    map< pair< int , int > , bool > M ;
    int cs = 0;
    while(tc--){
        memset(BIT,0,sizeof(BIT)); M.clear() ;
        int q;
        cin>>q;
        printf("Case %d:\n",++cs);
        while(q--){
            int type; cin>>type;
            if(type){
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2; x1++ ; y1++; x2++; y2++;
                int ans = Query(x2,y2)-Query(x2,y1-1)-Query(x1-1,y2)+Query(x1-1,y1-1);
                printf("%d\n",ans);
            }
            else{
                int x,y;
                cin>>x>>y; x++; y++;
                if(!M[ {x,y} ]){
                    Update(x,y,1) ;
                    M[ {x,y} ] = true ;
                }
            }
        }
    }
    return 0 ;
}
