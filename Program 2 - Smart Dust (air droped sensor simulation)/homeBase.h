#ifndef homeBase_H
#define homeBase_H
#include <list>
#include "bundle.h"
#include <fstream>


class homeBase
{
    public:

        homeBase() {}

    void bundle_Add(bundle temp)
    {
        bundle_List.push_back(temp);
    }

    void determine_target()
    {
        float regular = 0, amount = 0;

        int stepper = 0;

        bundle_Iteration = bundle_List.begin();
        while(bundle_Iteration != bundle_List.end())
        {
            amount += bundle_Iteration -> signal_Strength_find();
            stepper++;
            bundle_Iteration++;
        }

        regular = amount / stepper;

        cout << "regular signal strength: " << regular;

    }

    void print_homeBase_bundles()
    {
        bundle_Iteration = bundle_List.begin();
        while(bundle_Iteration != bundle_List.end())
        {
            bundle_Iteration -> display();
            bundle_Iteration++;
        }
    }

    void print_bundles_to_file()
    {
        ofstream bundle_Output_a;
        bundle_Output_a.open("Flechette_being_pinged.txt");
        bundle_Iteration  = bundle_List.begin();

            while(bundle_Iteration != bundle_List.end())
            {
                bundle_Output_a << bundle_Iteration -> X_flechette_Find() << " " << bundle_Iteration->Y_flechette_Find() << endl;
                bundle_Iteration++;
            }
        ofstream bundle_Output_b;
        bundle_Output_b.open("Dust_being_pinged.txt");
        bundle_Iteration  = bundle_List.begin();

        while(bundle_Iteration != bundle_List.end())
            {
                bundle_Output_b << bundle_Iteration->X_span_Find() << " " << bundle_Iteration->Y_span_Find() << endl;
                bundle_Iteration++;
            }
    }

    protected:
    private:
        list<bundle> bundle_List;
        list<bundle>::iterator bundle_Iteration;

};

#endif // homeBase_H
