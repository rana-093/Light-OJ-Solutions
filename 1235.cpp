#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll long long int
#define endl "\n"
#define db(x) cout<<#x<<" ->"<<x<<endl
#define db2(x,y) cout<<#x<<"->"<<x<<", "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define db4(w,x,y,z) cout<<#w <<" -> " << w << " , " << #x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++) { cout<<*it<<" "; } cout<< endl
#define IN freopen("input.txt","r",stdin)
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = (int)1e5+5;
vector< int > V;

void f(int idx,int lim,ll sum,vector< int >&v){
    if(idx==lim){ v.push_back(sum) ; return ; }
    for(int i = 0; i < 3 ; i++){
        f(idx+1,lim,sum+(i * V[idx]),v);
    }
}

int32_t main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
    int tc;
    cin >> tc;
    int cs = 0;
    while(tc--){
        int n , k;
        cin >> n >> k;
        V.clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            V.push_back(x);
        }
        int sz = V.size();
        int cur = (sz + 1) / 2;
//        db2(cur,sz);
        vector< int > A , B;
        f(0,cur,0,A);
        f(cur,sz,0,B);
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        B.erase(unique(B.begin(),B.end()),B.end());
//        prt(A);
//        prt(B);
//        cout << "==================" << endl;
        bool fl = 0;
        if(binary_search(A.begin(),A.end(),k)){
            fl = 1;
        }
        if(fl){
            cout << "Case " << ++cs << ": " << "Yes" << endl;
            continue;
        }
        for(int i = 0; i < A.size(); i++){
            int cur = A[i];
            int lagbe =  k - cur;
            if(binary_search(B.begin(),B.end(),lagbe)){
                fl = 1; break;
            }
        }
        if(fl){
            cout << "Case "<< ++cs << ": " << "Yes" << endl;
            continue;
        }
        cout << "Case " << ++cs << ": " << "No" << endl;
    }
    return 0;
}
