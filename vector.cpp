#include <iostream>
#include <cmath>
#include "vector.h"

    Vector3D::Vector3D() : Vector3D(0.0, 0.0, 0.0)
    {
    }
    Vector3D::Vector3D(double x, double y, double z)
    {
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    Vector3D::~Vector3D()
    {
    }
    double Vector3D::getX() const
    {
        return x;
    }
    double Vector3D::getY() const
    {
        return y;
    }
    double Vector3D::getZ() const
    {
        return z;
    }

    void Vector3D::setX(double x)
    {
        this -> x = x;
    }
    void Vector3D::setY(double y)
    {
        this -> y = y;
    }
    void Vector3D::setZ(double z)
    {
        this -> z = z;
    }
 
    bool Vector3D::operator == (const Vector3D& v2) const
    {
        double e = 0.00001;
        if(abs(this->getX() - v2.getX()) < e && abs(this->getY() - v2.getY()) < e && abs(this->getZ() - v2.getZ()) < e)
        {
            return true;
        }
        else
        {
            return false;
        }  
    }

    bool Vector3D::operator != (const Vector3D& v2) const
    {
        return !(*this == v2);
    }

    Vector3D Vector3D::operator + (const Vector3D& v2) const
    {
        return Vector3D(this -> getX() + v2.getX(), this -> getY() + v2.getY(), this -> getZ() + v2.getZ());
    }

    Vector3D Vector3D::operator - (const Vector3D& v2) const
    {
        return Vector3D(this -> getX() - v2.getX(), this -> getY() - v2.getY(), this -> getZ() - v2.getZ());
    }

    Vector3D Vector3D::operator * (const double a) const
    {
        return Vector3D(this -> getX() * a, this -> getY() * a, this -> getZ() *a);
    }

    double Vector3D::operator * (const Vector3D& v2) const
    {
    return this -> getX() * v2.getX() + this -> getY() * v2.getY() + this -> getZ() * v2.getZ();
    }

Vector3D operator * (const double a, const Vector3D& v)
{
    return Vector3D(v.getX() * a, v.getY() * a, v.getZ() * a);
}

std::ostream& operator << (std::ostream& os, const Vector3D& v)
{
    os << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")" << std::endl;
    return os;
}

std::istream& operator >> (std::istream &is, Vector3D &v)
{
    double a, b, c;
    std::cin >> a >> b >> c;
    v.setX(a);
    v.setY(b);
    v.setZ(c);
    return is;
}
