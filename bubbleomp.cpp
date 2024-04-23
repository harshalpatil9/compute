#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For clock()
#include <omp.h>    // OpenMP

// Sequential Bubble Sort
void bubbleSortSequential(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
 
}

// Parallel Bubble Sort using OpenMP
void bubbleSortParallel(int* arr, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printArray(int* arr, int size){
	for(int i=0;i<size;i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}  


int main() {
    const int size = 20000;
    int arrSeq[size];
    int arrPar[size];
    for (int i = 0; i < size; i++) {
        int num = rand() % 20000;  // Random numbers between 0 and 9999
        arrSeq[i]=num;
        arrPar[i]=num;
    }

    // Measure sequential bubble sort time
    clock_t startSeqBubble = clock();
    bubbleSortSequential(arrSeq, size);
    clock_t endSeqBubble = clock();
    double timeSeqBubble = double(endSeqBubble - startSeqBubble) / CLOCKS_PER_SEC;

    // Measure parallel bubble sort time
    clock_t startParBubble = clock();
    bubbleSortParallel(arrPar, size);
    clock_t endParBubble = clock();
    double timeParBubble = double(endParBubble - startParBubble) / CLOCKS_PER_SEC;

    // Print execution times
    
    std::cout << "Sorted Array (Sequential) : ";
    printArray(arrSeq,size);
    std::cout<<std::endl;
    std::cout << "Sorted Array (Parallel) : ";
    printArray(arrPar,size);
    
    std::cout<<std::endl;
    std::cout << "Sequential Bubble Sort Time: " << timeSeqBubble << " seconds" << std::endl;
    std::cout<<std::endl;
    std::cout << "Parallel Bubble Sort Time: " << timeParBubble << " seconds" << std::endl;
    
    
    return 0;
}
