
#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 100000
using namespace std;

struct point {
	double x, y;
}p[100005];

int a[100005];

int cmpx(const point& a, const point& b) {
	return a.x < b.x;
}

int cmpy(int &a, int &b) {
	return p[a].y < p[b].y;
}

inline double min(double a, double b) {
	return a < b ? a : b;
}
inline double dist(const point& a, const point& b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double closeset(int low, int high) {
	if (low == high)
		return MAX;
	if (low + 1 == high)
		return dist(p[low], p[high]);

	int mid = (low + high) >> 1;

	double ans = min(closeset(low, mid), closeset(mid + 1, high));

	int i, j, cnt = 0;
	for (i = low; i <= high; i++) {
		if (p[mid].x - ans <= p[i].x && p[i].x <= p[mid].x + ans)
			a[cnt++] = i;
	}
	sort(a, a + cnt, cmpy);

	for (i = 0; i < cnt; i++) {
		int k = i + 7 > cnt ? cnt : i + 7;
		for (j = i + 1; j < k; j++) {
			if (p[a[j]].y - p[a[i]].y > ans)
				break;
			ans = min(dist(p[a[i]], p[a[j]]), ans);
		}
	}
	return ans;
}
int main() {
	int n;
	printf("最近对的个数：\n");
	cin >> n;
	printf("横纵坐标：\n");
	while (n && n != 0) {
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		sort(p, p + n, cmpx);
		printf("最近对的距离为：\n");
		printf("%.2f\n", closeset(0, n - 1));
	}
	return 0;
}
