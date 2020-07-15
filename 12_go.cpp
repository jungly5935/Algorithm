#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>
#pragma warning(disable:4996)
using namespace std;
FILE* out = fopen("go.out", "wt");
FILE* inp = fopen("go.inp", "rt");

int test;
//위, 오른, 아래, 왼
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n;
char map[20][20];
bool visited[20][20];

/*
void dfs_recursion(int x, int y) {

	//함수에 들어왔으면 방문으로 표시
	visited[x][y] = true;
	//해당 단지 집의 수 증가
	groups[group_id]++;

	for (int i = 0; i < 4; i++) { //해당 위치 주변 위 오른 아래 왼 확인
		int nx = x + dx[i];
		int ny = y + dy[i];

		//지도를 벗어나지 않고
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			//집이면서 방문하지 않았다면 -> 방문
			if (map[nx][ny] == '.' && visited[nx][ny] == false) {
				dfs_recursion(nx, ny);
				B_cnt++;
			}
		}
	}
}
*/

int B_cnt; //. 주변 B
int W_cnt; //. 주변 W
int cnt;

int B_sum[20][20] = { 0 };
int W_sum[20][20] = { 0 };


void dfs_stack(int x, int y) {
	stack<pair<int, int> > s;
	s.push(make_pair(x, y));

	cnt++; //. 개수
	visited[x][y] = true;
	int nx = 0;
	int ny = 0;

	while (!s.empty()) {

		x = s.top().first;
		y = s.top().second;
		s.pop();

		for (int i = 0; i < 4; i++) {
			//i == 0 현재위치(x,y)에서 위, i==1 오른, i==2 밑 i==3 왼 확인
			nx = x + dx[i];
			ny = y + dy[i];

			if (map[nx][ny] == '.' && visited[nx][ny] == false)
			{
				cnt++; //. 개수
				visited[nx][ny] = true;
				s.push(make_pair(nx, ny));

			}
			if (0 <= nx && nx < test && 0 <= ny && ny < test) { //map 범위 안에서 보기 0~test
				if (map[nx][ny] == 'B') {
					B_cnt++; //. 주변 B만나면 count
					visited[nx][ny] = true;

				}
				else if (map[nx][ny] == 'W') {
					W_cnt++; //. 주변 W만나면 count
					visited[nx][ny] = true;

				}
			}
		}//for
	}//while		

	 //진짜 집 개수 
	if (B_cnt == 0) W_sum[x][y] = cnt; //B개수0일때 W집 수 계산
	if (W_cnt == 0) B_sum[x][y] = cnt; //W개수0일때 B집 수 계산


}

int main()
{
	fscanf(inp, "%d", &test);

	for (int y = 0; y < test; y++) {
		fgetc(inp);	//공백
		for (int x = 0; x < test; x++) {
			fscanf(inp, "%c", &map[y][x]);

		}
	}//입력

	for (int x = 0; x < test; x++) {
		for (int y = 0; y < test; y++) {
			if (map[x][y] == '.') { //흑돌 먼저 세기

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
