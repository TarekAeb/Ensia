#include <iostream>
#include <cmath>

using namespace std;

int min(int a, int b, int c, int d) {
    int minVal = a;
    if (b < minVal) {
        minVal = b;
    }
    if (c < minVal) {
        minVal = c;
    }
    if (d < minVal) {
        minVal = d;
    }
    return minVal;
}

int max(int a, int b, int c, int d) {
    int maxVal = a;
    if (b > maxVal) {
        maxVal = b;
    }
    if (c > maxVal) {
        maxVal = c;
    }
    if (d > maxVal) {
        maxVal = d;
    }
    return maxVal;
}

class Rectangle {
public:
    // Constructor with input validation and rectangle verification
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        if (!set(x1, y1, x2, y2, x3, y3, x4, y4)) {
            throw invalid_argument("Invalid coordinates or not a rectangle");
        }
    }

    // Private helper function for input validation and rectangle verification
    bool set(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        // Check if all coordinates are in the first quadrant and within limits
        if (!(x1 >= 0 && x1 <= 20 && y1 >= 0 && y1 <= 20 &&
              x2 >= 0 && x2 <= 20 && y2 >= 0 && y2 <= 20 &&
              x3 >= 0 && x3 <= 20 && y3 >= 0 && y3 <= 20 &&
              x4 >= 0 && x4 <= 20 && y4 >= 0 && y4 <= 20)) {
            return false;
        }

        // Check if opposite sides have equal length
        double d12 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        double d34 = sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2));
        if (abs(d12 - d34) > 1e-6) {
            return false;
        }

        // Check if adjacent sides have equal length
        double d13 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        double d24 = sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2));
        if (abs(d13 - d24) > 1e-6) {
            return false;
        }

        // All checks passed, store the coordinates
        topLeft.x = min(x1, x2, x3, x4);
        topLeft.y = max(y1, y2, y3, y4);
        bottomRight.x = max(x1, x2, x3, x4);
        bottomRight.y = min(y1, y2, y3, y4);
        return true;
    }

    // Calculates the length (larger dimension)
    double getLength() const {
        return bottomRight.x - topLeft.x;
    }

    // Calculates the width (smaller dimension)
    double getWidth() const {
        return topLeft.y - bottomRight.y;
    }

    // Calculates the perimeter
    double getPerimeter() const {
        return 2 * (getLength() + getWidth());
    }

    // Calculates the area
    double getArea() const {
        return getLength() * getWidth();
    }

    // Checks if the rectangle is a square
    bool isSquare() const {
        return getLength() == getWidth();
    }

private:
    // Top-left and bottom-right corner coordinates
    struct Point {
        double x, y;
    };
    Point topLeft, bottomRight;
};

int main() {
    // Example usage:
    try {
        Rectangle rect(1, 2, 4, 5, 6, 2, 3, 1); // Valid rectangle
        cout << "Length: " << rect.getLength() << endl;
        cout << "Width: " << rect.getWidth() << endl;
        cout << "Perimeter: " << rect.getPerimeter() << endl;
        cout << "Area: " << rect.getArea() << endl;
        cout << "Is square? " << (rect.isSquare() ? "Yes" : "No") << endl;

        Rectangle invalidRect(10, 25, 5, 20, 20, 15, 15, 10); // Invalid - points not in first quadrant
    }
    catch(exception ){
        cout<< "ERRor";
    }
}