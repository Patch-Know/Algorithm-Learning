// tv.cpp -- methods for the Tv class (Remote methods are inline)
#include <iostream>
#include "tv.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV? "TV" : "DVD") << endl;
    }
}

inline void Remote::Show() const
{
    std::cout << "Mode: " << ((mode == Tv::TV)? "TV" : "DVD") << std::endl;
    if (mode == Tv::TV)
    std::cout << "State: " << ((state == Common)? "Commom" : "Interactive") << std::endl;
}

inline void Tv::set_remote_state(Remote & r) const {if(state==On) r.state ^= 1;} 


int main()
{
    Tv a(Tv::On,233);
    Tv b(Tv::Off);
    Remote r(Tv::TV,Remote::Common);
    r.Show();
    std::cout << std::endl;
    a.set_remote_state(r);
    r.Show();
    std::cout << std::endl;
    b.set_remote_state(r);
    r.Show();
    std::cout << std::endl;
    a.set_remote_state(r);
    r.Show();
    std::cout << std::endl;
    return 0;
}