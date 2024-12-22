#include<iostream>
using namespace std;
// static variable/methods (outside class and methods) are limited to the translation unit ie this cpp file only.
// they are not seen on the global scope and even if there's a variable of same name outsite of this file
// we do not get the redefinition error, however if the variable is not marked static and is then again 
// declared in any other translation unit (file) we get the redefinition error.

// If a static variable is declared in a header file and the header file is included in multiple files
// in each of those files (translation units) the static variable will agian be declared.
// static variables are used to keep the variable private to that translation unit.
// try to mark the variables static if they will not be used outside the translation unit.
static int s_staticVariable; // variable with same name is present in revice.cpp, removing static should give error

// same goes with static function
void s_Function() {}

class staticTest {
public :
// static variable inside a class.
// static variable inside a class is shared by all the objects of that class it's not specific to any object.
// static variable of a class can be accessed directly if declared public by using class_name::static_variable_name
// static variable of a class needs to be declared in the file where they will be accessed.
// the static variables have a lifespan of the program.
    static int count;
// static methods inside a class
// static methods can only access static variables they can not access non-static members of a class.
// static methods can be directly accessed by just the class name like class_name::static_method_name
// no point referring static variables or methods with an object - obj.static_method(), rather above works better
    static void increment() {
        count++;
    }
};

// static variables declared inside a function
// When a variable is declared static inside a function the variable memory is shared across all the runs
// of the functions.
// the lifespan of such static variables are also program lifetime, that's why each run will manipulate the
// same memory location ie sharing the memory location across all the runs of the function.

void staticFunction() {
    static int s_FunctionRunCount;
    s_FunctionRunCount++;
    cout<<s_FunctionRunCount<<endl;
}
