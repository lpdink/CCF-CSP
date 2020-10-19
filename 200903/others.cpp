#include<bits/stdc++.h>
#define TLE ios::sync_with_stdio(0),cin.tie(0)
#define long long ll
const int INF = 0x3f3f3f3f;
const int maxn = 2 * 10005;
using namespace std;
map<string, int> mp;
int Opter[maxn], In[maxn], InDeg[maxn], k, m, n, T, s, cnt = 0, ans[maxn];
vector<int> vec[maxn], InVec[maxn], Inp_Num[maxn], Outp_Oper[maxn], topo;
queue<int> q;
inline int GetNum(string str) {
	int temp = 0;
	for (int j = 1; j < str.length(); ++j) {
		temp = temp * 10 + (str[j] - '0');
	}
	return temp;
}
void Init() {
	memset(Opter, 0, sizeof(Opter));
	memset(In, 0, sizeof(In));
	memset(InDeg, 0, sizeof(InDeg));
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i <= n + m; ++i) {
		vec[i].clear();
		InVec[i].clear();
	}
	for (int i = 0; i <= s; ++i) {
		Inp_Num[i].clear();
		Outp_Oper[i].clear();
	}
	topo.clear();
	while (!q.empty()) q.pop();
	cnt = 0;
}
int main() {
	TLE;
	mp["NOT"] = 1; mp["AND"] = 2; mp["OR"] = 3;
	mp["XOR"] = 4; mp["NAND"] = 5; mp["NOR"] = 6;
	cin >> T;
	while (T--) {
		Init();
		cin >> m >> n;
		for (int i = 1; i <= n; i++) {
			string opt, inp_s;
			cin >> opt >> k;
			Opter[i] = mp[opt];
			while (k--) {
				cin >> inp_s;
				int num = GetNum(inp_s);
				if (inp_s[0] == 'I') {
					vec[num + n].push_back(i); //OutDeg 
					InDeg[i]++;
				}
				else if (inp_s[0] == 'O') {
					vec[num].push_back(i);
					InDeg[i]++;
				}
			}
		}
		cin >> s;
		int t, ss;
		for (int i = 1; i <= s; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> t;
				Inp_Num[i].push_back(t);
			}
		}
		for (int i = 1; i <= s; ++i) {
			cin >> ss;
			while (ss--) {
				cin >> t;
				Outp_Oper[i].push_back(t);
			}
		}
		for (int i = 1; i <= n + m; ++i) {
			if (0 == InDeg[i]) q.push(i);
		}
		while (!q.empty()) {
			int now = q.front(); q.pop();cnt++; topo.push_back(now);
			for (int i = vec[now].size()-1; i >=0 ; --i) {
				InDeg[vec[now][i]]--; InVec[vec[now][i]].push_back(now);
				if (0 == InDeg[vec[now][i]]) q.push(vec[now][i]);
			}
		}
		if (cnt!=n+m) cout << "LOOP" << endl;
		else {
			for (int t = 1; t <= s; ++t) {
				for (int i = 1; i <= m; ++i) ans[i + n] = Inp_Num[t][i - 1];
				for (int i = 0; i < topo.size(); ++i) {
					if (topo[i] > n) continue;
					if (Opter[topo[i]] == 1) {
						ans[topo[i]] = !ans[InVec[topo[i]][0]];
					}
					else if (Opter[topo[i]] == 2) {
						ans[topo[i]] = ans[InVec[topo[i]][0]];
						for (int j = 1; j < InVec[topo[i]].size(); j++) {
							ans[topo[i]] &= ans[InVec[topo[i]][j]];
						}
					}
					else if (Opter[topo[i]] == 3) {
						ans[topo[i]] = ans[InVec[topo[i]][0]];
						for (int j = 1; j < InVec[topo[i]].size(); j++) {
							ans[topo[i]] |= ans[InVec[topo[i]][j]];
						}
					}
					else if (Opter[topo[i]] == 4) {
						ans[topo[i]] = ans[InVec[topo[i]][0]];
						for (int j = 1; j < InVec[topo[i]].size(); j++) {
							ans[topo[i]] ^= ans[InVec[topo[i]][j]];
						}
					}
					else if (Opter[topo[i]] == 5) {
						ans[topo[i]] = ans[InVec[topo[i]][0]];
						for (int j = 1; j < InVec[topo[i]].size(); j++) {
							ans[topo[i]] &= ans[InVec[topo[i]][j]];
						}
						ans[topo[i]] = !ans[topo[i]];
					}
					else if (Opter[topo[i]] == 6) {
						ans[topo[i]] = ans[InVec[topo[i]][0]];
						for (int j = 1; j < InVec[topo[i]].size(); j++) {
							ans[topo[i]] |= ans[InVec[topo[i]][j]];
						}
						ans[topo[i]] = !ans[topo[i]];
					}
				}
				for (int i = 0; i < Outp_Oper[t].size(); ++i) cout<<ans[Outp_Oper[t][i]]<<" "; 
				cout<<endl; 
			}
		}
	}
}
