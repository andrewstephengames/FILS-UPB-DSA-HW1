#include "journey.h"

JourneyThroughTheDesert::JourneyThroughTheDesert() {
    w = nrOasis = consumption = 0;
    aux = 1;
    oasis.water = 0;
    oasis.distanceToNext = 0;
}

void JourneyThroughTheDesert::readInput() {
    fstream fin("input.txt");
    fstream fout("output.txt");

    if (!fin.is_open())
    {
        cerr << "ERROR: cannot open input file: "
             << "input.txt" << endl;
        return;
    }

    fin >> nrOasis;
    
    fin >> consumption;
    
    for (int i = 0; i < nrOasis; i++)
    {
        fin >> oasis.water >> oasis.distanceToNext;
        queueInit.enqueue(oasis);
    }

    fin.close();
    fout.close();
}

void JourneyThroughTheDesert::execute() {
    bool errorHandle = 1; // handle errors, can't make the error functions work, aside from the file open
    //not global as we handle all the errors in this function

    ofstream fout("output.txt");

    if (consumption <= 0)
    {
        cerr << "ERROR: No consumption rate or negative value for it, impossible case!" << endl;
        return;
    }

    if (nrOasis < 2)
    {
        cerr << "ERROR: No road, need more than one oasis!" << endl;
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
            cerr << "ERROR: Distance too great or not enough water, can't do it this way" << endl;
            aux++;
            execute();
            return;
        }
        w += oasis.water;

        if (1.0 * (100 * w / consumption) < oasis.distanceToNext)
        {
            break;
        }
        else
        {
            w = w - oasis.distanceToNext / (100 / consumption);
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
