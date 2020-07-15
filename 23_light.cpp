#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
#define MAX 100002
typedef struct Input {
	int x;
	int y;
	int num; //index
}Input;

bool cmp(const Input& p1, const Input& p2) {
	if (p1.x < p2.x) {
		return true;
	}
	else if (p1.x == p2.x) {
		return p1.y < p2.y;
	}
	else {
		return false;
	}
}
bool y_cmp(const Input& p1, const Input& p2) {
	if (p1.y > p2.y) {
		return true;
	}
	else if (p1.y == p2.y) {
		return p1.x < p2.x;
	}
	else {
		return false;
	}
}

int main()
{
	FILE* out = fopen("light.out", "wt");
	FILE* inp = fopen("light.inp", "rt");

	int num;
	//Input* data = (struct Input*)malloc(sizeof(struct Input)*MAX);
	//Input data[MAX] = { 0 };
	vector <Input> data;
	Input put;
	fscanf(inp, "%d", &num);
	for (int i = 0; i < num; i++) {
		fscanf(inp, "%d %d", &put.x, &put.y);
		data.push_back(put);
	}
	sort(data.begin(), data.end(), cmp); //�������� ����
	//�ߺ� ������ ����
	int last_x = data[num - 1].x; 	//������ x�� ����
	int X;
	int X_cnt = 0;
	int del = 1;
	int X_index = 0;
	while (1) {
		X = data[X_index].x;
		X_cnt = 0;

		for (del = X_index; del < data.size(); del++) {

			if (data[del].x == X)X_cnt++; //���� ����
			else break;
		}
		data.erase(data.begin() + X_index, data.begin() + X_index + X_cnt - 1);
		X_index++;
		if (last_x == data[X_index].x)break;
	}//�ߺ�x ����
	for (int i = 0; i < data.size(); i++) data[i].num = i;
	int k;
	int l, r;
	fscanf(inp, "%d", &k);
	for (int z = 0; z < k; z++) {
		fscanf(inp, "%d %d", &l, &r);
		int cnt = 0;
		int index = 0;
		//	Input* max_list = (struct Input*)malloc(sizeof(struct Input) * MAX);
		//	Input max_list[MAX] = { 0 };
	//		for (int i = 0; i < MAX; i++)max_list[i].x = 0, max_list[i].y = 0, max_list[i].num = 0;
		vector <Input> max_list;
		vector <Input> memory;
		memory.assign(data.begin(), data.end()); //�״�� ����
		//���
		int ext = 0;
		int x = 0;
		int ll[2] = { 0 };
		while (1) {
			Input a;

			for (int i = 0; i < memory.size(); i++) {
				if (memory[i].x <= l) {
					//l���� ���� ���� max_list�迭�� �ֱ�
					a.x = memory[i].x;
					a.y = memory[i].y;
					a.num = i;
					max_list.push_back(a);
				}
				else {
					break;
				}
			}

			int Max = 0;

			if (max_list.size() == 0) {
				cnt = -1;
				break;
			}
			for (int i = 0; i < max_list.size(); i++) { //�ʿ� ���� �� ����Ʈ���� �����
				if (Max < max_list[i].y) {
					Max = max_list[i].y;
					index = max_list[i].num;
				}
			}

			// ���̿� ���� (������ (��������)

			if ((memory[index].x <= l) && (memory[index].y >= r)) {
				cnt++;
				break;
			}
			if (cnt > 0 && ll[1] == ll[0] && (Max < r)) {
				cnt = -1;
				break;
			}

			if (Max == 0) {
				cnt = -1;
				break;
			}

			cnt++;
			x++;
			ll[0] = l;//���� �� (�״��)
			l = memory[index].y;
			ll[1] = memory[index].y; //���� ��
			if (memory.size() == max_list.size()) {
				cnt = -1;
				break;
			}
			memory.erase(memory.begin(), memory.begin() + max_list.size());
			max_list.clear();


		}

		fprintf(out, "%d\n", cnt);

	}//z



	return 0;
}