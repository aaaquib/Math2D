#ifndef MATRIX3x3_H
#define MATRIX3x3_H
/**
\file Matrix3x3.h
\author Prof. Zachary Wartell 

\copyright Zachary Wartell, 2011, University of North Carolina at Charlotte.
Prof. Wartell designed the classes and gives students implementations of several methods. 
Students implement of the remaining functions.

\brief This file declares the classes Matrix3x3, Point2, and Vector2.

FOOTNOTES:
- [F1] Additional comments are given regarding the easiest way to implement
many of these methods. These are suggested approaches targeted at easy of implementation,
not at speed of computation. 


*/

/*******************************************************************************
    Includes	
*******************************************************************************/
//#include <MyLibrary/MyLibrary_exports.h>
#include <math.h>
#include <cmath>

/*******************************************************************************
    Macros
*******************************************************************************/
/**
EPISILON is the value for float's where we treat fabs(x) < EPISLON as 0.0
when doing comparisons of float pairs.
*/
#define EPISILON 1e-6f

/**
EQL tests for equality of two float's using EPISILON as our tolerance value.
*/
#define EQL(a,b) (fabs((a)-(b)) < EPISILON)

/**
NEQ tests for inequality of two float's using EPISILON as our tolerance value.
*/
#define NEQ(a,b) (fabs((a)-(b)) > EPISILON)


/*******************************************************************************
    Data Types 
*******************************************************************************/
namespace ITCS4120
{



/**
\brief Scalar data type on which our points,vectors,matrices, etc. are built.
*/
typedef float Scalar;


// forward declaration since Point2 and Vector2 cross-reference each other
class Vector2;
class Matrix3x3;

/**
\author Zachary Wartell
\brief Point2 represents a coordiate of 2D point relative to some
unspecified coordinate system.
*/
class Point2
    {
    public:
	/** Construct this Point2 with initial coordinates 'x' and 'y' */
	inline Point2 (Scalar x, Scalar y) {array[0]=x;array[1]=y;}
	/** Construct this Point2 with undefined default value */
	inline Point2 (){;}

	/****
	The operator[] overloads below allow read/write access to Point2 coordinates
	using standard array access notation. E.g.
          
	Point2 a,b;
	a[0] = 1.0f; a[1] = 1.0f;
	b[0] = a[0]; b[1] = a[1];
	****/

	/** Write accessor for coordinate 'i' */
	inline Scalar& operator[] (int i) { return array[i];}
	/** Read accessor for coordinate 'i' */
	inline const Scalar& operator[] (int i) const { return array[i];}

	/** return whether this Point2 equals 'p' */
	inline bool operator== (const Point2& p) const 
	    { return EQL(p.array[0],array[0]) && EQL(p.array[1],array[1]);}

	/** return whether this Point2 does not equal 'p' */
	inline bool operator!= (const Point2& p) const 
	    { return NEQ(p.array[0],array[0]) || NEQ(p.array[1],array[1]);}

	/**
	Add to this Point2 the Vector2 'v'.
	*/
	void operator+= (const Vector2& v);

	/**
	Subtract from this Point2 the Vector2 'v'.
	*/
	void operator-= (const Vector2& v);

	/**
	Assign this Point2 the affine combination: t * p1 + (1-t) * p2
	*/
	void assignCombination(const Point2& p1, const Point2& p2, Scalar t);

	/**
	Compute affine combination, t * p1 + (1-t) * p2, and return the result.
	*/
	static Point2 combine (const Point2& p1, const Point2& p2, Scalar t);

	/****
	 These are binary -/+ operations on Point2's and Vector2's.

	 For technical reasons these can't be static member functions and 
	 must be non-member functions.  But we want to give them private access, 
	 hence these given friend status.
	 ****/
	friend Vector2 operator-(const Point2& p2, const Point2& p1);
	friend Point2 operator-(const Point2& p1, const Vector2& v1);
	friend Point2 operator+(const Point2& p1, const Vector2& v1);
	friend Point2 operator* (const Matrix3x3& m, const Point2& p);
	friend class Vector2;
    private:
	Scalar array [2];
    };

/**
\author Zachary Wartell
\brief Vector2 represents a coordiate of 2D vector (a displacement) relative to some
unspecified coordinate system.

*/
class Vector2
    {
    public:
	/** Construct this Vector2 with initial coordinates 'x' and 'y' */
	inline Vector2 (Scalar x, Scalar y) {array[0]=x;array[1]=y;}
	/** Construct this Vector2 with undefined default value */
	inline Vector2 (){;}

	/****
	operator[] overloads below allow read/write access to Vector2 coordinates
	using standard array access notation. See comments in Point2
	*/

	/** Write accessor for coordinate 'i' */
	inline Scalar& operator[] (int i) { return array[i];}
	/** Read accessor for coordinate 'i' */
	inline const Scalar& operator[] (int i) const { return array[i];}

	/** return whether this Vector2 equals 'v' */
	inline bool operator== (const Vector2& v) const 
	    { return EQL(v.array[0],array[0]) && EQL(v.array[1],array[1]);}

	/** return whether this Vector2 does not equal 'v' */
	inline bool operator!= (const Vector2& v) const 
	    { return NEQ(v.array[0],array[0]) || NEQ(v.array[1],array[1]);}

	/** Compute length of this Vector2 */
	Scalar length()const;

	/** Convert this Vector2 to it's corresponding unit length vector */
	void normalize();

	/** return the normalized version of this Vector2 */
	Vector2 normal()const;

	/**
	Multiply this Vector2 by the scalar 's'.
	*/
	void operator*= (Scalar s);

	/**
	Add to this Vector2 the Vector2 'v'.
	*/
	void operator+= (const Vector2& v);

	/**
	Subtract from this Vector2 the Vector2 'v'.
	*/
	void operator-= (const Vector2& v);

	/****
	 These are binary -/+ operations on Point2's and Vector2's.

	 For technical reasons these can't be static member functions and 
	 must be non-member functions.  But we want to give them private access, 
	 hence these are given friend status.
	 ****/
	friend Vector2 operator-(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator+(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator-(const Point2& p2, const Point2& p1);
	friend Point2 operator-(const Point2& p1, const Vector2& v1);
	friend Point2 operator+(const Point2& p1, const Vector2& v1);
	friend Vector2 operator* (const Matrix3x3& m, const Vector2& v);
	friend class Point2;
    private:
	Scalar array [2];
    };


/**
\author Zachary Wartell
\brief Matrix3x3 represents a 3x3 matrix for encoding 2D collineations.

ITCS4120: For now only implement affine transformation methods.

FOOTNOTES:
- [F2] We could only store 2x3 if we assume all matrices are affine. But to
allow later improvements to Matrix3x3 which could support general 
2D collineations we use a 3x3 storage scheme.
*/
class Matrix3x3
    {
    public:    
    /** Default constructor.  Leaves data uninitialized. See also Matrix3x3(Initializer i) */
    inline Matrix3x3() {;}

    /** used to select one of several common default initial values */
    enum Initializer {ZERO_MATRIX,IDENTITY_MATRIX};

    /** Construct this matrix using one of several common defaults */
    Matrix3x3(Initializer i);

    /** 
	\brief Construct this Matrx3x3 by specifying all initial element values 
	Argument mij is used to initialize matrix element [i][j].
	*/
    Matrix3x3(
		Scalar m00, Scalar m01, Scalar m02,
		Scalar m10, Scalar m11, Scalar m12,
		Scalar m20, Scalar m21, Scalar m22);

    /****
    The operator[] overloads (below) allow read/write access to Matrix3x3 elements
    using standard array access notation.

	Usage:
		Matrix3x3 m1; Scalar s;
		m1[0][0] = 1.0;
		s = m1[0][0];
    
    ****/
    /** Write access for element in row [i] */
    inline Scalar* operator[](int i) {return array[i];}
    /** Read access for element in row [i] */
    inline const Scalar* operator[](int i)const {return array[i];}

    /****
      assignXXXX member functions.

	  These functions completely overwrite (i.e. they 'assign') the current values stored in the
	  'this' matrix with new values determined by the specific assignXXXX member function.
     ****/

    /** assign this Matrix3x3 all the elements of its matrix */
    void assign(
		Scalar m00, Scalar m01, Scalar m02,
		Scalar m10, Scalar m11, Scalar m12,
		Scalar m20, Scalar m21, Scalar m22);
    /** assign this Matrix3x3 a translation matrix */
    void assignTranslate(Scalar x, Scalar y);
    /** assign this Matrix3x3 a rotation matrix */
    void assignRotate(Scalar angle);
    /** assign this Matrix3x3 a scale matrix */
    void assignScale(Scalar x, Scalar y);
    /** assign this Matrix3x3 the identity matrix */
    void assignIdentity();

    /**** ITCS4120: Regarding the inverse methods (below), the easiest implementation is to 
    implement inverse() first and then re-use it (see [F1]).         
    ****/

    /** assign this Matrix3x3 the inverse of matrix 'm' */
    void assignInverse(const Matrix3x3& m);
    /** invert this Matrix3x3.  (Assign this matrix it's own inverse) */
    void assignInverse();
    /** return the inverse of this Matrix3x3 */
    Matrix3x3 inverse() const;

    /**** ITCS4120: Regarding the transpose methods (below), the easiest implementation is to 
    implement transpose() and then re-use it (see [F1]).         
    ****/

    /** assign this Matrix3x3 the transpose of matrix 'm' */
    void assignTranspose(const Matrix3x3& m);
    /** transpose this Matrix3x3.   (Assign this matrix it's own transpose). */
    void assignTranspose();
    /** return the transpose of this Matrix3x3 */
    Matrix3x3 transpose() const;

    /****
      misc. member functions
     ****/

    /** return whether this Matrix3x3 equals 'm' */
    bool operator== (const Matrix3x3& m) const;

    /** return whether this Matrix3x3 does not equal 'm' */
    bool operator!= (const Matrix3x3& m) const;

    /** compute the determinant of this Matrix3x3 */
    Scalar det()const;

    /** compute and return the determinant of a 2x2 matrix given by the following elements */
    static Scalar det(Scalar m00, Scalar m01,
		     Scalar m10, Scalar m11);


    /****
	 preXXXX member functions. The pre-multiply member functions (often called 'left-multiply'),
	 update the 'this' Matrix3x3 so that:
      
	    Matrix3x3::this = M_input_matrix * Matrix3x3::this

     where M_input_matrix is a specfic type of matrix built according to the specifics
	 of the given preXXXX member function. For example, for preTranslate the M_input_matrix equals
	 a translation matrix, for preRotate it equals a rotation matrix, etc.
     ****/

    /**** ITCS4120: Easiest implementation is to implement the matrix multiplier first
    (operator*). Call that method in preMultiply, and then implement remaining preXXXX 
    methods using calls to assignXXXX and preMultiply.  (see [F1]).         
    ****/
    /** Matrix3x3::this = M_Translate(x,y) * Matrix3x3::this */
    void preTranslate(Scalar x, Scalar y);
	/** Matrix3x3::this = M_Rotate(angle) * Matrix3x3::this */
    void preRotate(Scalar angle);
    /** Matrix3x3::this = M_Scale(x,y) * Matrix3x3::this */
    void preScale(Scalar x, Scalar y);
    /** Matrix3x3::this = M_m * Matrix3x3::this */
    void preMultiply(const Matrix3x3& m);

    /****
     postXXXX member functions. 
	 The post-multiply member functions (often called 'right-multiply'),
	 update the 'this' Matrix3x3 so that:
      
	    Matrix3x3::this = Matrix3x3::this * M_input_matrix     
     ****/

    /**** ITCS4120: Easiest implementation is to implement the the matrix multiplier first
    (operator*). Call that method in postMultiply, and then implement remaining postXXXX 
    methods using calls to assignXXXX and postMultiply. (see [F1]).
    ****/

    /** Matrix3x3::this = Matrix3x3::this * m */
    void postMultiply(const Matrix3x3& m);
    /** Matrix3x3::this = Matrix3x3::this * M_Translate(x,y) */
    void postTranslate(Scalar x, Scalar y);
    /** Matrix3x3::this = Matrix3x3::this * M_Rotate(angle) */
    void postRotate(Scalar angle);
    /** Matrix3x3::this = Matrix3x3::this * M_Scale(x,y) */
    void postScale(Scalar x, Scalar y);

    /****
    For technical reasons these can't be static member functions, but we
    want to give them private access, hence these are given friend status.
    ****/
    friend Matrix3x3 operator* (const Matrix3x3& m0, const Matrix3x3& m1);
    friend Point2 operator* (const Matrix3x3& m, const Point2& p);
    friend Vector2 operator* (const Matrix3x3& m, const Vector2& v);

    private:

    /** array for storing matrix (see [F2]) */
    Scalar array[3][3];
    };

/*******************************************************************************
    Function Prototypes
*******************************************************************************/

/****
 These are binary -/+ operations on Point2's and Vector2's.
 ****/

/**
Compute and return: v = v1 - v2.
*/
Vector2 operator-(const Vector2& v1, const Vector2& v2);

/**
Compute and return: v = v1 + v2.
*/
Vector2 operator+(const Vector2& v1, const Vector2& v2);

/**
Compute and return: v = p1 - p2.
*/
Vector2 operator-(const Point2& p1, const Point2& p2);

/**
Compute and return: p' = p1 + v1.
*/
Point2 operator+(const Point2& p1, const Vector2& v1);

/****
 These are binary operations involving matrices
 ****/

/** Compute m0 * m1 and return the result */
Matrix3x3 operator* (const Matrix3x3& m0, const Matrix3x3& m1);

/** Compute and return p' = m * p. 
    p is treated as a column matrix with 1 appended. */
Point2 operator* (const Matrix3x3& m, const Point2& p);

/** Compute and return v' = m * v. 
    v is treated as a column matrix with 0 appended. */
Vector2 operator* (const Matrix3x3& m, const Vector2& v);

/*******************************************************************************
    Function Prototypes (C exports)
*******************************************************************************/
/* NONE */
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

/*******************************************************************************
    Global Variable Declarations
*******************************************************************************/
/** 
\brief Const values for PI (Standard C++ doesn't appear to define Pi).
*/
extern const double PI_d;
extern const float PI_f;
/* NONE */
}
#endif
