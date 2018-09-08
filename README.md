# gweyl
=========

The software "gweyl" is a small library of C++ for the calculations
of representation theory of Lie algebras.

## Requirement

The followings are required.
+ boost 1.62 or newer
+ cmake (for build)

For example, if you use Debian, do
    $ sudo apt install libboost-all-dev cmake

## Usage

On source files,
    #include "gweyl.hpp"
When compiling, compile with -lgweyl

## COMPILE

Do
    $ cmake .
    $ make

If you want to test, do
    $make test

## Contribution

To contribute to gweyl, clone this repo locally and commit your code on a separate branch. Please write unit tests for your code, and run test before a pull-request:
    Write tests by test/CMakeLists.txt
    # make test


## License

[MIT](https://github.com/alleyhide/gweyl/blob/master/LICENSE)

## Author

[alleyhide](https://github.com/alleyhide)

