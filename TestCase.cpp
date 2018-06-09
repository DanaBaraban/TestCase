#include <stdio.h>
#include <iostream>
#include <sstream>
#include <strings.h>

class TestCase{

    void check_equal (int x, int y){
        if(x != y){
            printf("Error! Two numbers are not equal");
        }
    }
    void check_equal (struct x, struct y){
        if(x.num != y.num){
            printf("Error! Two numbers are not equal");
        }
    }

    void check_different (int x, int y){
        if(x == y){
            printf("Error! Two numbers are equal");
        }
    }

    void check_different (struct x, const struct y){
        if(x == y){
            printf("Error! Two numbers are equal");
        }
    }

    void check_output (const MyStruct& tc, ostream& out){
        std::stringstream string;
        string << tc.num; 
        if (string.str != out.str){
            printf("Error! Outputs are not the same.");
        }
    }

    void check_output (const int tc, ostream& out){
        std::stringstream string;
        string << tc; 
        if (string.str != out.str){
            printf("Error! Outputs are not the same.");
        }
    }

    void check_function (int function);
};
