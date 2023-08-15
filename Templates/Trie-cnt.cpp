// how many strings start with s
// how many strings equal s

class Trie {
public:

	struct node
	{
		node*child[26];
		int terminate, cnt_pfx;
		node ()
		{
			terminate = cnt_pfx = 0;
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
			cur->cnt_pfx++;
		}
		cur->terminate++;
	}

	int cnt_word (string s)
	{
		node*cur=root;
		for(auto it:s)
		{
			int idx=it-'a';
			if (cur->child[idx] == 0) return false;
			cur=cur->child[idx];
		}
		return cur->terminate;
	}


	int cnt_word_startsWith(string s)
	{
		node*cur=root;
		for(auto it:s)
		{
			int idx=it-'a';
			if (cur->child[idx] == 0) return false;
			cur=cur->child[idx];
		}
		return cur->cnt_pfx;
	}
};
