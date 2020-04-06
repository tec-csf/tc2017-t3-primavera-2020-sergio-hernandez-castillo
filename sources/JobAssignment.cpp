/**
 * Supongamos que disponemos de n trabajadores y n tareas. Sea bij > 0 el coste 
 * de asignarle el trabajo j al trabajador i. Una asignación de tareas puede ser 
 * expresada como una asignación de los valores 0 ó 1 a las variables xij, donde 
 * xij = 0 significa que al trabajador i no le han asignado la tarea j, y xij = 
 * 1 indica que sí. Una asignación válida es aquella en la que a cada trabajador 
 * sólo le corresponde una tarea y cada tarea está asignada a un trabajador. Dada 
 * una asignación válida, definimos el coste de dicha asignación como:
 * 
 * ∑n ∑n xijbij
 * i=1 j=1
 * 
 * Diremos que una asignación es óptima si es de mínimo coste
 * 
 * Greedy algorithm
 * 
 * 1) Ask how many jobs there are. The number of workers will be the same.
 * 2) Create a 2D array that will represent the assignation of jobs to the workers.
 *    The size of the array will be of [n][n], "n" being the number of jobs.
 *    For example, if "n" was equal to 3: [1, 0, 0]
 *                                        [0, 1, 0]
 *                                        [0, 0, 1]
 * 3) Create a 2D array that will represent the costs of each job per worker. The 
 *    size of the array will be of [n][n], "n" being the number of jobs. 
 *    For example, if "n" was equal to 3: [5, 12, 4]
 *                                        [15, 6, 3]
 *                                        [7, 8, 19]
 * 4) Fill the cost array with random numbers, preferably between 1 and 20
 * 5) Fill the assignation array with 0's
 * 6) Iterate over the cost array, column by column
 * 7) Iterate over the rows, n times per column
 * 7a) Check which worker has the lowest cost for the current column/job being analyzed
 * 7b) Assign the job to the lowest cost worker by saving a 1 in the same spot of the 
 *     assignation array. But only if there is no 1 saved in that spots row (iterate
 *     over the entire row separately just to check). If the lowest cost worker is 
 *     already taken, assign the job to the 2nd lowest cost worker.
 * 8) Calculate the total cost of the solution
 * 9) Print the solution (which worker does what job and the total cost)
*/

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void fillCosts(vector<vector<int>> &costs, int jobs, int max){
    srand(time(0));

    for (int row = 0; row < jobs; row++){
        for (int col = 0; col < jobs; col++){
            costs[row][col] = rand() % max + 1;
        }//Close for
    }//Close for
}//Close fillCosts

bool checkIfFree(vector<vector<int>> &assignations, int jobs, int row){
    for (int col = 0; col < jobs; col++){
        if (assignations[row][col] == 1){
            return false;
        }//Close if 
    }//Close for 

    return true;
}//Close checkIfFree

void printResults(vector<vector<int>> &costs, vector<vector<int>> &assignations, int jobs, int totalCost){
    cout << "\nThe following is a worker by costs matrix, where a row represents a worker and a column ";
    cout << "represents the cost of a job: \n" << endl;

    for (int i = 0; i < jobs; i++){
        for (int j = 0; j < jobs; j++){
            cout << "[" << costs[i][j] << "]";

            if (j == jobs - 1){
                cout << endl;
            }//Close if 
        }//Close for
    }//Close for

    cout << "\n";

    for (int row = 0; row < jobs; row++){
        for (int col = 0; col < jobs; col++){
            if (assignations[row][col] == 1){
                cout << "Worker " << row + 1 << " was assigned to job " << col + 1 << " with a cost of " 
                    << costs[row][col] << endl;
            }//Close if 
        }//Close for 
    }//Close for 

    cout << "\nThe total cost was " << totalCost << endl;
}//Close printResults

int assignJobs(vector<vector<int>> &costs, vector<vector<int>> &assignations, int jobs, int max){
    int row;
    int col;
    int min = max;
    int spotX;
    int spotY;
    int totalCost = 0;
    bool isItFree;

    for (col = 0; col < jobs; col++){
        for (row = 0; row < jobs; row++){
            isItFree = checkIfFree(assignations, jobs, row);

            if ((costs[row][col] < min) && (isItFree == true)){
                min = costs[row][col];
                spotX = row;
                spotY = col;
            }//Close if 
        }//Close for 

        assignations[spotX][spotY] = 1;

        min = max;
    }//Close for

    for (col = 0; col < jobs; col++){
        for (row = 0; row < jobs; row++){
            if (assignations[row][col] == 1){
                totalCost += costs[row][col];
            }//Close if
        }//Close for
    }//Close for 

    return totalCost;
}//Close assignJobs

int main(){
    int jobs;
    int max;
    int totalCost;

    cout << "Enter the amount of jobs: ";
    cin >> jobs;

    cout << "\n";

    cout << "Enter the maximum cost that a job can have: ";
    cin >> max;

    vector<vector<int>> costs(jobs, vector<int>(jobs));
    vector<vector<int>> assignations(jobs, vector<int>(jobs));

    fillCosts(costs, jobs, max);
    totalCost = assignJobs(costs, assignations, jobs, max);
    printResults(costs, assignations, jobs, totalCost);

    return 0;
}//Close main 