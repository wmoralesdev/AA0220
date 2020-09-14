// Weather forecast
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

// Create enum with weathers
enum weather {SUNNY, WINDY, RAINY, THUNDERSTORM, DROUGHT};

string enumToString(weather w);

int main(void) {
    // Required: get random seed, different with every execution
    srand(time(NULL));
    
    // Random quantity to generate - could be more or less
    int n = 20;

    // Vector to store rand generated weathers
    vector<weather> forecast;

    // Push n random weathers
    for(int i = 0; i < n; i++)
        forecast.push_back(weather(rand() % 4));

    // Weather to forecast - can be user input
    weather desired = WINDY;
    int aux = 0;

    // Calculating odds
    for(weather w : forecast)
        if(w == WINDY)
            aux++;
        
    cout << n << " weathers generated" << endl;
    cout << aux << " are " << enumToString(desired) << endl;
    cout << "The odds of a " << enumToString(desired) << " are " << ((double(aux) / forecast.size()) * 100) << "%" << endl;
}

// Converting enum to proper string representation
string enumToString(weather w) {
    switch (w)
    {
    case WINDY: 
        return "WINDY";
    case SUNNY:
        return "SUNNY";
    case RAINY:
        return "RAINY";
    case THUNDERSTORM:
        return "THUNDERSTORM";
    case DROUGHT:
        return "DROUGHT";
    default:
        return "";
    }
}