#include<bits/stdc++.h>
 
using namespace std;
 
#define maxn 100010
#define ll long long int
#define db(x) cout<<#x<<" -> "<<x<<endl
#define db2(x,y) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++) { cout<<*it<<" "; } cout<<endl
#define IN freopen("input.txt","r",stdin)
 
struct node{
    int mini, maxi;
}tree[ 4 * maxn ];
int data[maxn];
 
void build(int node, int b, int e){
    if( b == e ){
        tree[ node ].maxi = data[ b ];
        tree[ node ].mini = data[ b ];
        return ;
    }
    int mid = (b+e)>>1; int left = node<<1; int right = left + 1 ;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[ node ].maxi = max( tree[ left ].maxi , tree[ right ].maxi );
    tree[ node ].mini = min( tree[ left ].mini , tree[ right ].mini );
}
 
int Get_Max(int node, int b, int e, int i, int j){
    if( i > e || j < b ){ return -(int)1e8+10; }
    if ( b >= i && e <= j ){
        return tree[ node ].maxi;
    }
    int mid = (b+e)>>1; int left = node<<1; int right = left + 1 ;
    return max( Get_Max(left,b,mid,i,j) , Get_Max(right,mid+1,e,i,j) ) ;
}
 
int Get_Min(int node, int b, int e, int i, int j){
    if( i > e || j < b ){ return (int)1e8+10; }
    if ( b >= i && e <= j ){
        return tree[ node ].mini;
    }
    int mid = (b+e)>>1; int left = node<<1; int right = left + 1 ;
    return min( Get_Min(left,b,mid,i,j) , Get_Min(right,mid+1,e,i,j) ) ;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 //   IN;
    int t;
    cin>>t;
    int tc = 0;
    while(t--){
        int n, d;
        cin>>n>>d;
        for(int i=1; i<=n; i++){
            cin>>data[i];
        }
        build(1,1,n);
        int ans = 0;
        for(int i=1; i+d-1<=n; i++){
            int x = Get_Max(1,1,n,i,i+d-1);
            int y = Get_Min(1,1,n,i,i+d-1);
            ans = max(ans,abs(x-y));
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}

