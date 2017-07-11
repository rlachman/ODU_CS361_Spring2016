#include <iomanip>
using namespace std;

class value
{
    public:
        value(){}
        value(int Value, int Column,int Row)
        {
             RowX = Row;
             ValueX = Value;
             ColumnX = Column;
        }
        ~value(){}
        void ReturnValueCount()
        {
            cout << " Row " << RowX << " (" << ValueX << "," << ColumnX << ") ";
        }
        void PrintValueFromFile(ofstream& FromFile)
        {
            FromFile << " Row " << RowX << " (" << ValueX << "," << ColumnX << ") ";
        }
        int ReturnRow()
        {
            return RowX;
        }
        int ReturnCol()
        {
            return ColumnX;
        }
        int ReturnVal()
        {
            return ValueX;
        }
    friend class matrix;
    private:
        int RowX = 0;
        int ValueX = 0;
        int ColumnX = 0;

};
