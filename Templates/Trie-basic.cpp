// insert and search
struct Trie{
	struct Node{
		Node*child[26];
		int terminate;
		Node(){
			memset(child,0,sizeof child);
			terminate = 0;
		}
	};
	Node*root=new Node();
	void insert(string &s)
	{
		Node*cur=root;
		for(auto it:s)
		{
			int idx=it-'a';
			if(cur->child[idx] == 0)
			{
				cur->child[idx]=new Node();
			}
			cur=cur->child[idx];
		}
		cur->terminate = 1;
	}
	int find (string &s)
	{
		Node*cur=root;
		for(auto it:s)
		{
			int idx=it-'a';
			if (cur->child[idx] == 0) return -1;
			cur=cur->child[idx];
		}
		return cur->terminate;
	}
};
