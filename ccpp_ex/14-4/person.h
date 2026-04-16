#include <iostream>
#include <string>
#include <iomanip>

namespace PersonSet
{
    using namespace std;
    class Person
    {
        private:
            string fname;
            string lname;
        public:
            void Show() const { cout<< fname << ", " << lname;}
            Person(const char * f = "none",const char * l = "none"):fname(f),lname(l) {}
    };
    class Gunslinger : virtual public Person
    {
        private:
            int gunnum;
            double triggertime;
        public:
            double Draw() const {return triggertime;}
            void Show() const
            {
                cout << "Name: ";
                Person::Show();
                cout <<endl;
                cout<< "Gun number: " << gunnum << endl
                 << "Trigger time:  " << triggertime <<endl;
            }
            Gunslinger( int num, double time,const char * f = "none",const char * l = "none") : Person(f,l),
            gunnum(num),triggertime(time) {}

    };
    class PokerPlayer : virtual public Person
    {
        public:
            PokerPlayer(const char * f = "none",const char * l = "none") :Person(f,l) {}
            int Draw() const {srand(time(0));return rand()%52+1;}
            void Show() const
            {
                cout << "Name: ";
                Person::Show();
                cout <<endl;
            }
    };
    class BadDude : public Gunslinger,public PokerPlayer
    {
        public:
            double Gdraw() const {return Gunslinger::Draw();}
            double Cdraw() const {return PokerPlayer::Draw();}
            BadDude(int num, double time,const char * f = "none",const char * l = "none")
            : Person(f,l),Gunslinger(num,time,f,l)
            {}
    };
}