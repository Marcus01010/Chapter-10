#include<iostream>
using namespace std;

enum SpotStatus
{
EMPTY,
OCCUPIED,
RESERVED
};

char status_to_char(SpotStatus s)
{
if (s == EMPTY)
{
return 'E';
}
else if (s == OCCUPIED)
{
return 'O';
}
else
{
return 'R';
}
}

void print_garage_map(const SpotStatus garage[3][4])
{
cout << "Garage Map:" << endl;

for (int floor = 0; floor < 3; floor++)
{
    for (int spot = 0; spot < 4; spot++)
    {
        cout << status_to_char(garage[floor][spot]) << " ";
    }
    cout << endl;
}

cout << endl;
}

int count_empty_spots(const SpotStatus garage[3][4])
{
int empty_count = 0;

for (int floor = 0; floor < 3; floor++)
{
    for (int spot = 0; spot < 4; spot++)
    {
        if (garage[floor][spot] == EMPTY)
        {
            empty_count++;
        }
    }
}

return empty_count;
}

class ParkingGarage
{
private:
SpotStatus garage[3][4];
int parked_count[3];

bool is_valid_index(int floor, int spot)
{
    return (floor >= 0 && floor < 3 && spot >= 0 && spot < 4);
}
public:
ParkingGarage()
{
for (int floor = 0; floor < 3; floor++)
{
for (int spot = 0; spot < 4; spot++)
{
garage[floor][spot] = EMPTY;
}
}

    for (int floor = 0; floor < 3; floor++)
    {
        parked_count[floor] = 0;
    }

    garage[0][0] = RESERVED;
}

bool set_spot_status(int floor, int spot, SpotStatus new_status)
{
    if (!is_valid_index(floor, spot))
    {
        cout << "Invalid location!" << endl;
        return false;
    }

    if (floor == 0 && spot == 0)
    {
        cout << "Spot (0,0) is permanently reserved!" << endl;
        return false;
    }

    SpotStatus current_status = garage[floor][spot];

    if (new_status == OCCUPIED)
    {
        if (current_status == EMPTY)
        {
            garage[floor][spot] = OCCUPIED;
            parked_count[floor]++;
            return true;
        }
        else
        {
            cout << "Cannot park here!" << endl;
            return false;
        }
    }

    if (new_status == EMPTY)
    {
        if (current_status == OCCUPIED)
        {
            garage[floor][spot] = EMPTY;
            parked_count[floor]--;
            return true;
        }
        else
        {
            cout << "Cannot leave from here!" << endl;
            return false;
        }
    }

    if (new_status == RESERVED)
    {
        if (current_status == EMPTY)
        {
            garage[floor][spot] = RESERVED;
            return true;
        }
        else
        {
            cout << "Cannot reserve here!" << endl;
            return false;
        }
    }

    return false;
}

SpotStatus get_spot_status(int floor, int spot)
{
    return garage[floor][spot];
}

int get_parked_count(int floor)
{
    if (floor < 0 || floor > 3)
    {
        return 0;
    }

    return parked_count[floor];
}

void print_map()
{
    print_garage_map(garage);
}

int total_empty_spots()
{
    return count_empty_spots(garage);
}
};

int main()
{
ParkingGarage garage_system;

int n;
cin >> n;

for (int i = 0; i < n; i++)
{
    char op;
    int floor, spot;

    cin >> op >> floor >> spot;

    if (op == 'P')
    {
        garage_system.set_spot_status(floor, spot, OCCUPIED);
    }
    else if (op == 'L')
    {
        garage_system.set_spot_status(floor, spot, EMPTY);
    }
    else if (op == 'R')
    {
        garage_system.set_spot_status(floor, spot, RESERVED);
    }
    else
    {
        cout << "Invalid operation!" << endl;
    }
}

garage_system.print_map();

cout << "Parked Count Per Floor:" << endl;
for (int floor = 0; floor < 3; floor++)
{
    cout << "Floor " << floor << ": " << garage_system.get_parked_count(floor) << endl;
}

cout << endl;

cout << "Total empty spots: " << garage_system.total_empty_spots() << endl;

return 0;
}
