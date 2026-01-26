#include <iostream>
#include <vector>
#include <array>
#include <memory>   // For smart pointers
#include <algorithm> // For for_each

using namespace std;

constexpr int ARRAY_SIZE = 4; // C++11 constexpr

// Template works for Vector, std::array, and raw pointers
template<typename It>
void print_values(It begin, It end) {
    for (auto current = begin; current != end; ++current){
        cout << *current << " ";    
    }
    cout << "\n"; // Prefer \n over endl for performance
}

// "Under the hood" - How memory works
void raw_memory_mechanics() {
    cout << "--- Raw Memory ---\n";
    int a = 1; 
    // Show Stack address
    cout << "Stack var a: " << a << " @ " << &a << "\n";
    
    // Manual Heap allocation (Legacy style, but good for learning)
    int* heap_int = new int[3]{2,3,4}; 
    cout << "Heap ptr heap_int: " << *heap_int << " @ " << heap_int << "\n";
    print_values(heap_int, heap_int + 3);

    // Old style C array (Stack based)
    int c_array[ARRAY_SIZE] = {5, 6, 7, 8};
    print_values(c_array, c_array + ARRAY_SIZE);

    delete[] heap_int; // MUST delete manually
}

// "Modern C++" - How we write robust code
void modern_features() {
    cout << "--- Modern Features ---\n";
    
    // 1. std::array (Stack based, fixed size, safe)
    std::array<int, ARRAY_SIZE> safe_array{9, 10, 11, 12};
    print_values(safe_array.begin(), safe_array.end());

    // 2. std::unique_ptr (Heap based, auto-cleanup)
    auto smart_ptr = std::make_unique<int>(13);
    cout << "Smart pointer: " << *smart_ptr << " (No manual delete needed)\n";

    // 3. Vector and Lambdas
    vector<int> v{13, 14, 15, 16, 17, 18, 19}; // Initializer list
    
    // Add dynamic elements
    for (int i = 0; i < 3; ++i) v.push_back(i + 20);

    // Use a Lambda to modify items
    std::for_each(v.begin(), v.end(), [](int& n) {
        n += 1; // Increment every value by 1
    });

    print_values(v.begin(), v.end());
    
    // 4. Visualizing Vector Memory Layout
    // The vector object is on the Stack, its data is on the Heap
    cout << "Vector Object Address (Stack): " << &v << "\n";
    cout << "Vector Data Address (Heap):    " << &v[0] << "\n";
}

int main(){
    raw_memory_mechanics();
    modern_features();
    return 0;
}
