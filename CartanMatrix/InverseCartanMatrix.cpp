/**
 * @file   InverseCartanMatrix.cpp
 * @author ALIKAWA Hidehisa <alley_hide@ybb.ne.jp>
 * @date   2018/04/30
 * 
 * @brief  inverse matrix of CartanMatrix
 * 
 * 
 */
#include "gweyl.hpp"

namespace gweyl{

//
// invers matrix of Cartan matrix of type A
//
std::function<matrix(int)> InverseCartanMatrixA = [](int n){
        
    gweyl::matrix P;
    P.resize(n,n);

    for (unsigned i=0; i<P.size1(); i++){
        for (unsigned j=0; j<P.size2(); j++){
            if (i>j){
                P(i,j) = rational((n-i)*(j+1), n+1);
            } else {
                P(i,j) = rational((n-j)*(i+1), n+1);
            }
        }
    }
    
    return P;
};
    
//
// invers matrix of Cartan matrix of type B
//
std::function<matrix(int)> InverseCartanMatrixB = [](int n){

    matrix P;
    P.resize(n,n);

    for (unsigned i=0; i<P.size1(); i++){
        for (unsigned j=0; j<P.size2(); j++){
            if (j+1 == (unsigned)n){
                P(i,j)=rational(i+1,2);
            } else if (i<j){
                P(i,j)=rational(i+1);
            } else {
                P(i,j)=rational(j+1);
            }
        }
    }
    
    return P;
};

//
// invers matrix of Cartan matrix of type C
//
std::function<matrix(int)> InverseCartanMatrixC = [](int n){

    matrix P;
    P.resize(n,n);

    for (unsigned i=0; i<P.size1(); i++){
        for (unsigned j=0; j<P.size2(); j++){
            if (i < j){
                P(i,j)=rational(i+1);
            } else if (i+1 == (unsigned)n){
                P(i,j)=rational(j+1, 2);
            } else {
                P(i,j)=rational(j+1);
            }
        }
    }    
    return P;
};

//
// invers matrix of Cartan matrix of type D
//
std::function<matrix(int)> InverseCartanMatrixD = [](int n){

    matrix P;
    P.resize(n,n);

    for (unsigned i=0; i<P.size1(); i++){
        for (unsigned j=0; j<P.size2(); j++){
            if (i +2 < (unsigned)n){
                if (j < i){
                    P(i,j)=rational(j+1);
                } else if (j+2 < (unsigned)n) {
                    P(i,j)=rational(i+1);
                } else {
                    P(i,j)=rational(i+1, 2);
                }
		
            } else if (i+2 == (unsigned)n){
                if (j+2<(unsigned)n){
                    P(i,j)=rational(j+1, 2);
                } else if (j+2 == (unsigned)n){
                    P(i,j)=rational(n, 4);
                } else {
                    P(i,j)=rational(n-2, 4);
                }
            } else {
                if (j+2 < (unsigned)n){
                    P(i,j)=rational(j+1,2);
                } else if (j+2 == (unsigned)n){
                    P(i,j)=rational(n-2,4);
                } else {
                    P(i,j)=rational(n,4);
                }
            }
            
        }
    }
		
    return P;
};

//
// invers matrix of Cartan matrix of type E6
//
std::function<matrix()> InverseCartanMatrixE6 = [](){

    matrix P;
    P.resize(6,6);
    
    P(0,0)=rational(4, 3); P(0,1)=rational(1); P(0,2)=rational(5,3); P(0,3)=rational(2); P(0,4)=rational(4,3); P(0,5)=rational(2,3); 
    P(1,0)=rational(1); P(1,1)=rational(2); P(1,2)=rational(2); P(1,3)=rational(3); P(1,4)=rational(2); P(1,5)=rational(1); 
    P(2,0)=rational(5,3); P(2,1)=rational(2); P(2,2)=rational(10,3); P(2,3)=rational(4); P(2,4)=rational(8,3); P(2,5)=rational(4,3); 
    P(3,0)=rational(2); P(3,1)=rational(3); P(3,2)=rational(4); P(3,3)=rational(6); P(3,4)=rational(4); P(3,5)=rational(2); 
    P(4,0)=rational(4,3); P(4,1)=rational(2); P(4,2)=rational(8,3); P(4,3)=rational(4); P(4,4)=rational(10,3); P(4,5)=rational(5,3); 
    P(5,0)=rational(2,3); P(5,1)=rational(1); P(5,2)=rational(4,3); P(5,3)=rational(2); P(5,4)=rational(5,3); P(5,5)=rational(4,3);

    return P;
};

//
// invers matrix of Cartan matrix of type E7
//
std::function<matrix()> InverseCartanMatrixE7 = [](){

    matrix P;
    P.resize(7,7);

    P(0,0)=rational(2); P(0,1)=rational(2); P(0,2)=rational(3); P(0,3)=rational(4); P(0,4)=rational(3); P(0,5)=rational(2); P(0,6)=rational(1); 
    P(1,0)=rational(2); P(1,1)=rational(7,2); P(1,2)=rational(4); P(1,3)=rational(6); P(1,4)=rational(9,2); P(1,5)=rational(3); P(1,6)=rational(3,2); 
    P(2,0)=rational(3); P(2,1)=rational(4); P(2,2)=rational(6); P(2,3)=rational(8); P(2,4)=rational(6); P(2,5)=rational(4); P(2,6)=rational(2); 
    P(3,0)=rational(4); P(3,1)=rational(6); P(3,2)=rational(8); P(3,3)=rational(12); P(3,4)=rational(9); P(3,5)=rational(6); P(3,6)=rational(3); 
    P(4,0)=rational(3); P(4,1)=rational(9,2); P(4,2)=rational(6); P(4,3)=rational(9); P(4,4)=rational(15,2); P(4,5)=rational(5); P(4,6)=rational(5,2); 
    P(5,0)=rational(2); P(5,1)=rational(3); P(5,2)=rational(4); P(5,3)=rational(6); P(5,4)=rational(5); P(5,5)=rational(4); P(5,6)=rational(2); 
    P(6,0)=rational(1); P(6,1)=rational(3,2); P(6,2)=rational(2); P(6,3)=rational(3); P(6,4)=rational(5,2); P(6,5)=rational(2); P(6,6)=rational(3,2); 
    
    return P;
};

//
// invers matrix of Cartan matrix of type E8
//
std::function<matrix()> InverseCartanMatrixE8 = [](){

    matrix P;
    P.resize(8, 8);

    P(0,0)=rational(4); P(0,1)=rational(5); P(0,2)=rational(7); P(0,3)=rational(10); P(0,4)=rational(8); P(0,5)=rational(6); P(0,6)=rational(4); P(0,7)=rational(2);
    P(1,0)=rational(5); P(1,1)=rational(8); P(1,2)=rational(10); P(1,3)=rational(15); P(1,4)=rational(12); P(1,5)=rational(9); P(1,6)=rational(6); P(1,7)=rational(3);
    P(2,0)=rational(7); P(2,1)=rational(10); P(2,2)=rational(14); P(2,3)=rational(20); P(2,4)=rational(16); P(2,5)=rational(12); P(2,6)=rational(8); P(2,7)=rational(4);
    P(3,0)=rational(10); P(3,1)=rational(15); P(3,2)=rational(20); P(3,3)=rational(30); P(3,4)=rational(24); P(3,5)=rational(18); P(3,6)=rational(12); P(3,7)=rational(6);
    P(4,0)=rational(8); P(4,1)=rational(12); P(4,2)=rational(16); P(4,3)=rational(24); P(4,4)=rational(20); P(4,5)=rational(15); P(4,6)=rational(10); P(4,7)=rational(5);
    P(5,0)=rational(6); P(5,1)=rational(9); P(5,2)=rational(12); P(5,3)=rational(18); P(5,4)=rational(15); P(5,5)=rational(12); P(5,6)=rational(8); P(5,7)=rational(4);
    P(6,0)=rational(4); P(6,1)=rational(6); P(6,2)=rational(8); P(6,3)=rational(12); P(6,4)=rational(10); P(6,5)=rational(8); P(6,6)=rational(6); P(6,7)=rational(3);
    P(7,0)=rational(2); P(7,1)=rational(3); P(7,2)=rational(4); P(7,3)=rational(6); P(7,4)=rational(5); P(7,5)=rational(4); P(7,6)=rational(3); P(7,7)=rational(2);

    return P;
};

std::map<int, std::function<gweyl::matrix()>> InverseCartanMatrixFunctionTable_E {
    {6, InverseCartanMatrixE6},
    {7, InverseCartanMatrixE7},
    {8, InverseCartanMatrixE8},
};

std::function<matrix(int)> InverseCartanMatrixE = [](int n){
    return InverseCartanMatrixFunctionTable_E[n]();
};

//
// invers matrix of Cartan matrix of type F4
//    
std::function<matrix(int)> InverseCartanMatrixF4 = [](int n){

    matrix P;
    P.resize(n,n);

    P(0,0)=rational(2); P(0,1)=rational(3); P(0,2)=rational(2); P(0,3)=rational(1);
    P(1,0)=rational(3); P(1,1)=rational(6); P(1,2)=rational(4); P(1,3)=rational(2);
    P(2,0)=rational(4); P(2,1)=rational(8); P(2,2)=rational(6); P(2,3)=rational(3);
    P(3,0)=rational(2); P(3,1)=rational(4); P(3,2)=rational(3); P(3,3)=rational(2);
    
    return P;
};

//
// invers matrix of Cartan matrix of type G2
//
std::function<matrix(int)> InverseCartanMatrixG2 = [](int n){

    matrix P;
    P.resize(n,n);

    P(0,0)=rational(2); P(0,1)=rational(3);
    P(1,0)=rational(1); P(1,1)=rational(2);    
    return P;
};

std::map<gweyl::Type, std::function<gweyl::matrix(int)>> InverseCartanMatrixFunctionTable{
    {Type::A, InverseCartanMatrixA},
    {Type::B, InverseCartanMatrixB},
    {Type::C, InverseCartanMatrixC},
    {Type::D, InverseCartanMatrixD},
    {Type::E, InverseCartanMatrixE},
    {Type::F, InverseCartanMatrixF4},
    {Type::G, InverseCartanMatrixG2},        
};

matrix InverseCartanMatrix(Type X, unsigned n){
    return InverseCartanMatrixFunctionTable[X](n);
}

    
}
