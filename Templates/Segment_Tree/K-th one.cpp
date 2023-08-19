struct segtree {

	int size;
	vector<int> sums;
	void init (int n)
	{
		size = 1;
		while (size < n) size*=2;
		sums.resize(2 * size);
	}

	int com (int a, int b)
	{
		return a + b;
	}

	void built (vector<int> &v, int x, int lx, int rx)
	{
		if (rx == lx)
		{
			if (lx <= v.size())
			{
				sums[x] = v[lx-1];
			}
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
			sums[x] = num;
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

	int cal (int i, int x, int lx, int rx) // 1 3 // 1 8
	{
		if (rx == lx)
		{
			return lx - 1;
		}
		int m = (lx + rx) / 2;
		int s = sums[2 * x];
		if (i <= s) return cal (i, 2 * x, lx, m);
		else
			return cal (i-s, 2 * x + 1, m + 1, rx);
	}

	int cal (int i)
	{
		return cal(i, 1, 1, size);
	}

};
