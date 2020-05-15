#include <iostream>
#include "matrix.h"
    Matrix3D::Matrix3D() : Matrix3D(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
    {

    }
    Matrix3D::Matrix3D(double a11, double a12, double a13,
    double a21, double a22, double a23, 
    double a31, double a32, double a33)
    {
        this -> a[0] = a11;
        this -> a[1] = a12;
        this -> a[2] = a13;
        this -> b[0] = a21;
        this -> b[1] = a22;
        this -> b[2] = a23;
        this -> c[0] = a31;
        this -> c[1] = a32;
        this -> c[2] = a33; 
    }

    Matrix3D Matrix3D::operator * (const double a) const
    {
        return Matrix3D( this -> a[0] * a, this -> a[1] * a, this -> a[2] * a,
        this -> b[0] * a, this -> b[1] * a, this -> b[2] * a,
        this -> c[0] * a, this -> c[1] * a, this -> c[2] * a);
    }

    Matrix3D Matrix3D::operator - (const Matrix3D& mat) const
    {
        return Matrix3D( this -> a[0] - mat.a[0], this -> a[1] - mat.a[1], this -> a[2] - mat.a[2],
        this -> b[0] - mat.b[0], this -> b[1] - mat.b[1], this -> b[2] - mat.b[2],
        this -> c[0] - mat.c[0], this -> c[1] - mat.c[1], this -> c[2] - mat.c[2]);
    }

    Matrix3D Matrix3D::operator + (const Matrix3D& mat) const
    {
        return Matrix3D( this -> a[0] + mat.a[0], this -> a[1] + mat.a[1], this -> a[2] + mat.a[2],
        this -> b[0] + mat.b[0], this -> b[1] + mat.b[1], this -> b[2] + mat.b[2],
        this -> c[0] + mat.c[0], this -> c[1] + mat.c[1], this -> c[2] + mat.c[2]);
    }

    Vector3D Matrix3D::operator * (const Vector3D& v) const
    {
        return Vector3D( this -> a[0] * v.getX() + this -> a[1] * v.getY() + this -> a[2] * v.getZ(),
        this -> b[0] * v.getX() + this -> b[1] * v.getY() + this -> b[2] * v.getZ(),
        this -> c[0] * v.getX() + this -> c[1] * v.getY() + this -> c[2] * v.getZ());
    }

    Matrix3D Matrix3D::operator * (const Matrix3D& mat) const
    {
        return Matrix3D (this -> a[0] * mat.a[0] + this -> a[1] * mat.b[0] + this -> a[2] * mat.c[0],
        this -> a[0] * mat.a[1] + this -> a[1] * mat.b[1] + this -> a[2] * mat.c[1],
        this -> a[0] * mat.a[2] + this -> a[1] * mat.b[2] + this -> a[2] * mat.c[2],
        this -> b[0] * mat.a[0] + this -> b[1] * mat.b[0] + this -> b[2] * mat.c[0],
        this -> b[0] * mat.a[1] + this -> b[1] * mat.b[1] + this -> b[2] * mat.c[1],
        this -> b[0] * mat.a[2] + this -> b[1] * mat.b[2] + this -> b[2] * mat.c[2],
        this -> c[0] * mat.a[0] + this -> c[1] * mat.b[0] + this -> c[2] * mat.c[0],
        this -> c[0] * mat.a[1] + this -> c[1] * mat.b[1] + this -> c[2] * mat.c[1],
        this -> c[0] * mat.a[2] + this -> c[1] * mat.b[2] + this -> c[2] * mat.c[2]);
    }

    double Matrix3D::det() const
    {
        return a[0] * (b[1] * c[2] - b[2] * c[1]) - a[1] * (b[0] * c[2] - b[2] * c[0]) + a[2] * (b[0] * c[1] - b[1] * c[0]);
    }

std::ostream& operator << (std::ostream& os, const Matrix3D& mat) 
{
    os << "(" << mat.a[0] << " " << mat.a[1] << " " << mat.a[2] << ")" << std::endl;
    os << "(" << mat.b[0] << " " << mat.b[1] << " " << mat.b[2] << ")" << std::endl;
    os << "(" << mat.c[0] << " " << mat.c[1] << " " << mat.c[2] << ")" << std::endl;
    return os;
}

std::istream& operator >> (std::istream &is, Matrix3D &mat)
{
    std::cin >> mat.a[0] >> mat.a[1] >> mat.a[2];
    std::cin >> mat.b[0] >> mat.b[1] >> mat.b[2];
    std::cin >> mat.c[0] >> mat.c[1] >> mat.c[2];
    return is;
}

Matrix3D operator * (const double a, const Matrix3D& mat) 
{
    std::cout << mat.c[2];
    return Matrix3D (mat.a[0] * a, mat.a[1] * a, mat.a[2] * a,
    mat.b[0] * a, mat.b[1] * a, mat.b[2] * a,
    mat.c[0] * a, mat.c[1] * a, mat.c[2] * a);
}