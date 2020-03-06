#include <iostream>
using namespace std;

class Vector3D
{
protected:
double x, y, z;
public:

    Vector3D() : Vector3D(0.0, 0.0, 0.0)
    {
    }
    Vector3D(double x, double y, double z)
    {
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    ~Vector3D()
    {
    }
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    double getZ() const
    {
        return z;
    }

    void setX(double x)
    {
         this -> x = x;
    }
    void setY(double y)
    {
        this -> y = y;
    }
    void setZ(double y)
    {
        this -> z = z;
    }
 
    bool operator == (const Vector3D& v2) const
    {
        double e = 0.00001;
        if(this->getX() - v2.getX() < e && this->getY() - v2.getY() < e && this->getZ() - v2.getZ() < e)
        {
            return true;
        }
        else
        {
            return false;
        }  
    }

    bool operator != (const Vector3D& v2) const
    {
        if(*this == v2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    Vector3D operator + (const Vector3D& v2) const
    {
        return Vector3D(this -> getX() + v2.getX(), this -> getY() + v2.getY(), this -> getZ() + v2.getZ());
    }

    Vector3D operator - (const Vector3D& v2) const
    {
        return Vector3D(this -> getX() - v2.getX(), this -> getY() - v2.getY(), this -> getZ() - v2.getZ());
    }

    Vector3D operator * (const double a) const
    {
        return Vector3D(this -> getX() * a, this -> getY() * a, this -> getZ() *a);
    }

    double operator * (const Vector3D& v2)
    {
    return this -> getX() * v2.getX() + this -> getY() * v2.getY() + this -> getZ() * v2.getZ();
    }
};

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

class Matrix3D
{
    public:

    double a[3], b[3], c[3];

    Matrix3D() : Matrix3D(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
    {

    }
    Matrix3D(double a11, double a12, double a13,
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

    Matrix3D operator * (const double a)
    {
        return Matrix3D( this -> a[0] * a, this -> a[1] * a, this -> a[2] * a,
        this -> b[0] * a, this -> b[1] * a, this -> b[2] * a,
        this -> c[0] * a, this -> c[1] * a, this -> c[2] * a);
    }

    Matrix3D operator - (const Matrix3D& mat)
    {
        return Matrix3D( this -> a[0] - mat.a[0], this -> a[1] - mat.a[1], this -> a[2] - mat.a[2],
        this -> b[0] - mat.b[0], this -> b[1] - mat.b[1], this -> b[2] - mat.b[2],
        this -> c[0] - mat.c[0], this -> c[1] - mat.c[1], this -> c[2] - mat.c[2]);
    }

    Matrix3D operator + (const Matrix3D& mat)
    {
        return Matrix3D( this -> a[0] + mat.a[0], this -> a[1] + mat.a[1], this -> a[2] + mat.a[2],
        this -> b[0] + mat.b[0], this -> b[1] + mat.b[1], this -> b[2] + mat.b[2],
        this -> c[0] + mat.c[0], this -> c[1] + mat.c[1], this -> c[2] + mat.c[2]);
    }

    Vector3D operator * (const Vector3D& v)
    {
        return Vector3D( this -> a[0] * v.getX() + this -> a[1] * v.getY() + this -> a[2] * v.getZ(),
        this -> b[0] * v.getX() + this -> b[1] * v.getY() + this -> b[2] * v.getZ(),
        this -> c[0] * v.getX() + this -> c[1] * v.getY() + this -> c[2] * v.getZ());
    }

    Matrix3D operator * (const Matrix3D& mat)
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

    double det()
    {
        return a[0] * (b[1] * c[2] - b[2] * c[1]) - a[1] * (b[0] * c[2] - b[2] * c[0] + a[2] * (b[0] * c[1] - b[1] * c[0]));
    }
};

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
    cout << mat.c[2];
    return Matrix3D (mat.a[0] * a, mat.a[1] * a, mat.a[2] * a,
    mat.b[0] * a, mat.b[1] * a, mat.b[2] * a,
    mat.c[0] * a, mat.c[1] * a, mat.c[2] * a);
}

int main() 
{
    // Вектор задан в коде
    Vector3D A(1, 2, 3);
    // Вектор читается из cin
    Vector3D B;
   // cin >> B;

    // Базовые операции с векторами
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;

    // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // Матрица читается из cin
    Matrix3D D;
    cin >> D;

    // Базовые операции с матрицами
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    // Детерминант матрицы
    cout << "det(D) = " << D.det() << endl;

    // Умножение матрицы на вектор
    cout << "D * B = " << D * B << endl;

    return 0;
};


