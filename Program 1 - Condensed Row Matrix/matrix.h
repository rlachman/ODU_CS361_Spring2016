#include "row.h"
#include <iomanip>
using namespace std;

class matrix
{
public:
matrix(){}
    matrix(int j)
    {
        for(int i = 0; i < j; i++)
        {
            Ypointer = new row;
            RowList.push_back(*Ypointer);
        }
    }
    ~matrix(){}
    void ValueXadder(value * Xpointer, int k)
    {
        if(k <= RowList.size())
        {
            RowIterator = RowList.begin();
            for(int i = 0; i < k; i++)
            {
                RowIterator++;
            }
            RowIterator -> ValueXadder(Xpointer);
        }
        else
        {
            cout<<"Not enough rows"<<endl;
        }
    }
    void RowAdder()
    {
        Ypointer = new row;
        RowList.push_back(*Ypointer);
    }
    void MatrixReturn()
    {
        int i = 0;
        RowIterator = RowList.begin();
        for(int i = 0; i < RowList.size(); i++)
        {
            RowIterator -> RowReturn();
            RowIterator++;
        }
    }
    void MatrixReturnOutA()
    {
        ofstream FromFile("OutMatA.txt");
        int i = 0;
        RowIterator = RowList.begin();
        for(int i = 0; i < RowList.size(); i++)
        {
            RowIterator -> RowReturnF(FromFile);
            RowIterator++;
        }
    }
    void MatrixReturnOutB()
    {
        ofstream FromFile("OutMatB.txt");
        int i = 0;
        RowIterator = RowList.begin();
        for(int i = 0; i < RowList.size(); i++)
        {
            RowIterator -> RowReturnF(FromFile);
            RowIterator++;
        }
    }
    void AssignMatrixSize(int s)
    {
        MatrixSize = s;
    }
    int MatrixSizeReturn()
    {
        return MatrixSize;
    }
    void RowListBegin()
    {
        RowIterator = RowList.begin();
    }
    matrix MatrixAdder(const matrix& A, const matrix& B)
    {
        if(A.RowList.size() != B.RowList.size())
        {
            cout << "Must be equal dimension square matrices";
            return 0;
        }
        matrix Sum(A.RowList.size());
        value * sum;
        value ValueX;
        value ValueY;
        list<row>tempA = A.RowList;
        list<row>::iterator IteratorA;
        IteratorA = tempA.begin();
        list<row>tempB = B.RowList;
        list<row>::iterator IteratorB;
        IteratorB = tempB.begin();
        int ControlA = 0; int ControlB = 0;
        for( int i = 0; i < A.RowList.size(); i++)
        {
            row Acolumn = *IteratorA; row Bcolumn = *IteratorB;
            list<value>::iterator ValueIteratorA = Acolumn.ValueList.begin();
            list<value>::iterator ValueIteratorB = Bcolumn.ValueList.begin();
            ValueX = *ValueIteratorA; ValueY = *ValueIteratorB;
            for( int n = 0; n < Acolumn.ValueList.size() and n < Bcolumn.ValueList.size(); n++ )
            {
                ValueX = *ValueIteratorA; ValueY = *ValueIteratorB;
                if(ValueX.ReturnCol() == ValueY.ReturnCol() and ValueX.ReturnRow() == ValueY.ReturnRow())///
                {
                    ValueX.ReturnValueCount();
                    cout << " + ";
                    ValueY.ReturnValueCount();
                    cout << " = ";
                    sum = new value((ValueX.ReturnVal()+ValueY.ReturnVal()),(ValueX.ReturnCol()),n) ;
                    Sum.ValueXadder(sum,i);
                    //cout << " = ";
                    sum->ReturnValueCount();
                    cout << endl;
                    ValueIteratorA++;
                    ValueIteratorB++;
                    ControlA++; ControlB++;
                }
                if(ControlA == Acolumn.ValueList.size() and ControlB != Bcolumn.ValueList.size())
                {
                    ValueY = *ValueIteratorB;
                    ValueY.ReturnValueCount();
                    cout << " + ";
                    cout << "             ";
                    sum = new value((ValueY.ReturnVal()),(ValueY.ReturnCol()),n);
                    Sum.ValueXadder(sum,i);
                    cout << " = ";
                    sum -> ReturnValueCount();
                    cout << endl;
                    ControlB++;
                }
                if(ControlB == Bcolumn.ValueList.size() and ControlA != Acolumn.ValueList.size())
                {
                    ValueX = *ValueIteratorA;
                    ValueX.ReturnValueCount();
                    cout << " + ";
                    cout << "             ";
                    sum = new value((ValueX.ReturnVal()),(ValueX.ReturnCol()),n) ;
                    Sum.ValueXadder(sum,i);
                    cout << " = ";
                    sum -> ReturnValueCount();
                    cout << endl;
                    ControlA++;
                }
                if(ValueIteratorA -> ReturnRow() != ValueIteratorB -> ReturnRow() and
                   ValueIteratorA -> ReturnRow() < ValueIteratorB -> ReturnRow() and
                   ValueIteratorA != Acolumn.ValueList.end() and
                   ValueIteratorB != Bcolumn.ValueList.end())
                {
                    ValueX = *ValueIteratorA;
                    ValueX.ReturnValueCount();
                    cout << " + ";
                    cout << "     0       ";
                    sum = new value((ValueX.ReturnVal()),(ValueX.ReturnCol()),n) ;
                    Sum.ValueXadder(sum,i);
                    cout << " = ";
                    sum -> ReturnValueCount(); cout << endl;
                    ControlA++;
                    ValueIteratorA++;
                }
                if(ValueIteratorB->ReturnRow() < ValueIteratorA->ReturnRow()  and
                   ValueIteratorA->ReturnRow() != ValueIteratorB->ReturnRow() and
                   ValueIteratorA != Acolumn.ValueList.end() and
                   ValueIteratorB != Bcolumn.ValueList.end())
                {
                    ValueY = *ValueIteratorB;
                    sum = new value((ValueY.ReturnVal()),(ValueY.ReturnCol()),n) ;
                    Sum.ValueXadder(sum,i);
                    cout << "     0       ";
                    cout << " + ";
                    sum -> ReturnValueCount();
                    cout << " = ";
                    sum -> ReturnValueCount();
                    cout << endl;
                    ControlB++;
                    ValueIteratorB++;
                }
            }
            ControlA = 0;
            ControlB = 0;
            IteratorA++;
            IteratorB++;
        }
        return Sum;
    }
private:
    row * Ypointer;
    list<row>RowList;
    list<row>::iterator RowIterator;
    int MatrixSize = 0;
};


