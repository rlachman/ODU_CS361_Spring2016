#ifndef targer_H
#define target_H

using namespace std;

class target
{
    public:

        target(string c, int X_target, int Y_target)
        {
            x = X_target;
            y = Y_target;
            category = c;
            cout << c << " found traveling at coordinates: " << "(" << x << ", " << y << ")" << endl
                                     << "**************************************************" << endl;
        }

        void display()
    {
        cout << category << " target, position " << x << ", " << y << endl;
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

    int signal_Strength_find()
    {
        return signal_Strength;
    }

    private:
    double x,y;
    string category;
    int signal_Strength = 10;
};

#endif // TARGET_H
