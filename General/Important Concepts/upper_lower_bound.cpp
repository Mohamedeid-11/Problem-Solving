#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[5] = {1, 5, 6, 7, 8};
    cout << "lower bound for element 5: " << *lower_bound(arr, arr + 5, 5) << endl;
    cout << "lower bound for element 3: " << *lower_bound(arr, arr + 5, 3) << endl;
    cout << "upper bound for element 5: " << *upper_bound(arr, arr + 5, 5) << endl;

    cout << "lower bound for element 5 is at index: " << lower_bound(arr, arr + 5, 5) - arr << endl;
    cout << "lower bound for element 3 is at index: " << lower_bound(arr, arr + 5, 3) - arr << endl;
    cout << "upper bound for element 5 is at index: " << upper_bound(arr, arr + 5, 5) - arr << endl;

    cout << "upper bound for element 10 is at index: " << upper_bound(arr, arr + 5, 10) - arr << endl; // Not Found

    return 0;
}

/*
The lower_bound(k)
is a built - in function in C++ which returns an iterator or a pointer pointing to the key in the container which is greater than or equal to k passed in the parameter.

The upper_bound(k)
is a built - in function in C++ which returns an iterator or a pointer pointing to the key in the container which is greater than k passed in the parameter.

    Be careful,
the lower and upper bound functions must search in a sorted container because they do the same work as the binary search

    In case of using it with the arrays,
    it returns pointer.

    In case of using it with the STLs,
    it returns iterator.

    They are found in algorithm library.

#include <algorithm>
    Since the lower and upper bound does the same work as the binary search then their time complexity is
    O(LogN)
        where N
    is the size of the container.

    The function input differs according to the container used.

    Lower and upper bound in arrays:

lower_bound(arr_name, arr_name+array_size, value you want to search for it)

upper_bound(arr_name, arr_name+array_size, value you want to search for it)

It returns a pointer
 to the place of the value and if no suitable value was found,
 the pointer will point to a place that is after the last element in the array.

To get the index of the found value, you just subtract the beginning
 pointer
 which is arr_name from returned pointer and this will give you a number from 0
 to array_size-1 which is the index of the value and if the value was the array
 size
 then that means that the value wasn′t
 found
*/
