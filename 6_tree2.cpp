#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#pragma warning(disable:4996)

FILE* out = fopen("tree2.out", "wt");
FILE* inp = fopen("tree2.inp", "rt");
vector<int> pre, in, post;

vector<int> slice(const vector<int>& v, int a, int b) {

	return vector<int>(v.begin() + a, v.begin() + b);

}
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	const int N = preorder.size();
	if (preorder.empty()) return; //Ʈ��  ��� ����
	const int root = preorder[0];

	int i;
	for (i = 0; i < inorder.size(); i++) {
		if (inorder[i] == root)break;
	}
	const int L = i;
	const int R = N - 1 - L; //������ ����Ʈ��

	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	fprintf(out, "%d\n", root); //������ȸ�̹Ƿ� ���� �������� ��Ʈ ���

}

void printPreOrder(const vector<int>& postorder, const vector<int>& inorder) {

	const int N = inorder.size();
	if (postorder.empty()) return; //Ʈ��  ��� ����
	const int root = postorder[postorder.size() - 1]; // ��Ʈ�� ������ȸ ������

	//44�� ��Ʈ�� �̾Ƴ����ϴµ�,, �׷��� N������ �ƴ϶� L+1~ N-1���� �߶���ϴµ�,..

	int i;
	for (i = 0; i < inorder.size(); i++) {
		if (inorder[i] == root)
		{
			break; //������ȸ���� root ã��
		}
	}
	const int L = i; //���� ����Ʈ��
	const int R = N - 1 - L; //������ ����Ʈ��

	fprintf(out, "%d\n", root); //������ȸ�̹Ƿ�
	printPreOrder(slice(postorder, 0, L), slice(inorder, 0, L));
	if (N - L <= 0)
	{
		printPreOrder(slice(postorder, L + 1, N), slice(inorder, L + 1, N));
	}
	else
	{
		printPreOrder(slice(postorder, L, N - 1), slice(inorder, i + 1, N));
	}

}


int main() {
	int test;
	int flag[2] = { 9,9 };
	fscanf(inp, "%d", &test);
	for (int t = 0;t < 2;t++) {
		int a = 0;
		int N;

		fscanf(inp, "%d", &N);
		if (N == -1) //������ȸ(preorder)
		{
			flag[t] = N;
			for (int i = 0; i < test; i++) {
				fscanf(inp, "%d", &a);
				pre.push_back(a);
			}
		}
		else if (N == 0) //������ȸ(inorder)
		{
			flag[t] = N;
			for (int i = 0; i < test; i++) {
				fscanf(inp, "%d", &a);
				in.push_back(a);
			}
		}
		else // ������ȸ(postorder)
		{
			flag[t] = N;
			for (int i = 0; i < test; i++) {
				fscanf(inp, "%d", &a);
				post.push_back(a);
			}
		}

		if ((flag[0] == -1 && flag[1] == 0) || (flag[0] == 0 && flag[1] == -1)) // pre + in
		{
			printPostOrder(pre, in);
			fprintf(out, "\n");

		}

		else if ((flag[0] == 0 && flag[1] == 1) || (flag[0] == 1 && flag[1] == 0)) //in + post
		{
			printPreOrder(post, in);
			fprintf(out, "\n");
		}


	}//test

	return 0;
}