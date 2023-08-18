// output min number and How Many Min Numbers in that segment 

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
