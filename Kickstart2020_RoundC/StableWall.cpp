
/*
Author: Harshit Singh
Passed: AC (8pts,13pts)
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) (int)((x).size())
#define forn(i,n) for (int i=0; i < n; i++)
#define forse(i,s,e) for (int i=s; i < e; i++)
#define pb push_back
#define pf push_front
#define rb pop_back
#define rf pop_front
#define mp make_pair
#define fi first
#define se second
#define all(vec) vec.begin(), vec.end()
#define time() ((double)clock() / CLOCKS_PER_SEC)

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mx=26;
vector<int> adj[mx];
bool nd[mx]={};
int ind[mx]={};

vector<int> tsor;

void dfs(int u){
	nd[u]=1;
	for(auto i:adj[u]){
		if(nd[i]) continue;
		dfs(i);
	}
	tsor.pb(u);
	ind[u]=sz(tsor);
}

void solve(){
	forn(i,mx){
		tsor.clear();
	   	adj[i].clear();
		nd[i]=0;
		ind[i]=0;
	}

	int r,c;
	cin >> r >> c;
	vector<vector<int>> in(r,vector<int>(c));
	set<int> isn;
	forn(i,r){
		string inp;
		cin >> inp;
		forn(j,c){
			in[i][j]=inp[j]-'A';
			isn.insert(in[i][j]);
		}
	}
	for(auto cur:isn){
		forn(i,r-1){
			forn(j,c){
				if(in[i][j]==cur&&in[i+1][j]!=cur){
					adj[cur].pb(in[i+1][j]);
				}
			}
		}
	}

	for(auto cur:isn){
		if(!nd[cur]){
			dfs(cur);
		}
	}

	bool chk=1;
	for(auto cur:isn){
		for(auto v:adj[cur]){
			if(ind[v]>ind[cur]) chk=0;
		}
	}
	if(!chk) cout << "-1\n";
	else{
		for(auto i:tsor) cout << (char)('A'+i);
		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int T=1;
	cin >> T;
	forn(c,T){
		cout << "Case #" << c+1 << ": ";
		solve();
	}
}
