#include "Aircraft.h"

Helicopter::Helicopter(int id, std::string model, bool isPrivate) : Aircraft{ id, model }
{
	this->isPrivate = isPrivate;
	this->military = this->medicalEmergencies = this->publicTransport = true;
	if (isPrivate)
		this->leisureTime = true;
	this->maxAltitude = 12;
}

void Helicopter::output(std::ostream& stream)const
{
	stream << this->id << ',' << this->model << ',' << this->isPrivate;
	// return stream;
}

Plane::Plane(int id, std::string model, std::string mainWings, bool isPrivate) : Aircraft{ id, model }
{
	if (mainWings != "monoplane" && mainWings != "biplane")
		throw std::exception((std::string{ "A plane should be either monoplane or biplane not: " } + mainWings).c_str());
	this->mainWings = mainWings;
	this->isPrivate = isPrivate;
	this->military = this->publicTransport = true;
	if (isPrivate)
		this->leisureTime = true;
	this->maxAltitude = 26;
}

void Plane::output(std::ostream& stream)const
{
	stream << this->id << ',' << this->model << ',' << this->mainWings << ',' << this->isPrivate;
}

HotAirBaloon::HotAirBaloon(int id, std::string model, int weightLimit) : Aircraft{ id, model }
{
	this->weightLimit = weightLimit;
	this->maxAltitude = 21;
}

void HotAirBaloon::output(std::ostream& stream)const
{
	stream << this->id << ',' << this->model << ',' << this->weightLimit;
}

std::ostream& operator<<(std::ostream& stream, const Aircraft& aircraft)
{
	// TODO: insert return statement here
	//stream << aircraft.id << ',' << aircraft.model;
	aircraft.output(stream);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Helicopter& aircraft)
{
	// TODO: insert return statement here
	stream << aircraft.id << ',' << aircraft.model << ',' << aircraft.isPrivate;
	return stream;
}

std::vector<std::string> split(std::string string, char delimiter) {
	std::vector<std::string> result;
	std::stringstream ss(string);
	std::string arg;
	while (std::getline(ss, arg, delimiter)) {
		result.push_back(arg);
	}
	return result;
}

std::istream& operator>>(std::istream& stream, Helicopter& aircraft)
{
	// TODO: insert return statement here
	std::string line;
	std::getline(stream, line);
	std::vector<std::string> arguments;
	arguments = split(line, ',');
	aircraft.id = std::stoi(arguments[0]);
	aircraft.model = arguments[1];
	aircraft.isPrivate = stoi(arguments[2]);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Plane& aircraft)
{
	// TODO: insert return statement here
	stream << aircraft.id << ',' << aircraft.model << ',' << aircraft.mainWings << ',' << aircraft.isPrivate;
	return stream;
}

std::istream& operator>>(std::istream& stream, Plane& aircraft)
{
	// TODO: insert return statement here
	std::string line;
	std::getline(stream, line);
	std::vector<std::string> arguments;
	arguments = split(line, ',');
	aircraft.id = std::stoi(arguments[0]);
	aircraft.model = arguments[1];
	aircraft.mainWings = arguments[2];
	aircraft.isPrivate = stoi(arguments[3]);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const HotAirBaloon& aircraft)
{
	// TODO: insert return statement here
	stream << aircraft.id << ',' << aircraft.model << ',' << aircraft.weightLimit;
	return stream;
}

std::istream& operator>>(std::istream& stream, HotAirBaloon& aircraft)
{
	// TODO: insert return statement here
	std::string line;
	std::getline(stream, line);
	std::vector<std::string> arguments;
	arguments = split(line, ',');
	aircraft.id = std::stoi(arguments[0]);
	aircraft.model = arguments[1];
	return stream;
}
