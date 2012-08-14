/*
 *Challenge 87
 *
 *Write a function that calculates the intersection of two rectangles, returning 
 *either a new rectangle or some kind of null value. You're free to represent 
 *these rectangles in any way you want: tuples of numbers, class objects, 
 *new datatypes, anything goes. For this challenge, you'll probably want to 
 *represent your rectangles as the x and y values of the top-left and bottom-right 
 *points. (Rect(3, 3, 10, 10) would be a rectangle from (3, 3) (top-left) to 
 *(10, 10) (bottom-right).)
 *
 *As an example, rectIntersection(Rect(3, 3, 10 10), Rect(6, 6, 12, 12)) would 
 *return Rect(6, 6, 10, 10), while 
 *rectIntersection(Rect(4, 4, 5, 5), Rect(6, 6, 10 10)) would return null.
 */

#include <iostream>
#include <algorithm>

using namespace std;


struct Rectangle {
    struct Coordinate {
        int x, y;
    }; 
    Coordinate top_left, bottom_right;
    Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) {
        top_left.x = x1;
        top_left.y = y1;
        bottom_right.x = x2;
        bottom_right.y = y2;
    }
};

Rectangle rectIntersection(const Rectangle& rectA, const Rectangle& rectB) {
    Rectangle intersection_Rectangle(max(rectA.top_left.x, rectB.top_left.x), 
                                     max(rectA.top_left.y, rectB.top_left.y),
                                     min(rectA.bottom_right.x, rectB.bottom_right.x),
                                     min(rectA.bottom_right.y, rectB.bottom_right.y));

    if (intersection_Rectangle.top_left.x > intersection_Rectangle.bottom_right.x ||
        intersection_Rectangle.bottom_right.y < intersection_Rectangle.bottom_right.y) {
        return Rectangle();
    }
    else {
        return intersection_Rectangle;
    }
}

int main() {
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    cout << "Enter first rectangle's coords:" << endl;
    cout << "Top Left X: ";
    cin >> ax1;
    cout << "Top Left Y: ";
    cin >> ay1;
    cout << "Bottom Right X: ";
    cin >> ax2;
    cout << "Bottom Right Y: ";
    cin >> ay2;
    cout << "Enter second rectangle's coords:" << endl;
    cout << "Top Left X: ";
    cin >> bx1;
    cout << "Top Left Y: ";
    cin >> by1;
    cout << "Bottom Right X: ";
    cin >> bx2;
    cout << "Bottom Right Y: ";
    cin >> by2;

    Rectangle rectA(ax1, ay1, ax2, ay2);
    Rectangle rectB(bx1, by1, bx2, by2);
    Rectangle intersection1 = rectIntersection(rectA, rectB);
    cout << "rectA(" << rectA.top_left.x << "," << rectA.top_left.y << ",";
    cout << rectA.bottom_right.x << "," << rectA.bottom_right.y << ")" << endl; 
    cout << "rectB(" << rectB.top_left.x << "," << rectB.top_left.y << ",";
    cout << rectB.bottom_right.x << "," << rectB.bottom_right.y << ")" << endl;
    cout << "intersection(" << intersection1.top_left.x << "," << intersection1.top_left.y << ",";
    cout << intersection1.bottom_right.x << "," << intersection1.bottom_right.y << ")" << endl;

    return 0;
}
