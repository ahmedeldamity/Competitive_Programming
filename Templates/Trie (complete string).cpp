class Trie {

public:

	struct node
	{
		node*child[26];
		bool terminate;
		node ()
		{
			terminate = 0;
			memset(child,0,sizeof child);
		}
	};
	node*root = new node();

	void insert(string s)
	{
		node*cur=root;
		for(auto it:s)
		{
			int idx=it-'a';
			if(cur->child[idx] == 0)
			{
				cur->child[idx]=new node();
			}
			cur=cur->child[idx];
		}
		cur->terminate = true;
	}

	bool checkIsPrefix (string s)
	{
		node*cur=root;
		for(auto it:s)
		{
			int idx=it-'a';
			if(cur->child[idx] == 0)
			{
				return false;
			}
			cur=cur->child[idx];
			if (cur->terminate == 0) return false;
		}
		return true;
	}

};
