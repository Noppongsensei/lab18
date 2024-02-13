#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
    double x, y, w, h; 
};


double overlap(Rect R1,  Rect R2) {
    if(R1.x>0){
    double x1 = max(R1.x, R2.x);
    double y1 = max(R1.y, R2.y);
    double x2 = min(R1.x + R1.w, R2.x + R2.w);
    double y2 = min(R1.y + R1.h, R2.y + R2.h);
    double overlapWidth = max(0.0, x2 - x1);
    double overlapHeight = max(0.0, y2 - y1);
    return overlapWidth * overlapHeight;
    }else{
        return R2.w*R2.h;
    }
}

int main() {
    Rect R1 = {1, 1, 5, 5};
    Rect R2 = {2, 2, 5, 5};
    cout << overlap(R1, R2) << endl; 

    R1 = {1, 1, 5, 5};
    R2 = {7, 2, 3, 3};
    cout << overlap(R1, R2) << endl; 

    R1 = {-1, 2, 6.9, 9.6};
    R2 = {0, 0, 1.2, 2.5};
    cout << overlap(R1, R2) << endl; 

    return 0;
}








