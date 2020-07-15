#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
vector < vector <char> > bit(200);
int cnt;
string s;
FILE* out = fopen("bitmap.out", "wt");
FILE* inp = fopen("bitmap.inp", "rt");

bool sameCheck(int sx, int sy, int n, int m) { // -1 �̸� ������ �ٸ�
	for (int i = sy; i < m; i++) {
		for (int j = sx; j < n; j++) {
			if (bit[sy][sx] != bit[i][j]) return false;
		}
	}
	return true;
}
void div(int sx, int sy, int n, int m) {

	char f;
	fscanf(inp, "%c", &f);
	if (f == '\n') fscanf(inp, "%c", &f); // ���๮�ڰ� ���� �ѱ�

	int nsx, msy;
	if ((n + sx) % 2 == 0) {
		nsx = (n + sx) / 2;
	}
	else {
		nsx = (n + sx) / 2 + 1;
	}
	if ((m + sy) % 2 == 0) {
		msy = (m + sy) / 2;
	}
	else {
		msy = (m + sy) / 2 + 1;
	}

	if (f == 'D') {
		if (n - sx == 1) { // ���� �� ��
			div(sx, sy, nsx, msy); // ���� ���
			div(sx, msy, nsx, m); // ���� �ϴ�
		}
		else if (m - sy == 1) { // ���� �� ��
			div(sx, sy, nsx, msy); // ���� ���
			div(nsx, sy, n, msy); // ������ ���
		}
		else {
			div(sx, sy, nsx, msy); // ���� ���
			div(nsx, sy, n, msy); // ������ ���
			div(sx, msy, nsx, m); // ���� �ϴ�
			div(nsx, msy, n, m); // ������ �ϴ�
		}
	}
	else {
		for (int i = sy; i < m; i++) {
			for (int j = sx; j < n; j++) {
				bit[i][j] = f;
			}
		}
	}
}
void cond(int sx, int sy, int n, int m) { // ����

	if (sameCheck(sx, sy, n, m)) { // ���ΰ� ��� ������
		s.push_back(bit[sy][sx]);
	}
	else { // ���ΰ� �ٸ���
		s.push_back('D');

		int nsx, msy;
		if ((n + sx) % 2 == 0) {
			nsx = (n + sx) / 2;
		}
		else {
			nsx = (n + sx) / 2 + 1;
		}
		if ((m + sy) % 2 == 0) {
			msy = (m + sy) / 2;
		}
		else {
			msy = (m + sy) / 2 + 1;
		}
		if (msy == 23) {
			int a = 0;
		}
		if (n - sx == 1) { // ���� �� ��
			cond(sx, sy, nsx, msy); // ���� ���
			cond(sx, msy, nsx, m); // ���� �ϴ�
		}
		else if (m - sy == 1) { // ���� �� ��
			cond(sx, sy, nsx, msy); // ���� ���
			cond(nsx, sy, n, msy); // ������ ���
		}
		else {
			cond(sx, sy, nsx, msy); // ���� ���
			cond(nsx, sy, n, msy); // ������ ���
			cond(sx, msy, nsx, m); // ���� �ϴ�
			cond(nsx, msy, n, m); // ������ �ϴ�
		}
	}
}
int main() {

	int x, y; //x ����, y ����
	char text;
	while (1) {

		fscanf(inp, "%c %d %d", &text, &y, &x);
		if (text == '#')break;//��������
		bit.clear();
		bit.resize(y, vector<char>(x));
		cnt = 0;

		int up, down, left, right;

		if (x % 2 == 0)//¦��
		{
			left = x / 2;
			right = x / 2;
		}
		else //Ȧ��
		{
			left = x / 2 + 1;
			right = x / 2;
		}

		if (y % 2 == 0)
		{
			up = y / 2;
			down = y / 2;
		}
		else
		{
			up = y / 2 + 1;
			down = y / 2;
		}

		char num;
		if (text == 'B') {
			//	fgetc(inp);
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					fscanf(inp, "%c", &num);
					if (num == '\n') { // check�� ���๮���̸� ����
						j--;
						continue;
					}
					bit[i][j] = num;
				}
			}// �Է�
			fprintf(out, "D %d %d\n", y, x);
			cond(0, 0, x, y);
			for (int i = 0; i < s.length();) {
				fprintf(out, "%c", s[i++]);
				if (i % 50 == 0) fprintf(out, "\n");
			}
			fprintf(out, "\n");
		}//text=='B'

		else if (text == 'D') {

			fprintf(out, "B %d %d", y, x);
			fprintf(out, "\n");
			div(0, 0, x, y);
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					fprintf(out, "%c", bit[i][j]);
					cnt++; //���� ���� ����
					if (cnt % 50 == 0) fprintf(out, "\n");
				}
			}
			if (cnt % 50 != 0) fprintf(out, "\n");

		}//text=='D'

	}//while (�Է� ������)
	return 0;
}