#include <iostream>
using namespace std;

void display_solution(int *x, int n){
    std::cout<<"Solution Found ( ";
    for(int l=0; l<n; l++) std::cout<<x[l]+1<<" ";
    std::cout<<")"<<endl;
    for(int i=0; i<n; i++){
        std::cout<<"[ ";
        for(int j=0; j<n; j++){
            if(x[i] == j) std::cout<<"* ";
            else std::cout<<"- ";
        }
        std::cout<<"]"<<endl;
    }
}

/** Determines whether it is legal to place kth queen on ith column **/
bool can_place(int k, int i, int *x){
    for(int j=k-1; j>=0; j--){ // Check for clash with already placed queens
        if(i == x[j] || abs(j-k) == abs(x[j]-i)) return false;
    }
    return true;
}
/** Recursive Algorithm to find the solutions of N-Queen Problem **/
void NQueen(int k, int n, int *x){
    for(int i=0; i<n; i++){ // Try out all columns placements
        if(can_place(k, i, x)){ // Is it legal to place kth Queen on ith Column?
            x[k] = i; // Save the column for kth Queen into Solution tuple
            if(k == n-1) { // last queen placed and solution is generated
                display_solution(x, n);
            }else{
                NQueen(k+1, n, x); // Place the next k+1 Queen
            }
        }
    }
}


/** Iterative Algorithm to find solutions of N-Queen Problem **/
void NQueenI(int n){
    int solutions_count = 0;
    int x[n]; // Solution tuple
    int k=0; // Queen Number
    int save[n]; // Array to save column no upto which all columns have been tried in each row
    for(int l=0; l<n; l++) save[l] = -1; // No columns are tried initially
    while(k != -1){ // When there is no legal col position for 1st Queen then we have tried all possibilities and k reached -1
        // Get next legal column position to place kth Queen
        int col;
        for(col=save[k]+1; col<n && !can_place(k,col,x); col++);
        if(col == n){ // No legal column position found as end of columns reached
            save[k] = -1; // Clear the last save column position for kth Queen before backtracking
            k--; // Go to Previous Queen and adjust its column position
        }else{
            x[k] = col; // Save column no into solution tuple for kth queen
            save[k] = col; // Save column position for kth Queen
            if(k == n-1){ // When last queen placed
                display_solution(x, n);
                solutions_count++;
            }else{
                k++; // Place next k+1 Queen
            }
        }
    }
    std::cout<<"Total "<<solutions_count<<" solutions found for "<<n<<"-Queen Problem"<<endl;
}

int main() {
    std::cout<<"Enter the no of queens : ";
    int queens;
    std::cin>>queens;
    //int x[queens]; //solution tupple
    //NQueen(0, queens, x); // Call recursive algorithm by placing the 1st Queen initially
    NQueenI(queens); // Call iterative algorithm
    return 0;
}
