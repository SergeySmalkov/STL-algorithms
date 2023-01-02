#include <iostream>
#include <vector>
#include <deque>

int main() {
    //Oveloaded sort, but works
    int test[] = {5,10,15,20,25};
    std::sort (test,test + std::size(test));

    //Random access iterator is required - deque, vector

    //Introsort or introspective sort is a hybrid sorting algorithm
    //It begins with quicksort
    //It switches to heapsort when the recursion depth exceeds a level based on (the logarithm of) the number of elements being sorted
    //It switches to insertion sort when the number of elements is below some threshold

    std::vector<int> vec{10, 1, 5, 2, 50, 3};
    std::sort(vec.begin() + 1, vec.end() - 1, std::greater<int>{});
    for (int i = 0; i < vec.size(); ++i) std::cout << vec[i] << " "; std::cout << "\n";
    //10 50 5 2 1 3

    //First 3 elements from begin will be largest from ALL (difference with std::sort) elements from begin to end and in descending order
    //Other elements without specific order
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end(), std::greater<int>{});
    for (int i = 0; i < vec.size(); ++i) std::cout << vec[i] << " "; std::cout << "\n";
    //50 10 5 2 1 3

    //Middle element is placed as the container would be sorted, elements from right are lower, elements from left are larger
    std::deque<int> deq {10, 1, 5, 2, 50, 3};
    std::nth_element(deq.begin(),deq.end() - 3, deq.end(), std::greater<int>{});
    for (int i = 0; i < deq.size(); ++i) std::cout << deq[i] << " "; std::cout << "\n";
    //5 50 10 "3" 2 1


    //If container is a heap already - use sort heap to sort it
    //sort_heap is smtg like
//    void sort_heap( RandomIt first, RandomIt last )
//    {
//        while (first != last)
//            std::pop_heap(first, last--);
//    }
    std::make_heap(deq.begin(), deq.end(), std::greater<int>{});
    std::sort_heap(deq.begin(), deq.end(), std::greater<int>{});
    for (int i = 0; i < deq.size(); ++i) std::cout << deq[i] << " "; std::cout << "\n";
    //50 10 5 3 2 1

    //merge two sorted vectors
    int first[] = {5,10,15,20,25};
    int second[] = {50,40,30,20,10};
    std::vector<int> v(10);
    std::sort (first,first + std::size(first));
    std::sort (second,second + std::size(second));
    std::vector<int>::iterator it = std::copy (first, first + std::size(first), v.begin());
    std::copy (second,second + std::size(second),it);
    std::inplace_merge (v.begin(),v.begin() + std::size(first),v.end());
    for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " "; std::cout << "\n";
    return 0;
}
