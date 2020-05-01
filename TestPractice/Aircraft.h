#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Aircraft
{
public:
	int id, maxAltitude;
	std::string model;
	bool publicTransport, medicalEmergencies, leisureTime, military;
public:
	Aircraft(int id = 0, std::string model = "-") { this->id = id, this->model = model; publicTransport = medicalEmergencies = leisureTime = military = false; };
	friend std::ostream& operator<<(std::ostream& stream, const Aircraft& aircraft);
	virtual void output(std::ostream& stream) const = 0;
};

class Helicopter : public Aircraft {
public:
	//int maxAltitude = 12;
	bool isPrivate;
public:
	Helicopter(int id = 0, std::string model = "-", bool isPrivate = true);
	void output(std::ostream& stream)const override;
};

std::ostream& operator<<(std::ostream& stream, const Helicopter& aircraft);
std::istream& operator>>(std::istream& stream, Helicopter& aircraft) ;

class Plane : public Aircraft {
public:
	bool isPrivate;
	//int maxAltitude = 26;
	std::string mainWings;
public:
	Plane(int id = 0, std::string model = "-", std::string mainWings = "monoplane", bool isPrivate = true);
	void output(std::ostream& stream)const override;
};

std::ostream& operator<<(std::ostream& stream, const Plane& aircraft);
std::istream& operator>>(std::istream& stream, Plane& aircraft);

class HotAirBaloon : public Aircraft {
public:
	//int maxAltitude = 21;
	int weightLimit;
public:
	HotAirBaloon(int id = 0, std::string model = "-", int weightLimit = 0);
	void output(std::ostream& stream)const override;
};

std::ostream& operator<<(std::ostream& stream, const HotAirBaloon& aircraft);
std::istream& operator>>(std::istream& stream, HotAirBaloon& aircraft);


