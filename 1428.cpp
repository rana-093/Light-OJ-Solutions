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

const int N = (int)5e4+5;

namespace SuffixArray{

    vector<int> sort_cyclic_shifts(string const& s) {
        int n = s.size();
        const int alphabet = 256;
        vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++)
            cnt[i] += cnt[i-1];
        for (int i = 0; i < n; i++)
            p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i-1]])
                classes++;
            c[p[i]] = classes - 1;
        }
        vector<int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)
                    pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++)
                cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i-1];
            for (int i = n-1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
                if (cur != prev)
                    ++classes;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
        return p;
    }

    vector<int> suffix_array_construction(string s) {
        s += "$";
        vector<int> sorted_shifts = sort_cyclic_shifts(s);
        sorted_shifts.erase(sorted_shifts.begin());
        return sorted_shifts;
    }

    vector<int> lcp_construction(string const& s, vector<int> const& p) { /// LCP in O(1)
        int n = s.size();
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            rank[p[i]] = i;

        int k = 0;
        vector<int> lcp(n-1, 0);
        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < n && j + k < n && s[i+k] == s[j+k])
                k++;
            lcp[rank[i]] = k;
            if (k)
                k--;
        }
        return lcp;
    }
}

namespace kmp{
    #define maxn 50005 /// max string length
    int lps[maxn];
    string pattern,text;
    int NN,MM; ///MM -> pattern.size() , NN->text.size()
//    NN = text.size();
//    MM = pattern.size();

    void ComputeLPS(){
        int len = 0;
        lps[0] = 0;
        int i=1;
        while(i < pattern.size()){
            if(pattern[len]==pattern[i]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector< int >  kmp(){
        vector< int > V;
        int i=0;
        int cnt = 0;
        int j=0; //i for text, j for pattern
        while(i < text.size()){
            if(text[i]==pattern[j]){
                i++;
                j++;
            }
            if(j==pattern.size()){
                cnt++;
                V.push_back(i-1);
                j = lps[j-1];
            }
            else if(text[i]!=pattern[j]){
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return V;
    }
}


int32_t main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
    int tc;
    cin >> tc;
    int cs = 0;
    while(tc--){
        string A , B;
        cin >> A >> B;
        kmp::text = A , kmp::pattern = B;
        kmp::ComputeLPS();
        vector< int > V = kmp::kmp();
        vector< int > p = SuffixArray::suffix_array_construction(A);
        vector< int > lcp = SuffixArray::lcp_construction(A,p);
//        prt(temp);
//        prt(V);
        ll ans = 0LL;
        int sz = A.size();
        int szB = B.size();
        for(int i = 0; i < p.size() ; i++){
            int len = sz - p[i];
            auto it = lower_bound(V.begin(),V.end(),p[i]+szB-1);
            int cur = -1;
            if(it==V.end()){
                cur = len;
//               cout << "here" << endl;
            }
            else{
                int res = *it;
                cur = res - p[i];
            }
            int l = (i > 0) ? lcp[i-1] : 0;
            int test = *it;
            cur-=l;
            cur = max(cur,0);
            ans+=cur;
        }
        cout << "Case " << ++cs <<": " << ans << endl;
    }
    return 0;
}
