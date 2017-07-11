#ifndef flechette_H
#define flechette_H

using namespace std;

class flechette
{
    public:

    flechette(int X_position, int Y_position)
    {
        x = X_position;
        y = Y_position;
        cout << "Flechette at coordinates: " << "(" << x << ", " << y << ")" << endl
                                << "**************************************" << endl;
    }

    void display()
    {
        cout << "The flechette at coordinates " << "(" << x << ", " << y << ")" << endl
                                    << "**************************************" << endl;
    }

     int X_find()
    {
        return x;
    }

    int Y_find()
    {
        return y;
    }

    private:
    double x,y;
};

#endif // FLECHETTE_H
