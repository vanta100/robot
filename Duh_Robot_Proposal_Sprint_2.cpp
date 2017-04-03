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
  void get_power_and_compartment(int bc, int ma) {
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
  void get_powers(double p, double e) {
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
  
 
 public:
  Robot_model(Robot_part _head, Robot_part _torso, Robot_part _battery, Robot_part _locomotor, Robot_part _arm) : head{_head}, torso{_torso}, battery{_battery}, locomotor{_locomotor}, arm{_arm} {}
  void robot_info();
  double cost();
  double max_speed();
  double max_battery_life();
};

class Shop { 
 public:
  void create_new_robot_part(Robot_part part) { parts.push_back(part);}
  void create_new_robot_model();
  void create_new_customer();
  void create_new_sales_associate();
  void create_new_order();
 private:
  //Order order;
  //Customer customer;
  //Sales_associate sales_associate;
  vector<Robot_part> parts;
  vector<Robot_model> model;
};
 
  

class Controller {
  public:
    //Controller();
    void execute();
    void create_new_robot_model();	
    //void execute_cmd(int cmd);
  private:
   Shop shop;
   
  
};

void Controller::execute() {

shop.create_new_robot_part(Head("Head",1,1.00,"lol"));
shop.create_new_robot_part(Torso("Torso",1,1.00,"lol"));
shop.create_new_robot_part(Battery("Battery",1,1.00,"lol"));
shop.create_new_robot_part(Locomotor("Locomotor",1,1.00,"lol"));
shop.create_new_robot_part(Arm("Arm",1,1.00,"lol"));

}

void Controller::create_new_robot_model() {
Head head("Head",1,1.00,"lol");
Torso torso("Torso",1,1.00,"lol");
Battery battery("Battery",1,1.00,"lol");
Locomotor locomotor("Locomotor",1,1.00,"lol");
Arm arm("Arm",1,1.00,"lol");
Robot_model robot_model(head, torso, battery, locomotor, arm);
}

int main() {
Controller controller;
controller.execute();

}



