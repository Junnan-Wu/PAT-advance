//1138 Postorder Traversal
#include<iostream>
#include<vector>

using namespace std;

vector<int> preorder, inorder, postorder;
int N;
void input();
void build_tree(int root, int start, int end);

int main()
{
	input();
	build_tree(0, 0, N - 1);
	cout << postorder[0] << endl;
	return 0;
}

void input()
{
	scanf("%d", &N);
	preorder.resize(N);
	inorder.resize(N);
	for (int i = 0; i < N; i++)
		cin >> preorder[i];
	for (int i = 0; i < N; i++)
		cin >> inorder[i];
	return;
}

void build_tree(int root, int start, int end)
{
	//一旦postorder中有元素，直接退出
	if (postorder.size() != 0)
		return;
	//start与end是inorder的起点与终点（包含end）
	//root是preorder的根节点的位置
	if (start > end)
		return;
	int i = start;
	while (i<end && inorder[i] != preorder[root])i++;//找到中序的根节点位置
	//继续找左树
	build_tree(root+1, start, i-1);
	//继续找右树
	build_tree(root + 1 + i - start, i + 1, end);
	postorder.push_back(preorder[root]);
	return;
}
