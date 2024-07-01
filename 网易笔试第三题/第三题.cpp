

#include <iostream>
#include <vector>
using namespace std;

class building {
public:
    int x, y, influence;
    bool isinrange(int x0, int y0) const {
        return max(abs(x - x0), abs(y - y0)) <= influence;
    }
};
int main()
{
    int n;
    cin >> n;

    vector<building> buildings(n);
    for (int i = 0; i < n; ++i) {
        cin >> buildings[i].x >> buildings[i].y >> buildings[i].influence;
    }

    int q;
    cin >> q;
    while (q--) {
        int x0, y0;
        cin >> x0 >> y0;
        int influence = 0;
        for (const auto& building : buildings) {
            if (building.isinrange(x0, y0)) {
                influence++;
            }
        }
        cout << influence << endl;

    }
    return 0;
}

