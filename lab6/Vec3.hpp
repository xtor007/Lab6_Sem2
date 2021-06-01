//
//  Vec3.hpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 28.05.2021.
//

#ifndef Vec3_hpp
#define Vec3_hpp

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <vector>
#include <utility>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <cmath>

class Vec3f {
public:
    Vec3f() : x(0), y(0), z(0) {}
    Vec3f(float xx) : x(xx), y(xx), z(xx) {}
    Vec3f(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}
    Vec3f operator * (const float &r) const { return Vec3f(x * r, y * r, z * r); }
    Vec3f operator * (const Vec3f &v) const { return Vec3f(x * v.x, y * v.y, z * v.z); }
    Vec3f operator - (const Vec3f &v) const { return Vec3f(x - v.x, y - v.y, z - v.z); }
    Vec3f operator + (const Vec3f &v) const { return Vec3f(x + v.x, y + v.y, z + v.z); }
    Vec3f operator - () const { return Vec3f(-x, -y, -z); }
    Vec3f& operator += (const Vec3f &v) { x += v.x, y += v.y, z += v.z; return *this; }
    friend Vec3f operator * (const float &r, const Vec3f &v)
    { return Vec3f(v.x * r, v.y * r, v.z * r); }
    friend std::ostream & operator << (std::ostream &os, const Vec3f &v)
    { return os << v.x << ", " << v.y << ", " << v.z; }
    float x, y, z;
    Vec3f crossProduct(const Vec3f &b)
    {
        return Vec3f(
            y * b.z - z * b.y,
            z * b.x - x * b.z,
            x * b.y - y * b.x
        );
    }
    inline float dotProduct(const Vec3f &b)
    { return x * b.x + y * b.y + z * b.z; }
    float length() {
        return sqrt(x*x + y*y + z*z);
    }
    void normalize()
    {
        float mag2 = x * x + y * y + z * z;
        if (mag2 > 0) {
            float invMag = 1 / sqrtf(mag2);
            x = x*invMag;
            y = y*invMag;
            z = z*invMag;
            return;
        }
    }
};
 








#endif /* Vec3_hpp */
