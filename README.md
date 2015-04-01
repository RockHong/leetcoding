A playground to not forget the c++ language...

## How to Run
`${GTEST_DIR}` is your google test directory.       
`gtest_main.cc` is stolen from `${GTEST_DIR}`.        

### g++ on cygwin
Add `-std=gnu++11` to let g++ compile against google test. (For g++ 4.8.3 on cygwin,
`-std=c++11` does not work.)     

    g++ -std=gnu++11 -isystem ${GTEST_DIR}/include/ -L${GTEST_DIR}/ A_CPP_FILE_IN_THIS_REPO gtest_main.cc -lgtest -o test_main

For example,

    # g++ 4.8.3, cygwin
    g++ -std=gnu++11 -isystem /cygdrive/c/Hong/bin/gtest-1.7.0/include/ -L/cygdrive/c/Hong/bin/gtest-1.7.0/ 172_Factorial_Trailing_Zeroes.cpp gtest_main.cc -lgtest -o test_main


