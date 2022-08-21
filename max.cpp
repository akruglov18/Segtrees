#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<sstream>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<regex>
#include<list>

#define pb push_back
#define all(p) (p).begin(),(p).end()
#define rep(ind,sz) for(int (ind) = 0; (ind) < (sz); (ind)++)
#define vi vector<int>
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define ve vector
#define mp make_pair
#define PI 3.14159265358979323846
#define int long long

using namespace std;

struct segtree {
	vi t;
	int size;
	void init(int n) {
		size = 1;
		while (size < n)
			size *= 2;
		t.assign(2 * size - 1, 0);
	}
 
	void update(int x) {
		t[x] = max(t[2 * x + 1], t[2 * x + 2]);
	}
 
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			t[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		if (i < mid)
			set(i, v, 2 * x + 1, lx, mid);
		else
			set(i, v, 2 * x + 2, mid, rx);
		update(x);
	}
 
	int getMax(int x, int l, int r, int lx, int rx) {
		if (l >= rx || r <= lx) {
			return 0;
		}
		if (lx >= l && rx <= r) {
			return t[x];
		}
		int mid = (lx + rx) / 2;
		int m1 = getMax(2 * x + 1, l, r, lx, mid);
		int m2 = getMax(2 * x + 2, l, r, mid, rx);
		return max(m1, m2);
	}
 
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
 
	int getMax(int l, int r) {
		return getMax(0, l, r, 0, size);
	}
};
