#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>
#pragma warning(disable:4996)
using namespace std;
FILE* out = fopen("go.out", "wt");
FILE* inp = fopen("go.inp", "rt");

int test;
//��, ����, �Ʒ�, ��
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n;
char map[20][20];
bool visited[20][20];

/*
void dfs_recursion(int x, int y) {

	//�Լ��� �������� �湮���� ǥ��
	visited[x][y] = true;
	//�ش� ���� ���� �� ����
	groups[group_id]++;

	for (int i = 0; i < 4; i++) { //�ش� ��ġ �ֺ� �� ���� �Ʒ� �� Ȯ��
		int nx = x + dx[i];
		int ny = y + dy[i];

		//������ ����� �ʰ�
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			//���̸鼭 �湮���� �ʾҴٸ� -> �湮
			if (map[nx][ny] == '.' && visited[nx][ny] == false) {
				dfs_recursion(nx, ny);
				B_cnt++;
			}
		}
	}
}
*/

int B_cnt; //. �ֺ� B
int W_cnt; //. �ֺ� W
int cnt;

int B_sum[20][20] = { 0 };
int W_sum[20][20] = { 0 };


void dfs_stack(int x, int y) {
	stack<pair<int, int> > s;
	s.push(make_pair(x, y));

	cnt++; //. ����
	visited[x][y] = true;
	int nx = 0;
	int ny = 0;

	while (!s.empty()) {

		x = s.top().first;
		y = s.top().second;
		s.pop();

		for (int i = 0; i < 4; i++) {
			//i == 0 ������ġ(x,y)���� ��, i==1 ����, i==2 �� i==3 �� Ȯ��
			nx = x + dx[i];
			ny = y + dy[i];

			if (map[nx][ny] == '.' && visited[nx][ny] == false)
			{
				cnt++; //. ����
				visited[nx][ny] = true;
				s.push(make_pair(nx, ny));

			}
			if (0 <= nx && nx < test && 0 <= ny && ny < test) { //map ���� �ȿ��� ���� 0~test
				if (map[nx][ny] == 'B') {
					B_cnt++; //. �ֺ� B������ count
					visited[nx][ny] = true;

				}
				else if (map[nx][ny] == 'W') {
					W_cnt++; //. �ֺ� W������ count
					visited[nx][ny] = true;

				}
			}
		}//for
	}//while		

	 //��¥ �� ���� 
	if (B_cnt == 0) W_sum[x][y] = cnt; //B����0�϶� W�� �� ���
	if (W_cnt == 0) B_sum[x][y] = cnt; //W����0�϶� B�� �� ���


}

int main()
{
	fscanf(inp, "%d", &test);

	for (int y = 0; y < test; y++) {
		fgetc(inp);	//����
		for (int x = 0; x < test; x++) {
			fscanf(inp, "%c", &map[y][x]);

		}
	}//�Է�

	for (int x = 0; x < test; x++) {
		for (int y = 0; y < test; y++) {
			if (map[x][y] == '.') { //�浹 ���� ����

				if (map[x][y] == '.' && visited[x][y] == false) {
					dfs_stack(x, y);
				}
				cnt = 0;
				B_cnt = 0;
				W_cnt = 0;
			}

		}
	}
	int B_result = 0;
	int W_result = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			B_result += B_sum[i][j];
			W_result += W_sum[i][j];
		}
	}
	fprintf(out, "%d %d", B_result, W_result);

	return 0;
}
