#include<iostream> // use <> angular brackets when the direcory of the file is added to include paths.
// c++ std library header files do not have .h extensio, but on the other hand c header files does ex <stdio.h>
#include<string>
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
    enum LOG_LEVEL {
        LEVEL_ERROR, LEVEL_WARNING, LEVEL_INFO
    };

private :
    LOG_LEVEL m_logLevel = LEVEL_INFO; // default log level info
public :
    void setLogLevel(LOG_LEVEL logLevel) {
        m_logLevel = logLevel;
    }

    void error(const char* message) {
        if (m_logLevel >= LEVEL_ERROR) 
            cout<< "[ERROR]: "<<message<<endl;
    }
    void warn(const char* message) {
        if (m_logLevel >= LEVEL_WARNING) 
            cout<< "[WARNING]: "<<message<<endl;
    }

    void info(const char* message) {
        if (m_logLevel >= LEVEL_INFO)
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



// Enums in C++
// enum is just an integer which generally holds a value from a predefined set of values.
// enums can be used to store a set of values example = catagories, levels, states etc.
// the type of integer to be used to define enum can be given by having ": int_type"

enum state : unsigned int {
    safe, compromised, lockdown
};
// by default the "values" of enums start from 0 however, they can be explicitly set as well
// safe = 5, compromised, lockdown will be ( safe = 5, compromised = 6,lockdown = 7)
// enums are not namespace in themselves and do use enclosing namespace to use them
// check Log class implementation and use for better visualization.



// constructor in c++
// constructor is the function which is used to initialize an object (initialize the member variables of class),
// by default C++ creats a constructor like  "ClassName () {}" with no arguments.
// deleting a constructor to prevent it's use for example delete a default constuctor with no args
// we could make the default consructor with no args as privete as well but then also it can be called.
// delete shows intention and gives better error.
class Foo
{
   public:
       Foo() = delete; // C++ won't create a default constructor if a constructor with arguments is defined.
       Foo(int bar) : m_bar(bar) {};

// Destructors in c++
// destructors are used to destruct the objects created by the constructor of a class.
// destructors are used to de-allocate memory, close db connections, kill sub-processess etc.
// any memory allocated on the heap while initialization or use of the object must be freed in the 
// destructor to avoid memory leak
    ~Foo() {}
   private:
       int m_bar;
};


// Interface / abstract class with pure virtual function
// No object can be created from Printable direclty it is meant to be a base class.

class Printable {
public :
    virtual void printData() = 0;
    // Any child class inherting from Printable must override printData() function to be able to instantiate.
};

// oops in c++
class OOPS  : public Printable {
public :
    int data;

    OOPS() {}
    OOPS(int d ) : data(d){}
    OOPS(int d, int pd ) : data(d), privateData(pd){}


    virtual void printData() override {
        cout<<"data "<<data<<endl;
    }
private : 
    int privateData;
};

// Inheritance 
// by the property of inheritance the child class inherits all the public members of parent class.
// members declared public can be directly accessed and modified in the child class.
// 
class Inheritance : public OOPS {
public :
    int childData;
    Inheritance() {}
    Inheritance (int d) : OOPS(d) {
        printData();
        cout << "accessing data variable of parent calss " << data << endl;
        // access members declared private in base class does not work, below won't work
        // cout << "accessing data variable of private parent calss " << privateData << endl;
    }
};

// Polyimorphism in c++
// Polymorphism is the ability of objects to behave differently based on the actual underlying type.
// Polymorphism = many forms

// Compile time polymorphism 

// - Function overloading
//  Function overloading refers to having multiple functions of the same name but with different number of
//  arguments

// - Operator overloading
//  Operator overloading refers to the operators behaving differently based on the data types provided in args
//  example - 5 + 5 = 10, "Hello" + "World" = "Hello World"

// Run time over polymorphism
// - Method overriding 
//   When a child class has methods of same name and same arguments as the base class then it's called method
//   overriding, in this case the method being executed depends on the actual object whether base class or
//   child class object is used to call the method.

// - Virtual functions
//   Virtual functions are the functions marked with "virtual" keyword in the base class.
//   These functions enable the creation of vtable for the class objects and run time resolving of function calls
//   If a virtual function of base class is overridden in child class then which fuction is going to be called
//   will depend on the actual type of object pointed by the pointer instead of the pointer type, this is done
//   with the help of vtable, if there is even a single virtual function in a class then the vtable will be created.
//   The destructor must be marked as virtual if the class has any virtual functions this is to make sure 
//   that the destructor of the child class is called when using pointer of base class to point a child class obj.


// - Pure virtual functions (interface or abstract classes)
//   A method is called "pure virtual" if it has declaration like - "virtual void func_name() = 0"
//   Pure virtual functions need not be defined.
//   If a class has a pure virtual function then the class becomes abstract or interface class 
//   Interface classes can not be instantiated directly and any child class inheriting from interface classes must
//   override such pure virtual functions if not done then it also becomes an interface class and it 
//   can't be instantiated as well.
//   using pure virtual functions gurantees that any child object(instantiated) will have functions marked as 
//   pure virtual in the base class.
//   if child class has overridden the pure virtual function of base class then child of child may skip it.

// ** If a function is marked as virtual in the base class then it becomes virtual throughout inheritance
// hierarchy, even if in classess ( A -> B -> C), class B does not mark it virtual explicitly, it will still be
// virtual for class C and if the object of class C is used to call it then it will always call class C's variant
// of the function doesn't matter if it is pointed by pointer type of B, or A.

// ref - http://www.parashift.com/c++-faq-lite/virtual-dtors.html

// v_table and v_pointer 
//  - v_table
//
// - v_pointer
//  


class Polymorphism : public OOPS {
public :
    int polyData;
    Polymorphism() {}
    Polymorphism(int d) : polyData(d) {}
    // printData is still virtual even though not explicitly marked
    void printData() override {
        cout<<" Polimorphism class data - " << polyData << endl;
    }
};

class PolymorphismLayer2 : public Polymorphism {
public :
    int polyData;
    PolymorphismLayer2() {}
    PolymorphismLayer2(int d) : polyData(d) {}
    // printData is still virtual even though not explicitly marked
    void printData() override {
        cout<<" Polimorphism2 class data - " << polyData << endl;
    }
};


// visiblity in c++

// Private : 
// By default all the members of a class are private and can only be accessed by other member functions of the
// class inside the class.
// Private fuctions can not be accessed by the object like obj.privateFunction() outside the class.
// Private functions can not be accessed by the child classes as well.


// Pubilc :
// By dafault all the members of structs are public.
// public memebers can be accessed by child classes and directly from objects like obj.privateFunction() 
// Usually the functions which needs to be exposed to the usage of objects are declared public.

// Protected :
// Protected members of a class can be accessed by all the child classess directly however they can not be 
// directly from objects like obj.privateFunction() 

// visibility is a way to show the purpose of members if a memeber is marked as private it shows the idea 
// that the member should not be exposed out of the class.
// on the other hand the public shows that the member can be directly used and exposed.

// Friend classes 


class Visiblity {
public :
    int getAge() { return m_age;};
    int getCustomerID() {return m_customerID; }
    
    string m_name; // directly accessible from class objects as well as child classess.
protected : 
    int m_customerID; // accessible in this class and child classess only.
private :
    int m_age; // accessible in this class only.
};

// array in c++
// arrays are data types which stores data in continuos memory locations be it stack or heap allocated.
// when an array is heap allocated it's accessible untill manually deleted[] or program terminates.
// no way to know the size of an array therefore always maintain a size manually in the program.
// sizeof(array) / sizeof(type) can give the count but not always accurate and does not work for heap allocated
// arrays.

void arrays() {
    int stackArray[5]; // stack allocated
    int* heapArray = new int[5]; // heap allocated
    for (int i = 0; i < 5 ; i++) {
        stackArray[i] = 10;
        heapArray[i] = 10;
    }
    int* intPtr = stackArray;
    cout <<"stackArray index 2 - " << stackArray[2] << endl;
    cout <<"heapArray index 2 - " << heapArray[2] << endl;
    cout <<"stackArray index 2 with int pointer  - " << *(intPtr + 2) << endl;
}


// strings in c++ 
// a string is an array of characters.
// strings are immutible by default can not extend a string.
// default encoding is ascii for characters - 1 byte = 2^8 = 256 characters, other encoding to support more
// type of characters and other languages like utf 16 etc.
//***  "Hello" anything in double quotes is a const char array. 
void strings() {
    char* str = "Hello"; // c type string c++ has std::string, this is stack allocated but "Hello" is 
    // string literal, these are null terminated by default.
    // str[0] = 'J'; // string literals like "Hello" are stored in read-only memory, and direct modification
    // is not allowed, instead use something like char str[] = "Hello"; basically explicilty creating a char array.
    // manupulate c style string with strcpy(), strlen() etc.
    cout << " string Hello modified like array - "<< str <<" with size " <<endl ;

    // on the similar lines 
    char strArr[6] = {'H', 'e', 'l', 'l', 'o', 0}; // this is not null terminated by default need a 
    // '\0' or numeric 0 to null terminate it.
    cout << " string Hello stored in a char array - "<< strArr << endl ;
    
    //char * concat = "Hello" + "How are you?"; //(this does not work since both of these are const char arrays)

    // C++ style string 
    string  cppStr = "Hello";
    //string cppStr = "Hello" + "World"; // does not work since both are const char *.
    cppStr += "World"; // need to use this instead.
    bool contains = (cppStr.find("World") != string::npos); // string::npos is the end position for strings.
}

// String literal in c++
// using namespace std::string_literals;
// Any code that's in between 2 double quotes is a string literal ex - "Hi";
// String literals are stored in a constant part of data in the binary itself.
// String literals can not be modified therefore it's always a good idea to mark them const char*
// String literals are always stored in read only memory.
void stringLiteral() {
    const char* cStr = u8"Hello"; // 1 byte per char
    const wchar_t* wCstr = L"Hi"; // wchar_t is compiler decided it could take 2 byte or 4 bytes 
    const char16_t* cStr16 = u"Hello"; // 2 bytes per char
    const char32_t* cStr32 = U"Hello"; // 4 bytes per char
    
    //char* newStr = "Hello" + "World"; // it's not allowed as both are const char *.
    // however with string literal, below can be done.
    string newStr = "Hello"s + "World";
    

    //a raw string literal is a string in which the escape characters like ‘ \n, \t, or \” ‘ of C++ are 
    // not processed. Hence, a raw string literal that starts with R”( and ends in )”.
    //It ignores all the special characters like \n and \t and treats them like normal text.
    
    
}
int main() {
    
    variables();
    pointers();
    references();

    // class 
    Player p;

    // inheritance 
    Inheritance inh(99);

    Log logger;
    logger.setLogLevel(Log::LEVEL_WARNING);

    // Polymorphism
    // object type is Polymorphism but pointer is OOPS.
    OOPS* poly = new Polymorphism(100);
    poly->printData(); // 100 should print since printData is declared virtual in the base classes
    Polymorphism* poly2 = new PolymorphismLayer2(200);
    // printData of PolymorphismLayer2 will be called even if Polymorphism does not declare 
    // printData  virtul explicitly.
    // Virtualness of functions works in multiple levels so if you declare a function virtual in base class
    // it would be implicitly marked virtual in all child classes as well.
    poly2->printData();

    // arrays 
    arrays();

    // string 
    strings();





    // Static variable outside a class or function
    // Static variable outside a class or method is 

    
    // main() function automatically returns 0, other functions with return type must return.
}