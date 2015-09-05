/**
\file Matrix3x3.cpp

\brief This file implements the classes Matrix3x3, Point2 and Vector2.

TO DO LIST:
\todo 

BUG LIST:
\bug This file probably has a bug. 

FOOTNOTES:
- [F1] This is an example footnote.

REFERENCES:
- [R1] Donald Hearn and M. Pauline Baker.  Computer Graphics with OpenGL: Third Edition.

\internal
*/

/*******************************************************************************
    Includes	
*******************************************************************************/
#ifdef WIN32
#include <windows.h>
#endif

#include <Math2D/Matrix3x3.h>

using namespace ITCS4120;

/*******************************************************************************
    File Scope Macros 
*******************************************************************************/
/* NONE */
/*******************************************************************************
    File Scope Function Prototypes 
*******************************************************************************/
/* NONE */
/*******************************************************************************
    File Scope Data Types 
*******************************************************************************/
/* NONE */

/*******************************************************************************
    File Scope Global Variable Definitions
*******************************************************************************/
/* NONE */

/*******************************************************************************
    Library Scope Global Variable Definitions
*******************************************************************************/
const double ITCS4120::PI_d = 4.0*atan(1.0);
const Scalar  ITCS4120::PI_f = (Scalar)(4.0*atan(1.0));

/*******************************************************************************
    Exported Scope Global Variable Definitions 
*******************************************************************************/
/* NONE */

/*******************************************************************************
    Exported Scope Functions & Class Member Functions 
*******************************************************************************/
/* NONE */

/*******************************************************************************
    Library Scope Functions & Class Member Functions 
*******************************************************************************/


/*******************************************************************************
    Point2 Methods
*******************************************************************************/
/** ITCS 4120: Put Point2 Methods here... 
Students must implement all methods listed in class definition.
*/

void Point2::operator+= (const Vector2& v)
    {
    array[0]=array[0]+v.array[0];
    array[1]=array[1]+v.array[1];
    }
void Point2::operator-= (const Vector2& v)
    {
    array[0]=array[0]-v.array[0];
    array[1]=array[1]-v.array[1];
    }
void Point2::assignCombination(const Point2& p1, const Point2& p2, Scalar t)
    {
    array[0]= t*p1.array[0] + (1-t)*p2.array[0];
    array[1]= t*p1.array[1] + (1-t)*p2.array[1];
    }
Point2 Point2::combine (const Point2& p1, const Point2& p2, Scalar t)
    {
    Point2 p;
    p.array[0]= t*p1.array[0] + (1-t)*p2.array[0];
    p.array[1]= t*p1.array[1] + (1-t)*p2.array[1];
    return p;
    }

/*******************************************************************************
    Vector2 Methods
*******************************************************************************/
/** ITCS 4120: Put Vector2 Methods here... 
Students must implement all methods listed in class definition.
*/
Scalar Vector2::length()const
    {
    return (sqrt(array[0]*array[0] + array[1]*array[1]));
    }
void Vector2::normalize()
    {
    Scalar length;
    length = sqrt(array[0]*array[0] + array[1]*array[1]);
    array[0]=array[0] / length;
    array[1]=array[1] / length;
    }
Vector2 Vector2::normal()const
    {
    Vector2 v;
    Scalar length;
    length = sqrt(array[0]*array[0] + array[1]*array[1]);
    v.array[0]=array[0] / length;
    v.array[1]=array[1] / length;
    return v;
    }
void Vector2::operator*= (Scalar s)
    {
    array[0]=array[0]*s;
    array[1]=array[1]*s;
    }
void Vector2::operator+= (const Vector2& v)
    {
    array[0]=array[0] + v.array[0];
    array[1]=array[1] + v.array[1];
    }
void Vector2::operator-= (const Vector2& v)
    {
    array[0]=array[0] - v.array[0];
    array[1]=array[1] - v.array[1];
    }


/*******************************************************************************
    Matrix3x3 Methods
*******************************************************************************/
/** ITCS 4120: Put Matrix3x3 Methods here... I give the code for a few examples
Students must implement all methods listed in class definition.
*/

Matrix3x3::Matrix3x3 (
      Scalar m00, Scalar m01, Scalar m02,
      Scalar m10, Scalar m11, Scalar m12,
      Scalar m20, Scalar m21, Scalar m22)
    {
    // \todo implement this
    array[0][0] = m00;
    array[0][1] = m01;
    array[0][2] = m02;
    array[1][0] = m10;
    array[1][1] = m11;
    array[1][2] = m12;
    array[2][0] = m20;
    array[2][1] = m21;
    array[2][2] = m22;
    }

Matrix3x3::Matrix3x3(Initializer i)
    {
    switch(i)
	{
	case ZERO_MATRIX:
	    for(int i=0;i<9;i++) *((Scalar*)array+i)=0.0f;
	    break;
	case IDENTITY_MATRIX:
	    assignIdentity();
	    break;
	}
    }

/**
\author Zachary Wartell
\brief 'assign' assigns this Matrix3x3 all the elements, where argument 
mij is assigned to element [i][j].
*/
void Matrix3x3::assign(
      Scalar m00, Scalar m01, Scalar m02,
      Scalar m10, Scalar m11, Scalar m12,
      Scalar m20, Scalar m21, Scalar m22)
   {
   // \todo implement this
    array[0][0] = m00;
    array[0][1] = m01;
    array[0][2] = m02;
    array[1][0] = m10;
    array[1][1] = m11;
    array[1][2] = m12;
    array[2][0] = m20;
    array[2][1] = m21;
    array[2][2] = m22;
   };

void Matrix3x3::assignIdentity()
   {
   assign (1.0f,0.0f,0.0f,
	   0.0f,1.0f,0.0f,
	   0.0f,0.0f,1.0f);
   }

void Matrix3x3::assignTranslate(Scalar x, Scalar y)
   {
   // \todo implement this
   assign (1.0f,0.0f,x,
	   0.0f,1.0f,y,
	   0.0f,0.0f,1.0f);
   }
void Matrix3x3::assignRotate(Scalar angle)
    {
    assign (cosf(angle*PI_f/180),-sinf(angle*PI_f/180),0.0f,
	   sinf(angle*PI_f/180),cosf(angle*PI_f/180),0.0f,
	   0.0f,0.0f,1.0f);
    }
void Matrix3x3::assignScale(Scalar x, Scalar y)
    {
    assign (x, 0.0f, 0.0f,
	   0.0f, y, 0.0f,
	   0.0f, 0.0f, 1.0f);
    }
Matrix3x3 Matrix3x3::inverse() const
    {
    Matrix3x3 m1,m2;
    Scalar d;
    m1.assign(array[0][0],array[0][1],array[0][2],array[1][0],array[1][1],array[1][2],array[2][0],array[2][1],array[2][2]);
    m2.assignIdentity();
    d = m1.det();
    if (d != 0)
	{
	m1 = m1.transpose();

	m2[0][0] = det(m1.array[1][1],m1.array[1][2],m1.array[2][1],m1.array[2][2]);
	m2[0][1] = -1 * det(m1.array[1][0],m1.array[1][2],m1.array[2][0],m1.array[2][2]);
	m2[0][2] = det(m1.array[1][0],m1.array[1][1],m1.array[2][0],m1.array[2][1]);
	m2[1][0] = -1 * det(m1.array[0][1],m1.array[0][2],m1.array[2][1],m1.array[2][2]);
	m2[1][1] = det(m1.array[0][0],m1.array[0][2],m1.array[2][0],m1.array[2][2]);
	m2[1][2] = -1 * det(m1.array[0][0],m1.array[0][1],m1.array[2][0],m1.array[2][1]);
	m2[2][0] = det(m1.array[0][1],m1.array[0][2],m1.array[1][1],m1.array[1][2]);
	m2[2][1] = -1 * det(m1.array[0][0],m1.array[0][2],m1.array[1][0],m1.array[1][2]);
	m2[2][2] = det(m1.array[0][0],m1.array[0][1],m1.array[1][0],m1.array[1][1]);

	for(int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
		m2[i][j] = m2[i][j] / d;
	}
    return m2;
    }
void Matrix3x3::assignInverse(const Matrix3x3& m)
    {
    Matrix3x3 minv;
    minv = m.inverse();
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	    array[i][j] = minv[i][j];
    }
void Matrix3x3::assignInverse()
    {
    Matrix3x3 m;
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	    m[i][j] = array[i][j];
    m = m.inverse();
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	    array[i][j] = m[i][j];
    }

Matrix3x3 Matrix3x3::transpose() const
    {
    Matrix3x3 m;
    for(int i=0;i<3;i++)
	{
	for(int j=0;j<3;j++)
	    {
	    m[i][j] = array[j][i];
	    }
	}
    return m;
    }
void Matrix3x3::assignTranspose(const Matrix3x3& m)
    {
    Matrix3x3 mtrans;
    mtrans = m.transpose();
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	    array[i][j] = mtrans[i][j];
    }
void Matrix3x3::assignTranspose()
    {
    Matrix3x3 m;
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	    m[i][j] = array[i][j];
    m = m.transpose();
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	    array[i][j] = m[i][j];
    }
bool Matrix3x3::operator== (const Matrix3x3& m) const
    {
    bool flag = true;
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	    if(array[i][j] != m[i][j])
		{
		flag = false;
		break;
		}
    return flag;
    }
bool Matrix3x3::operator!= (const Matrix3x3& m) const
    {
    bool flag = false;
	for(int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
		if(array[i][j] != m[i][j])
		    {
		    flag = true;
		    break;
		    }
    return flag;
    }

Scalar Matrix3x3::det()const
    {
    return (array[0][0] * det(array[1][1],array[1][2], array[2][1],array[2][2]) - array[0][1] * det(array[1][0],array[1][2], array[2][0],array[2][2]) + array[0][2] * det(array[1][0],array[1][1], array[2][0],array[2][1]));
    }

Scalar Matrix3x3::det(Scalar m00, Scalar m01,
		     Scalar m10, Scalar m11)
    {
    return (m00*m11 - m01*m10);
    }

// \todo implement rest of preXXXX functions

void Matrix3x3::preMultiply(const Matrix3x3& m)
    {
    Scalar temp=0; Matrix3x3 mm;
    for (int i = 0; i < 3; i++)
	{
	for (int j = 0; j < 3; j++)
	    {
	    temp = 0;
	    for (int k = 0; k < 3; k++)
		{
		temp += m[i][k] * array[k][j];
		}
	    mm[i][j]=temp;
	    }
	}
    for (int i = 0; i < 3; i++)
	{
	for (int j = 0; j < 3; j++)
	    {
	    array[i][j] = mm[i][j];
	    }
	}
    }

void Matrix3x3::preTranslate(Scalar x, Scalar y)
    {
    Matrix3x3 m;
    m.assignTranslate(x,y);
    preMultiply(m);
    }
void Matrix3x3::preRotate(Scalar angle)
    {
    Matrix3x3 m;
    m.assignRotate(angle);
    preMultiply(m);
    }
void Matrix3x3::preScale(Scalar x, Scalar y)
    {
    Matrix3x3 m;
    m.assignScale(x,y);
    preMultiply(m);
    }

// \todo implement rest of postXXXX functions

void Matrix3x3::postMultiply(const Matrix3x3& m)
   {
   // \todo implement this function. See suggested implementation in Matrix3x3.h
    Scalar temp=0; Matrix3x3 mm;
    for (int i = 0; i < 3; i++)
	{
	for (int j = 0; j < 3; j++)
	    {
	    temp = 0;
	    for (int k = 0; k < 3; k++)
		{
		temp += array[i][k] * m[k][j];
		}
	    mm[i][j]=temp;
	    }
	}
    for (int i = 0; i < 3; i++)
	{
	for (int j = 0; j < 3; j++)
	    {
	    array[i][j] = mm[i][j];
	    }
	}
   }

void Matrix3x3::postTranslate(Scalar x, Scalar y)
   {
   // ITCS4120: This follows the suggested implementation discussed in Matrix3x3.h
   Matrix3x3 m;
   m.assignTranslate(x,y);
   postMultiply(m);
   }

void Matrix3x3::postRotate(Scalar angle)
    {
    Matrix3x3 m;
    m.assignRotate(angle);
    postMultiply(m);
    }

void Matrix3x3::postScale(Scalar x, Scalar y)
    {
    Matrix3x3 m;
    m.assignScale(x,y);
    postMultiply(m);
    }


/*******************************************************************************
    Non-Member Functions
/******************************************************************************/
/** ITCS 4120: Put Non-member functions here... I give the code for a few examples
Students must implement all functions listed in Matrix3x3.h.
*/
Vector2 ITCS4120::operator-(const Vector2& v1, const Vector2& v2)
    {
    Vector2 tmp;
    tmp.array[0] = v1.array[0]-v2.array[0];
    tmp.array[1] = v1.array[1]-v2.array[1];
    return tmp;
    }

Vector2 ITCS4120::operator+(const Vector2& v1, const Vector2& v2)
    {
    Vector2 tmp;
    tmp.array[0] = v1.array[0]+v2.array[0];
    tmp.array[1] = v1.array[1]+v2.array[1];
    return tmp;
    }

Vector2 ITCS4120::operator-(const Point2& p2, const Point2& p1)
    {
    Vector2 tmp;
    tmp.array[0] = p2.array[0]-p1.array[0];
    tmp.array[1] = p2.array[1]-p1.array[1];
    return tmp;
    }

Point2 ITCS4120::operator+(const Point2& p1, const Vector2& v1)
    {
    Point2 tmp;
    tmp.array[0] = p1.array[0]+v1.array[0];
    tmp.array[1] = p1.array[1]+v1.array[1];
    return tmp;
    }

Point2 ITCS4120::operator-(const Point2& p1, const Vector2& v1)
    {
    Point2 tmp;
    tmp.array[0] = p1.array[0]-v1.array[0];
    tmp.array[1] = p1.array[1]-v1.array[1];
    return tmp;
    }

Point2 ITCS4120::operator* (const Matrix3x3& m, const Point2& p)
   {
   // \todo implement this function
   Scalar temp=0; float p1[3], p2[3];
   p1[0]=p.array[0];
   p1[1]=p.array[1];
   p1[2]=1;
    for (int i = 0; i < 3; i++)
	{
	    temp = 0;
	    for (int k = 0; k < 3; k++)
		{
		temp += m[i][k] * p1[k];
		}
	    p2[i]=temp;
	}
  return Point2(p2[0],p2[1]);
   }

Vector2 ITCS4120::operator* (const Matrix3x3& m, const Vector2& v)
   {
   // \todo implement this function
   Scalar temp=0; float v1[3], v2[3];
   v1[0]=v.array[0];
   v1[1]=v.array[1];
   v1[2]=0;
    for (int i = 0; i < 3; i++)
	{
	    temp = 0;
	    for (int k = 0; k < 3; k++)
		{
		temp += m[i][k] * v1[k];
		}
	    v2[i]=temp;
	}
   return Vector2(v2[0],v2[1]);
   }

Matrix3x3 ITCS4120::operator* (const Matrix3x3& m0, const Matrix3x3& m1)
   {
   // \todo implement this function
   Scalar temp=0; Matrix3x3 m;
    for (int i = 0; i < 3; i++)
	{
	for (int j = 0; j < 3; j++)
	    {
	    temp = 0;
	    for (int k = 0; k < 3; k++)
		{
		temp += m0[i][k] * m1[k][j];
		}
	    m[i][j]=temp;
	    }
	}
   return m;
   }

// \todo implement the rest of the non-member functions
