#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;

class UnionFind {
	private: vi p, rank;
	public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
} } };

int main() {
	int n,u,v,w;
	cin>>n;
	vector< pair<int, ii> > EdgeList;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &u, &v, &w);
		EdgeList.push_back(make_pair(w, ii(u, v))); }
	sort(EdgeList.begin(), EdgeList.end());
	int mst_cost = 0;
	UnionFind UF(n);
	for (int i = 0; i < n; i++) {
		pair<int, ii> front = EdgeList[i];
		if (!UF.isSameSet(front.second.first, front.second.second)) {
			mst_cost += front.first;
			UF.unionSet(front.second.first, front.second.second);
		}
	}
	printf("MST cost = %d (Kruskal’s)\n", mst_cost);
	return 0;
}
