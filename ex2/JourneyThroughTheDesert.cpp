#include <iostream>
#include <fstream>
#include "myQueue.h"
using namespace std;

struct Oasis
{
    int water;
    int distanceToNext;
};

class JourneyThroughTheDessert
{
private:
    Oasis oasis;
    Queue<Oasis> queueInit;
    Queue<Oasis> queueAux;
    float w;
    int nrOasis, consuption, aux; // aux to see if we can complete the road or not, before computing

public:
    void readInput()
    {
        fstream fin("input.txt");
        fstream fout("output.txt");

        if (!fin.is_open())
        {
            cerr << "Error opening input file: "
                 << "input.txt" << endl;
            return;
        }

        
        fin >> nrOasis;
       
        fin >> consuption;
     
        for (int i = 0; i < nrOasis; i++)
        {
            fin >> oasis.water >> oasis.distanceToNext;
            queueInit.enqueue(oasis);
        }

        fin.close();
        fout.close();
    }

    void execute()
    {
        bool errorHandle = 1; // handle errors, can't make the error functions work, aside from the file open
        //not global as we handle all the errors in this function

        ofstream fout("output.txt");

        if (consuption <= 0)
        {
            fout << "No consuption rate or negative value for it, impossible case!" << endl;
            return;
        }

        if (nrOasis < 2)
        {
            fout << "No road, need more than one oasis!" << endl;
            return;
        }

        queueAux = queueInit;

        for (int i = 0; i < aux; i++)
            queueAux.enqueue(queueAux.dequeue());

        while (queueAux.getSize() != 0)
        {
            oasis = queueAux.dequeue();

            if (oasis.distanceToNext < 1 || oasis.water < 1)
            {
                fout << "Distance to great or not enogh water, can't do it this way" << endl;
                aux++;
                execute();
                return;
            }

            w += oasis.water;

            if (1.0 * (100 * w / consuption) < oasis.distanceToNext)
            {
                break;
            }
            else
            {
                w = w - oasis.distanceToNext / (100 / consuption);
            }
        }
        
        if (queueAux.getSize() == 0)
            fout << aux << " is the oasis from where we can start our journey" << endl;
        else
        {
            fout << aux << "is not good as a start point" << endl;
            aux++;
            execute();
        }

        fout.close();
    }

    JourneyThroughTheDessert()
    {
        w = nrOasis = consuption = 0;
        aux = 1;
        oasis.water = 0;
        oasis.distanceToNext = 0;
    }
};

int main()
{
    JourneyThroughTheDessert journey;
    journey.readInput();
    journey.execute();

    return 0;
}
