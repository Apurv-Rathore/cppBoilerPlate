#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define int long long
#define rep(i,n) for (int i=0;i<n;i++)
#define repi(i,x,n) for (int i=x;i<n;i++)
#define br cout<<endl
#define vi vector<int>
using namespace std;
int nocmp;
int largest;


int p[100001];
int sz[100001];
int parent(int x){
    if (x==p[x]) return x;
    p[x]=parent(p[x]);
    return p[x];
}
void unionn(int a, int b){
    if (sz[a]<sz[b]){
        swap(a,b);
    }
    if (a!=b){
        p[b]=a;
        sz[a]+=sz[b];
        largest=max(largest,sz[a]);
    }
}
void solve(){
    rep(i,100001) {
        p[i]=i;
        sz[i]=1;
    }
	int n,m;
    cin>>n>>m;
    largest=1;
    nocmp=n;
    rep(i,m){
        int a,b;
        cin>>a>>b;   
        
        int pa = parent(--a);
        int pb = parent(--b);

        if (pa!=pb){
            nocmp-=1;
            unionn(pa,pb);
        }
        
        cout<<nocmp<<" "<<largest<<endl;
    }

}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastio
    int t;
    t = 1;
    // cin>>t;
    while(t--){
		solve();
	}
}
