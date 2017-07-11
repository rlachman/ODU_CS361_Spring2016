#ifndef dust_H
#define dust_H

using namespace std;


class dust
{
    public:

    dust(string c, int X_position, int Y_position)
    {
        x = X_position;
        y = Y_position;
        category = c;
    }

    void display()
    {
        cout << category << " dust at coordinates: " << "(" << x << ", " << y << ")" << endl
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

    string object_Find()
    {
        return category;
    }

    void signal_Fixed(float signal)
    {
        signal_Strength = signal;
    }

    float singal_Find()
    {
        return signal_Strength;
    }

    private:
    double x,y;
    string category;
    int distance = 6;
    float signal_Strength;

};

#endif // DUST_H
