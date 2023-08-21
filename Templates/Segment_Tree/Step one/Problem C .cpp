#include <bits/stdc++.h>
#include <unordered_map>
#define dp double
#define ll long long
#define F .first
#define S .second
#define el << "\n"
#define pob pop_back
#define pub push_back
#define ve v.end()
#define vb v.begin()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define test_case int t; cin >> t; while (t--)
#define lop(i, a, n) for (ll i = a; i < n; i++)
#define pol(i, a, n) for (ll i = (n - 1); i >= a; i--)
#define rd  vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
void El_DamitY()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
int O = 2e9+9;

struct item {
	int num, rep;
};

struct segtree {

	int size;
	vector<item> sums;
	void init (int n)
	{
		size = 1;
		while (size < n) size*=2;
		sums.resize(2 * size);
	}

	item com (item a, item b)
	{
		if (a.num < b.num) return a;
		else if (b.num < a.num) return b;
		return {a.num, a.rep + b.rep};
	}

	void built (vector<int> &v, int x, int lx, int rx)
	{
		if (rx == lx)
		{
			if (lx <= v.size())
				sums[x] = {v[lx-1], 1};
			return;
		}
		int m = (lx + rx) / 2;
		built(v, 2 * x , lx, m);
		built(v, 2 * x + 1, m + 1, rx);
		sums[x] = com(sums[2 * x] , sums[2 * x + 1]);
	}

	void built (vector<int> &v)
	{
		built (v, 1, 1, size);
	}

	void set (int i, int num, int x, int lx, int rx)
	{
		if (rx == lx)
		{
			sums[x] = {num, 1};
			return;
		}
		int m = (lx + rx) / 2;
		if (i <= m)
			set(i, num, 2 * x, lx, m);
		else
			set(i, num, 2 * x + 1, m + 1, rx);
		sums[x] = com(sums[2 * x] , sums[2 * x + 1]);
	}

	void set (int i, int num)
	{
		set(i, num, 1, 1, size);
	}


	item cal (int l, int r, int x, int lx, int rx) // 1 3 // 1 8
	{
		if (lx > r || l > rx) return {O, 0};
		if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		item sl = cal(l, r, 2 * x , lx, m);
		item sr = cal(l, r, 2 * x + 1, m + 1, rx);
		return com(sl , sr);
	}

	item cal (int l, int r)
	{
		return cal(l, r, 1, 1, size);
	}

};

void solve()
{
	int n, m; cin >> n >> m;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	segtree st;
	st.init(n);
	st.built(v);
	while (m--)
	{
		int op; cin >> op;
		if (op == 1)
		{
			int i, num; cin >> i >> num;
			st.set(i+1, num);
		}
		else
		{
			int l, r; cin >> l >> r;
			item ans = st.cal(l+1, r);
			cout << ans.num << " " << ans.rep el;
		}
	}
}

signed main()
{
	El_DamitY();
	//file();
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
}
