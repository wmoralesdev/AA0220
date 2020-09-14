/*
    3.  Vectors in R3

    Create a struct that contains the necessary data to operate with vectors in R3
    The following operations need to be made:
        Add vectors
        Substract vectors
        Calculate the magnitude of a vector
        Calculate the unitary of a vector
        Compare two vectors
*/

#include <cmath>

// Required struct
struct vectorR3 {
    double x, y, z;

    // Constructors overloading
    vectorR3() {}
    vectorR3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    vectorR3(const vectorR3& v) : x(v.x), y(v.y), z(v.z) {}

    // Member functions
    double magnitude() {
        return sqrt(x * x + y * y + z * z);
    }

    vectorR3 unitary() {
        double r = 1 / magnitude();

        return vectorR3(x * r, y * r, z * r);
    }

    // Operator overloading
    bool operator==(const vectorR3& v) {
        return this->x == v.x && this->y == v.y && this->z == v.z;
    }
};