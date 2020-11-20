#include <iostream>

int lo = 0;
int hi = 5;
int j = 0;

int main(){
    for (int i = lo; i <= hi; i++) {  
        for(int k = j - 1; k >= 0; --k){
            std::cout << k;
        }
        ++j;
        std::cout << '\n';
    }
    system("pause");
}