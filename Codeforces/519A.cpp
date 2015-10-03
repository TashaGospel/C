#include <iostream>
using namespace std;

int main() {
    int white = 0, black = 0;
    char cur;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            cin >> cur;
            switch (cur) {
                case 'Q': white += 9; break;
                case 'q': black += 9; break;
                case 'R': white += 5; break;
                case 'r': black += 5; break;
                case 'B': white += 3; break;
                case 'b': black += 3; break;
                case 'N': white += 3; break;
                case 'n': black += 3; break;
                case 'P': white++; break;
                case 'p': black++; break;
            }
        }

    if (white > black) cout << "White";
    else if (black > white) cout << "Black";
    else cout << "Draw";
}
