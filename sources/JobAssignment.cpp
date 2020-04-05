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

using namespace std;

int main(){
    int jobs = 0;

    cout << "Enter the amount of jobs to be done: ";
    cin >> jobs;

    int costs[jobs][jobs];
    int assignations[jobs][jobs];
}//Close main 