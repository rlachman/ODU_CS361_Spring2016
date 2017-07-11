#ifndef bundle_H
#define bundle_H


class bundle
{
    public:

        bundle(float X_Flech, float Y_Flech, float X_span, float Y_span, string dust_Cat, float strength_signal)
        {
            X_flechette_nearby = X_Flech;
            Y_flechette_nearby = Y_Flech;
            X_dust = X_span;
            Y_dust = Y_span;
            dust_Category = dust_Cat;
            signal_Strength = strength_signal;
        }

        float signal_Strength_find()
        {
            return signal_Strength;
        }

        void display()
        {
            cout << "Bundle information received by home base included: " << '\n' << "A flechette at coords " << "(" <<
            X_flechette_nearby << "," <<
            Y_flechette_nearby << ")" << " received data from " <<
            dust_Category << "dust located at coords " << "(" <<
            X_dust << ","<<
            Y_dust << ")." << '\n'
            << "The signal was received with a strength of " << signal_Strength << "." << endl;
            cout << "*****************************************************************************************" << endl;
        }

        float X_flechette_Find()
        {
            return X_flechette_nearby;
        }

         float Y_flechette_Find()
        {
            return Y_flechette_nearby;
        }

        float X_span_Find()
        {
            return X_dust;
        }

         float Y_span_Find()
        {
            return Y_dust;
        }

    protected:
    private:
        float X_flechette_nearby;
        float Y_flechette_nearby;
        float X_dust;
        float Y_dust;
        string dust_Category;
        float signal_Strength;

};

#endif // bundle_H
