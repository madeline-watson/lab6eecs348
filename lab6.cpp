#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

static const int MAX_SIZE = 100;

void readData(int size, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE]){
    ifstream file;
    file.open("input.txt");
    file >> size;

    if(size > MAX_SIZE){ //when the size is above the max size
        std::cout << "Invalid input";
    }

    for(int i = 0; i < size; i++){ //populate matrix A
        for(int j = 0; j < size; j++){
            file >> A[i][j];
        }
    }

    for(int i = 0; i < size; i++){ //populate matrix B
        for(int j = 0; j < size; j++){
            file >> B[i][j];
        }
    }

    file.close();
}

void print(int arr[MAX_SIZE][MAX_SIZE], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << setw(3) << arr[i][j] << setw(3) << " ";
        }
        cout << "\n";
    }
}

void add(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int size){
    int C[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    print(C, size);
}

void mult(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int size){
    int C[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int sum = 0; 
			for (int k = 0; k < size; k++) { 
				int prod;
				prod = (A[i][k] * B[k][j]); 
				sum += prod;
			}
		    C[i][j] = sum; 
		}
	}
	print(C, size); 
}

void sub(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int size){
    int C[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    print(C, size);
}

int main(){
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], size = 3;
    readData(size, A, B);
    std::cout << "Madeline Watson\nLab #6: Matrix Manipulation";
    std::cout << "\nMatrix A:\n";
    print(A, size);
    std::cout << "\nMatrix B:\n";
    print(B, size);
    std::cout << "\nMatrix Sum (A + B):\n";
    add(A, B, size);
    std::cout << "\nMatrix Product (A * B):\n";
    mult(A, B, size);
    std::cout << "\nMatrix Difference (A - B):\n";
    sub(A, B, size);
    return 0;
}