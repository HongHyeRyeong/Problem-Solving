#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class info {
public:
	int x, y, p, q;
};

bool cmp(const info& a, const info& b) {
	if (1LL * a.q * b.p != 1LL * b.q * a.p)
		return 1LL * a.q * b.p < 1LL * b.q * a.p;
	if (a.y != b.y)
		return a.y < b.y;
	return a.x < b.x;
}

// ccw: �ݽð� �������� �Ǵ��ϴ� �˰���
bool ccw(info a, info b, info c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y > 0;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<info> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].x >> v[i].y;

	// ������ �� ��ǥ(���� ���� �Ʒ� ��ġ�� ��ǥ)�� �ε��� 0�� ���� ���� ������ �Ѵ�.
	sort(v.begin(), v.end(), cmp);

	// �ݽð� �������� ����
	for (int i = 1; i < n; i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}
	sort(v.begin() + 1, v.end(), cmp);

	int index = 2;
	vector<int> polygon;
	polygon.push_back(0), polygon.push_back(1);
	while (index < n) {
		while (polygon.size() >= 2) {
			// ���� ����� �� 2���� ���ο� �� �ϳ��� ������ �ݽð� �������� Ȯ���Ѵ�.
			int second = polygon.back();
			polygon.pop_back();
			int first = polygon.back();

			if (ccw(v[first], v[second], v[index])) {
				polygon.push_back(second);
				break;
			}
		}
		polygon.push_back(index++);
	}

	cout << polygon.size();
}