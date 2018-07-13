/**
 * @file   gweyl.hpp
 * @author ALIKAWA Hidehisa <alleyhide@gmail.com>
 * @date   2018/04/30
 * 
 * @brief  private header file of gweyl
 * 
 * 
 */
#pragma once

#include "gweyl.hpp"

namespace gweyl{

matrix CartanMatrix(Type X, unsigned n);
matrix InverseCartanMatrix(Type X, unsigned n);

}
