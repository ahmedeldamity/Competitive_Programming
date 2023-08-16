struct Trie {

	struct Node {

		Node*child[2];
		Node ()
		{
			memset(child,0,sizeof child);
		}
	};

	Node*root = new Node();

	void insert (int num)
	{
		Node*cur = root;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (num >> i) & 1;
			if (cur->child[bit] == 0)
			{
				cur->child[bit] = new Node();
			}
			cur = cur->child[bit];
		}
	}

	int returnMax (int num)
	{
		Node*cur = root;
		int mx = 0;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (num >> i) & 1;
			if (cur->child[1 - bit] != 0)
			{
				mx = mx | (1 << i);
				cur = cur->child[1 - bit];
			}
			else
			{
				cur = cur->child[bit];
			}
		}
		return mx;
	}

};
