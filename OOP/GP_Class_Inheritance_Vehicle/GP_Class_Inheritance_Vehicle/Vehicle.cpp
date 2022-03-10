#include <iostream>																									

using namespace std;

class Vehicle
{
public:
	enum E_GEAR
	{
		P = 0,
		ONE,
		TWO,
		THREE,
		FOUR,
		R,
		N,
		D
	};
protected:
	E_GEAR _gear;
	float _speed;
	int _seats;

public:
	Vehicle(int seats = 4)
	{
		_gear = E_GEAR::N;
		_speed = 0;
		_seats = seats;

		cout << "Vehicle [" << this << "]" << endl;
	}
	~Vehicle()
	{
		cout << "~Vehicle [" << this << "]" << endl;
	}
	void Accel()
	{
		_speed++;
	}
	void Break()
	{
		_speed--;
	}
	void SetGear(E_GEAR gear)
	{
		_gear = gear;
	}
	void Display()
	{
		cout << "############## Display " << endl;
		cout << "[" << this << "]'s Gear : " << _gear << endl;
		cout << "[" << this << "]'s Speed : " << _speed << endl;
		cout << "[" << this << "]'s Seats : " << _seats << endl;

	}
};

class C_Bicycle : public Vehicle
{
public:
	C_Bicycle(int seats = 4)
	{
		_gear = E_GEAR::N;
		_speed = 0;
		_seats = seats;

		cout << "Bicycle [" << this << "]" << endl;
	}
	~C_Bicycle()
	{
		cout << "~Bicycle [" << this << "]" << endl;
	}
};

class C_Motorcycle : public Vehicle
{
private:
	int _engine;
public:
	C_Motorcycle(int seats = 1, int engine = 1500)
	{
		_gear = E_GEAR::N;
		_speed = 0;
		_seats = seats;
		_engine = engine;

		cout << "Motorcycle [" << this << "]" << endl;
	}
	~C_Motorcycle()
	{
		cout << "~Motorcycle [" << this << "]" << endl;
	}
	void ShowEngine()
	{
		cout << "Motorcycle [" << this << "]'s engine : "
			<< _engine << endl;
	}
};

class C_Bus : public Vehicle
{
private:
	int _engine;
public:
	C_Bus(int seats = 12, int engine = 3000)
	{
		_gear = E_GEAR::N;
		_speed = 0;
		_seats = seats;
		_engine = engine;

		cout << "Bus [" << this << "]" << endl;
	}
	~C_Bus()
	{
		cout << "~Bus [" << this << "]" << endl;
	}
	void ShowEngine()
	{
		cout << "Bus [" << this << "]'s engine : "
			<< _engine << endl;
	}
};

class C_Truck : public Vehicle
{
private:
	int _engine;
	float _carry;
public:
	C_Truck(int seats = 2, int engine = 5000, int carry = 5)
	{
		_gear = E_GEAR::N;
		_speed = 0;
		_seats = seats;
		_engine = engine;
		_carry = carry;

		cout << "Truck [" << this << "]" << endl;
	}
	~C_Truck()
	{
		cout << "~Truck [" << this << "]" << endl;
	}
	void ShowEngine()
	{
		cout << "Truck [" << this << "]'s engine : "
			<< _engine << endl;
	}
	void ShowCarryingCapacity()
	{
		cout << "Truck [" << this << "]'s CarryingCapacity : "
			<< _carry << endl;
	}
};

void VehicleMain()
{
	Vehicle myVehicle = Vehicle(2);
	myVehicle.Accel();
	myVehicle.Break();
	myVehicle.SetGear(Vehicle::E_GEAR::P);
	myVehicle.Display();

	C_Bicycle myBicycle = C_Bicycle(1);
	myBicycle.Accel();
	myBicycle.Break();
	myBicycle.SetGear(Vehicle::E_GEAR::P);

	C_Motorcycle Motorcycle = C_Motorcycle(1);
	Motorcycle.Accel();
	Motorcycle.Break();
	Motorcycle.SetGear(Vehicle::E_GEAR::P);
	Motorcycle.ShowEngine();

	C_Bus myBus = C_Bus(1);
	myBus.Accel();
	myBus.Break();
	myBus.SetGear(Vehicle::E_GEAR::P);
	myBus.ShowEngine();

	C_Truck myTruck = C_Truck(1);
	myTruck.Accel();
	myTruck.Break();
	myTruck.SetGear(Vehicle::E_GEAR::P);
	myTruck.ShowEngine();
	myTruck.ShowCarryingCapacity();

}

void main()
{
	VehicleMain();
}