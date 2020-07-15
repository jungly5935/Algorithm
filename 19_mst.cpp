#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NODE 100009
#pragma warning(disable:4996)
using namespace std;

FILE* inp = fopen("mst.inp", "rt");
FILE* out = fopen("mst.out", "wt");

int n;
int m;

typedef struct Text {
	int node[2];
	int distance;
	int num;
}Text;

Text temp[MAX_NODE];
Text e[MAX_NODE];

void merge(int left, int mid, int right) {
	int i, j, k, l;
	i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {

		if (e[i].distance > e[j].distance) {
			temp[k] = e[j];
			j++;
		}
		else if (e[i].distance == e[j].distance) {
			if (e[i].num > e[j].num) {
				temp[k] = e[j];
				j++;
			}
			else {
				temp[k] = e[i];
				i++;
			}
		}
		else {
			temp[k] = e[i];
			i++;
		}
		k++;
	}

	if (i > mid) for (l = j; l <= right; l++) {
		temp[k] = e[l];
		k++;
	}
	else for (l = i; l <= mid; l++) {
		temp[k] = e[l];
		k++;
	}
	for (l = left; l <= right; l++) e[l] = temp[l];
}
void merge_Sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_Sort(left, mid);
		merge_Sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int getParent(int parent[], int node) {
	if (parent[node] == node) return node;
	return getParent(parent, parent[node]);
}
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

//----------------------------kruskal

typedef struct G { // 그래프 구조체
	struct G* link;
	struct Text D;
}G;

Text Data[MAX_NODE];
G* graph[MAX_NODE];
G* rear[MAX_NODE];
Text Queue[MAX_NODE * 2];

int s;

Text Delete() {
	Text temp = Queue[1];
	Queue[1] = Queue[s];
	Queue[s].distance = MAX_NODE; //거리 모두 무한대로 초기화
	Queue[s].num = -MAX_NODE;
	Queue[s].node[0] = -MAX_NODE;
	Queue[s].node[1] = -MAX_NODE;

	int index = 1;
	s--;

	while ((index * 2) <= s) { // adjust 알고리즘
		if (Queue[index * 2].distance == Queue[(index * 2) + 1].distance && Queue[index * 2].distance < Queue[index].distance) {
			if (Queue[index * 2].num < Queue[(index * 2) + 1].num) {
				Text a = Queue[index];
				Queue[index] = Queue[(index * 2)];
				Queue[(index * 2)] = a;

				index *= 2;
			}
			else if (Queue[index * 2].num >= Queue[(index * 2) + 1].num) {
				Text a = Queue[index];
				Queue[index] = Queue[(index * 2) + 1];
				Queue[(index * 2) + 1] = a;

				index = (index * 2) + 1;
			}
			else break;
		} //if
		else if (Queue[index * 2].distance > Queue[(index * 2) + 1].distance) {
			if (Queue[index].distance > Queue[(index * 2) + 1].distance || (Queue[index].distance > Queue[(index * 2)].distance)) {
				Text a = Queue[index];
				Queue[index] = Queue[(index * 2) + 1];
				Queue[(index * 2) + 1] = a;

				index = (index * 2) + 1;
			}
			else break;
		}
		else {
			if (Queue[index].distance > Queue[(index * 2)].distance) {
				Text a = Queue[index];
				Queue[index] = Queue[(index * 2)];
				Queue[(index * 2)] = a;

				index *= 2;
			}
			else break;
		}
	}
	return temp;
}
int result2[MAX_NODE];
bool visit[MAX_NODE] = { false }; //방문 노드 표시
typedef struct info {
	int u, v, weight, num;
}info;
bool operator< (info A, info B) {
	if (A.weight == B.weight) return A.num > B.num;
	return A.weight > B.weight;
}
vector< vector < info > > vec;
vector< int > seq;
void prim(int s) {
	priority_queue<info> pq;
	vector<bool> visited(n);
	pq.push({ 0,s,0,0 });

	while (!pq.empty()) {
		int u = pq.top().u;
		int v = pq.top().v;
		int w = pq.top().weight;
		int num = pq.top().num;
		pq.pop();

		if (!visited[v]) {
			seq.push_back(num);
			visited[v] = true;
		}

		for (int i = 0; i < vec[v].size(); i++) {
			if (!visited[vec[v][i].v]) {
				pq.push(vec[v][i]);
			}
		}
	}
}

int main() {

	int u, v, distance;
	int num;
	fscanf(inp, "%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		graph[i] = (G*)malloc(sizeof(G)), graph[i]->link = NULL;
		rear[i] = (G*)malloc(sizeof(G)), rear[i]->link = graph[i];
	}
	vec.resize(n);
	for (int i = 0; i < m; i++) {
		fscanf(inp, "%d %d %d", &Data[i].node[0], &Data[i].node[1], &Data[i].distance);
		e[i].node[0] = Data[i].node[0];
		e[i].node[1] = Data[i].node[1];
		e[i].distance = Data[i].distance;
		e[i].num = i;
		vec[e[i].node[1]].push_back({ e[i].node[1],e[i].node[0],e[i].distance,e[i].num });
		vec[e[i].node[0]].push_back({ e[i].node[0],e[i].node[1],e[i].distance,e[i].num });

		//kruskal 초기화

		Data[i].num = i;
		G* temp1 = rear[Data[i].node[0]]->link;
		temp1->link = (G*)malloc(sizeof(G));

		temp1->link->D = Data[i];
		temp1->link->link = NULL;
		rear[Data[i].node[0]]->link = temp1->link;

		G* temp2 = rear[Data[i].node[1]]->link;
		temp2->link = (G*)malloc(sizeof(G));

		temp2->link->D = Data[i];
		temp2->link->link = NULL;
		rear[Data[i].node[1]]->link = temp2->link;
		//prim초기화
	}
	merge_Sort(0, m);

	int par[MAX_NODE];
	for (int i = 0; i < MAX_NODE; i++) par[i] = -1;

	//각 정점이 포함된 그래프가 어디인지 저장
	for (int i = 0; i < n; i++) {
		par[i] = i;
	}

	int sum = 0;
	int result[MAX_NODE];
	for (int i = 0; i < MAX_NODE; i++)result[i] = -1;
	for (int i = 0; i < MAX_NODE; i++) {
		//사이클이 발생하지 않는 경우 그래프에 포함
		if (!findParent(par, e[i].node[0], e[i].node[1])) {
			sum += e[i].distance;
			result[i] = e[i].num;
			unionParent(par, e[i].node[0], e[i].node[1]);
		}
	}

	fprintf(out, "Tree edges by Kruskal algorithm: %d\n", sum);
	for (int i = 0; i < MAX_NODE; i++) { if (result[i] != -1)fprintf(out, "%d\n", result[i]); }

	//	---------------------------------kruskal

	prim(0);
	fprintf(out, "Tree edges by Prim algorithm with starting vertex 0: %d\n", sum);
	for (int i = 1; i < n; i++) fprintf(out, "%d\n", seq[i]);
	seq.clear();
	prim(n / 2);
	fprintf(out, "Tree edges by Prim algorithm with starting vertex %d: %d\n", n / 2, sum);
	for (int i = 1; i < n; i++) fprintf(out, "%d\n", seq[i]);
	seq.clear();
	prim(n - 1);
	fprintf(out, "Tree edges by Prim algorithm with starting vertex %d: %d\n", n - 1, sum);
	for (int i = 1; i < n; i++) fprintf(out, "%d\n", seq[i]);
	seq.clear();

	fclose(inp);
	fclose(out);
	return 0;
}