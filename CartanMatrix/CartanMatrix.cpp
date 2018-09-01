/**
 * @file   CartanMatrix.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/04/30
 * 
 * @brief  CartanMatrix
 * 
 * Released under the MIT license
 */

#include <map>
#include <functional>

#include "gweyl.hpp"


namespace gweyl{

//
// Cartan matrix of type A
//
std::function<matrix(int)> CartanMatrixA = [](int n){
    gweyl::matrix A;
    A.resize(n,n);

    for (unsigned i=0; i< A.size1(); ++i){
        A(i, i) = rational(2);
    }
	
    for (unsigned i=0; i+1< A.size1(); ++i){
        A(i, i+1) = rational(-1);
        A(i+1, i) = rational(-1);
    }
    
    return A;
};

//
// Cartan matrix of type B
//

std::function<matrix(int)> CartanMatrixB = [](int n){
    gweyl::matrix A;
    A.resize(n,n);

    
    for (unsigned i=0; i< A.size1(); ++i){
        A(i, i) = rational(2);
    }
	
    for (unsigned i=0; i+1< A.size1(); ++i){
        A(i, i+1) = rational(-1);
        A(i+1, i) = rational(-1);
    }

    A(n-1, n-2) = rational(-2);

    return A;
};

//
// Cartan matrix of type C
//
std::function<matrix(int)> CartanMatrixC = [](int n){
    gweyl::matrix A;
    A.resize(n,n);

    for (unsigned i=0; i< A.size1(); ++i){
        A(i, i) = rational(2);
    }
	
    for (unsigned i=0; i+1< A.size1(); ++i){
        A(i, i+1) = rational(-1);
        A(i+1, i) = rational(-1);
    }

    A(n-2, n-1) = rational(-2);

    return A;
};

//
// Cartan matrix of type D
//
std::function<matrix(int)> CartanMatrixD = [](int n){
    gweyl::matrix A;
    A.resize(n,n);

    for (unsigned i=0; i< A.size1(); ++i){
        A(i, i) = rational(2);
    }
	
    for (unsigned i=0; i+1< A.size1(); ++i){
        A(i, i+1) = rational(-1);
        A(i+1, i) = rational(-1);
    }

    A(n-1, n-3) = rational(-1);
    A(n-1, n-2) = rational(0);
    A(n-3, n-1) = rational(-1);
    A(n-2, n-1) = rational(0);
    
    return A;
};

//
// Cartan matrix of type E
//
std::function<matrix(int)> CartanMatrixE = [](int n){
    gweyl::matrix A;
    A.resize(n,n);

    for (unsigned i=0; i< A.size1(); ++i){
        A(i, i) = rational(2);
    }
	
    for (unsigned i=0; i+1< A.size1(); ++i){
        A(i, i+1) = rational(-1);
        A(i+1, i) = rational(-1);
    }

    A(0, 1) = rational(0);
    A(0, 2) = rational(-1);
    A(1, 2) = rational(0);
    A(1, 3) = rational(-1);
        
    A(1, 0) = rational(0);
    A(2, 0) = rational(-1);
    A(2, 1) = rational(0);
    A(3, 1) = rational(-1);

    return A;
};

//
// Cartan matrix of type F
//
std::function<matrix(int)> CartanMatrixF = [](int n){
    gweyl::matrix A;
    A.resize(n,n);
    
    for (unsigned i=0; i< A.size1(); ++i){
        A(i, i) = rational(2);
    }
	
    for (unsigned i=0; i+1< A.size1(); ++i){
        A(i, i+1) = rational(-1);
        A(i+1, i) = rational(-1);
    }

    A(2, 1) = rational(-2);
 
    return A;
};

//
// Cartan matrix of type G
//
std::function<matrix(int)> CartanMatrixG = [](int n){
    gweyl::matrix A;
    A.resize(n,n);

    A(0,0) = rational(2);
    A(1,1) = rational(2);
    A(1,0) = rational(-1);
    A(0,1) = rational(-3);
    
    return A;
};

//
// table of CartanMatrix functions
//
std::map<gweyl::Type, std::function<gweyl::matrix(int)>> CartanMatrixFunctionTable{
    {Type::A, CartanMatrixA},
    {Type::B, CartanMatrixB},
    {Type::C, CartanMatrixC},
    {Type::D, CartanMatrixD},
    {Type::E, CartanMatrixE},
    {Type::F, CartanMatrixF},
    {Type::G, CartanMatrixG},
                
};

matrix CartanMatrix(Type X, unsigned n){
    return CartanMatrixFunctionTable[X](n);
}


//
// The followings are the first implementation
//
#if 0
matrix CartanMatrix(Type X, unsigned n){

    matrix A;
    A.resize(n, n);

    if (X == Type::A){
        for (unsigned i=0; i< A.size1(); ++i){
            A(i, i) = rational(2);
        }
	
        for (unsigned i=0; i+1< A.size1(); ++i){
            A(i, i+1) = rational(-1);
            A(i+1, i) = rational(-1);
        }
    }
    
    if (X == Type::B){

        for (unsigned i=0; i< A.size1(); ++i){
            A(i, i) = rational(2);
        }
	
        for (unsigned i=0; i+1< A.size1(); ++i){
            A(i, i+1) = rational(-1);
            A(i+1, i) = rational(-1);
        }

        A(n-1, n-2) = rational(-2);
    }

    if (X == Type::C){
        
        for (unsigned i=0; i< A.size1(); ++i){
            A(i, i) = rational(2);
	}
	
	for (unsigned i=0; i+1< A.size1(); ++i){
            A(i, i+1) = rational(-1);
            A(i+1, i) = rational(-1);
	}

        A(n-2, n-1) = rational(-2);

    }

    if (X == Type::D){

        for (unsigned i=0; i< A.size1(); ++i){
            A(i, i) = rational(2);
	}
	
	for (unsigned i=0; i+1< A.size1(); ++i){
            A(i, i+1) = rational(-1);
            A(i+1, i) = rational(-1);
	}

        A(n-1, n-3) = rational(-1);
        A(n-1, n-2) = rational(0);
        A(n-3, n-1) = rational(-1);
        A(n-2, n-1) = rational(0);

    }

    if (X == Type::E){
        
        for (unsigned i=0; i< A.size1(); ++i){
            A(i, i) = rational(2);
	}
	
	for (unsigned i=0; i+1< A.size1(); ++i){
            A(i, i+1) = rational(-1);
            A(i+1, i) = rational(-1);
	}

        A(0, 1) = rational(0);
        A(0, 2) = rational(-1);
        A(1, 2) = rational(0);
        A(1, 3) = rational(-1);
        
        A(1, 0) = rational(0);
        A(2, 0) = rational(-1);
        A(2, 1) = rational(0);
        A(3, 1) = rational(-1);

    }

    if (X == Type::F){
        
        for (unsigned i=0; i< A.size1(); ++i){
            A(i, i) = rational(2);
	}
	
	for (unsigned i=0; i+1< A.size1(); ++i){
            A(i, i+1) = rational(-1);
            A(i+1, i) = rational(-1);
	}


        A(2, 1) = rational(-2);
    }

    if (X == Type::G){
        
        A.resize(2,2);

        A(0,0) = rational(2);
        A(1,1) = rational(2);
        A(1,0) = rational(-1);
        A(0,1) = rational(-3);

    }
    return A;
}
#endif
}
