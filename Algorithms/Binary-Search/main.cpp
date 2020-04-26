#include <iostream>

#include <vector>
// Binary Search
// Expect a sorted sequence
// return a result in a LogN complexity

#define CHECK(a,b) (a==b ? "Pass" : "Fail")


template <class T>
int binary_search_iterate(const std::vector<T> & sortedSequence, const T & value) {

    const int size = sortedSequence.size();
    int start_index = 0;
    int end_index = size-1;
    while(true) {
        const int mid = (start_index + end_index) / 2;
        if(start_index > end_index) {
            return -1;
        }
        if (sortedSequence[mid] == value) {
            return mid;
        }
        else if (sortedSequence[mid] > value) {
            end_index = mid - 1;
        }
        else  {
            start_index = mid + 1;
        }
    }
}


template <class T>
int binary_search_recursive(const std::vector<T> & sortedSequence, const T & value, int start_index, int end_index)  {

    if (start_index > end_index) {
        return -1;
    }

    const int mid = (start_index + end_index) / 2;

    if (sortedSequence[mid] == value) {
        return mid;
    }
    else if (sortedSequence[mid] > value) {
        return binary_search_recursive<T>(sortedSequence, value, start_index, mid - 1);
    }
    else {
        return binary_search_recursive<T>(sortedSequence, value, mid + 1, end_index);
    }

}
int main() {
    std::vector<int> arraylist_even{ 10, 20, 30, 40, 50, 60 };
    std::vector<int> arraylist_odd{ 10, 20, 30, 40, 50 };

    std::cout<< CHECK(binary_search_iterate<int>(arraylist_even, 30), 2) << std::endl;
    std::cout<< CHECK(binary_search_iterate<int>(arraylist_even, 10) , 0) <<std::endl;
    std::cout<< CHECK(binary_search_iterate<int>(arraylist_odd, 50) , 4 ) <<std::endl;
    std::cout<< CHECK(binary_search_iterate<int>(arraylist_odd, 30), 2) <<std::endl;
    std::cout<< CHECK(binary_search_iterate<int>(arraylist_odd, -100), -1) <<std::endl;

    std::cout<< CHECK(binary_search_iterate<int>(arraylist_even, 100), -1) <<std::endl;
    std::cout<< CHECK(binary_search_iterate<int>(arraylist_even, 35), -1) <<std::endl;
    std::cout<< CHECK(binary_search_iterate<int>(arraylist_odd, 200), -1) <<std::endl;
    std::cout<< CHECK(binary_search_iterate<int>(arraylist_odd, 35), -1) <<std::endl;

    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, 30, 0, arraylist_even.size() -1), 2) << std::endl;
    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, 10, 0, arraylist_even.size() -1), 0) << std::endl;
    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, 50, 0, arraylist_even.size() -1), 4) << std::endl;
    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, 30, 0, arraylist_even.size() -1), 2) << std::endl;
    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, -100, 0, arraylist_even.size() -1), -1) << std::endl;

    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, 100, 0, arraylist_even.size() -1), -1) << std::endl;
    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, 35, 0, arraylist_even.size() -1), -1) << std::endl;
    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, 200, 0, arraylist_even.size() -1), -1) << std::endl;
    std::cout<< CHECK(binary_search_recursive<int>(arraylist_even, 35, 0, arraylist_even.size() -1), -1) << std::endl;

    return 0;
}
