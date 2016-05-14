#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct node
{
	int value;
	node* left;
	node* right;

	node(int val) : value(val), left(NULL), right(NULL){}
	~node()
	{
		delete left;
		delete right;
	}
} node;

//this solution exceeds the time limit 
int main()
{
	int n, a;
	cin >> n >> a;
	node* root = new node(a);
	string ret;

	for(int i = 1; i < n; ++i)
	{
		cin >> a;

		node* cur = root;
		while(cur != NULL)
		{
			if(cur->value < a)
			{
				if(cur->right == NULL)
				{
					ret += std::to_string(cur->value) + ' ';
					cur->right = new node(a);
					break;
				}	
				cur = cur->right;
			}
			else
			{
				if(cur->left == NULL)
				{
					ret += std::to_string(cur->value) + ' ';
					cur->left = new node(a);
					break;
				}	
				cur = cur->left;
			}
		}
	}
	cout << ret << endl;

	delete root;
	
	return 0;
}