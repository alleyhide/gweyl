#
# @file CMakeLists.txt for gweyl test
# @author ALIKAWA Hidehisa <alleyhide@gmail.com>
#


link_directories(../gweyl)

add_executable(CartanMatrixTest CartanMatrixTest.cpp)
target_link_libraries(CartanMatrixTest gweyl)

add_executable(InverseCartanMatrixTest InverseCartanMatrixTest.cpp)
target_link_libraries(InverseCartanMatrixTest gweyl)

add_executable(VectorTest VectorTest.cpp)
target_link_libraries(VectorTest gweyl)



#
# test
#
enable_testing()

#
# test for Cartan Matrix
#
#add_test(test0002 test/CartanMatrixTest A 1)
#set_tests_properties(test0002 PROPERTIES PASS_REGULAR_EXPRESSION "2/1")
#add_test(test0003 test/CartanMatrixTest A 2)
#set_tests_properties(test0003 PROPERTIES PASS_REGULAR_EXPRESSION "2/1,-1/1.,.-1/1,2/1")
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
testInverseCartanMatrix(A 11)
testInverseCartanMatrix(A 12)
testInverseCartanMatrix(A 13)
testInverseCartanMatrix(A 14)
testInverseCartanMatrix(A 15)
testInverseCartanMatrix(A 16)
testInverseCartanMatrix(A 17)
testInverseCartanMatrix(A 18)
testInverseCartanMatrix(A 19)
testInverseCartanMatrix(A 20)

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
testInverseCartanMatrix(B 11)
testInverseCartanMatrix(B 12)
testInverseCartanMatrix(B 13)
testInverseCartanMatrix(B 14)
testInverseCartanMatrix(B 15)
testInverseCartanMatrix(B 16)
testInverseCartanMatrix(B 17)
testInverseCartanMatrix(B 18)
testInverseCartanMatrix(B 19)
testInverseCartanMatrix(B 20)

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
testInverseCartanMatrix(C 11)
testInverseCartanMatrix(C 12)
testInverseCartanMatrix(C 13)
testInverseCartanMatrix(C 14)
testInverseCartanMatrix(C 15)
testInverseCartanMatrix(C 16)
testInverseCartanMatrix(C 17)
testInverseCartanMatrix(C 18)
testInverseCartanMatrix(C 19)
testInverseCartanMatrix(C 20)

# type D
testInverseCartanMatrix(D 4)
testInverseCartanMatrix(D 5)
testInverseCartanMatrix(D 6)
testInverseCartanMatrix(D 7)
testInverseCartanMatrix(D 8)
testInverseCartanMatrix(D 9)
testInverseCartanMatrix(D 10)
testInverseCartanMatrix(D 11)
testInverseCartanMatrix(D 12)
testInverseCartanMatrix(D 13)
testInverseCartanMatrix(D 14)
testInverseCartanMatrix(D 15)
testInverseCartanMatrix(D 16)
testInverseCartanMatrix(D 17)
testInverseCartanMatrix(D 18)
testInverseCartanMatrix(D 19)
testInverseCartanMatrix(D 20)

# type E
testInverseCartanMatrix(E 6)
testInverseCartanMatrix(E 7)
testInverseCartanMatrix(E 8)

# type F
testInverseCartanMatrix(F 4)

# type G
testInverseCartanMatrix(G 2)
