/**
 * @file   gweyl.hpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/04/30
 * 
 * @brief  public header file of gweyl
 * 
 * Released under the MIT license
 */
#pragma once

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

///
/// The definition of Cartan Matrix is equivalent to
/// the definition of the root space, according to structure theory of Lie algebra,
/// that is, Cartan matrix is the source of "gweyl"
///
matrix CartanMatrix(Type X, unsigned n);
matrix InverseCartanMatrix(Type X, unsigned n);

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
    Cartan(const Cartan &rhs);
    virtual ~Cartan();
    Cartan& operator=(const Cartan& rhs);

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

    //
    // @return highest root <not implemented>
    //
    VectorRootSpace HighestRoot();

    //
    // @return zero vector
    //
    VectorRootSpace Zero();
    
    //
    // @return half sum of positive roots
    //
    VectorRootSpace Rho();

    //
    // @return positive roots
    //
    std::vector<VectorRootSpace> PositiveRoots();

    //
    // @return roots <not implemented>
    //
    std::vector<VectorRootSpace> Roots();

    // getters
    Type type();
    Type type() const;
    unsigned rank();
    unsigned rank() const;

    // operators
    bool operator==(const Cartan& rhs);
    bool operator!=(const Cartan& rhs);

    
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
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
    VectorRootSpace(const VectorRootSpace& rhs);
    VectorRootSpace& operator=(const VectorRootSpace& rhs);

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
    VectorRootSpace& operator+=(const VectorRootSpace& rhs);
    VectorRootSpace& operator-=(const VectorRootSpace& rhs);
    VectorRootSpace& operator*=(rational r);

    // dominant integral
    bool dominant();
    bool integral();
    bool isDominantIntegral();
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

//
// operators of the class VectorRootSpace
//
rational InnerProduct(VectorRootSpace& v, VectorRootSpace& w);
VectorRootSpace operator+(const VectorRootSpace& v1, const VectorRootSpace& v2);
VectorRootSpace operator-(const VectorRootSpace& v1, const VectorRootSpace& v2);
VectorRootSpace operator*(const VectorRootSpace& v1, const rational r);
VectorRootSpace operator*(const rational r, const VectorRootSpace& v1);

//
// class IrreducibleRepresentation
// 
class IrreducibleRepresentation{
public:
    //constructors
    IrreducibleRepresentation();
    explicit IrreducibleRepresentation(VectorRootSpace& highestweight);
    virtual ~IrreducibleRepresentation();
    IrreducibleRepresentation(const IrreducibleRepresentation& rhs);
    IrreducibleRepresentation& operator=(const IrreducibleRepresentation& rhs);

    //getters
    Type type();
    Type type() const;
    unsigned rank();
    unsigned rank() const;
    VectorRootSpace highestweight();
    VectorRootSpace highestweight() const;

    //operators
    bool operator==(const IrreducibleRepresentation& rhs);
    bool operator!=(const IrreducibleRepresentation& rhs);

    int dimension();
    
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};


}
