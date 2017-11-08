#ifndef PATH_PLANNING_PREDICTIONS_H
#define PATH_PLANNING_PREDICTIONS_H

#include "Track.h"
#include <vector>
#include <chrono>
#include <map>

using namespace std;
class Vehicle {
	public:
	    vector <vector <double>> vehStates; 
	    double as, ad;
	    double vs, vd;

	    Vehicle() : vehStates(6,vector<double>(0.0)) {}
	    ~Vehicle() {}
	    vector<vector<double>> getState();
};

class Predictions {
	public:
	  map <int, Vehicle> vehicles;
	  vector<vector<double>> current_sf; 
	  Predictions()  {}
	  ~Predictions() {}
	  void update (Track track, vector<vector<double>>sensor_fusion);
	  double GetEpsi (Track track, double vx, double vy, double s, double d);
	  vector<int> getVehList();
	  double GetVehSinT(int vehID, double t);
	  vector<int> CarsInLane(double car_s, double car_d);
};

#endif