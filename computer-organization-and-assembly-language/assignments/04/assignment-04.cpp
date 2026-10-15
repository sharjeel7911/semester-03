#include <iostream>
using namespace std;

int main() {
    short int arr1[2][2] = { {1,2}, {3,4} };
    short int arr2[2][2] = { {5,6}, {7,8} };
    int result[2][2] = { 0 };

    cout << "Array 1" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) cout << arr1[i][j] << "  ";
        cout << endl;
    }

    cout << endl << endl << "Array 2" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) cout << arr2[i][j] << "  ";
        cout << endl;
    }

    __asm
    {
        movd mm2, arr2             
        movd mm3, arr2 + 4        
        punpcklwd mm2, mm3        

        movd mm0, arr1            
        pmaddwd mm0, mm2          
        movd result, mm0

        psrlq mm2, 32
           
        movd mm0, arr1                
        pmaddwd mm0, mm2            
        movd result + 4, mm0

        movd mm2, arr2            
        movd mm3, arr2 + 4     
        punpcklwd mm2, mm3
      
        movd mm0, arr1 + 4      
        pmaddwd mm0, mm2        
        movd result + 8, mm0

        psrlq mm2, 32 
      
        movd mm0, arr1 + 4           
        pmaddwd mm0, mm2         
        movd result + 12, mm0

        { emms }
    }

    cout << endl << "Result" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) cout << result[i][j] << "  ";
        cout << endl;
    }
    return 0;
}