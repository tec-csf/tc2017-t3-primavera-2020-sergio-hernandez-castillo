/**
 * Sea W un conjunto de enteros no negativos y M un número entero positivo. 
 * El problema consiste en diseñar un algoritmo para encontrar todos los 
 * posibles subconjuntos de W cuya suma sea exactamente M.
 * 
 * Backtracking
 * 
 * 1) Ask for the size of the list of positive numbers, preferably between 1 and 5
 * 2) Create a vector with that size
 * 3) Fill the vector with random numbers, preferably between 1 and 10
 * 4) Ask for a target number, preferably between 1 and 20
 * 5) Iterate over each number, adding as you go to check if a subset that
 *    sums up to the target exists.
 * 6) If a subset is found, print it 
 * 
 * Example: List = {9, 1, 3, 5, 6}, target = 17
 * First root number on the list: 9 + 1 = 10, 10 <= 17? True, next number
 *                                10 + 3 = 13, 13 <= 17? True, next number
 *                                13 + 5 = 18, 18 <= 17? False, go back 
 * 
 *                                13 + 6 = 19, 19 <= 17? False, go back
 * 
 *                                10 + 5 = 15, 15 <= 17? True, next number
 *                                15 + 6 = 21, 21 <= 17? False, go back
 * 
 *                                10 + 6 = 16, 16 <= 17? True, but there's no 
 *                                more numbers left to try, go back
 * 
 *                                9 + 3 = 12, 12 <= 17? True, next number
 *                                12 + 5 = 17, 17 <= 17? True, solution found
 * 
 * Solution: {9, 3, 5}
*/

#include <iostream>
#include <vector>

using namespace std;

bool doesItRepeat(int set[], int size, int number){
    for (int i = 0; i < size; i++){
        if (number == set[i]){
            return true;
        }//Close if 
    }//Close for 

    return false;
}//Close doesItRepeat

void fillSet(int set[], int size){
    int number;
    bool repeats = false;

    cout << "\nEnter positive numbers for the set: " << endl;

    for (int i = 0; i < size; i++){
        if (i == 0){
            cout << "Number " << i + 1 << ": ";
            cin >> number;

            while (number <= 0){
                cout << "Only numbers that are greater than or equal to 1 are allowed." << endl;
                cout << "Number " << i + 1 << ": ";
                cin >> number;
            }//Close while 

            set[i] = number;
        }//Close if 

        else {
            cout << "Number " << i + 1 << ": ";
            cin >> number;

            while (number <= 0){
                cout << "Only numbers that are greater than or equal to 1 are allowed." << endl;
                cout << "Number " << i + 1 << ": ";
                cin >> number;
            }//Close while 

            repeats = doesItRepeat(set, size, number);

            while (repeats == true){
                cout << "No repeated numbers are allowed." << endl;
                cout << "Number " << i + 1 << ": ";
                cin >> number;

                while (number <= 0){
                    cout << "Only numbers that are greater than or equal to 1 are allowed." << endl;
                    cout << "Number " << i + 1 << ": ";
                    cin >> number;
                }//Close while

                repeats = doesItRepeat(set, size, number);               
            }//Close while

            set[i] = number;
        }//Close else 
    }//Close for 
}//Close fillSet

void printSet(int set[], int size){
    for (int i = 0; i < size; i++){
        if (i == 0){
            cout << "\nThe set being analyzed is: [";
        }//Close if 

        if (i != size - 1){
            cout << set[i] << ", ";
        }//Close if 

        else {
            cout << set[i] << "]" << endl;
        }//Close else
    }//Close for

    cout << "\n";
}//Close printResults

void printSol(vector<int> &sol){
    for (int i = 0; i < sol.size(); i++){
        if (i == 0){
            cout << "Solution: [";
        }//Close if 

        if (i != sol.size() - 1){
            cout << sol[i] << ", ";
        }//Close if 

        else {
            cout << sol[i] << "]" << endl;
        }//Close else
    }//Close for 
}//Close printSol

void subsets(int set[], vector<int> &sol, int size, int target, int sum, int pos){
    if (sum == target){
        printSol(sol);
    }//Close if 

    for (int i = pos; i < size; i++){
        if ((sum + set[i]) <= target){
            sum += set[i];
            sol.push_back(set[i]);

            subsets(set, sol, size, target, sum, i + 1);     

            sum -= set[i];
            sol.pop_back();
        }//Close if
    }//Close for 
}//Close subsets

int main(){
    int size;
    int target;
    int sum = 0;
    int pos = 0;
    bool keepAsking = true;

    cout << "If no solutions are printed, then there were none." << endl;
    cout << "Enter the size of the set of positive numbers (it cannot be less than 1): ";

    while (keepAsking == true){
        cin >> size;

        if (size < 1){
            cout << "\nEnter a number greater than 0: ";
        }//Close if

        else { 
            keepAsking = false;
        }//Close else 
    }//Close while

    keepAsking = true;
    int set[size];
    vector<int> sol;

    fillSet(set, size);

    cout << "\nEnter the target number (it cannot be less than 1): ";

    while (keepAsking == true){
        cin >> target;

        if (target < 1){
            cout << "\nEnter a number greater than 0: ";
        }//Close if

        else { 
            keepAsking = false;
        }//Close else 
    }//Close while

    printSet(set, size);
    subsets(set, sol, size, target, sum, pos);
    
    return 0;
}//Close main 