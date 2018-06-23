/**
 * @file   gweyl.hpp
 * @author ALIKAWA Hidehisa <alley_hide@ybb.ne.jp>
 * @date   2018/04/30
 * 
 * @brief  public header file of gweyl
 * 
 * 
 */
#pragma once

#include <exception>
#include <map>
#include <iostream>
#include <functional>

#include <boost/rational.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace gweyl{

using rational=boost::rational<int>;
using matrix= boost::numeric::ublas::matrix<rational>;
using NumberVector=boost::numeric::ublas::vector<rational>;

// gweyl treats simple Lie algebra types
// in Cartan's classification
enum class Type{
    A,B,C,D,E,F,G,
};

enum class Coordinate {
    standard, fundamental,
};

// trace
void trace(std::string& msg);



class Cartan
{
public:
    explicit Cartan(Type X, unsigned n);
    Cartan() = delete;
    ~Cartan();

    matrix CartanMatrix();
    matrix InverseCartanMatrix();
private:
    Type X_;
    unsigned rank_;
};


matrix CartanMatrix(Cartan& t);
matrix InverseCartanMatrix(Cartan& t);


class Vector
{
public:    
    explicit Vector(Cartan &V, NumberVector& v, Coordinate c);
    explicit Vector(Type X, unsigned r, NumberVector& v, Coordinate c);
private:
    Cartan V_;
    NumberVector simpleCoefficients_;
    NumberVector fundamentalCoefficients_;
    
};

}
