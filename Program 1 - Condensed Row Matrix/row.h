#include "value.h"
#include <iomanip>
using namespace std;

class row
{
    friend class matrix;
    public:
        row(){}
        ~row(){}
    void ValueXadder(value * Xpointer)
    {
        ValueList.push_back(*Xpointer);
    }
    void advance_iterator()
    {
        ValueIterator++;
    }
    void RowReturn()
    {
        ValueIterator = ValueList.begin();
        while(ValueIterator!=ValueList.end())
        {
            ValueIterator->ReturnValueCount();
            ValueIterator++;
        }
        cout<<endl<<endl;
    }
    void RowReturnF(ofstream& FromFile)
    {
        ValueIterator = ValueList.begin();
        while(ValueIterator!=ValueList.end())
        {
            ValueIterator->PrintValueFromFile(FromFile);
            ValueIterator++;
        }
        cout<<endl;
    }
    friend class matrix;
    private:
        list<value>ValueList;
        list<value>::iterator ValueIterator;
};
