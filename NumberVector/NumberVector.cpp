/**
 * @file   NumberVector.cpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/07/28
 * 
 * @brief  for NumberVector or matrix
 * 
 * Released under the MIT license
 */
#include "gweyl.hpp"

namespace gweyl{


#if 0
bool operator==(const matrix &X, const matrix &Y){
    return !(X != Y);
}


bool operator!=(const matrix &X, const matrix &Y){
    if (X.size1() != Y.size1()){
        return true;
    }

    if (X.size2() != Y.size2()){
        return true;
    }

    for (unsigned i=0; i<X.size1(); ++i){
        for (unsigned j=0; j<X.size2(); ++j){
            if (X(i, j) != Y(i, j)){
                return true;
            }
        }
    }
    
    return false;        
}

bool operator==(const NumberVector &v, const NumberVector &w){
    return !(v != w);
}

bool operator!=(const NumberVector &v, const NumberVector &w){
    if (v.size() != w.size()){
        return true;
    }

    for (unsigned i=0; i<v.size(); ++i){
        if (v(i) != w(i)){
            return true;
        }
    }
    return false;
}
#endif


bool equal(const matrix &X, const matrix &Y){
    if (X.size1() != Y.size1()){
        return false;
    }

    if (X.size2() != Y.size2()){
        return false;
    }

    for (unsigned i=0; i<X.size1(); ++i){
        for (unsigned j=0; j<X.size2(); ++j){
            if (X(i, j) != Y(i, j)){
                return false;
            }
        }
    }
    
    return true;        
}


bool equal(const NumberVector &v, const NumberVector &w){
    if (v.size() != w.size()){
        return false;
    }

    for (unsigned i=0; i<v.size(); ++i){
        if (v(i) != w(i)){
            return false;
        }
    }
    return true;
}


#if 0
bool equal(NumberVector& v, NumberVector& w){
    if (v.size() != w.size()){
        return false;
    }

    for (unsigned i=0; i<v.size(); ++i){
        if (v(i) != w(i)){
            return false;
        }
    }
    return true;
    
}
#endif

}
