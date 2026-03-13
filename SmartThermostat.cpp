#include
using namespace std;

class Thermostat
{
private:
int temperature;

public:
Thermostat()
{
temperature = 24;
}

void set_temperature(int t)
{
    if (t >= 16 && t <= 30)
    {
        temperature = t;
    }
    else
    {
        cout << "Invalid temperature!" << endl;
    }
}

int get_temperature()
{
    return temperature;
}
};

int main()
{
Thermostat room;

int new_temp;
cin >> new_temp;

room.set_temperature(new_temp);

cout << "Current temperature: " << room.get_temperature() << endl;

return 0;
}

