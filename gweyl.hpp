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

//
//
bool operator==(matrix &X, matrix &Y);
bool operator!=(matrix &X, matrix &Y);

bool operator==(NumberVector &X, NumberVector &Y);
bool operator!=(NumberVector &X, NumberVector &Y);

// gweyl treats simple Lie algebra types
// in Cartan's classification
enum class Type{
    invalid,A,B,C,D,E,F,G,
};

enum class Coordinate {
    simple, fundamental,
};

// trace
void trace(std::string& msg);

class Vector;

//
// class Cartan
//  other names are RootSpace, DynkinDiagram, ..
// fundamental class of gweyl
//
class Cartan
{
public:
    explicit Cartan(Type X, unsigned n);
    Cartan();
    virtual ~Cartan();

    matrix CartanMatrix();
    matrix InverseCartanMatrix();

    Vector SimpleRoot(unsigned i);
    Vector FundamentalWeight(unsigned i);
    Vector Zero();
    Vector Rho();

    Type type();
    int rank();
protected:
    Type X_{Type::invalid};
    unsigned rank_{0};
};

using RootSpace = Cartan;
using DynkinDiagram = Cartan;

//
// The followings are operators of the class Cartan
//

bool operator==(Cartan &X, Cartan &Y);
bool operator!=(Cartan &X, Cartan &Y);

class Vector : public RootSpace
{
public:    
    explicit Vector(Type X, NumberVector& v, Coordinate c);
    void printf();

    NumberVector simpleCoefficients();
    NumberVector fundamentalCoefficients();

    Vector operator-() const;
    Vector operator+() const;
private:
    NumberVector simpleCoefficients_;
    NumberVector fundamentalCoefficients_;
    matrix CartanMatrix_;
    matrix InverseCartanMatrix_;
};

//
// The followings are operators of the class Vector
//

bool operator==(Vector &X, Vector &Y);
bool operator!=(Vector &X, Vector &Y);
Vector operator+(Vector &X, Vector &Y);
Vector operator-(Vector &X, Vector &Y);
rational InnerProduct(Vector& v, Vector& w);

}
