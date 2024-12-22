#include<iostream> // use <> angular brackets when the direcory of the file is added to include paths.
// c++ std library header files do not have .h extensio, but on the other hand c header files does ex <stdio.h>
#include "../header-files/revise.h" // user "" quotes anytime else, for relative file location to current file.
using namespace std;

void variables() {
    // variables differ by size only
    // int is 4 bytes (32 bits) since int is signed it has 31 bits usable to store values 
    // it can store values from  -2billion to +2billion
    int a = 1;
    cout<<"Size of int "<< sizeof(int) << endl;
    // char is 1 byte 8 bit
    char  b = 'b';
    cout<<"Size of char "<< sizeof(char) << endl;
    // short is 2 bytes 8 bit
    short c = 100;
    cout<<"Size of short "<< sizeof(short) << endl;
    // long is also 4 bytes generally 
    long d = 1000;
    cout<<"Size of long "<< sizeof(long) << endl;
    // long long has 8 bytes 
    long long e = 10000;
    cout<<"Size of long long "<< sizeof(long long) << endl;
    // can add unsigned to any of these variable types to get extra 1 bit and double the capacity.
    // The main difference between datatypes is the amount of memory taken

    // for decimals 2 data types 
    // float 4 bytes large : append 'f' at the end to store as float, 
    // otherwise it will be treated as double only
    float f = 1.45f;
    cout<<"Size of float "<< sizeof(float) << endl;
    // double is 8 bytes
    double g = 1.456;
    cout<<"Size of double "<< sizeof(double) << endl;

    // bool is 1 byte, coule be 1 bit but the rest of the bytes because of memory address.
    bool h = 1;
    cout<<"Size of double "<< sizeof(double) << endl;
}

// Pointers 
// pointer for all types is just an integer that holds the memory address.
// The type is used to manipulate the data which is pointed by the data.

void pointers() {
    // void pointer - we do not care what kind of data is pointed by the pointer, it's just a memory address
    // as long as the data 
    void * voidPtr = nullptr;
    int intVar = 5;
    cout<<"intVar address ="<<&intVar<<endl;
    voidPtr = &intVar;
    // below line will not work as it will not know how many bytes to ready from the memory address 
    // stored in void pointer which means we can store a memory address in void pointer but to access/manipulate
    // it we need to cast it to another type.
    // -- cout<<*voidPtr<<endl;
    // but if we cast the void pointer which points to an int to a int pointer then it should work
    int *intPtr = (int*)voidPtr;
    cout<< "Casted void pointer : "<< *intPtr<<endl;

    // Pointers are nothing but vaiables which stores memory addresses of other types/variables.
    // so we can have pointers that point to other pointers.

    int** intPtr2 = &intPtr; // ** to denote it's a pointer to (int*)* and stored address of intPtr (&intPtr)
    cout<< "Derefrencing a pointer to int pointer : " << *(*intPtr2) << endl;
}


// reference helper function
void referenceHelper(int& intRef) {
    intRef++;
}

// References are special kind of variables which stores the reference (alias) to an already existing variable
// References can not be created and assigned later, they need to be assigned at the time of declaration.
// Once a reference is declared it can not be re-assiged to any other value
void references() {
    int intValue = 5;
    int& refInt = intValue;
    refInt ++;
    cout<< " Increased the value by reference : "<<intValue<<endl;
    referenceHelper(intValue);
    cout<< " Increased the value by call by reference : "<<intValue<<endl;
}


// Classes in C++
// Classes are blueprints and multiple objects of the same blueprints could be created.
// By default all the members of a class are PRIVATE.
// functions inside the class are called METHODS.

class Player {
    int x, y;
    int speed;

}; // need semi colon at then end of class declaration.

// Structs in C++
// structs are similar to class only difference is that by default the memebrs are PUBLIC
// We have structs in C++ to enable backward compatibility with C
// struct depends on the usage only, generally they are used to store data with not that much complex 
// functionality, for more complex designs/objects better use classes, use structs just to store data for 
// design sake
struct PlayerStruct {
    int x, y;
    int speed;
};

// LOG Class

class Log {
public :
    int m_LogLevelError = 0;
    int m_LogLevelWarning = 1;
    int m_LogLevelInfo = 2;

private :
    int m_logLevel = m_LogLevelInfo; // default log level info
public :
    void setLogLevel(int logLevel) {
        m_logLevel = logLevel;
    }

    void error(const char* message) {
        if (m_logLevel >= m_LogLevelWarning) 
            cout<< "[ERROR]: "<<message<<endl;
    }
    void warn(const char* message) {
        if (m_logLevel >= m_LogLevelError) 
            cout<< "[WARNING]: "<<message<<endl;
    }

    void info(const char* message) {
        if (m_logLevel >= m_LogLevelInfo)
            cout<< "[INFO]: "<<message<<endl;
    }

};

// Static variable or function outside a class or method (on global scope)
// check static.cpp for more details.
int s_staticVariable = 5;
// static function of same name in static .cpp
void s_Function() {}

// static variable inside a class.
// static variable inside a class is shared by all the objects of that class it's not specific to any object.
// static variable of a class can be accessed directly if declared public by using class_name::static_variable_name
// static variable of a class needs to be declared in the file where they will be accessed.
// the static variables have a lifespan of the program.

// static methods inside a class
// static methods can only access static variables they can not access non-static members of a class.
// static methods can be directly accessed by just the class name like class_name::static_method_name




int main() {
    
    variables();
    pointers();
    references();

    // class 
    Player p;




    // Static variable outside a class or function
    // Static variable outside a class or method is 

    
    // main() function automatically returns 0, other functions with return type must return.
}