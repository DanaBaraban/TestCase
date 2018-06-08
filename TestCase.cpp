#include <stdio.h>

class TestCase{

    void check_equal (int x, int y){
        if(x != y){
            printf("Error! Two numbers are not equal");
        }
    }
    void check_equal (struct x, struct y){
        if(x != y){
            printf("Error! Two numbers are not equal");
        }
    }

    void check_different (MyStruct x, const MyStruct& y){
        if(x == y){
            printf("Error! Two numbers are equal");
        }
    }

    void check_different (MyStruct x, const MyStruct& y){
        if(x == y){
            printf("Error! Two numbers are equal");
        }
    }

    void check_output (const MyStruct& tc, ostream& out){
        std::stringstream str;
        str << tc.num; 
        if (str.compare(out))
        else printf("Error! Outputs are not the same.")
    }

    void check_output (const int tc, ostream& out){
        std::stringstream str;
        str << tc; 
        if (str.compare(out))
        else printf("Error! Outputs are not the same.")
    }
}