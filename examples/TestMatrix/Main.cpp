/**
Copyright 2007, All Rights Reserved: Zachary Wartell, University of North Carolina at Charlotte
\file Main.cpp
\author Zachary Wartell
\brief Main.cpp file
*/
#include <iostream>
#include <assert.h>
#include <Math2D/Matrix3x3.h>

using namespace std;
using namespace ITCS4120;


void test()
    {    
    /** ITCS4120: Once you get all methods implemented replace 0 with 1 to compile the test function
    */
   #if 0     
    Vector2 v1,v2,v3;
    Point2 p1,p2,p3;
    Matrix3x3 m1, m2, m3;

    v1 [0] = 1.0f; v1 [1] = 5.0f;
    v2 [0] = 6.0f; v2 [1] = 10.0f;
    v3 = v1 + v2;
    assert (v3 == Vector2(7.0,15.0));
    v3 = v1 - v2;
    assert (v3 == Vector2(-5.0,-5.0));
    assert(v1.length() == 5.0990195135927848300282241090228f);

    v3 += v3;
    assert (v3 == Vector2(-10.0,-10.0));
    v3 *= 5.0;
    assert (v3 == Vector2(-50.0,-50.0));

    m1.assign(5,6,4,
	1,2,3,
	3,5,9);
    m2=m1.inverse();
    m3.assign(3/11,-34/11,10/11,
	0,33/11,-11/11,
	-1/11,-7/11,4/11);
    m1.assignInverse(m2);
    assert(m1 == (m2.inverse()));
    m1.assign(3/11,0,-1/11,
	-34/11,33/11,-7/11,
	10/11,-11/11,4/11);
    assert(m1 == (m3.transpose()));

    m1.assign(5,6,4,
	1,2,3,
	3,5,9);
    m2.assign(2,6,1,
	      9,6,5,
	      3,4,5);
    m3.assign(76,82,55,
	      29,30,26,
	      78,84,73);
    m1.postMultiply(m2);
    assert(m1==m3);
    
    m1.assign(5,6,4,
	1,2,3,
	3,5,9);
    m2.assign(2,6,1,
	      9,6,5,
	      3,4,5);
    m3.assign(19,29,35,
	      66,91,99,
	      34,51,69);
    m1.preMultiply(m2);
    assert(m1==m3);

    cout << "Test passed!\n";
   #endif
    }


/**
\brief 'main' is the standard C/C++ main function where execution starts
*/
int main (int argc, char** argv)
    {    
    test();
    return 0;
    }
