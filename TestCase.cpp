#include <stdio.h>
#include <iostream>
#include <sstream>
#include <strings.h>
using namespace std;

class TestCase{
public:
ostream *stream ;
string message;

int pass;
int fail;

	TestCase(string s, ostream &os){
		stream = &os;
		message = s; 
		pass=0;
		fail=0;
	}
	
	template <class T> TestCase check_equal(T x, T y) { 
		if(x == y){
			pass++;
        }
		else { (*stream) << message <<": "<< "Failure in test #"<<  (pass+fail+1) << ": "<< x << " should equal " << y << "!"<<endl;
		fail++;
		}
		return (*this);
	}
	
	template <class T> TestCase check_different(T x, T y) { 
		if(x != y){
			pass++;
        }
		else {(*stream) << message<< ": "<< "Failure in test #"<<  (pass+fail+1) << ": "<< x << " should not equal " << y << "!"<<endl;
		fail++;
		}
		return (*this);
	}
	
	
	template <class T, class K, typename function> TestCase check_function(function func ,K x, T y) {
		//T k = func((T)x);
		if(func(x) == (T)y){
			pass++;
        }
		else {(*stream) << message<< ": "<< "Failure in test #"<<  (pass+fail+1) << ":  Function should return "<< (T)y << " but returned " << func(x) << "!"<<endl;
		fail++;
		}
		return (*this);
	}
	template <class T, class H, class K> TestCase check_function(T (*func)(H) ,K x, T y) {
		//T k = func((T)x);
		if(func((H)x) == (T)y){
			pass++;
        }
		else {(*stream) << message<< ": "<< "Failure in test #"<<  (pass+fail+1) << ":  Function should return "<< (T)y << " but returned " << func((H)x) << "!"<<endl;
		fail++;
		}
		return (*this);
	}
	
/*	template <class T, class H, class K> TestCase check_function( const H &func(H) ,K x, T y) {
		//T k = func((T)x);
		if(func((H)x) == (T)y){
			pass++;
        }
		else {(*stream) << message<< ": "<< "Failure in test #"<<  (pass+fail+1) << ":  Function should return "<< (T)y << " but returned " << func((H)x) << "!"<<endl;
		fail++;
		}
		return (*this);
	}*/

	template <class T> TestCase check_output(T x, string y) { 
		stringstream string;
        string << x;
        if (string.str().compare(y) == 0){
            pass++;
        }
		else {(*stream) << message<< ": "<< "Failure in test #"<<  (pass+fail+1) << ": string value should be "<< y << " but is " << string.str() << "!"<<endl;
		fail++;
		}
		return (*this);
	}
	
	void print(){
		(*stream) << message <<": "<< fail <<" failed, "<< pass <<" passed, "<< (pass+fail) <<" total."<<endl<<"---"<<endl;
	}
	
	
	
};
