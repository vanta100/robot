#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Robot_part {
 protected:
  string name;
  int model_number;
  double cost;
  string description;
  string image_filename;
  vector<Robot_part> parts;
 public:
  Robot_part(string _name, int _model_number, double _cost, string _description) : name(_name), model_number(_model_number), cost(_cost),
                                                                                  description(_description) {}
};

//
//	ROBOT PARTS
//

class Head : public Robot_part {
 private:
  double power;
 public:
  Head(string _name, int _model_number, double _cost, string _description) : Robot_part(_name,_model_number,_cost,_description) {}
  void get_power(double p) {
   power = p;
  }
  void test(Head h) { 
   parts.push_back(h);
  }

};

class Locomotor : public Robot_part {
 private:
  double max_power;
 public:
  Locomotor(string _name, int _model_number, double _cost, string _description) : Robot_part(_name,_model_number,_cost,_description) {}
  void get_power(double p) {
   max_power = p;
  }
};

class Torso : public Robot_part {
 private:
  int battery_compartments;
  int max_arms;
 public:
  Torso(string _name, int _model_number, double _cost, string _description) : Robot_part(_name,_model_number,_cost,_description) {}
  void get_power(int bc, int ma) {
   max_arms = ma;
   battery_compartments = bc;
  }
}; 

class Battery : public Robot_part {
 private:
  double power_available;
  double max_energy;
 public:
  Battery(string _name, int _model_number, double _cost, string _description) : Robot_part(_name,_model_number,_cost,_description) {}
  void get_power(double p, double e) {
   power_available = p;
   max_energy = e;
  }
};

class Arm : public Robot_part {
 private:
  double max_power;
 public:
  Arm(string _name, int _model_number, double _cost, string _description) : Robot_part(_name,_model_number,_cost,_description) {}
  void get_power(double p) {
   max_power = p;
  }
};

class Robot_model {
 private:
  string name;
  int model_number;
  Robot_part torso;
  Robot_part head;
  Robot_part locomotor;
  Robot_part arm;
  Robot_part battery;
  vector<Robot_part> Robot_parts;
 
 public:
  void add_robot_part(Robot_part part) {Robot_parts.push_back(part);} ;
  void robot_info();
  double cost();
  double max_speed();
  double max_battery_life();
};

/*class Controller {
  public:
    Controller (Robot_part& rbot) : robot_part(rbot) { }   NOT SURE HOW TO IMPLEMENT YET
    void cli();
    void execute_cmd(int cmd);
  private:
    Robot_part& robot_part;
  
};*/

int main() {

}



