#include "Aircraft.h"

using namespace std;

vector<Aircraft*> createAircrafts() {
	vector<Aircraft*> result;
	result.push_back(new Helicopter{ 1,"modelA","1" });
	result.push_back(new Helicopter{ 1,"modelA1","1" });
	result.push_back(new Helicopter{ 1,"modelA2","1" });
	result.push_back(new Plane{ 1,"modelA","monoplane","1" });
	result.push_back(new Plane{ 1,"modelA","monoplane","1" });
	result.push_back(new Plane{ 1,"modelA","monoplane","1" });
	result.push_back(new Plane{ 1,"modelA","biplane","1" });
	result.push_back(new Plane{ 1,"modelA","biplane","1" });
	result.push_back(new HotAirBaloon{ 1,"modelA4"});
	result.push_back(new HotAirBaloon{ 1,"modelA1"});
	result.push_back(new HotAirBaloon{ 1,"modelA0"});
	result.push_back(new HotAirBaloon{ 1,"modelA2"});
	result.push_back(new HotAirBaloon{ 1,"modelA3"});
	return result;
}

void printMenu() {
	cout << "1. Add Helicopter" << endl;
	cout << "2. Add Plane" << endl;
	cout << "3. Add Hot Air Baloon" << endl;
	cout << "4. Display based on activity" << endl;
	cout << "5. Display based on maximum altitude" << endl;
}

int main() {
	vector<Aircraft*> Aircrafts = createAircrafts();
	string input;
	printMenu();
	while (getline(cin, input)) {
		try {
			if (input == "1") {
				Aircraft* newAircraft;
				Helicopter* heli = new Helicopter{};
				cin >> *heli;
				newAircraft = heli;
				Aircrafts.push_back(newAircraft);
			}
			else if (input == "2") {
				Aircraft* newAircraft;
				Plane* plane = new Plane{};
				cin >> *plane;
				newAircraft = plane;
				Aircrafts.push_back(newAircraft);
			}
			else if (input == "3") {
				Aircraft* newAircraft;
				HotAirBaloon* hot = new HotAirBaloon{};
				cin >> *hot;
				newAircraft = hot;
				Aircrafts.push_back(newAircraft);
			}
			else if (input == "4") {
				string activity;
				getline(cin, activity);
				ofstream file(activity);
				if (activity == "public transportation") {
					for (const Aircraft* aircraft : Aircrafts) {
						if (aircraft->publicTransport)
							file << *aircraft << endl; 
					}
				} else if (activity == "medical emergencies") {
					for (const Aircraft* aircraft : Aircrafts) {
						if (aircraft->medicalEmergencies)
							file << *aircraft << endl;
					}
				}
				else if(activity == "leisure time") {
					for (const Aircraft* aircraft : Aircrafts) {
						if (aircraft->leisureTime)
							file << *aircraft << endl;
					}
				}
				else if(activity == "military") {
					for (const Aircraft* aircraft : Aircrafts) {
						if (aircraft->military)
							file << *aircraft << endl;
					}
				}
			}
			else if (input == "5") {
				int maxAltitude;
				cin >> maxAltitude;
				ofstream file("da");
				for (const Aircraft* aircraft : Aircrafts) {
					if (aircraft->maxAltitude > maxAltitude)
						file << *aircraft << endl;
				}
			}
		}
		catch (const exception& ex) {
			cout << ex.what() << endl;
		}
		printMenu();
	}
}