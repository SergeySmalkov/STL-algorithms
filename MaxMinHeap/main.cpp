#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>

int main() {
    //https://www.youtube.com/watch?v=2olsGf6JIkU
    //ORDERED vector, but max or min element will be on top
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    min_heap.push(55);
    min_heap.push(40);
    min_heap.push(95);
    min_heap.push(25);
    min_heap.push(1);
    min_heap.push(10);
    min_heap.push(2);
    min_heap.push(0);
    std::vector<int> a;
    while (!min_heap.empty()) {std::cout << min_heap.top() << " "; min_heap.pop();}
    //0 1 2 10 25 40 55 95

    std::vector<int> vec {10,1,2,0,15,1};
    std::cout << '\n';

    std::priority_queue<int, std::vector<int>, std::less<int>> max_heap (vec.begin(), vec.end());
    while (!max_heap.empty()) {std::cout << max_heap.top() << " "; max_heap.pop();}
    //15 10 2 1 1 0
    //vec unchanged
    std::cout << '\n';

    //REQUIRED RANDOM ACCESS ITERATOR! ONLY VECTOR OR DEQUE
    std::make_heap(vec.begin(),vec.end());
    for (int i = 0; i < vec.size(); ++i) {std::cout << vec[i] << " ";}
    //NOT just ordered queue, but MAX HEAP!
    //15 10 2 0 1 1
    std::cout << '\n';
    vec.push_back(12);
    //push_heap pushes last element as it was in heap
    std::push_heap(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {std::cout << vec[i] << " ";}
    //15 10 12 0 1 1 2
    std::cout << '\n';

    std::make_heap(vec.begin(),vec.end(), std::greater<>{});
    for (int i = 0; i < vec.size(); ++i) {std::cout << vec[i] << " ";}
    std::cout << '\n';
    //Min_heap
    //0 1 1 10 15 12 2
    vec.push_back(11);
    //push_heap pushes last element as it was in heap
    std::push_heap(vec.begin(), vec.end(), std::greater<int>{});
    for (int i = 0; i < vec.size(); ++i) {std::cout << vec[i] << " ";}
    std::cout << '\n';
    //0 1 1 10 15 12 2 11

    //pop swaps first element with the last and for does the heap_down for the first element
    std::pop_heap(vec.begin(), vec.end(), std::greater<int>{});
    vec.pop_back();
    for (int i = 0; i < vec.size(); ++i) {std::cout << vec[i] << " ";}
    //1 1 2 10 15 12 11
    std::cout << '\n';

    //EXAMPLE WITH DEQUE
    std::deque<int> deque {{1,31}};
    deque.push_back(5);
    deque.insert(deque.begin() + 2, 1000);
    deque[2];
    std::make_heap(deque.begin(), deque.end());
    for (int i = 0; i < deque.size(); ++i) {std::cout << deque[i] << " ";}
    std::cout << '\n';

    return 0;
}
