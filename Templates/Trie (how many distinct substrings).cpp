class Trie {

public:

	struct node
	{
		node*child[26];
		node ()
		{
			memset(child,0,sizeof child);
		}
	};
	node*root = new node();

	int insert(string s)
	{
		int cnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			node *cur = root;
			for (int j = i; j < s.size(); j++)
			{
				int idx = s[j] - 'a';
				if (cur->child[idx] == 0)
				{
					cnt++;
					cur->child[idx] = new node();
				}
				cur = cur->child[idx];
			}
		}
		return cnt+1;
	}
};
