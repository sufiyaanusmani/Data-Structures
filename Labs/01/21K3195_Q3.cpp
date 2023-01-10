// Name: Sufiyaan Usmani
// Roll No: 21K-3195
// Section: BCS-3J

#include <iostream>
using namespace std;

int main(){
    int num, i, sum;
    while (1){
        cout << "Enter a number (-1 to exit): ";
        cin >> num;
        if (num == -1){
            break;
        }
        else{
            sum = 0;
            cout << "Factors of " << num << ": ";
            for (i = 1; i <= num; i++){
                if (num % i == 0){
                    cout << "  " << i;
                    sum += i;
                }
            }
            cout << endl << "Sum of factors: " << sum << endl << endl;
        }
    }
    return 0;
}
