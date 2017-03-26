#include <iostream>
#include <string>
using namespace std;

class Robot_part {
 protected:
  string name;
  int model_number;
  double cost;
  string description;
  string image_filename;
};

//
//	ROBOT PARTS
//

class Head : public Robot_part {
 private:
  double power;
  double iq;
};

class Locomotor : public Robot_part {
 private:
  double max_power;
};

class Torso : public Robot_part {
 private:
  int battery_compartments;
  int max_arms;
}; 

class Battery : public Robot_part {
 private:
  double power_available;
  double max_energy;
};

class Arm : public Robot_part {
 private:
  double max_power;
};

int main() {

}



