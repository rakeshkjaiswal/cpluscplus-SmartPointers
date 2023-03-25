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
        refCount = new int(1);
    }
    SharedPtr(const SharedPtr& ref) {
        ptr = ref.ptr;
        refCount = ref.refCount;
        (*refCount)++;
    }
    SharedPtr& operator=(SharedPtr& ref) {
        if (*this == ref)
            return *this;
        if (refCount != nullptr) {
            (*refCount)--;
            if (*refCount == 0) {
                delete ptr;
                delete refCount;
            }
        }
        ptr = ref.ptr;
        refCount = ref.refCount;
        (*refCount)++;
    }
    ~SharedPtr() {
        cout << "\n~SharedPtr() is called:";
        if (refCount != nullptr) {
            (*refCount)--;
            cout << "\nrefCount:" << *refCount;
            if (*refCount == 0) {
                cout << "\n~SharedPtr() refCount is zero";
                delete ptr;
                delete refCount;
            }
        }
    }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};
int main()
{
    std::cout << "Hello World!\n";

    SharedPtr<char> mySPtr;
    char* name = new char[2];
    cin >> name;
    string myname("Rakesh");
    
    cout << "\nsizeof name:" << sizeof(name)<<" and "<<strlen(name)<<" myname:"<<myname.length();
    
    if (name != nullptr)
        cout << "\nEntered name is " << name;
    {
        SharedPtr<char> mySPtr1(name);
        {
            SharedPtr<char> mySPtr2(mySPtr1);
            cout <<*mySPtr2;
        }
    }
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
