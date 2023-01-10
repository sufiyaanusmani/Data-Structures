// Name: Sufiyaan Usmani
// Roll No: 21K-3195
// Section: BCS-3J

#include <iostream>
#include <fstream>
using namespace std;

// Arguments to this program: input_file.txt output_file.txt
// Folder where this program is stored must also contain input_file.txt

int main(int argc, char **argv){
    ifstream fin;
    ofstream fout;
    char ch;

    fin.open(argv[1], ios::in);
    if (!fin){
        cout << "Error: Can not open input_file.txt. Please make sure that input_file.txt already exists" << endl;
    }
    else{
        fout.open(argv[2], ios::out);
        ch = fin.get();
        while (!fin.eof()){
            fout.put(ch);
            ch = fin.get();
        }
        fin.close();
        fout.close();
        cout << "Written to output_file.txt successfully" << endl;
    }
    return 0;
}
