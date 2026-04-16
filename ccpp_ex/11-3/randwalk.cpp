// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    unsigned long steps_sum;
    unsigned long steps_min;
    unsigned long steps_max;
    double target;
    double dstep;
    int times=0;
    bool is_first =true;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout << "Enter test times: ";
        if (!(cin >> times) || times <=0)
            break;
        //display distance and step size
        cout << "Target Distance: " << target << ", Step size: " << dstep
        <<", Test times: " << times <<endl;
        for (int i=0;i<times;i++){
        while (result.magval() < target)
        {
            //cout<< steps <<": "<<result<<endl;
            direction = rand() % 360;
            step.reset(dstep, direction, VECTOR::Vector::POL);
            result = result + step;
            steps++;
        }
        steps_sum+=steps;
        if(is_first){ steps_max=steps_min=steps;is_first=false;}
        else{
            if(steps>steps_max) steps_max=steps;
            if(steps<steps_min) steps_min=steps;
        }
        // cout<< steps <<": "<<result<<endl;
        // cout << "After " << steps << " steps, the subject "
        //     "has the following location:\n";
        // cout << result << endl;
        // result.polar_mode();
        // cout << " or\n" << result << endl;
        // cout << "Average outward distance per step = "
        //     << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        }
        //display3
        //cout<< "test times = " <<times<<endl;
        cout<< "max steps = " <<steps_max<<endl;
        cout<< "min steps = " <<steps_min<<endl;
        cout<< "average steps = " <<(double)steps_sum/times<<endl;
        steps_sum=0;
        times=0;
        is_first=true;
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0; 
}
