#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    int n = towers.size();
    int maxQuality = 0;
    vector<int> bestCoord = {0, 0};
    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            int quality = 0;
            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < n; i++) {
                int dx = towers[i][0] - x;
                int dy = towers[i][1] - y;
                if (dx*dx + dy*dy <= radius*radius) {
                    int q = towers[i][2] / (1 + sqrt(dx*dx + dy*dy));
                    pq.push({q, 0});
                }
            }
            int k = min((int)pq.size(), 5);
            for (int i = 0; i < k; i++) {
                quality += pq.top().first;
                pq.pop();
            }
            if (quality > maxQuality) {
                maxQuality = quality;
                bestCoord = {x, y};
            }
        }
    }
    return bestCoord;
}

int main() {
    int n, radius;
    cout<< "Number of tower location?";
    cin>>n ;
    cout<<"radius?";
    cin>>radius;

    vector<vector<int>> towers(n, vector<int>(3));
    for (int i = 0; i <n; i++) {
        cout<<"tower "<<i+1<<" cordinates?";
        cin >>towers[i][0] >> towers[i][1] >> towers[i][2];
    }

    vector<int> ans = bestCoordinate(towers, radius);
    cout << "The Network quality is maximum at  "<< ans[0] << ", " << 
ans[1] << endl;

    return 0;
}
