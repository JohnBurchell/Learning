struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode *root) {
	
		int max = -99999999;
		totalRoot(root, max);
		return max;
	}

	int totalRoot(TreeNode *root, int& max)
	{
		if (!root)
		{
			return 0;
		}

		int left = std::max(0, totalRoot(root->left, max));
		int right = std::max(0, totalRoot(root->right, max));

		max = std::max(max, left + right + root->val);

		return root->val + std::max(left, right);
	}

	/*

	*/
};

void main()
{
	Solution solution{};	
	TreeNode* treeNode = new TreeNode{ -3 };

	std::cout << solution.maxPathSum(treeNode) << std::endl;

	delete(treeNode->left);
	delete(treeNode->right);
	delete(treeNode);

	//Not portable, remove on linux
	system("pause");
}