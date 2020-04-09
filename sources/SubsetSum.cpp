/**
 * Author: Sergio Hernandez Castillo - A01025210
 * Date: 06/04/2020
 * Description: C++ implementation of the Backtracking solution to the subset sum problem.
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Checks if a number given as a set element repeats in the set.
 * 
 * @param[in] set[] the array that represents the set of positive numbers
 * @param[in] size the size of set
 * @param[in] number the given number that will be checked for repetitions
 * 
 * @returns "true" if the number repeats in the set, "false" if it doesn't
*/
bool doesItRepeat(int set[], int size, int number){
    // Iterate over the whole set
    for (int i = 0; i < size; i++){
        /**
         * If the given number is equal to any set element, return "true", 
         * if not, return "false".
        */
        if (number == set[i]){
            return true;
        }//Close if 
    }//Close for 

    return false;
}//Close doesItRepeat

/**
 * Fills the set with positive and non-repetitive numbers.
 * 
 * @param[in] set[] the array that represents the set of positive numbers
 * @param[in] size the size of set
*/
void fillSet(int set[], int size){
    // The number that will be given by the user
    int number;
    // The variable that will say if a number repeats or not
    bool repeats = false;

    cout << "\nEnter positive numbers for the set: " << endl;

    // Iterate over the whole set
    for (int i = 0; i < size; i++){
        // If its the first number the program asks for
        if (i == 0){
            cout << "Number " << i + 1 << ": ";
            cin >> number;

            // Will ask again and again for a number if its less than or equal to 0
            while (number <= 0){
                cout << "Only numbers that are greater than or equal to 1 are allowed." << endl;
                cout << "Number " << i + 1 << ": ";
                cin >> number;
            }//Close while 

            // Saves the number in the current spot of the set
            set[i] = number;
        }//Close if 

        // If its not the first number the program asks for 
        else {
            cout << "Number " << i + 1 << ": ";
            cin >> number;

            // Will ask again and again for a number if its less than or equal to 0
            while (number <= 0){
                cout << "Only numbers that are greater than or equal to 1 are allowed." << endl;
                cout << "Number " << i + 1 << ": ";
                cin >> number;
            }//Close while 

            /**
             * Calls a method that will check if the given number repeats in the set, saving a 
             * "true" or "false" in the variable.
            */
            repeats = doesItRepeat(set, size, number);

            // Will ask again and again for a number if it repeats in the set
            while (repeats == true){
                cout << "No repeated numbers are allowed." << endl;
                cout << "Number " << i + 1 << ": ";
                cin >> number;

                // Will ask again and again for a number if its less than or equal to 0
                while (number <= 0){
                    cout << "Only numbers that are greater than or equal to 1 are allowed." << endl;
                    cout << "Number " << i + 1 << ": ";
                    cin >> number;
                }//Close while

                /**
                 * Calls a method that will check if the given number repeats in the set, saving a 
                 * "true" or "false" in the variable.
                */
                repeats = doesItRepeat(set, size, number);               
            }//Close while

            // Saves the number in the current spot of the set
            set[i] = number;
        }//Close else 
    }//Close for 
}//Close fillSet

/**
 * Prints the set of positive numbers.
 * 
 * @param[in] set[] the array that represents the set of positive numbers
 * @param[in] size the size of set
 */
void printSet(int set[], int size){
    // Iterate over the whole set
    for (int i = 0; i < size; i++){
        // If its the first time the loop runs
        if (i == 0){
            cout << "\nThe set being analyzed is: [";
        }//Close if 

        // If it isn't the first or last time this loop runs
        if (i != size - 1){
            cout << set[i] << ", ";
        }//Close if 

        // If its the last time this loop runs
        else {
            cout << set[i] << "]" << endl;
        }//Close else
    }//Close for

    cout << "\n";
}//Close printSet

/**
 * Prints the solution subset.
 * 
 * @param[in] &sol the address in memory of the vector that 
 *      represents the solution subset
*/
void printSol(vector<int> &sol){
    // Iterate over the whole subset
    for (int i = 0; i < sol.size(); i++){
        // If its the first time the loop runs
        if (i == 0){
            cout << "Solution: [";
        }//Close if 

        // If it isn't the first or last time this loop runs
        if (i != sol.size() - 1){
            cout << sol[i] << ", ";
        }//Close if 

        // If its the last time this loop runs
        else {
            cout << sol[i] << "]" << endl;
        }//Close else
    }//Close for 
}//Close printSol

/**
 * Calls the method to print the solution subset if a temporal sum is equal to the 
 *      target number and creates possible solution subsets using a recursive call.
 *      The recursive call will use the "for" loop to check every available subset 
 *      in the set.
 * 
 * @param[in] set[] the array that represents the set of positive numbers
 * @param[in] &sol the address in memory of the vector that represents the solution 
 *      subset
 * @param[in] size the size of set
 * @param[in] target the target number
 * @param[in] sum a temporal sum used to see if a subset adds up to the target
 * @param[in] pos the position of the set array being analyzed
*/
void subsets(int set[], vector<int> &sol, int size, int target, int sum, int pos){
    // If the temporal sum is equal to the target
    if (sum == target){
        printSol(sol);
    }//Close if 

    // Iterate over the whole set starting from the given position
    for (int i = pos; i < size; i++){
        /**
         * If the value of the temporal sum plus the current element in the set is 
         * less than or equal to the target.
        */
        if ((sum + set[i]) <= target){
            // Make the sum equal to itself plus the current element in the set
            sum += set[i];
            // Push back/add the current element into the solution subset
            sol.push_back(set[i]);

            /**
             * Recursive call that carries the temporal sum and the position to 
             * start analyzing from as the only different variables.
            */
            subsets(set, sol, size, target, sum, i + 1);     

            // Make the sum equal to itself minus the current element in the set
            sum -= set[i];
            // Pop back/remove the current element from the solution subset
            sol.pop_back();
        }//Close if
    }//Close for 
}//Close subsets

/**
 * Asks for the size of the set of positive numbers, the target number, and calls the methods 
 *      that will fill the set, print it, and the method that checks if any solution subsets
 *      exist.
*/
int main(){
    // The size of the set
    int size;
    // The target number
    int target;
    // The temporal sum used to check for solution subsets
    int sum = 0;
    // The starting position in the set 
    int pos = 0;
    // The variable used to check if the size/target should be entered again
    bool keepAsking = true;

    cout << "If no solutions are printed, then there were none." << endl;
    cout << "Enter the size of the set of positive numbers (it cannot be less than 1): ";

    // Will ask again and again for the size if its not greater than 0
    while (keepAsking == true){
        cin >> size;

        // If the size is still not greater than 0
        if (size < 1){
            cout << "\nEnter a number greater than 0: ";
        }//Close if

        // If the size is now greater than 0, stops the loop
        else { 
            keepAsking = false;
        }//Close else 
    }//Close while

    // Resets the variable 
    keepAsking = true;
    // The array that represents the set of positive numbers
    int set[size];
    // The vector that represents the solution subset
    vector<int> sol;

    // Calls the method to fill the set with positive/non-repetitive numbers
    fillSet(set, size);

    cout << "\nEnter the target number (it cannot be less than 1): ";

    // Will ask again and again for the target if its not greater than 0
    while (keepAsking == true){
        cin >> target;

        // If the target is still not greater than 0
        if (target < 1){
            cout << "\nEnter a number greater than 0: ";
        }//Close if

        // If the target is now greater than 0, stops the loop
        else { 
            keepAsking = false;
        }//Close else 
    }//Close while

    // Calls the method that will print the set
    printSet(set, size);
    // Calls the method that will check if any solution subsets exist
    subsets(set, sol, size, target, sum, pos);
    
    return 0;
}//Close main 