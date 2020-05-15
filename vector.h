
#include <iostream>
#ifndef VECTOR_H
#define VECTOR_H
class Vector3D
{
protected:
double x, y, z;
public:

    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    bool operator == (const Vector3D& v2) const;
    bool operator != (const Vector3D& v2) const;

    Vector3D operator + (const Vector3D& v2) const;
    Vector3D operator - (const Vector3D& v2) const;
    Vector3D operator * (const double a) const;
    double operator * (const Vector3D& v2) const;
 
};

Vector3D operator * (const double a, const Vector3D& v);
std::ostream& operator << (std::ostream& os, const Vector3D& v);
std::istream& operator >> (std::istream &is, Vector3D &v);
#endif