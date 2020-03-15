#include<bits/stdc++.h>
///#include <ext/pb_ds/assoc_container.hpp>
///#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
///using namespace __gnu_pbds;

#define ll long long
#define endl "\n"
#define db(x) cout<<#x<<" ->"<<x<<endl
#define db2(x,y) cout<<#x<<"->"<<x<<", "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define db4(w,x,y,z) cout<<#w <<" -> " << w << " , " << #x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++) { cout<<*it<<" "; } cout<< endl
#define IN freopen("input.txt","r",stdin)

///typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int maxn = (int)2e5+5;
const ll mod = (ll)1e9+7 ;

namespace NumberTheory{

    ll fact[maxn+5];
    ll inverseFact[maxn+5];
    vector< int > Prime;
    bool vis[maxn+5];

    void seive(){
        for(int i=2; i*i<=maxn; i++){
            if(vis[i]==0){
                for(int j=(2*i); j<=maxn; j+=i){
                    vis[j] = true;
                }
            }
        }
        Prime.push_back(-1);
        Prime.push_back(2);
        for(int i=3; i<=maxn; i+=2){
            if(vis[i]==0){
                Prime.push_back(i);
            }
        }
    }

    ll bigmod(ll a, ll n){
        if( n==0 ) { return 1LL; }
        if( n%2==0 ){
            ll ret = bigmod(a,n/2);
            return ( (ret%mod) * (ret%mod) ) % mod;
        }
        else { return ( ( a % mod ) * ( bigmod(a,n-1) % mod ) ) % mod ; }
    }

    ll modInverse(ll a){
        return bigmod(a,mod-2)%mod;
    }

    ll nCr(int n, int r){
        ll ans = (1LL*(fact[n] * inverseFact[r])%mod * inverseFact[n-r]) % mod ;
        return (ans%mod);
    }

    void PreProcess(){
        fact[0] = 1LL;
        for(int i=1; i<=maxn; i++){ fact[i] = (  1LL * fact[i-1] *  i )  % mod ; }
        inverseFact[maxn] = modInverse(fact[maxn]) ;
        for(int x=maxn-1 ; x>=0 ; x--) inverseFact[x] = ( 1LL * inverseFact[x+1] * (x+1) ) % mod ;
    }

    vector< pair< int , int >  > f(int x){
        vector< pair< int , int > > temp;
        for(int i=0; Prime[i]*Prime[i]<=x; i++){
            if(x%Prime[i]==0){
                int cnt = 0;
                while(x%Prime[i]==0){
                    cnt++;
                    x/=Prime[i];
                }
                temp.push_back( make_pair(Prime[i],cnt) );
            }
        }
        if(x>1){
            temp.push_back(make_pair(x,1));
        }
        return temp;
    }
}

using namespace NumberTheory;
ll dp[505][505];
ll mul[505] ;
ll inverse[505];
int m , oo;
int n,p;

ll solve(int pos, int taken){
    if(taken == 0){ return 1LL ;  }
    if(pos == 0){
        if(taken!=0){ return 0LL ; }
        return 1LL ;
    }
    ll &ret = dp[pos][taken] ;
    if(ret!=-1){ return ret ; }
    ret = 0LL;
    ll temp = 1LL;
    for(int i = 0; i <= taken ; i++){
        ret+=( temp % mod  * solve(pos-1,taken-i) ) % mod;
        ret%=mod;
        temp*=Prime[pos] % mod;
        temp%=mod;
    }
    ret%=mod;
    return dp[pos][taken] = ret % mod;
}

int32_t main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
    seive();
    ll lol = 1LL;
    for(int i = 1; i <= 500; i++){
        lol*=( 1LL * ( (Prime[i]-1) ) % mod  ) % mod;
        lol%=mod;
        inverse[i] = lol;
    }
    int tc;
    cin >> tc;
    int cs = 0;
    memset(dp,-1,sizeof(dp));
    while(tc--){
        cin >> n >> p;
        m = p , oo = n - p ;
        ll ans = ( solve(m,oo) % mod * inverse[p] % mod ) % mod;
        ans+=mod;
        ans%=mod;
        cout <<"Case "<<++cs<<": "<< ans << endl;
    }
    return 0;
}
