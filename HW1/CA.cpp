/*
Name:   Shu Chen
HW1:    Cellular Automata
Discrip:Sim the Cell behavior by rules.
*/
#include <iostream>
#include <cmath>
using std::cin;

void convertRuleSetNumberToRuleSetArray(int n, int* bitArray);
int BinaryToInt(int binary);
void displayCurrentGeneration(int* array, int len);
void computeNextGeneration(int* oldCells, int* newCells, int len, int* rule);
int convertNeighborhoodToIndex(int left, int mid, int right);
bool GetCell(int* cells, int len, int index);

int main(){
    int rules[8] = {}; //this is a const array
    int cellLen = 64;
    int SimStep = 49;
    int cells[cellLen] = {};
    int newCells[cellLen] = {};
    cells[cellLen/2-1] = 1;
    
    int ruleInput;
    std::cout<<"Please enter a proper number (0-255) for rule";
    cin >> ruleInput;
    if(std::cin.fail() || ruleInput < 0 || ruleInput > 255) {
        std::cout<<"Not a valid number, exiting the program..."<<std::endl;
        return 0;
    }

    convertRuleSetNumberToRuleSetArray(ruleInput,rules);

    displayCurrentGeneration(cells, cellLen);
    for(int i = 0; i<SimStep; i++){
        computeNextGeneration(cells, newCells, cellLen, rules);
        displayCurrentGeneration(cells, cellLen);
    }

    std::cout << std::endl;
    return 0;
}



/// @brief turn dicimal to bool array
/// @param n dicimal input
/// @param bitArray result return
/// @param arrLen length of the bit array
void convertRuleSetNumberToRuleSetArray(int n, int* bitArray){
    int index = 0;
    while(n > 0){
        bitArray[index] = (n%2==1);     //We need the reverse order for the binary rule
        n/=2;
        index ++;        
    }
}

/// @brief Turn binary to dicmal
/// @param binary 
/// @return int in dicmal form
int BinaryToInt(int binary){
    int result = 0;
    int mult = 1;
    while(binary > 0){
        result += binary % 2 * mult;
        mult *= 2;
        binary /= 10;
    }
    return result;
}

/// @brief Cal the cell from old cell to next step(new cell)
/// @param oldCells old cells
/// @param newCells new cells array as an container
/// @param len length of the array
/// @param rule rule for calculation
void computeNextGeneration(int* oldCells, int* newCells, int len, int* rule){
    for(int i = 0; i < len; i++){
        int index = convertNeighborhoodToIndex(GetCell(oldCells,len,i-1),
                    GetCell(oldCells,len,i) ,GetCell(oldCells,len,i+1));
        newCells[i] = rule[index];
    }
        std::copy(newCells, newCells + len, oldCells);
}

/// @brief Convert three cells to index of the array
/// @param left 
/// @param mid 
/// @param right 
/// @return the index from three bits
int convertNeighborhoodToIndex(int left, int mid, int right){
    return left*4+mid*2+right;
}

/// @brief Get a cell or return 0 for bool array
/// @param cells int array cells
/// @param len len of the array
/// @param index index of the element
/// @return bool val
bool GetCell(int* cells, int len, int index){
    if(index < 0 || index >= len){
        return 0;
    }
    return cells[index];
}

/// @brief Print the cell in a single line
/// @param array array that store this cell
/// @param len length of this array
void displayCurrentGeneration(int* array, int len){
    for(int i = 0; i < len; i++){
        if(array[i])std::cout<<"#";
        else std::cout<<" ";        
    }
    std::cout<<"\n";
}

