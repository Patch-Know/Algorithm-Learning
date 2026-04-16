// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
#include <vector>
#include <random>
const int MIN_PER_HR = 60;

int newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
// setting things up
    // std::srand(std::time(0));    //  random initializing of rand()
    
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter the number of ATMs: ";
    int atm=1;
    cin >> atm;
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    std::vector<Queue> qarr(atm);
    for (int i = 0;i<atm;i++){
        qarr[i].setsize(qs);
    }

    cout << "Enter the number of simulation hours: ";
    int hours;              //  hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    cin >> perhour;
    double perminute;    //  average time between arrivals
    perminute = (double)perhour/MIN_PER_HR;

    Item temp;              //  new customer data
    long turnaways = 0;     //  turned away by full queue
    long customers = 0;     //  joined the queue
    long served = 0;        //  served during the simulation
    long sum_line = 0;      //  cumulative line length
    std::vector<long> wtarr(atm,0); 
    long line_wait = 0;     //  cumulative time in line
    int number;


// running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (number=newcustomer(perminute))  // have newcomer
        {
            // if (line.queuecount()<=line2.queuecount()){
            //     if (line.isfull())
            //         turnaways++;
            //     else
            //     {
            //         customers++;
            //         temp.set(cycle);    // cycle = time of arrival
            //         line.enqueue(temp); // add newcomer to line
            //     }
            // }else{
            //     if (line2.isfull())
            //         turnaways++;
            //     else
            //     {
            //         customers++;
            //         temp.set(cycle);    // cycle = time of arrival
            //         line2.enqueue(temp); // add newcomer to line
            //     }
            // }
            for (int i=0;i<number;i++){
                int min=qarr[0].queuecount();
                int qmin=0;
                for (int j=1;j<atm;j++){
                    if(qarr[j].queuecount()<min){
                        min=qarr[j].queuecount();
                        qmin=j;
                    } 
                }
                if (qarr[qmin].isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    qarr[qmin].enqueue(temp); // add newcomer to line
                }
            }

        }
        // if (wait_time <= 0 && !line.isempty())
        // {
        //     line.dequeue (temp);      // attend next customer
        //     wait_time = temp.ptime(); // for wait_time minutes
        //     line_wait += cycle - temp.when();
        //     served++;
        // }
        // if (wait_time > 0)
        //     wait_time--;
        for (int i = 0;i<atm;i++){
            if (wtarr[i] <= 0 && !qarr[i].isempty())
            {
                qarr[i].dequeue (temp);      // attend next customer
                wtarr[i] = temp.ptime(); // for wtarr[i] minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wtarr[i] > 0)
                wtarr[i]--;
        }
        
        for (int i = 0;i<atm;i++){
            sum_line+=qarr[i].queuecount();
        }
    }

// reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit /atm<< endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
int newcustomer(double x)
{
    // 静态随机数引擎和分布对象（避免重复构造）
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::poisson_distribution<> dist(1.0); // 初始占位，后续重置参数
    if (x <= 0.0) {
        return 0;   // 平均到达率为0时，每分钟到达人数恒为0
    }
    dist.param(std::poisson_distribution<>::param_type(x));
    return dist(gen);
}
