/**
 * @file   gweyl.hpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
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

//
// our namespace "gweyl"
//
namespace gweyl{

//
// rational numbers
//
using rational=boost::rational<int>;

//
// matrix of rational numbers
//
using matrix=boost::numeric::ublas::matrix<rational>;

//
// number vector
// this is vector of mathematics (primitive linear algera)
//
using NumberVector=boost::numeric::ublas::vector<rational>;

//
// we define equality of matirx and number vector
// because boost does not define the equality
//
bool equal(const matrix &X, const matrix &Y);
bool equal(const NumberVector &v, const NumberVector &w);

//
// gweyl treats simple Lie algebra types
// in Cartan's classification
//
enum class Type{
    invalid,A,B,C,D,E,F,G,
};

//
// Coordinate system
// There are at least two coordinates on root spaces.
// One is simple roots, and the other is fundamental weights.
//
enum class Coordinate {
    simple, fundamental,
};

//
// trace the message
// @param[in] msg message
// 
//
void trace(std::string& msg);

class VectorRootSpace;

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

    //
    // @return Cartan matrix
    //
    matrix CartanMatrix();
    
    //
    // @return invers of Cartan matrix
    //
    matrix InverseCartanMatrix();

    //
    // @return the 'i'-th simple root
    //
    VectorRootSpace SimpleRoot(unsigned i);

    //
    // @return the 'i'-th fundamental weight
    //
    VectorRootSpace FundamentalWeight(unsigned i);
    //VectorRootSpace Zero();
    //VectorRootSpace Rho();

    //
    // getter of X_
    // @return type
    //
    Type type();
    Type type() const;
    
    //
    // getter of rank_
    // @return n
    //
    unsigned rank();
    unsigned rank() const;

    bool operator==(const Cartan& rhs);
    bool operator!=(const Cartan& rhs);

    Cartan& operator=(const Cartan& rhs);
protected:
    Type X_{Type::invalid};
    unsigned rank_{0};
};

//
// In gweyl, the class RootSpace, DynkinDiagram and the class Cartan are same
//
using RootSpace = Cartan;
using DynkinDiagram = Cartan;

//
// Vector in root space
//
class VectorRootSpace 
{
public:
    // constructors
    explicit VectorRootSpace(Type X, NumberVector& v, Coordinate c);
    VectorRootSpace();
    virtual ~VectorRootSpace();

    // for debug
    void printf();

    // getters
    NumberVector simpleCoefficients();
    NumberVector simpleCoefficients() const;
    NumberVector fundamentalCoefficients();
    NumberVector fundamentalCoefficients() const;
    Type type();
    Type type() const;
    unsigned rank();
    unsigned rank() const;

    // eqaulity
    bool isInSameSpace(const VectorRootSpace& rhs);
    bool operator==(const VectorRootSpace& rhs);
    bool operator!=(const VectorRootSpace& rhs);

    // operators
    VectorRootSpace& operator=(const VectorRootSpace& rhs);
    VectorRootSpace& operator+=(const VectorRootSpace& rhs);
    VectorRootSpace& operator-=(const VectorRootSpace& rhs);
    VectorRootSpace& operator*=(rational r);
private:
    RootSpace space_;
    NumberVector simpleCoefficients_;///< coefficients for simple roots coordinate
    NumberVector fundamentalCoefficients_;///< coefficients for fundamental weights coordinate
};

//
// operators of the class Vector
//
rational InnerProduct(VectorRootSpace& v, VectorRootSpace& w);

}
