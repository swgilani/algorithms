#include <iostream>
#include <random>
using namespace std;



void selectionSort(int array[], int n, int start){

    int i;
    int z;
    int minIndex;
    int temp;

    for (i = start ; i < n-1; i++){
        minIndex = i;
        
        for (z = i+1; z<n; z++){
            if (array[z] < array[minIndex]){
                minIndex = z;
            }

        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;

        }
    }
}

void printSelectionSort(int n) {
    
    int array[n];

    for (int i = 0; i < n; i++){
        array[i] = 1+rand()%(4*n);
    }
    auto startTime = std::chrono::steady_clock::now();
    selectionSort(array, n,0);
    auto endTime = std::chrono::steady_clock::now();
    auto totalTime = endTime-startTime;

    std::cout<<"Size of array (Selection Sort): ";
    std::cout<<n<<endl;
    std::cout << std::chrono::duration <double, std::milli> (totalTime).count() << " ms taken to run." << std::endl;

}


void merge(int array[], int l, int c, int r){

    int n1;
    int n2;
    n1 = (c-l+1);
    n2 = (r-c);

    int leftArray[n1];
    int rightArray[n2];

    for(int i = 0; i<n1;i++){
        leftArray[i] = array[l+i];
    }
    for(int j = 0; j<n2;j++){
        rightArray[j] = array[c+j+1];
    }
    int index = l;
    int o = 0; //i
    int q = 0; //j
    

    while (o < n1 && q < n2){

        if (leftArray[o] <= rightArray[q]){
        array[index] = leftArray[o];
        o++;
        }
        else {
            array[index] = rightArray[q];
            q++;
        }
        index++;
    }

    while (o<n1){
        array[index] = leftArray[o];
        o++;
        index++;
    }

    while (q<n2){
        array[index] = rightArray[q];
        q++;
        index++;
    }
}


void mergeSort(int array[], int left, int right) {

    int center;
    if (left < right)
    {
        center = left+(right-left)/2;
        mergeSort(array,left,center);
        mergeSort(array, center+1,right);
        merge(array, left, center,right);
    }
}

void printMerge(int n) {
      
    int array[n];

    for (int i = 0; i < n; i++){
        array[i] = 1+rand()%(4*n);
    }
    auto startTime = std::chrono::steady_clock::now();
    mergeSort(array,0,n);
    auto endTime = std::chrono::steady_clock::now();
    auto totalTime = endTime-startTime;

    std::cout<<"Size of array (Merge Sort): ";
    std::cout<<n<<endl;
    std::cout << std::chrono::duration <double, std::milli> (totalTime).count() << " ms taken to run." << std::endl;
}


void modifiedmergeSort(int array[], int left, int right){
    //Selection sort is better to do when there is a smaller array (less than 30 elements)
    int center;
    if (left < right)
    {
        center = left+(right-left)/2;
        if (right-left < 30){
            selectionSort(array,right-left,left);
        } 

    else {
        mergeSort(array,left,center);
        mergeSort(array, center+1,right);
        
    }
    merge(array, left, center,right);

    }
}

void printmodifiedmergeSort(int n){
int array[n];

    for (int i = 0; i < n; i++){
        array[i] = 1+rand()%(4*n);
    }
    auto startTime = std::chrono::steady_clock::now();
    modifiedmergeSort(array,0,n);
    auto endTime = std::chrono::steady_clock::now();
    auto totalTime = endTime-startTime;

    std::cout<<"Size of array (Modified Merge Sort): ";
    std::cout<<n<<endl;
    std::cout << std::chrono::duration <double, std::milli> (totalTime).count() << " ms taken to run." << std::endl;

}


int main() {

    int n = 5;

    for (int i =0; i<=6; i++){
    printMerge(n);
    printSelectionSort(n);
    printmodifiedmergeSort(n);
    printf("\n");

    n=n*3;
    }
    return 0;
  
}