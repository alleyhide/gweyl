#include "gweyl.hpp"
#include "gweyl_private.hpp"


namespace gweyl{

Vector::Vector(Type X, NumberVector& v, Coordinate c){
    X_ = X;
    rank_ = v.size();

    CartanMatrix_ = CartanMatrix();
    InverseCartanMatrix_ = InverseCartanMatrix();

    if (c == Coordinate::simple){
        simpleCoefficients_ = v;
        fundamentalCoefficients_ = prod(CartanMatrix_, v);
    }else {
        simpleCoefficients_ = prod(InverseCartanMatrix_, v);
        fundamentalCoefficients_ = v;
    }
}
                  
void Vector::printf(){
    std::cout << "simple " << simpleCoefficients_ << std::endl;
    std::cout << "fundamental " << fundamentalCoefficients_ << std::endl;
}


}
