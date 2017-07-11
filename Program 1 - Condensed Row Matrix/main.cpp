//Ryan Lachman 
//CS 361 - Feb 2 2016
//Project: Condensed Matrix

#include <iostream>
#include <list>
#include <fstream>
#include "matrix.h"

void MenuReturn(ifstream&, ifstream&, matrix& , matrix& );

int RowSize(ifstream& );
int FileColumn(ifstream& );

float File();
//float MatrixScope(ifstream& MatrixA);
float FileVector(ifstream& );

matrix FileMatrix(ifstream& );
matrix UserMatrix();

int main()
{
    matrix matA;
    matrix matB;

    ifstream MatrixA("matA.txt");
    ifstream MatrixB("matB.txt");

    MenuReturn(MatrixA, MatrixB, matA , matB);

    cout << endl;

    return 0;
}
void MenuReturn(ifstream& MatrixA, ifstream& MatrixB, matrix& matA, matrix& matB)
{
    char letterChoice;
    cout << endl <<"      ****************************    " << endl
         <<"      * A. Load Mat A from file  *    " << endl
         <<"      * B. Load Mat B from file  *    " << endl
         <<"      * C. Enter A from keyboard *    " << endl
         <<"      * D. Enter B from keyboard *    " << endl
         <<"      * E. Compute A = A+B       *    " << endl
         <<"      * F. Compute A = A*B       *    " << endl
         <<"      * G. Save A to file        *    " << endl
         <<"      * H. Save B to file        *    " << endl
         <<"      * I. Display A             *    " << endl
         <<"      * J. Display B             *    " << endl
         <<"      * K-Z. Quit                *    " << endl
         <<"      ****************************    " << endl << endl
         <<" Enter one of the above letter options: ";
    cin >> letterChoice;
    cout <<" **************************************** " << endl;
    switch(letterChoice)
        {
            case 'A':
            case 'a':
            {
                matA = FileMatrix(MatrixA);
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 'B':
            case 'b':
            {
                matB = FileMatrix(MatrixB);
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 'C':
            case 'c':
            {
                matA = UserMatrix();
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 'D':
            case 'd':
            {
                matB = UserMatrix();
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 'E':
            case 'e':
            {
                cout << " A = A+B" << endl <<endl;
                matA = matA.MatrixAdder(matA,matB);
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 6:
            {
                cout << " Under Construction....(was not able to solve)" << endl;
                break;
            }
            case 'G':
            case 'g':
            {
                cout << " Saved A to output file" << endl;
                matA.MatrixReturnOutA();
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 'H':
            case 'h':
            {
                cout << " Saved B to output file" << endl;
                matB.MatrixReturnOutB();
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 'I':
            case 'i':
            {
                cout << " Display A" << endl;
                matA.MatrixReturn();
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 'J':
            case 'j':
            {
                cout << " Display B" << endl;
                matB.MatrixReturn();
                MenuReturn(MatrixA, MatrixB, matA, matB);
                break;
            }
            case 'K':
            case 'k':
            {
                cout << " Quit";
                return;
            }
        }
}
matrix UserMatrix()
{
    int MatrixScope;
    cout << "Enter matrix size: ";
    cin >> MatrixScope;
    matrix UserM(MatrixScope);
    value * PointerValue;
    int PresentRow = 0;
    int PresentRowSize = 0;
    int InputValue;
    int InputColumn;
    for(int j = 0; j < MatrixScope; j++)
    {
        cout << "Enter quantity of (value,column) pairs: ";
        cin >> PresentRowSize;
        for(int i = 0; i < PresentRowSize; i++)
        {
            cout << "Enter value: ";
            cin>>InputValue;
            cout << "Enter column: ";
            cin>>InputColumn;
            PointerValue = new value(InputValue,InputColumn,PresentRow);
            int PresentColumn = PointerValue -> ReturnCol();
            UserM.ValueXadder(PointerValue,PresentColumn);
        }
        PresentRow++;
    }
    UserM.MatrixReturn();
    return UserM;
}
matrix FileMatrix(ifstream& MatrixA)
{
    int MatrixScope;
    MatrixA >> MatrixScope;
    cout << " Square matrix from text file is size: " << MatrixScope << endl <<endl;
    matrix FileM(MatrixScope);
    value * PointerValue;
    int PresentRow = 0;
    int PresentRowSize = 0;
    int InputValue;
    int InputColumn;
    for(int j = 0; j < MatrixScope; j++)
    {
        MatrixA >> PresentRowSize;
        for(int i = 0; i < PresentRowSize; i++)
        {
            MatrixA>>InputValue; MatrixA>>InputColumn;
            PointerValue = new value(InputValue,InputColumn,PresentRow);
            int PresentColumn = PointerValue -> ReturnCol();
            FileM.ValueXadder(PointerValue,PresentColumn);
        }
        PresentRow++;
    }
        FileM.MatrixReturn();
        return FileM;
}

