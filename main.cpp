#include <iostream>
#include <vector>
#include <algorithm>

bool checkRows(std::vector<std::vector<int>>Grid,int row,int col,int N){
    for (int i = 0; i < 9;i++){
        if(i != col){
            if (Grid[row][i] == N){
                return false;
            }
        }
        else{
            continue;
        }
    }return true;
}
//CHECK THE COLUMNS
bool checkColumns(std::vector<std::vector<int>>&Grid,int row,int col,int N){
    for (int i = 0; i < 9;i++){
        if(i != row){
            if (Grid[i][col] == N){
                return false;
            }
        }
        else{
            continue;
        }
    }return true;
}
//CHECK THE BLOCK
bool checkBlock(std::vector<std::vector<int>>&Grid,int row,int col,int N){
    int startRow = row - (row%3);
    int startColumn = col - (col%3);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(i != row && j != col){
                 if (Grid[i+ startRow][j+startColumn] == N){
                     return false;
                 }
             }
        }
    }return true;
}

bool isValid(std::vector<std::vector<int>>&Grid,int row,int col,int N){
    return checkBlock(Grid,row,col,N) && checkColumns(Grid,row,col,N) && checkRows(Grid,row,col,N);
}

//CHECK IF THE CELL IS EMPTY
bool cellEmpty(std::vector<std::vector<int>>&Grid,int row,int col){
    if (Grid[row][col] == 0){
        return true;
    }return false;
}

bool isComplete(std::vector<std::vector<int>>&Grid){
    for (int i = 0; i < 9 ; i++){
        for (int j = 0; j < 9; j++){
            if(Grid[i][j] == 0){
                return false;
            }
        }
    }return true;
}

bool SolveSoduko(std::vector<std::vector<int>>&Grid){
    if(isComplete(Grid)){
        return true;
    }

    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            if(cellEmpty(Grid,row,col)){
                for(int n = 1; n <= 9; n++){
                    if(isValid(Grid,row,col,n)){
                        Grid[row][col] = n;
                        if(SolveSoduko(Grid)){
                            return true;
                        }
                        Grid[row][col] = 0;
                    }
                }return false;
            }
        }
    }
}

void printSolvedSoduko(std::vector<std::vector<int>>&Grid){

    std::cout << "--------------------------" << std::endl << "SOLVED!!" << std::endl << "--------------------------" << std::endl;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            std::cout << Grid[i][j] << " ";
        }std::cout << std::endl;
    }
}

int main()
{
//TEST CASES


//5 3 0 0 7 0 0 0 0
//6 0 0 1 9 5 0 0 0
//0 9 8 0 0 0 0 6 0
//8 0 0 0 6 0 0 0 3
//4 0 0 8 0 3 0 0 1
//7 0 0 0 2 0 0 0 6
//0 6 0 0 0 0 2 8 0
//0 0 0 4 1 9 0 0 5
//0 0 0 0 8 0 0 7 9



    int x;
    std::vector<std::vector<int>>Grid;
    for(int i = 0; i < 9; i++){
        std::vector<int>tempVec;
        for(int j = 0; j < 9; j++){
            std::cin >> x;
            tempVec.push_back(x);
        }
        Grid.push_back(tempVec);
    }

    if(SolveSoduko(Grid)){
        printSolvedSoduko(Grid);
    }
    else{
     std::cout << "NO SOLUTION";
    }
    return 0;
}
