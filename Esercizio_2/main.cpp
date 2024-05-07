#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

// Funzione per generare un vettore di un certo tipo e dimensione
template<typename T>
vector<T> generate_vector(size_t size, const string& vector_type) {
    vector<T> vec;
    if (vector_type == "random") {
        for (size_t i = 0; i < size; ++i) {
            vec.push_back(rand() % 1000);
        }
    } else if (vector_type == "sorted") {
        for (size_t i = 0; i < size; ++i) {
            vec.push_back(i);
        }
    } else if (vector_type == "reverse_sorted") {
        for (size_t i = size; i > 0; --i) {
            vec.push_back(i);
        }
    }
    return vec;
}

// Funzione per misurare il tempo di esecuzione di un algoritmo di sorting
template<typename T>
double measure_time(void (*sorting_algorithm)(vector<T>&), vector<T>& vec) {
    clock_t start_time = clock();
    sorting_algorithm(vec);
    clock_t end_time = clock();
    return double(end_time - start_time) / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <vector_size> <vector_type>" << endl;
        return 1;
    }

    size_t vector_size = atoi(argv[1]);
    string vector_type = argv[2];

    // Inizializza il generatore di numeri casuali con un seed basato sull'orario corrente
    srand(time(NULL));

    vector<int> vec = generate_vector<int>(vector_size, vector_type);

    // Misura il tempo di esecuzione per BubbleSort
    double bubble_sort_time = measure_time(BubbleSort<int>, vec);

    // Re-inizializza il vettore per MergeSort
    vec = generate_vector<int>(vector_size, vector_type);

    // Misura il tempo di esecuzione per MergeSort
    double merge_sort_time = measure_time(MergeSort<int>, vec);


    cout << "Vector Type: " << vector_type << endl;
    cout << "Vector Size: " << vector_size << endl;
    cout << "BubbleSort Time: " << bubble_sort_time << " seconds" << endl;
    cout << "MergeSort Time: " << merge_sort_time << " seconds" << endl;

    return 0;
}
