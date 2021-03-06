#
# @file CMakeLists.txt for gweyl test
# @author ALIKAWA Hidehisa <alleyhide@gmail.com>
# @date   2018/04/30
# Released under the MIT license
#


link_directories(../gweyl)

#
# work
# for debug
#
add_executable(work work.cpp)
target_link_libraries(work gweyl)

#
# test for class Cartan
# tests are in the source
#
add_executable(CartanTest CartanTest.cpp)
target_link_libraries(CartanTest gweyl)

#
# test for class CartanMatrix
#
add_executable(CartanMatrixTest CartanMatrixTest.cpp)
target_link_libraries(CartanMatrixTest gweyl)

#
# test for class inverse matrix of CartanMatrix
#
add_executable(InverseCartanMatrixTest InverseCartanMatrixTest.cpp)
target_link_libraries(InverseCartanMatrixTest gweyl)

#
# test for class VectorRootSpace
#
add_executable(VectorRootSpaceTest VectorRootSpaceTest.cpp)
target_link_libraries(VectorRootSpaceTest gweyl)

#
# test for Positive Roots
#
add_executable(PositiveRootsTest PositiveRootsTest.cpp)
target_link_libraries(PositiveRootsTest gweyl)

#
# test for Rho
#
add_executable(RhoTest RhoTest.cpp)
target_link_libraries(RhoTest gweyl)

#
# test for class Representation
#
add_executable(IrreducibleRepresentationTest IrreducibleRepresentationTest.cpp)
target_link_libraries(IrreducibleRepresentationTest gweyl)



#
# test
#
enable_testing()


#
# tests for Cartan
#
add_test(testCartan001 CartanTest)
set_tests_properties(testCartan001 PROPERTIES FAIL_REGULAR_EXPRESSION "Error")

#
# tests for Vector in root space
#
add_test(testVectorRootSpace001 VectorRootSpaceTest)
set_tests_properties(testVectorRootSpace001 PROPERTIES FAIL_REGULAR_EXPRESSION "Error")

#
# tests for Rho in root space
#
add_test(testRho001 RhoTest)
set_tests_properties(testRho001 PROPERTIES FAIL_REGULAR_EXPRESSION "Error")

#
# tests for Representation
#
add_test(testIrreducibleRepresentation001 IrreducibleRepresentationTest)
set_tests_properties(testIrreducibleRepresentation001 PROPERTIES FAIL_REGULAR_EXPRESSION "Error")






#
# test for CartanMatrix
#
macro (testCartanMatrix arg1 arg2 result)
  add_test(testCartanMatrix${arg1}${arg2} CartanMatrixTest ${arg1} ${arg2})
  set_tests_properties(testCartanMatrix${arg1}${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(testCartanMatrix)


# type A
testCartanMatrix (A 1 "2/1")
testCartanMatrix (A 2 "2/1,-1/1.,.-1/1,2/1")
testCartanMatrix (A 3 "2/1,-1/1,0/1.,.-1/1,2/1,-1/1.,.0/1,-1/1,2/1")
# type B
testCartanMatrix (B 1 "n must be >= 2")
testCartanMatrix (B 2 "2/1,-1/1.,.-2/1,2/1")
testCartanMatrix (B 3 "2/1,-1/1,0/1.,.-1/1,2/1,-1/1.,.0/1,-2/1,2/1")


# type C
testCartanMatrix (C 1 "n must be >= 2")
testCartanMatrix (C 2 "2/1,-2/1.,.-1/1,2/1")
testCartanMatrix (C 3 "2/1,-1/1,0/1.,.-1/1,2/1,-2/1.,.0/1,-1/1,2/1")

# type D
testCartanMatrix (D 3 "n must be >= 4")
testCartanMatrix (D 4 "2/1,-1/1,0/1,0/1.,.-1/1,2/1,-1/1,-1/1.,.0/1,-1/1,2/1,0/1.,.0/1,-1/1,0/1,2/1")

# type E
testCartanMatrix (E 5 "n must be 6,7 or 8")
testCartanMatrix (E 9 "n must be 6,7 or 8")
testCartanMatrix (E 6 "2/1,0/1,-1/1,0/1,0/1,0/1.,.0/1,2/1,0/1,-1/1,0/1,0/1.,.-1/1,0/1,2/1,-1/1,0/1,0/1.,.0/1,-1/1,-1/1,2/1,-1/1,0/1.,.0/1,0/1,0/1,-1/1,2/1,-1/1.,.0/1,0/1,0/1,0/1,-1/1,2/1")
testCartanMatrix (E 7 "2/1,0/1,-1/1,0/1,0/1,0/1,0/1.,.0/1,2/1,0/1,-1/1,0/1,0/1,0/1.,.-1/1,0/1,2/1,-1/1,0/1,0/1,0/1.,.0/1,-1/1,-1/1,2/1,-1/1,0/1,0/1.,.0/1,0/1,0/1,-1/1,2/1,-1/1,0/1.,.0/1,0/1,0/1,0/1,-1/1,2/1,-1/1.,.0/1,0/1,0/1,0/1,0/1,-1/1,2/1")
testCartanMatrix (E 8 "2/1,0/1,-1/1,0/1,0/1,0/1,0/1,0/1.,.0/1,2/1,0/1,-1/1,0/1,0/1,0/1,0/1.,.-1/1,0/1,2/1,-1/1,0/1,0/1,0/1,0/1.,.0/1,-1/1,-1/1,2/1,-1/1,0/1,0/1,0/1.,.0/1,0/1,0/1,-1/1,2/1,-1/1,0/1,0/1.,.0/1,0/1,0/1,0/1,-1/1,2/1,-1/1,0/1.,.0/1,0/1,0/1,0/1,0/1,-1/1,2/1,-1/1.,.0/1,0/1,0/1,0/1,0/1,0/1,-1/1,2/1")

# type F
testCartanMatrix (F 3 "n must be 4")
testCartanMatrix (F 5 "n must be 4")
testCartanMatrix (F 4 "2/1,-1/1,0/1,0/1.,.-1/1,2/1,-1/1,0/1.,.0/1,-2/1,2/1,-1/1.,.0/1,0/1,-1/1,2/1")

# type G
testCartanMatrix (G 1 "n must be 2")
testCartanMatrix (G 3 "n must be 2")
testCartanMatrix (G 2 "2/1,-3/1.,.-1/1,2/1")


# for inverse matrix
macro (testInverseCartanMatrix arg1 arg2)
  add_test(testInverseCartanMatrix${arg1}${arg2} InverseCartanMatrixTest ${arg1} ${arg2} check)
    set_tests_properties(testInverseCartanMatrix${arg1}${arg2}
    PROPERTIES FAIL_REGULAR_EXPRESSION "not identity matrix")
endmacro(testInverseCartanMatrix)

# type A
testInverseCartanMatrix(A 1)
testInverseCartanMatrix(A 2)
testInverseCartanMatrix(A 3)
testInverseCartanMatrix(A 4)
testInverseCartanMatrix(A 5)
testInverseCartanMatrix(A 6)
testInverseCartanMatrix(A 7)
testInverseCartanMatrix(A 8)
testInverseCartanMatrix(A 9)
testInverseCartanMatrix(A 10)

# type B
testInverseCartanMatrix(B 2)
testInverseCartanMatrix(B 3)
testInverseCartanMatrix(B 4)
testInverseCartanMatrix(B 5)
testInverseCartanMatrix(B 6)
testInverseCartanMatrix(B 7)
testInverseCartanMatrix(B 8)
testInverseCartanMatrix(B 9)
testInverseCartanMatrix(B 10)

# type C
testInverseCartanMatrix(C 2)
testInverseCartanMatrix(C 3)
testInverseCartanMatrix(C 4)
testInverseCartanMatrix(C 5)
testInverseCartanMatrix(C 6)
testInverseCartanMatrix(C 7)
testInverseCartanMatrix(C 8)
testInverseCartanMatrix(C 9)
testInverseCartanMatrix(C 10)


# type D
testInverseCartanMatrix(D 4)
testInverseCartanMatrix(D 5)
testInverseCartanMatrix(D 6)
testInverseCartanMatrix(D 7)
testInverseCartanMatrix(D 8)
testInverseCartanMatrix(D 9)
testInverseCartanMatrix(D 10)

# type E
testInverseCartanMatrix(E 6)
testInverseCartanMatrix(E 7)
testInverseCartanMatrix(E 8)

# type F
testInverseCartanMatrix(F 4)

# type G
testInverseCartanMatrix(G 2)



#
# tests for Positive Roots
#
macro (testPositiveRoots arg1 arg2 result)
  add_test(testPositiveRoots${arg1}${arg2} PositiveRootsTest ${arg1} ${arg2})
  set_tests_properties(testPositiveRoots${arg1}${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(testPositiveRoots)



# type A
testPositiveRoots (A 1 "1/1")
testPositiveRoots (A 2 "1/1,0/1.....1/1,1/1.....0/1,1/1")
testPositiveRoots (A 3 "1/1,0/1,0/1.....1/1,1/1,0/1.....1/1,1/1,1/1.....0/1,1/1,0/1.....0/1,1/1,1/1.....0/1,0/1,1/1")

# type B
testPositiveRoots (B 2 "1/1,0/1.....1/1,1/1.....0/1,1/1.....1/1,2/1")
testPositiveRoots (B 3 "1/1,0/1,0/1.....1/1,1/1,0/1.....1/1,1/1,1/1.....0/1,1/1,0/1.....0/1,1/1,1/1.....0/1,0/1,1/1.....1/1,2/1,2/1.....1/1,1/1,2/1.....0/1,1/1,2/1")

# type C
testPositiveRoots (C 2 "1/1,0/1.....1/1,1/1.....0/1,1/1.....2/1,1/1")
testPositiveRoots (C 3 "1/1,0/1,0/1.....1/1,1/1,0/1.....1/1,1/1,1/1.....0/1,1/1,0/1.....0/1,1/1,1/1.....0/1,0/1,1/1.....1/1,2/1,1/1.....2/1,2/1,1/1.....0/1,2/1,1/1")

# type D
testPositiveRoots (D 4 "1/1,0/1,0/1,0/1.....1/1,1/1,0/1,0/1.....1/1,1/1,1/1,0/1.....0/1,1/1,0/1,0/1.....0/1,1/1,1/1,0/1.....0/1,0/1,1/1,0/1.....1/1,1/1,1/1,1/1.....0/1,1/1,1/1,1/1.....0/1,0/1,0/1,1/1.....1/1,1/1,0/1,1/1.....0/1,1/1,0/1,1/1.....1/1,2/1,1/1,1/1")

# type E
testPositiveRoots (E 6 "1/1,2/1,2/1,3/1,2/1,1/1")
testPositiveRoots (E 7 "2/1,2/1,3/1,4/1,3/1,2/1,1/1")
testPositiveRoots (E 8 "2/1,3/1,4/1,6/1,5/1,4/1,3/1,2/1")

# type F
testPositiveRoots (F 4 "2/1,3/1,4/1,2/1")

# type G
testPositiveRoots (G 2 "1/1,0/1.....0/1,1/1.....1/1,1/1.....2/1,1/1.....3/1,1/1.....3/1,2/1")

