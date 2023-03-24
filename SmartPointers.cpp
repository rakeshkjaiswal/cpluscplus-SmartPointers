// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<class T> class SharedPtr{
    T* ptr;
    int* refCount;
public:
    SharedPtr():ptr(nullptr), refCount(nullptr) {}
    SharedPtr(T* p) {
        ptr = p;
        refCount = new int;
        *refCount = 1;
    }
    SharedPtr(SharedPtr& ref) {
        ptr = ref.ptr;
        *(ref.refCount)++;
        refCount = ref.refCount;
    }
    SharedPtr& operator=(SharedPtr& ref) {
        if (*this == ref)
            return *this;

        (*refCount)--;
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
        }
        ptr = ref.ptr;
        refCount = ref.refCount;
        (*refCount)++;
    }
    ~SharedPtr() {
        (*refCount)--;
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
        }
    }
};
int main()
{
    std::cout << "Hello World!\n";

    SharedPtr<char> mySPtr;
    char* name = new char;
    cin >> name;
    string myname("Rakesh");
    
    cout << "\nsizeof name:" << sizeof(name)<<" and "<<strlen(name)<<" myname:"<<myname.length();
    
    if (name != nullptr)
        cout << "\nEntered name is " << name;
    {
        //SharedPtr<char> mySPtr1(name);
    }
    if (name != nullptr)
        cout << "\nEntered name is " << name;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
