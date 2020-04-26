#include <iostream>

#include <vector>
// Binary Search
// Expect a sorted sequence
// return a result in a LogN complexity

template <class T>
int binary_search_iterate(const std::vector<T> & sortedSequence, const T & value) {

    const int size = sortedSequence.size();
    int start_index = 0;
    int end_index = size-1;
    while(true) {
        int mid = (start_index + end_index) / 2;
        if(start_index == end_index) {
            return -1;
        }
        if (sortedSequence[mid] == value) {
            return mid;
        }
        if (sortedSequence[mid] > value) {
            end_index = mid;
        }
        if (sortedSequence[mid] < value) {
            start_index = mid + 1;
        }
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> arraylist_even{ 10, 20, 30, 40, 50, 60 };
    std::vector<int> arraylist_odd{ 10, 20, 30, 40, 50 };

    std::cout<<binary_search_iterate<int>(arraylist_even, 30)<<std::endl;
    std::cout<<binary_search_iterate<int>(arraylist_even, 10)<<std::endl;
    std::cout<<binary_search_iterate<int>(arraylist_odd, 50)<<std::endl;
    std::cout<<binary_search_iterate<int>(arraylist_odd, 30)<<std::endl;
    return 0;
}
