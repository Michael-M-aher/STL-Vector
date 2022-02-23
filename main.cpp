#include "CustomVector.cpp"
#include <iostream>

using namespace std;

int main()
{
    /* this is the variable that will store the array, you can have
     * a vector of any type!
     */
    CustomVector<int> v;

    /* add some elements to the back */
    v.Push_back(3);
    v.Push_back(2);
    v.Push_back(1);

    CustomVector<int> v2(v);
    CustomVector<double> v3(5);
    CustomVector<string> v4;

    cout << "Integer Vector: ";

    /* print the vector */
    v.print();

    try {

        /* return the element at the specified index */
        cout << v.at(4) << endl;

    } catch(const char* str) {
        cout << str << endl;
    }

    /* remove an element from the back */
    v.Pop_back();

    cout << "After removing last element: ";
    v.print();

    /* add an element to the specified index */
    v.Insert(1, 12);

    cout << "After insertion: ";
    v.print();

    /* remove an element by specifying its index */
    v.Erase(1);

    cout << "After erase: ";
    v.print();

    /* resizes the vector */
    v.Resize(6);

    cout << "After resize: ";
    v.print();

    /* returns if the specified index is valid or not */
    if (v.valid_position(5))
        cout << "valid position" << endl;

    /* clear the vector */
    v.Clear();

    /* returns if the vector is empty or not */
    if (v.Empty())
        cout << "vector is empty" << endl;
    v = v2;

    /* return the index of the specified element */
    cout << "Element found at: " << v.Find(2) << endl;

    v3.Push_back(1.3);
    v3.Push_back(2.5);
    cout << "Double Vector: ";
    v3.print();

    v4.Push_back("first");
    v4.Push_back("second");
    cout << "String Vector: ";
    v4.print();

    return 0;
}