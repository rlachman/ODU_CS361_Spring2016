//Ryan Lachman 
//CS 361 - March 18 2016
//Project: Smart Dust

//The purpose of this program is to simulate a military exercise involving 
//disbursement of sensors from an airplane that will then detect a varying level of objetives 
//below it. Such objectives involve detecting the size, shape, and movement of an object.
//As well as levels of radiation in the area. All this data is then stored and sent back to HQ. 

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <list>
#include <random>
#include <vector>
#include "dust.h"
#include "flechette.h"
#include "homeBase.h"
#include "bundle.h"
#include "target.h"


using namespace std;

void generate_dust(list<dust>& dust_list)
{
    int stepper = 0,
    i = 0,
    X_dust = 50,
    Y_dust = 100;

    default_random_engine random_production(time(NULL));

    // Dust distributed uniformly between 35 & 65

    uniform_real_distribution<double> dust_Dispersal(35.0,65.0);

    // Generate three types of dust. Switch case for each type of dust
    while(i < 99)
    {
        switch(stepper)
        {
            case 0: // Case 0 for Acoustic dust
                {
                    dust Airdropped_D("Acoustic ",X_dust,Y_dust);
                    dust_list.push_back(Airdropped_D);
                    stepper++;
                    break;
                }
            case 1: // Case 1 for Impact
                {
                    dust Airdropped_D("Impact   ",X_dust,Y_dust);
                    dust_list.push_back(Airdropped_D);
                    stepper++;
                    break;
                }
            case 2: // Case 2 for Radiation
                {
                    dust Airdropped_D("Radiation",X_dust,Y_dust);
                    dust_list.push_back(Airdropped_D);
                    stepper++;
                    break;
                }
            case 3: // Case 4 for Thermal
                {
                    dust Airdropped_D("Thermal  ",X_dust,Y_dust);
                    dust_list.push_back(Airdropped_D);
                    stepper = 0;
                    break;
                }
            default:
                {
                    break;
                }

        }
        // Distribute x co-ordinate of the dust uniformly
        X_dust = dust_Dispersal(random_production);
        // Decrement y co-ordinate
        Y_dust--;
        i++;
    }
}

void print_generated_dust(list<dust>& dust_list,ofstream& dropped_Dust_output)
{

    // Print the dust generated in the file

    list<dust>::iterator dust_Iteration;

    cout << "******************************" << endl;
    cout << "Commencing Smart Dust Mission!" << endl;
    cout << "******************************" << endl;

    cout << "**************************************" << endl;
    cout << "Airdrop of dust and flechette cargo..." << endl;
    cout << "**************************************" << endl;

    dust_Iteration = dust_list.begin();

    while(dust_Iteration != dust_list.end())
    {
        dust_Iteration -> display();
        dropped_Dust_output <<
        dust_Iteration -> X_find() << " " <<
        dust_Iteration -> Y_find() << endl;
        dust_Iteration++;
    }
}

void generate_flechette(vector<flechette>& flechette_Trajectory)
{
    int X_flechette = 49,
        Y_flechette = 99;

    uniform_real_distribution <double> flechette_Dispersal_X(40,60);

    uniform_real_distribution <double> flechette_Dispersal_Y(5,15);

    default_random_engine production(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        flechette Airdropped_F(X_flechette,Y_flechette);
        flechette_Trajectory.push_back(Airdropped_F);
        X_flechette = flechette_Dispersal_X(production);
        Y_flechette = Y_flechette - flechette_Dispersal_Y(production);
    }
}

void print_generated_flechette(vector<flechette>& flechette_Trajectory, ofstream& dropped_Flechette_output)
{
    vector<flechette>::iterator flechette_Iteration;

    flechette_Iteration = flechette_Trajectory.begin();

    while (flechette_Iteration != flechette_Trajectory.end())
    {
        dropped_Flechette_output <<
        flechette_Iteration -> X_find() << " " <<
        flechette_Iteration -> Y_find() << endl;
        flechette_Iteration++;
    }
}

void move_target(vector<target>& passing_Target)
{
    int X_target = 0,
        Y_target = 50;

    uniform_real_distribution<double> target_Dispersal_X(1,3);

    uniform_real_distribution<double> target_Dispersal_Y(-2,2);

    default_random_engine production(time(NULL));

    cout << "**********************" << endl;
    cout << "Searching the area...." << endl;
    cout << "**********************" << endl;

    for(int i = 0; i < 100; i++)
    {
        target Insurgent("Insurgent", X_target ,Y_target);
        X_target += target_Dispersal_X(production);
        Y_target += target_Dispersal_Y(production);
        passing_Target.push_back(Insurgent);
    }
}

void print_target(vector<target>& passing_Target,ofstream& passing_Target_output)
{
    vector<target>::iterator target_Iteration;

    target_Iteration = passing_Target.begin();

    while (target_Iteration != passing_Target.end())
    {
        passing_Target_output <<
        target_Iteration->X_find() << " " <<
        target_Iteration->Y_find() << endl;
        target_Iteration++;
    }
}

void target_dust_talk(vector<target>& passing_Target,list<dust>& dust_list,list<dust>& dust_Pinged)
{

    // Euclidian distance is used
    // Target talks to the dust.

    vector<target>::iterator target_Iteration;
    list<dust>::iterator dust_Pinged_Iteration;
    list<dust>::iterator dust_Iteration;

    target_Iteration = passing_Target.begin();

    float X_dust = 0,
          Y_dust = 0,
          X_find_target = 0,
          Y_find_target = 0,
          span = 0,
          X_span = 0,
          Y_span = 0,
          signal_Strength = 0;


    cout << "*******************************" << endl;
    cout << "The size of the dust list is: " << dust_list.size() << endl;
    cout << "*******************************" << endl;

    cout << "***********************" << endl;
    cout << "Dust receiving data...." << endl;
    cout << "***********************" << endl;

    for(int i = 0; i < 100; i++)
    {
        X_find_target = target_Iteration->X_find();
        Y_find_target = target_Iteration->Y_find();
        dust_Iteration = dust_list.begin();

        while(dust_Iteration != dust_list.end())//dust_list.size(); j++)
        {
            X_dust = dust_Iteration->X_find();
            Y_dust = dust_Iteration->Y_find();
            X_span = X_find_target - X_dust;
            Y_span = Y_find_target - Y_dust;

            span = abs(sqrt(pow(X_span,2.0) + pow(Y_span,2.0)));

            if(span <= 5)
            {
                cout << dust_Iteration -> object_Find() << " dust at coords " << "(" <<
                        X_dust << ", " <<
                        Y_dust << ")" << " has received data on an " <<
                        target_Iteration -> object_Find() << " at coords " << "(" <<
                        X_find_target << "," <<
                        Y_find_target << ")";
                        signal_Strength = (target_Iteration -> signal_Strength_find()) / (span * span);
                cout << " with signal strength: " << signal_Strength << endl;
                cout << "********************************************************************************************************************" << endl;
                dust_Iteration -> signal_Fixed(signal_Strength);
                dust_Pinged.push_back(*dust_Iteration);
            }
            dust_Iteration++;
        }
        target_Iteration++;
    }
}

void dust_flechette_talk(list<dust>& dust_Pinged,list<bundle>& bundle_List,vector<flechette>& flechette_Trajectory)
{

    string dust_Category;

    float signal_Strength_dust,
          X_dust_nearby = 0,
          X_flechette_nearby = 0,
          Y_dust_nearby = 0,
          Y_flechette_nearby = 0,
          X_span_nearby = 0,
          Y_span_nearby = 0,
          span_Flechette = 0;


    cout << "*****************************" << endl;
    cout << "Flechettes receiving data...." << endl;
    cout << "*****************************" << endl;

    list<dust>::iterator dust_Pinged_Iteration;
    vector<flechette>::iterator flechette_Iteration;

    dust_Pinged_Iteration = dust_Pinged.begin();
    while(dust_Pinged_Iteration != dust_Pinged.end())
    {
        dust_Category = dust_Pinged_Iteration->object_Find();
        signal_Strength_dust = dust_Pinged_Iteration->singal_Find();
        X_dust_nearby = dust_Pinged_Iteration->X_find();
        Y_dust_nearby = dust_Pinged_Iteration->Y_find();

        // Loop to check flechettes in range

        flechette_Iteration = flechette_Trajectory.begin();

        while(flechette_Iteration != flechette_Trajectory.end())
        {
            X_flechette_nearby = flechette_Iteration->X_find();
            Y_flechette_nearby = flechette_Iteration->Y_find();
            X_span_nearby = X_dust_nearby - X_flechette_nearby;
            Y_span_nearby = Y_dust_nearby - Y_flechette_nearby;

            // Used Euclidian distance to calculate.

            span_Flechette = abs(sqrt(pow(X_span_nearby,2.0)+pow(Y_span_nearby,2.0)));

                if(span_Flechette <= 10)
                {
                    cout << "Flechette at coords " << "(" <<
                    X_flechette_nearby << ", " <<
                    Y_flechette_nearby << ")" << " received signal from dust at coords " << "(" <<
                    X_dust_nearby << ", " <<
                    Y_dust_nearby << ")" << " data being bundled for home base." << endl
                    << "***********************************************************************************************************" << endl;

                    bundle Bundle(X_flechette_nearby,Y_flechette_nearby,X_dust_nearby,Y_dust_nearby,dust_Category,signal_Strength_dust);
                    bundle_List.push_back(Bundle);
                }


        // Increment flechette
        flechette_Iteration++;
        }
        // Increment dust_Pinged_Iteration
        dust_Pinged_Iteration++;
    }
}

void bundle_homeBase(list<bundle>& bundle_List)
{
    cout << "*************************************************" << endl;
    cout << "Information Bundles transmitting to home base...." << endl;
    cout << "*************************************************" << endl;

    homeBase homeBase_Main;
    list<bundle>::iterator bundle_Iteration;
    bundle_Iteration = bundle_List.begin();

    // Iterate through the list and send the bundle to headquarter.

    while(bundle_Iteration != bundle_List.end())
    {
        homeBase_Main.bundle_Add(*bundle_Iteration);
        cout << "Bundle information sending..." << endl;
        cout << "*****************************" << endl;
        bundle_Iteration++;
    }

    cout << "*********************************************************" << endl;
    cout << "Information received by home base.....printing data found" << endl;
    cout << "*********************************************************" << endl;

    homeBase_Main.print_homeBase_bundles();
    homeBase_Main.print_bundles_to_file();

    cout << "**************************************************************************" << endl;
    cout << "Smart Dust Mission Complete! Now how to deal with this insurgent...hmmmmmm" << endl;
    cout << "**************************************************************************" << endl;

}


int main()
{
    // File Stream to output Dropped_Dust,Target_Information and Dropped_Flechette

    ofstream dropped_Dust_output, dropped_Flechette_output, passing_Target_output;
    dropped_Dust_output.open("Dropped_Dust.txt");
    dropped_Flechette_output.open("Dropped_Flechette.txt");
    passing_Target_output.open("Target_Information.txt");

    list<dust> dust_list;
    vector<flechette> flechette_Trajectory;
    vector<target> passing_Target;
    list<dust> dust_Pinged;
    list<bundle> bundle_List;
    list<bundle>::iterator bundle_Iteration;

    // Generate Dust and Print Generated Dust
    generate_dust(dust_list);
    print_generated_dust(dust_list,dropped_Dust_output);

    // Generate Flechette and Print Generated Flechette
    generate_flechette(flechette_Trajectory);
    print_generated_flechette(flechette_Trajectory,dropped_Flechette_output);

    // Move target and Print Target Movement History
    move_target(passing_Target);
    print_target(passing_Target,passing_Target_output);

    // Target talks to Dust
    target_dust_talk(passing_Target,dust_list,dust_Pinged);

    // Dust talks to Flechette
    dust_flechette_talk(dust_Pinged,bundle_List,flechette_Trajectory);

    // Transfer bundles to Head Quarter
    bundle_homeBase(bundle_List);

    // Plot it on gnuplot
    system("gnuplot commandfile.txt");

    return 0;
}
