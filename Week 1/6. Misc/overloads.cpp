#include <iostream>
#include <cmath>
using namespace std;

// Defining vector2D struct
struct vector2D {
    // Field members
    double x, y;
    
    // Struct constructors
    vector2D() : x(0), y(0) {}
    vector2D(double _x, double _y) : x(_x), y(_y) {}
    vector2D(const vector2D& v) : x(v.x), y(v.y) {}

    // Field functions
    double magnitude() {
        return sqrt(x * x + y * y);
    }

    vector2D unit() {
        float r = 1 / magnitude();
        return vector2D(x * r, y * r);
    }

    // Operator overloading
    // Overload consists in left hand side operand, and right hand side operand
    // rhs is received in overload to operate with current, this references to lhs
    vector2D operator+(const vector2D& rhs) {
        return vector2D(this->x + rhs.x, this->y + rhs.y);
    }

    void operator+=(const vector2D& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
    }

    vector2D operator-(const vector2D& rhs) {
        return vector2D(this->x - rhs.x, this->y - rhs.y);
    }

    void operator-=(const vector2D& rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
    }

    string toString() {
        return "x: " + to_string(this->x) + ", y: " + to_string(this->y);
    }
};

int main(void) {
    vector2D vct1(2, 3);
    vector2D vct2(4, 5);

    vector2D vct3 = vct1 + vct2;

    cout << vct3.toString() << endl;

    vct3 += vct1;

    cout << vct3.toString() << endl;

    return 0;
}