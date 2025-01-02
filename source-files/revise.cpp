#include<iostream> // use <> angular brackets when the direcory of the file is added to include paths.
// c++ std library header files do not have .h extensio, but on the other hand c header files does ex <stdio.h>
#include<string>
#include<memory>
#include<vector>
#include<tuple>
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
} struct_variable; // this way a variable "struct_variable" will also be declared along witht the struct type

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

// A variable declared static inside a function also lives till the program is terminated.
// however it can only be accessed inside that function only and can't be accessed from outside the function.
// The static variable inside a function is shared for all function runs.
void function_f() {
    static int  function_f_calls= 0; // this will execute only once.
    function_f_calls++;
    cout <<" function_f is called "<< function_f_calls << " times"<<endl;
}

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
    string newStr = "Hello"s + "World"; // '""s' is an operator in string literal which returns a string from 
    //  string literal.
    
    // String literals are stored in a constant part of data in the binary itself.
    // String literals can not be modified therefore it's always a good idea to mark them const char*
    const char* literalStr = "Hello world";
    // char* literalStr = "Hello World";
    // literalStr[0] = 'J';  // this will not work and result in errors.

    char literalStrArr[12] = "Hello World";
    literalStrArr[0] = 'J';// allowed! but the actual string stored in read only data segment does not change 
    // instead a copy is made in literalStrArr and that's modified


    // Raw strings
    // a raw string literal is a string in which the escape characters like ‘ \n, \t, or \” ‘ of C++ are 
    // not processed. Hence, a raw string literal that starts with R”( and ends in )”.
    // It ignores all the special characters like \n and \t and treats them like normal text.
    const char* rawString = R"(Hello \n \0 World)"; // R"()" operator enables using literal meaning of 
    // escape characters basically you can write text inside it without worrying about any special escape
    // charater like \n \t \0 etc.
    cout<<"Raw string  - "<< rawString<<endl;
}


// const in c++
// const is a promise that we will not change the value, this is better for readibility, shows purpose 
// and also enforeces the idea of not changing a varible for any reasons.
void constInCpp() {
    const int maxValue = 99; 

    int * intVal = new int(5);
    *intVal = 10; // changing the content pointer by the pointer.

    cout << " Int value : " << *intVal << endl;

    int* intVal2 = new int(15);

    cout << " Int value2 : " << *intVal2 << endl;

    intVal = intVal2; // changing the memory address pointed by the pointer

    const int* intVal3 = new int(20); // Making the value pointed by the pointer a const. POINTER TO A CONST INT
    int* const intVal4 = new int(25); // Making the pointer itself const. CONST POINTER TO AN INT
    intVal3 = intVal4;
    // *intVal3 = 30;  // does not work since the pointer is to a const int.
    // intVal4 = intVal3; // does not work since it's a constant pointer to int.
    *intVal4 = 30;
    const int* const intVal5 = new int(50); // CONSTANT POINTER TO A CONSTANT INT, no modification will work.
}
// const in classes 
class ConstInClass {
public :
    int m_age;
    mutable int m_houseNo; // mutable keyword in c++ 
    int getAge() const { // const in a function declaration/definition after parenthesis means the method must not modify any class members
        // age+=5; // this will not work since method is marked with const.
        return m_age;
    }
    int getHouseNo() const {
        m_houseNo += 1; // even though the method is marked as const the m_houseNo can be modified since it is declared as mutable.
        return m_houseNo; // mutable variables can be modified in functions which guarentee constness.
    }
    
};
// ** a const object of a class can only access methods which are declared as const, it can't call the methoda which do not guarantee constness.
// therefore always mark methods which are not modifying any value as const.


// initializer list in c++
// Initilzer lists are used to initilize class memebers before constructor body gets executed.
// non static const members needs to be initialized in he initiliizer list only not in the constructor body
// if members are not initilized in the initializer list then anyway these variables are created with their default constructor
// and then in the constructor body they are assigned with "=" operator to the actual objects. (PERFORMANCE REASON)
// *** The parameterized constructor of a base class can only be called from the initializer lists before entering constructor body.
class InitHelper{
    int m_x;
    int m_y;
public:
    InitHelper(int x, int y) : m_x(x), m_y(y) {
        cout<<" Creating InitHelper" <<endl;
    }
};

class InitList{
public :
    const int m_x;
    InitHelper m_ih;
    int & m_xRef;
    // all the variables are initilized with their default values before going into the compiler body
    // and then late.
    InitList(int x, InitHelper& ih) : m_x (x), m_ih(ih) , m_xRef(x) {
        // int m_x = x; // const members needs to be initialized int he initiliizer list only not in the constructor body.
        // m_ih = ih; // since InitHelper does not have a default constructor then it must be initialized in the initilizer list.
        // reference members also needs to be initilized in the initializer lists.
    }
};


// New keyword in c++
// The "new" keyword (operator) is used to allocate memory for the supplied type on the heap.
// The memory allocated by new keyword must be freed by calling "delete" object name.
// new returns a pointer to the object after creating it on the heap.
// The lifetime of objects allocated by new keywords is the lifetime of the program unless explicitly freed by calling delete.
// Allocating memory on heap by using new takes more time then allocating on stack.
// usually calling new calls underlying c malloc(sizeof(class type))
// If new is used with arrays like new int[10] then delete also needs to be called in a similar manner "delete []"
void newInCpp() {
    int * intA = new int();
    int * arrayInt = new int[10];

    delete intA;
    delete [] arrayInt;
}

// implicit and explicit conversions in c++

// explicit keyword in c++
// explicit keyword in front of a constructor disables the ability of the class object to implicitly convert the type mentioned in the
// single argumented constructor to the class type.

class Conversions {
public : 
    explicit Conversions(int id) : m_id (id) {}
    Conversions(string username) : m_username(username) {}
private:
    int m_id;
    string m_username;
};

void conversionsInCpp() {
    // Conversions c1 = 10; // code does not work since the constructor which takes int as argument is marked explicit and needs to 
    // be called explicitly.
    Conversions c2 = string("jraghuwa"); // implicit conversion from string to Conversions since there exist a constructor in conversions
    // which takes string as an argument.
}

// Operator overloading in c++
// Operators can be overloaded just like normal functions. 

class OperatorOverloading{ 
public :
    OperatorOverloading( int x, int y) : m_x(x), m_y(y) {}
    void print() {
        cout<<" X : " << m_x << "Y : "<< m_y<<endl;
    }
    OperatorOverloading add (const OperatorOverloading& other) { // this can direclty be done in operator += however this is more readable.
        this->m_x += other.m_x;
        this->m_y += other.m_y;
        return *this;
    }
    OperatorOverloading operator += (const OperatorOverloading& other) { // the "+=" operator is being overloaded to add x and y variables.
        return add(other); // operators are like methods only just the actual operator is preceeded by "operator" in the signature.
    }
    friend ostream& operator<< (ostream& cout, OperatorOverloading& ool); // declaring friend so that it can access private members.
private :
    int m_x;
    int m_y;

};

// overloading the "<<" operator to support OperatorOverloading class
// doing it outside because it's not part of OperatorOverloading class but instead it's part of 
// ostream class.
ostream& operator<< (ostream& cout_, OperatorOverloading& ool) {
    cout_ << "X value : " << ool.m_x << " Y value : " << ool.m_y;
    return cout_;
}

void operatorOverloadingInCpp() {
    OperatorOverloading a(1,1);
    OperatorOverloading b(1,1);
    a.print();
    b.print();
    a += b;
    a.print();
    cout << a << " " << b << endl;
}

// this keyword in c++
// it's only accessible inside a class method.
// the "this" keyword refers to the self object for which the method is called.
// 

class ThisKeyword{
public :
    ThisKeyword(){};
    int getX() { return this->x;}
    ThisKeyword add (const ThisKeyword & other) {
        this->x + other.x; // this is being used to access the data members of current class.
        return *this;
    }
private :
    int x ;
};


// Smart pointers in c++

// Smart pointers in c++ are tools to prevent bugs related to memory leaks and provides automatic deallocation of objects allocated on the
// heap storage.
// Smart pointers should be used everywhere they can be used in modern c++
// Smart pointers are scope based pointers and they destruct the underlying object (object pointed to) when they go out of scope.
// They are available in <memory> class.

class SmartPointers{
public :
    SmartPointers() {
        cout<< "CREATING object for smart pointer demonstration"<<endl;
    }
    ~SmartPointers() {
        cout<< "DELETING object for smart pointer demonstration"<<endl;
    }

};

void smartPointers() {

    // unique pointers -
    // unique pointers can not be copied and "=" operator is deleted for unique pointers.
    // 
    {
        unique_ptr<SmartPointers> p_log = make_unique<SmartPointers>(); // Preffered way of making unique pointers, make_unique handles exceptions generated
        {
            // by the Log constructor if any, make_unique returns a unique pointer
            // unique_ptr<Log> p_log2 = new Log(); // does not work since the 
            unique_ptr<SmartPointers> p_log3(new SmartPointers()); // In case Log class had private constructor better to use this, however 
        }
    }
    // both p_log and p_log2 wil get out of scope and SmartPointers objects will get deleted.

    // Shared pointers -
    // Shared pointers are similar to unique pointers in the sense that they delete the objected pointer by them
    // when they go out of scope.
    // Shared pointers can be copied and copying a shared pointer increases their reference count by 1.
    // The object pointed by shared pointers is destroyed when all the shared pointers pointing to that object
    // gets out of scope ie reference count becomes 0.

    // https://stackoverflow.com/questions/20895648/difference-in-make-shared-and-normal-shared-ptr-in-c
    // https://www.reddit.com/r/cpp_questions/comments/q647ms/how_to_copy_and_reference_a_shared_ptr/
    
    
    {
        shared_ptr<SmartPointers> sp_log; 
        {
            shared_ptr<SmartPointers> sp_log2 = make_shared<SmartPointers>(); // Preffered way of making shared pointers.
            // Make_shared handles exceptions generated
            // Allocates memory only once for object initialized and control block of shared pointer
            // Which stores the reference count etc.

            // Shared_ptr<SmartPointers> sp_log2(new SmartPointers()) // another way.
            // This way does not handle exceptions in object constructor and memory allocation.
            // also does 2 allocations 1. for the object 2. for the control block of shared ptr.
            // This is slightly slower than using make_shared.
            sp_log = sp_log2;
            cout << " Reference count of shared pointer = "<< sp_log2.use_count()<<endl;
            shared_ptr<SmartPointers> sp_log3(sp_log);
            cout << " Reference count of shared pointer = "<< sp_log2.use_count()<<endl;
        }
        cout << " Reference count of shared pointer = "<< sp_log.use_count()<<endl;

        // Weak pointers - 
        // A weak pointer is similar to shared pointer with 1 key difference it does not increase the 
        // ref count of a shared pointer.
        // Weak pointer can be used when we don't want the pointer to affect the object lifespan.
        // weak pointer has a function "expired()" to check if the underlying objec is alive or not.
        // also to use a share pointer "lock()" is needed which returns a shared pointer object if the weak
        // pointer is not expired.

        // Since there there's only one allocation, the pointee's memory cannot be deallocated until the 
        // control block is no longer in use. A weak_ptr can keep the control block alive indefinitely to
        // determine whether the shared pointer is alive or not.

        weak_ptr<SmartPointers> wp_log = sp_log;
        cout << " Reference count of shared pointer after weak pointer assignment = "<< sp_log.use_count()<<endl;
    } // the SmartPointers object will get deleted once the control exits this scope.
}


// copying and copy constructor in c++
// C++ provides a default shallow copy constructor and assignment operator.
// the shalow copy constructor and assignment operator works fine if non of the members are pointers
// and they do not require explicit memory allocation.

// However if the class has pointers then the shallow copy only copies the
// memory address of the pointers ie it only copies the pointers and not the object pointed by pointer.

// Therefore an explicit copy constructor and assignment operator is required with explicit memory allocations 
// if the class has pointers.
class CopyHelper{
public :
    CopyHelper(int d) : m_data(d) {}
    int m_data;
};

class Copy {
public:
    Copy(int a) : m_a(a), m_ch(new CopyHelper(a)) {};
    // explicit copy constructor doing a deep copy of the m_ch pointer.
    Copy(const Copy& other) {
        this->m_a = other.m_a;
        m_ch = new CopyHelper(*other.m_ch);
    }
    int getData () {
        return m_ch->m_data;
    }
    void modifyData (int newData) {
        m_ch->m_data = newData;
    }

private:
    int m_a;
    CopyHelper* m_ch;
};

void copyInCpp() {
    Copy obj(10);
    Copy objCopy = obj; 
    // by default shallow copy will happen and the m_ch of both the objects will point to the 
    // same memory location, try commenting out the copy constructor to recreate it.
    cout << " obj data - " << obj.getData()<< " objCopy Data - "<< objCopy.getData() <<endl;
    obj.modifyData(5); // modifying data in m_ch of 1 object will change other object as well.
    cout << " Modified the obj data to 5 "<<endl;
    cout << " obj data - " << obj.getData()<< " objCopy Data - "<< objCopy.getData() <<endl;
}

// arrow -> operator in c++
// -> operator is used to dereference a pointer and then access members of that class.
// -> can be overloaded to return a pointer type.
class Arrow {
public :
    void printArrow() {
        cout <<"Printing Arrow" << endl;
    }
};

// ScopedPtr implementation like unique_ptr but only for Arrow class.
class ScopedPtr {
public :
    ScopedPtr(Arrow* a) : m_arrow(a) {}
    ~ScopedPtr() {
        delete m_arrow;
    }
    Arrow* getArrow() {
        return m_arrow;
    }
    Arrow* operator ->() { // -> must return a pointer type
        return getArrow();
    }
    
private :
    Arrow* m_arrow;
};


void arrowInCpp() {
    ScopedPtr sp_arrow(new Arrow());
    // how to access the Arrow object from scoped pointer?
    // we can write a function which returns the Arrow object or pointer.
    sp_arrow.getArrow()->printArrow();
    // or overload the "->" operator to return the m_arrow POINTER. ( it needs to return pointer and not
    // the dereferenced object)
    sp_arrow->printArrow();
}



// Vectors in c++
// vectors are dynamic arrays which resize themselves if their capacity is exaushted.
// when resizing a new vector of bigger size is created and all the elements of the old vector are copied to it.
// this happens everytime the capacity is exhauted theirfore it takes a toll on performance.
// vectors do need a valid deep copy "copy constructor" might result in errors if used with classes with pointers
// but no copy constructors.

class VectorDemo{
public :
    VectorDemo(int a, int b ) : m_a(a), m_b(b) {}
    // copy constructor
    VectorDemo(const VectorDemo& other) : m_a(other.m_a), m_b(other.m_b) {
        cout<< "VectorDemo is Copied"<<endl;    
    }
    int m_a, m_b;
};

void vectorInCpp() {
    vector<VectorDemo> vec; //  vec(3) will not work since it creates 3 objects with default constructor
    // but in VectorDemo default constructor is absent.
    vec.reserve(3); // This will reserver space in the vector for 3 VectorDemo instances.
    vec.push_back(VectorDemo(1,2)); // first the VectorDemo object will be created here in main then copied to
    // the actualy memory allocated to the vector-  copy constructor will be called.
    vec.push_back({3,4}); // similar to above line will first create obj here then copy to vector ie copy
    // constructor will be called.
    vec.emplace_back(5,6); // VectorDemo object will directly be created on the memory allocated to the vector.
    // these arguments are called variadic arguments and they are forwarded to the constructor of VectorDemo 
    // class by emplace_back and then the object is created in the vector itself, emplace is sort of in-place
    for (auto& vd : vec) {
        cout << " a value : "<<vd.m_a << " b value : "<<vd.m_b<<endl;
    }
}


// tuples in c++
// tuples are  introduced in c++ 11
// tuples are fixed sized collection of hetrogeneous values it's an extension of what std::pair does.
// a tuple can have data of different types.
// tuple is in <tuple> class.
void tuplesInCpp() {
    // declaring tuple
    tuple<int, int, string> t1;
    // declaring and initializing a tuple 
    tuple<int, int, float> t2(1, 1, 1.0f);
    // another way to initialize a tuple.
    t1 = make_tuple(1, 2, "Hi");
    // another way to initialize a tuple.
    tuple<int ,int> t3 = {3, 3};

    // Reading data from a tuple.

    // using get() method from <tuple.
    int a, b; // declare variables to store data which will be read from tuple.
    string c;
    a = get<0>(t1);
    b = get<1>(t1);
    c = get<2>(t1);
    cout << "Data read from tuple - "<< a << " "<< b <<" "<< c << endl;

    // another way to read data from tuple is by using tie() function which reads data from a tuple
    // and stores it in varibles which it takes as arguments.
    int d ,e;
    float f;
    tie(d, e, f) = t2;

    cout << "Data read from tuple - "<< d << " "<< e <<" "<< f << endl;

    tuple<int,int> t4(4, 5);
    tuple<int,int> t5(6, 7);
    cout << "Data read from tuple - "<< get<0>(t4) << " "<< get<1>(t4) << endl;
    cout << "Data read from tuple - "<< get<0>(t5) << " "<< get<1>(t5) << endl;
    // swapping the values of 2 tuples
    cout<<" Swapping 2 tuples " <<endl;
    t4.swap(t5);
    cout << "Data read from tuple - "<< get<0>(t4) << " "<< get<1>(t4) << endl;
    cout << "Data read from tuple - "<< get<0>(t5) << " "<< get<1>(t5) << endl;

    // concatnating 2 tuples by using tuple_cat(), it returns a third tuple with new type 
    tuple <int, int, int, int> t6 = tuple_cat(t4, t5);

}



// how to deal with multiple return values in c++
// there are a few ways to deal with return values from a function which includes using containers like
// vector ( if all the return variables are of same type) ,pair if there are 2 varible (could be of diff type)
// or passing varibles by reference and setting them in called function.
// or defining struct and using those to return variables

// Passing varibles by reference 
void multipleReturnValuesHelperPassByRef( int &a, string &b) {
    a = 10;
    b = "Hello";
}

// returning a pair LIMITED to 2 values.
pair<int, string> multipleReturnValuesHelperByUsingPair() {
    return make_pair(10, "Hello");
}

// declaring a new struct and using it to return values.
struct IntString {
    int a;
    string b;
    float c;
};

IntString multipleReturnValuesHelperUsingStruct() {
    return {10, "Hello", 1.0f}; // implicit conversion and assignment.
}

// by using tuples c++ 11+
tuple <int, string, float> multipleReturnValuesHelperUsingTuple() {
    return {10, "Hello", 1.0f}; // implicit conversion to a typle
}
void multipleReturnValues() {

    // pass by reference 
    int a ;
    string b;
    multipleReturnValuesHelperPassByRef(a, b);
    cout << "Value of A -" <<a<< " Value of B - "<< b<<endl;
    // using pair
    auto p = multipleReturnValuesHelperByUsingPair();
    cout << "Value of A -" <<p.first<< " Value of B - "<< p.second<<endl;
    //using helper struct 
    IntString is = multipleReturnValuesHelperUsingStruct();
    cout << "Value of A -" <<is.a<< " Value of B - "<< is.b<< " Value of C - "<< is.c<<endl;
    // using tuple.
    tuple <int, string, float> t = multipleReturnValuesHelperUsingTuple();
    cout << "Value of A -" <<get<0>(t)<< " Value of B - "<<get<1>(t)<< " Value of C - "<< get<2>(t)<<endl;
    // ** Prefered way should be : 1. pass by reference (if no of args <= 2) 
    // 2. Using custom struct ( if the struct can be reused in code )
    // 3. tuple - a tuple can also be used to return multiple values.
}

// structured bindings in c++ 
// structured bindings is a way to unpack multiple variables at once.
// taking above multiple return values fuction for example 

void structuredBindingsInCpp() {
    // while using structured bindings the no of variables should be same as the unpacking container.
    cout<<"Structured bindings " <<endl;
    //using structured bindings to unpack a structure 
    auto [a, b, c] = multipleReturnValuesHelperUsingStruct();
    cout << "Value of A -" <<a<< " Value of B - "<< b<< " Value of B - "<<c<<endl;

    // using structured bindings to unpack a tuple.
    auto [ d, e, f] = multipleReturnValuesHelperUsingTuple();
    cout << "Value of D -" <<d<< " Value of E - "<< e<< " Value of F - "<<f<<endl;
    
    pair <int, string> p{5, "FUCK"};
    auto [ g, h ] = p;
    cout<< "Value of G - "<< g<< " Value of H - "<<h<<endl;
}


// templates in c++ 
// templates in c++ are a way to create generic class definitions for differnt types.
// templated classes or functions are only created by the compiler for a spcific type if they are used
// any errors in the templated functions/classes are only caught during compilation if these are used
// somewhere in code.
// templates are very powerful tool to create generic code
// template are blueprints for functions and classes
// STL is created with the use of templates
template<typename T>
T add(T first , T second) {
    return first + second;
}

template<typename T>
void print(T a) {
    cout<< "Printing from templated function - " << a << endl; // This will work only if the cout 
    // function is overloaded for T type.
}

template<typename T>
void syntaxError(T a) {
    //ccccouttt << a << endl; // clearly a syntax error, but some compiler won't notify it since it's not used
    // clang does raise an error though
}


// dynamic (run time size allocation) is not supported 
class Array {
private :
    int m_size;
    // int  m_array[m_size]; // ERROR fields must have a constant size: 'variable length array in structure' 
    // extension will never be supported
    // defined an array variable with size that is not compile time constant.
public :
    int getSize() const {
        return m_size;
    }
};

// template<typename T1, class T2> // instead of typename class can also be used.

template<int size, typename T> 
class ArrayFixed {
private :
    T m_array[size];
public :
    int getSize() const {
        return size;
    }
};

void templates() {
    // using add for strings
    int a = 10, b = 5;
    cout <<" Templated add fuction for integers - " <<add <int>(a, b) << endl;
    string c = "Hi,";
    string d = " How are you ?";
    cout <<" Templated add fuction for strings - " <<add <string>(c, d) << endl;
    print(a); // we don't always need to give the type in angular braces.
    print<string>("Hello");
    print(5.5f);

    // int n = 10; int array[n]; // it's not allowed at compile time since the value of n can change.
    // array of fixed size at compile time
    ArrayFixed <5, int> arrayOf5;
    cout << "the size of the fixed array is -  "<< arrayOf5.getSize()<<endl;
}


// stack and heap memory allocation in c++
// https://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap
// Stack allocatoion - 
// In stack allocation the memory is allocated in the way a stack works, there's a stack with a top
// pointer and whenever a piece of memory of size N is required the stack grows by size N and then returns the
// new top of the stack, then the program can use this allocated memory.

// Stack allocation is much faster it has very less (possibly 1) cpu instructions just to grow the stack 
// and in case of freeing up the memory also it's fast the stack is shrunk by the size of deleted element.
// the parameters passed to functions and local variables are also stored on the stack memory and

// When the function returns are the stack also shrinks.
// Very large objects must not be allocated on the stack.
// Implemented with an actual stack data structure.

// Heap memory allocation - 
// Heap memory allocation is much slower than compared to stack allocation memory, due to the bookkeeping
// involved.

// In C++ when something is allocated on heap memory by using the "new" keyword it must be freed explicitly 
// by the user with "delete" keyword when it's not needed anymore else the memory will be leaked and
// won't be available for use till the program terminates.

// Heap memory allocation involves finding the size of memory required to be allocated and if not available ask
// the OS for the memory which is much slower, then keep track of the allocated memory.
//
void stackAndHeapAllocation() {

    int a = 10; // stack allocation.
    int *b = new int(5); // heap allocation.
    
}


// macros in c++
// Macros in cpp are basically replacing text (code statements, text substitution) in code in the pre-processing phase.
// The pre-processor changes the actual code before it goes to the compiler and it replaces the text (macros)
// with the actual values of the macros.

// Macro has scope of current compilation unit, and if it's included in header file then it will be defined 
// in call cpp files where that header file is included.

// Macros must be used carefully as to not write confusing code
#define open_curly_bracket {
#define clode_curly_bracker }

void macros() {
    if (true) open_curly_bracket
        cout << "Terrible example of writing macros" << endl;
        cout << "Never write code like this "<< endl;
    clode_curly_bracker
    // macros can have arguments as well which makes them function like
    #define LOG(x) cout << "Logged from a macro " << x << endl;
    LOG("hello");
    // macro which takes 2 arguments.
    #define ADD(a, b) a + b
    cout <<"Adding 2 numbers from macro " << ADD(10, 10) << endl;

    // Multiline macros
    // a macro can expand to multiple lines with "\<enter>" the last character must be "\"
    // immediately followed by an enter ( there must not be a space after \)
    // "\" works like escape character for the next character, it can be used to escape spaces as well.
    #define RECTANGLE_STARS(l, b, pattern)\
    {\
        for (int i = 0; i < l; i++) {\
            for (int j = 0; j < b; j++) {\
                cout<<pattern;\
            }\
            cout<<endl;\
    }\
    }\

    cout<< "Printing retangle with \"*\" for 4 by 20 "<<endl;
    RECTANGLE_STARS(4, 20, '*');

    // macros to macros nested macros.
    #define ADD_INTEGERS(a, b) ADD(a, b)
    cout <<"Adding 2 Integers from nested macro " << ADD_INTEGERS(20, 10) << endl; 
 }


int main() {
    
    variables();
    pointers();
    references();

    // class in c++;
    Player p;

    // structs in c++
    PlayerStruct ps { 10, 9, 8}; // struct memebers can be initialized with curly braces, 
    // it;s the optimal syntax, also see there's no 3 parameter constructor in PlayerStruct still the 
    // initialization works.
    PlayerStruct ps1 = {7, 6 , 5}; // this also works fine;
    PlayerStruct ps2 = {4, 3 ,2}; // this also works
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

    // string literal
    stringLiteral();

    // const in c++
    constInCpp();

    // initializer list in c++
    InitHelper ih(5, 5);
    InitList il(5, ih);


    // operator overloading 
    operatorOverloadingInCpp();

    // smart pointers in c++
    smartPointers();

    // copy constructor in c++
    copyInCpp();

    // -> in c++ arrow in c++
    arrowInCpp();

    // vectors in c++
    vectorInCpp();

    // Static variable in a function;
    function_f();
    function_f();

    // tuples in c++
    tuplesInCpp();

    // how to deal with multiple return values in c++
    multipleReturnValues();

    // structured bindings in c++
    structuredBindingsInCpp();

    // templated in c++
    templates();

    // stack and heap memory allocation in c++
    stackAndHeapAllocation();

    // macros in c++
    macros();
    
    // main() function automatically returns 0, other functions with return type must return.
}