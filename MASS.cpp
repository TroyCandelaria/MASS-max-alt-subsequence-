#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

class MASS{

private:
    std::vector<std::vector<int>> massTable;
public:
    MASS(int SIZE){
        massTable.resize(SIZE);
        for(int i = 0; i<SIZE; i++){
            massTable[i].resize(SIZE);
        }
    }
    int findMass(std::vector<int> S, const int SIZE){
        //trivial case j-1,=1
        //only one or two number
        //return max
        if(SIZE < 3){return std::max(S[0],S[SIZE-1]);}
        else{
            //i=j-s when accessing S to flip table and to make iterative solution have sequential access
            for(int s=0; s<SIZE; s++){
                for(int j=s; j<SIZE; j++){
                    if(j==j-s){massTable[s][j] = S[j];}
                    else{
                        massTable[s][j] = max3(massTable[s-1][j-1], massTable[s-1][j], checkK(s, j, SIZE));
                    }
                }
            }
        }
        return massTable[SIZE-1][SIZE-1];
    }
    //checks for max value considering all K values
    int checkK(int s, int j, const int SIZE){
        int max = 0;
        for(int k=j-s+1; k<j; k++){
            int temp = massTable[k-1-(j-s)][k-1] + massTable[j-2-(k-1)][j] - massTable[0][k];
            if(max < temp){
                max = temp;
            }
        }
        return max;
    }
    //returns the max of 3 ints
    int max3(int a, int b, int c){
        int temp = std::max(a, b);
        return std::max(temp, c);

    }
};

int main(){

    //get values from console
    std::vector<int> input;
    int temp;
    while(std::cin >> temp){
        input.push_back(temp);
    }

    MASS m = MASS(input.size());
    std::cout<< "the maximum MASS value is: " << m.findMass(input, input.size());

}
