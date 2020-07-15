#include <stdio.h>
#include<queue>
#define MAX 1099
#pragma warning (disable:4996)
using namespace std;


int n, m, h, result;
int water[MAX][MAX];
int a[MAX][MAX], b[MAX][MAX];

int max(int a, int b) {
	int m = 0;
	if (a > b)m = a;
	else m = b;
	return m;
}
struct Data {
	int x, y, h;
	bool operator<(const Data& x)const {
		return h > x.h; //�⺻������ max hip (����ū�� ��������)
	}
};

priority_queue <Data> pq;

void Insert(int x, int y, int h) {
	Data temp;
	if (water[x][y]) return;
	temp.x = x;
	temp.y = y;
	temp.h = h;
	pq.push(temp);
}


int main() {

	FILE* out = fopen("watertank.out", "wt");
	FILE* inp = fopen("watertank.inp", "rt");

	int test;

	fscanf(inp, "%d", &test);


	for (int t = 0; t < test; t++) {
		fscanf(inp, "%d %d %d", &n, &m, &h);
		result = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				a[i][j] = 0, b[i][j] = 0, water[i][j] = 0;
			}
		}//�ʱ�ȭ

		for (int i = 1; i <= n + 1; i++) {
			for (int j = 1; j <= m; j++) { //����+1 * m��ŭ �ݺ�
				fscanf(inp, "%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m + 1; j++) { //���� * m+1��ŭ �ݺ�
				fscanf(inp, "%d", &b[i][j]);
			}
		}

		for (int i = 1; i <= n + 1; i++) {
			for (int j = 1; j <= m; j++) { //����+1 * m��ŭ �ݺ�
				if (a[i][j] == -1) {
					a[i][j] = h;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m + 1; j++) { //���� * m+1��ŭ �ݺ�
				if (b[i][j] == -1) {
					b[i][j] = h;
				}
			}
		}
		//�� ���� �ʱ�ȭ

		for (int i = 1; i <= n; i++) {
			Insert(i, 1, b[i][1]); //����
			Insert(i, m, b[i][m + 1]); //������
			water[i][0] = water[i][m + 1] = true;
		}
		for (int i = 1; i <= m; i++) {
			Insert(1, i, a[1][i]); //����
			Insert(n, i, a[n + 1][i]); //�Ʒ���
			water[0][i] = water[n + 1][i] = true;
		}
		//�ٱ��� �� üũ �Ϸ�


		Data temp;
		int x, y, h;
		while (pq.size()) {

			temp = pq.top(); //���� ���� ���� ���� top������
			pq.pop();

			if (water[temp.x][temp.y] == 1)continue;//�̹� ó�� �������� ���ʿ�x
			water[temp.x][temp.y] = 1;


			x = temp.x;
			y = temp.y;
			h = temp.h;

			Insert(x - 1, y, max(h, a[x][y])); //�ٷ� �����ִ� �� ���.. 4 4�̰� ����2�� 4 ��� (���� ū�� ���)
			Insert(x + 1, y, max(h, a[x + 1][y])); //����
			Insert(x, y - 1, max(h, b[x][y])); // ����
			Insert(x, y + 1, max(h, b[x][y + 1])); //������

			result += h;
		}
		fprintf(out, "%d\n", result);

	}//test


	fclose(inp);
	fclose(out);
	return 0;
}