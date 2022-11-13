/*
Author: Avani Mehrotra
Date:11/12/22
Concept: Analyze the data

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <math.h>
#include <sstream>
#include <cstring>
#include<algorithm>
#include <cctype>
#include <regex>


using namespace std;

struct Drill
{
    double bitDepth, rateOfPenetration, hookLoad, differentialPressure, weightOnBit;
    int drillBitID;
    string drillBitName;
    long double time;//, price;
};

struct RemoveDelimiter
{
  bool operator()(char c)
  {
    return (c =='\r' || c =='\t' || c == ' ' || c == '\n');
  }
};

void Display(Drill data[], int numElements)
{

    cout << fixed << setprecision(2);
    cout << "BIT_DEPTH  RATE_OF_PENETRATION  HOOK_LOAD  DIFFERENTIAL_PRESSURE  WEIGHT_ON_BIT  DRILL_BIT_ID   DRILL_BIT_NAME     TIME" << endl;
    for(int i = 1; i < numElements; i++)
    {
        cout << setw(9) << data[i].bitDepth << setw(21) << data[i].rateOfPenetration << setw(11) << data[i].hookLoad;
        cout << setw(23) << data[i].differentialPressure << setw(15) << data[i].weightOnBit << setw(14) << data[i].drillBitID
        << setw(9) << data[i].drillBitName << setw(9) << data[i].time << setw(8) << endl;//data[i].price << endl;
    }
    cout << endl;

}


int main()
{
    //Variables
    string fileName;
    ifstream inFS;
    string info;
    vector<string> counter;
    int numRecords = 0;
    const int NUM_ELMTS = 1000000;


    //read in the file
    cout << "Enter input file: ";
    getline(cin, fileName);
    inFS.open(fileName);
    if (!inFS.is_open())
    {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        return 0;
    }
    cout << endl;

    //get size of file
    if(inFS.is_open())
    {
        while(getline(inFS, info))
        {
            counter.push_back(info);
            numRecords++;

        }
        inFS.close();
    }

    //array
    Drill * bitSetup = new Drill[NUM_ELMTS];

    string title;
    inFS.open(fileName);
    if(inFS.is_open())
    {
        for(int i = 0; i < numRecords; i++)
        {
            if(i == 0)
            {
                getline(inFS, title);
                i++;
            }
            inFS >> bitSetup[i].bitDepth;
            inFS >> bitSetup[i].rateOfPenetration;
            inFS >> bitSetup[i].hookLoad;
            inFS >> bitSetup[i].differentialPressure;
            inFS >> bitSetup[i].weightOnBit;
            inFS >> bitSetup[i].drillBitID;
            getline(inFS, bitSetup[i].drillBitName);
        }
        inFS.close();
    }




    double price = 0.00;
    int change = 0;

    for(int i = 0; i < numRecords; i++)
    {
        bitSetup[i].time = bitSetup[i].bitDepth / bitSetup[i].rateOfPenetration;
    }


/*
    for(int i = 0; i < numRecords - 1; i++)
    {
        //bitSetup[i].price = ;
        if(bitSetup[i].drillBitID != bitSetup[i + 1].drillBitID)
        {
            if(bitSetup[i].drillBitName == "Buzz Drilldrin")
            {
                bitSetup[i].price += 5000 + (1.5 * (bitSetup[i].bitDepth - bitSetup[change].bitDepth));
                change = i;
            }
            else if(bitSetup[i].drillBitName == "Astro Bit")
            {
                for(int j = change; j < i; j++)
                {
                    time += bitSetup[j].time;
                }
                bitSetup[i].price += 3000 + (1 * (bitSetup[i].bitDepth - bitSetup[change].bitDepth)) + (1500 * time);
                change = i;

            }
            else if(bitSetup[i].drillBitName == "Apollo")
            {
                for(int j = change; j < i; j++)
                {
                    time += bitSetup[j].time;
                }
                bitSetup[i].price += 1000 + (4 * (bitSetup[i].bitDepth - bitSetup[change].bitDepth)) + (2500 * time);
                change = i;
            }
            else if(bitSetup[i].drillBitName == "ChallengDriller")
            {
                bitSetup[i].price += 10000;
                change = i;
            }
            //
        }
    }
*/
  Display(bitSetup, numRecords);

    //remove whitespace
    for(int i = 0; i < numRecords; i++)
    {
        remove(bitSetup[i].drillBitName.begin(), bitSetup[i].drillBitName.end(), '\t');
        remove(bitSetup[i].drillBitName.begin(), bitSetup[i].drillBitName.end(), ' ');
       // string word = bitSetup[i].drillBitName;
        //word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());

    //    word.erase(remove_if( word.begin(), word.end(),
     //[](char c){ return (c =='\r' || c =='\t' || c == ' ' || c == '\n');}), word.end() );

        //cout << bitSetup[i].drillBitName;
    }

     long double time = 0.00;
     int loop1, loop2, loop3, loop4 = 0;
    cout << fixed << setprecision(2);
    for(int i = 1; i < numRecords; i++)
    {
        time = time + bitSetup[i].time;
        if(bitSetup[i].drillBitID != bitSetup[i + 1].drillBitID)
        {
            if(bitSetup[i].drillBitName[0] == 'B')
            {
                price = 5000 + (1.5 * (bitSetup[i].bitDepth - bitSetup[change].bitDepth));
                if(loop1 > 0)
                    price -= 5000;
                cout << "Price of BuzzDrilldrin: $" << price << " and takes " << time << " hours to drill." << endl;
                change = i;
                time = 0.00;
                loop1++;
              // bitSetup[i].price = 0;
            }
            else if(bitSetup[i].drillBitName[1] == 's')
            {
                price = 3000 + (bitSetup[i - 1].bitDepth - bitSetup[change].bitDepth) + (1500 * time);
                if(loop1 > 0)
                    price -= 3000;
                cout << "Price of AstroBit is: $" << price << " and takes " << time << " hours to drill."<< endl;
                change = i;
                time = 0.00;
                loop2++;
            }
            else if(bitSetup[i].drillBitName[1] == 'p')
            {
                price = 1000 + (4 * (bitSetup[i - 1].bitDepth - bitSetup[change].bitDepth)) + (2500 * time);
                if(loop1 > 0)
                    price -= 1000;z
                }
                cout << "Price of Challenger is: $10000 and takes " << time << " hours to drill." << endl;
                change = i;
                time = 0.00;
                loop4++;
            }
            //
        }
    }

    //cout << bitSetup.price;

    delete [] bitSetup;

    return 0;
}

