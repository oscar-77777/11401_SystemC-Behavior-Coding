#include "List.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./main <input_file>\n";
        return 1;
    }

    ifstream fin(argv[1]);
    ofstream fout("RESULT");

    if (!fin) {
        cout << "Error: cannot open input file.\n";
        return 1;
    }

    List A;
    fin >> A;
    fout << "Original List A:\n" << A;

    List B = A;
    List C; C = A;
    List D(A);
    fout << "List B (copy constructor):\n" << B;
    fout << "List C (assignment):\n" << C;
    fout << "List D (copy):\n" << D;

    List E = B + C;
    fout << "After E = B + C:\n" << E;

    ++E;
    fout << "After ++E:\n" << E;

    E++;
    fout << "After E++:\n" << E;

    E += D;
    fout << "After E += D:\n" << E;

    --E;
    fout << "After --E:\n" << E;

    E--;
    fout << "After E--:\n" << E;

    fout.close();
    fin.close();

    cout << "All operations completed. Results written to RESULT.\n";
    return 0;
}
