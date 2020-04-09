/**
 * Author: Sergio Hernandez Castillo - A01025210
 * Date: 04/04/2020
 * Description: C++ implementation of a greedy algorithm that solves the job assignment problem
*/

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

/**
 * Fills the 2D costs vector with random numbers between 1 and max minus 1.
 * 
 * @param[in] &costs the address in memory of the 2D vector that 
 *      represents the costs of each job per worker
 * @param[in] jobs the number of jobs
 * @param[in] max the maximum cost that a job can have
*/
void fillCosts(vector<vector<int>> &costs, int jobs, int max){
    /**
     * Seed that will make sure different random numbers are generated 
     * every time the program runs.
    */
    srand(time(0));

    // Iterate over all the rows of the 2D vector
    for (int row = 0; row < jobs; row++){
        // Iterate over all the columns of the 2D vector
        for (int col = 0; col < jobs; col++){
            /**
             * Assigns a random number between 1 and max minus 1 to the current 
             * spot in the 2D vector.
            */
            costs[row][col] = rand() % (max - 1) + 1;
        }//Close for
    }//Close for
}//Close fillCosts

/**
 * Checks if a worker is free via the 2D vector that represents the 
 *      job assignations.
 * 
 * @param[in] &assignations the address in memory of the 2D vector that 
 *      represents the job assignations
 * @param[in] jobs the number of jobs
 * @param[in] row the row in the 2D vector that represents the 
 *      worker being analyzed
 * 
 * @returns "true" if the worker is free to be assigned to a job, or 
 *      "false" if he is not
*/
bool checkIfFree(vector<vector<int>> &assignations, int jobs, int row){
    // Iterate over all the columns of the 2D vector 
    for (int col = 0; col < jobs; col++){
        /**
         * If any of the columns (jobs) in the worker's row is equal to 
         * 1, then he is already assigned to a job.
        */
        if (assignations[row][col] == 1){
            return false;
        }//Close if 
    }//Close for 

    return true;
}//Close checkIfFree

/**
 * Prints the 2D costs vector, showcasing all the costs of a job per worker. It also prints which worker
 *      was assigned to which job and the total cost of the solution.
 * 
 * @param[in] &costs the address in memory of the 2D vector that represents the costs of each job per 
 *      worker
 * @param[in] &assignations the address in memory of the 2D vector that represents the job assignations
 * @param[in] jobs the number of jobs
 * @param[in] totalCost the total cost of a solution
*/
void printResults(vector<vector<int>> &costs, vector<vector<int>> &assignations, int jobs, int totalCost){
    cout << "\nThe following is a worker by costs matrix, where a row represents a worker and a column ";
    cout << "represents the cost of a job: \n" << endl;

    // Iterate over the rows of the 2D vector
    for (int i = 0; i < jobs; i++){
        // Iterate over the columns of the 2D vector 
        for (int j = 0; j < jobs; j++){
            cout << "[" << costs[i][j] << "]";

            // If its the last column in the row 
            if (j == jobs - 1){
                cout << endl;
            }//Close if 
        }//Close for
    }//Close for

    cout << "\n";

    // Iterate over the rows of the 2D vector
    for (int row = 0; row < jobs; row++){
        // Iterate over the columns of the 2D vector 
        for (int col = 0; col < jobs; col++){
            // If an assigned job was found
            if (assignations[row][col] == 1){
                cout << "Worker " << row + 1 << " was assigned to job " << col + 1 << " with a cost of " 
                    << costs[row][col] << endl;
            }//Close if 
        }//Close for 
    }//Close for 

    cout << "\nThe total cost was " << totalCost << endl;
}//Close printResults

/**
 * Assigns a job to the worker with the lowest cost, until there are no more jobs left to assign, 
 *      but only if the worker is free. It also calculates the total cost using the 2D 
 *      assignations vector.
 * 
 * @param[in] &costs the address in memory of the 2D vector that represents the costs of each job per 
 *      worker
 * @param[in] &assignations the address in memory of the 2D vector that represents the job assignations
 * @param[in] jobs the number of jobs
 * @param[in] max the maximum cost that a job can have
 * 
 * @returns the total cost of a solution 
*/
int assignJobs(vector<vector<int>> &costs, vector<vector<int>> &assignations, int jobs, int max){
    // Used to represent a row
    int row;
    // Used to represent a column
    int col;
    // Represents the minimum cost, but starts as the value of the maximum
    int min = max;
    // Saves the row of a promising worker for the solution
    int spotX;
    // Saves the column of a promising worker for the solution 
    int spotY;
    // The total cost of a solution, it first starts as 0
    int totalCost = 0;
    // Tells if a worker is free to be assigned to a job
    bool isItFree;

    // Iterate over the columns of the 2D vector
    for (col = 0; col < jobs; col++){
        // Iterate over the rows of the 2D vector
        for (row = 0; row < jobs; row++){
            /**
             * Calls the method that checks if a worker is free to be assigned to a job and saves
             * the "true" or "false" value in the variable.
            */
            isItFree = checkIfFree(assignations, jobs, row);

            // If the current worker has the lowest cost and is free for the job
            if ((costs[row][col] < min) && (isItFree == true)){
                // Saves the new minimum cost 
                min = costs[row][col];
                // The row and column of the worker is saved 
                spotX = row;
                spotY = col;
            }//Close if 
        }//Close for 

        // Assigns the job to the worker that is currently saved
        assignations[spotX][spotY] = 1;

        // Resets the minimum cost 
        min = max;
    }//Close for

    // Iterate over the columns of the 2D vector
    for (col = 0; col < jobs; col++){
        // Iterate over the rows of the 2D vector
        for (row = 0; row < jobs; row++){
            // If a worker assigned to a job was found
            if (assignations[row][col] == 1){
                // Add up the total cost
                totalCost += costs[row][col];
            }//Close if
        }//Close for
    }//Close for 

    return totalCost;
}//Close assignJobs

/**
 * Asks for the amount of jobs, the maximum cost that a job can have, and calls three methods: 
 *      the one that fills the 2D costs vector, the one that assigns jobs to workers (saving 
 *      the total cost in a variable), and the one that prints the results. 
*/
int main(){
    // The number of jobs
    int jobs;
    // The maximum cost that a job can have
    int max;
    // The total cost of a solution
    int totalCost;
    // The variable that will be used to check if jobs/max should be entered again
    bool keepAsking = true;

    cout << "Enter the amount of jobs: ";

    // Will ask again and again for the amount of jobs if its not greater than 1 
    while (keepAsking == true){
        cin >> jobs;

        // If the amount of jobs is still less than or equal to 1
        if (jobs <= 1){
            cout << "Enter a number greater than 1: ";
        }//Close if 

        // If the amount of jobs is now greater than 1, the loop stops
        else {
            keepAsking = false;
        }//Close else
    }//Close while 

    cout << "\n";
    // Resets the variable 
    keepAsking = true;

    cout << "A job will never have a cost equal to the maximum cost." << endl;
    cout << "Enter the maximum cost that a job can have: ";
    
    // Will ask again and again for the maximum cost if its not greater than 3
    while (keepAsking == true){
        cin >> max;

        // If the maximum cost is still less than or equal to 3
        if (max <= 3){
            cout << "Enter a number greater than 3: ";
        }//Close if 

        // If the maximum cost is now greater than 3, the loop stops
        else {
            keepAsking = false;
        }//Close else
    }//Close while

    // The 2D vector that represents the costs of each job per worker 
    vector<vector<int>> costs(jobs, vector<int>(jobs));
    // The 2D vector that represents the job assignations 
    vector<vector<int>> assignations(jobs, vector<int>(jobs));

    // Calls the method that will fill the 2D costs vector
    fillCosts(costs, jobs, max);
    // Calls the method that will assign one job per worker and saves the total cost
    totalCost = assignJobs(costs, assignations, jobs, max);
    // Calls the method that will print the results 
    printResults(costs, assignations, jobs, totalCost);

    return 0;
}//Close main 