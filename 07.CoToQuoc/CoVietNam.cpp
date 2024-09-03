#include "bits/stdc++.h"
#include <unistd.h>
#include <random>
using namespace std;
const int LINE_PER_FRAME = 25;

const double PI = 3.14159;
vector<pair<int, int>> points(5);
vector<pair<int, int>> defaultPoints(5);
double angle = 2 * PI / 5; 
int starSize = 10;
int width = 10 * 10; int height = 10 * 3;
bool isMakingSmaller = true;
void precaculate(){
    for (int i = 0; i < 5; ++i) {
        points[i].first = static_cast<int>(starSize * cos(i * angle - PI / 2) + width / 2);
        points[i].second = static_cast<int>(starSize * sin(i * angle - PI / 2) + height / 2);
        if(i == 1 || i == 2) {
            points[i].first += (int)points[i].first*0.11;
        } else if(i == 3|| i ==4){
            points[i].first -= (int)points[i].first*0.11;
        }
    }
    defaultPoints = points;
}

void spiningCaculator(){
    // caculate with ratio
    // TODO: Point 1,2 should be changed more than 3 4
    if(isMakingSmaller){
        for (int i = 0; i < 5; ++i) {
            if(i == 1 || i == 2) {
                if(points[i].first > defaultPoints[0].first) points[i].first -= 1;
            } else if(i == 3|| i ==4){
                if(points[i].first < defaultPoints[0].first) points[i].first += 1;
            }
        }
        if(points[1].first == defaultPoints[0].first){
            isMakingSmaller = !isMakingSmaller;
        }
    } else {
        for (int i = 0; i < 5; ++i) {
            if(i == 1 || i == 2) {
                if(points[i].first < defaultPoints[i].first) points[i].first += 1;
            } else if(i == 3|| i ==4){
                if(points[i].first > defaultPoints[i].first) points[i].first -= 1;
            }
        }
        if(points[1].first == defaultPoints[1].first){
        isMakingSmaller = ~isMakingSmaller;
        }
    }

}

void drawLine(vector<vector<char>>& canvas, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;
    
    while (true) {
        canvas[y1][x1] = '*';
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}


string drawFilledStar(int size) {
    vector<vector<char>> canvas(height, vector<char>(width, ' '));

    string vang = "========================================  vang.truong97  ===========================================";
    string name = "=================================    Việt Nam - 02/09/2024  ========================================";
    vector<char> charVang(vang.begin(), vang.end());
    vector<char> charName(name.begin(), name.end());
    canvas[0] = charVang; 
    canvas[height-1] = charName;

    for(int i = 1; i < height-1; i ++){
        canvas[i][0] = '|'; canvas[i][1] = '|'; canvas[i][width-1] = '|'; canvas[i][width-2] = '|';
    }

    for (int i = 0; i < 5; ++i) {
        drawLine(canvas, points[i].first, points[i].second, points[(i + 2) % 5].first, points[(i + 2) % 5].second);
    }

    string res = " ";
    for (const auto& row : canvas) {
        res += "\n";
        for (const auto& cell : row) {
            res += cell;
        }
    }
    return res;
}

int main(){
    int i = 0;
    precaculate();
    while(1) {
        if(i++ % 4 == 0) spiningCaculator();
        cout << drawFilledStar(5);
        usleep(1000);
    }
    return 0;
}