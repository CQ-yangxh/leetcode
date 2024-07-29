#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
    Point() : x(0), y(0) {};
    Point(int x, int y) : x(x), y(y) {}
};

// 计算两点之间的欧式距离平方
int squaredDistance(const Point& a, const Point& b) {
    double dis = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return round(dis);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    long long q;
    cin >> q;

    vector<Point> cp(q);
    vector<int> ck(q);
    for (int i = 0; i < q; i++){
        cin >> cp[i].x >> cp[i].y >> ck[i];
    }

    for (int i = 0; i < q; i++) {
        Point base(cp[i].x, cp[i].y);
        int k = ck[i];

        // 使用优先队列（最大堆）找出最近的k个点
        priority_queue<int> maxHeap;
        for (const auto& point : points) {
            int dist = squaredDistance(base, point);
            if (maxHeap.size() < k) {
                maxHeap.push(dist);
            } else if (dist < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(dist);
            }
        }

        // 输出结果
        vector<int> results;
        while (!maxHeap.empty()) {
            results.push_back(maxHeap.top());
            maxHeap.pop();
        }

        // 按升序输出结果
        std::sort(results.begin(), results.end(), greater<int>());
        for (int j = 0; j < results.size() - 1; j++){
            cout << results[j] << " ";
        }
        cout << results[results.size()-1];
        // ！！！我不确定下面这个endl最后一行需不需要输出！！！
        if (i != q-1) cout << endl;
    }

    return 0;
}
