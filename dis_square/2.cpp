#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <cmath>     // for sqrt (optional, if needed)
using namespace std;

struct Point {
    int x, y;
    double distance_squared; // 存储距离的平方
};

vector<int> findKNearestPoints(vector<Point> &points, const Point &cp, int k) {
    vector<int> distancesSquared;

    // 计算每个点到 (x, y) 的距离的平方
    for (auto &point : points) {
        point.distance_squared = int(pow(point.x - cp.x, 2) + pow(point.y - cp.y, 2));
        distancesSquared.push_back(point.distance_squared);
    }

    // 对距离的平方进行排序
    sort(distancesSquared.begin(), distancesSquared.end(), less<double>());
    auto first = distancesSquared.begin();
    auto kpointer = distancesSquared.begin() + k;
    vector<int> res(first, kpointer);
    return res;
}

int main() {
    // 输入数据
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int q;
    cin >> q;

    vector<Point> cp(q);
    vector<int> k(q);
    for (int i = 0; i < q; i++){
        cin >> cp[i].x >> cp[i].y >> k[i];
    }

    for (int i = 0; i < q; i++){
        vector<int> res = findKNearestPoints(points, cp[i], k[i]);
        for (int j = res.size()-1; j >= 0; j--)
            cout << res[j] << " ";
        if (i == q - 1) continue;
        cout << endl;
    }

    return 0;
}