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
  Robot_part(string _name, int _model_number, double _cost, string _description) : name{_name}, model_number{_model_number}, cost{_cost},
                                                                                  description{_description} {}

};

//
//	ROBOT PARTS
//

class Head : public Robot_part {
 private:
  double power;
 public:
  Head(string _name, int _model_number, double _cost, string _description, double _power) : Robot_part(_name,_model_number,_cost,_description), power{_power} {}


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
  void create_new_robot_model(Robot_model model) {models.push_back(model);}
  void create_new_customer();
  void create_new_sales_associate();
  void create_new_order();
 private:
  //Order order;					Things commented out at this point are not being used for this sprint
  //Customer customer;
  //Sales_associate sales_associate;                         
  vector<Robot_part> parts;
  vector<Robot_model> models;
};
 
  

class Controller {
  public:
    void execute(); //kind of like a view class
    void create_new_robot_model();
    void create_new_robot_parts();	
  private:
   Shop shop;
};

void Controller::execute() {
 int choice;
 cout << "What would you like to do?\n\n"<<"(0) Create new robot parts" <<'\n'<< "(1) Create new robot model\n";
 cin >> choice;

 if (choice == 0) {
  create_new_robot_parts();
 }
 
 else if(choice == 1) {
  create_new_robot_model();
 }
 
 else {
  cout << "Invalid input\n" << "Exiting Program...\n";
  exit(0);
 }
 }

void Controller::create_new_robot_parts() {
string name, input;
int model_number, get_out; //get_out is to break the loop

double cost;
string description;
cout << "\n\n (0) quit\n (1) head\n (2) torso\n (3) battery\n (4) locomotor\n (5) arm\n Enter one of the choices: ";
cin >> get_out;
while(get_out != 0) {
 switch(get_out) {
  case(1): {
   
  }
  case(2): {
  
  }
  case(3): {
   
  }
  case(4): {
   
  }
  case(5): {

  }
  default: {
   cout<<"\nWould you like to continue adding parts?\n\n (0) quit\n (1) head\n (2) torso\n (3) battery\n (4) locomotor\n (5) arm\n Enter one of the choices: ";
   cin >> get_out;
  }
 }
}

shop.create_new_robot_part(Head("Head",1,1.00,"lol",1.0));
shop.create_new_robot_part(Torso("Torso",1,1.00,"lol"));
shop.create_new_robot_part(Battery("Battery",1,1.00,"lol"));
shop.create_new_robot_part(Locomotor("Locomotor",1,1.00,"lol"));
shop.create_new_robot_part(Arm("Arm",1,1.00,"lol"));

}

void Controller::create_new_robot_model() {
Head head("Head",1,1.00,"lol",1.0);
Torso torso("Torso",1,1.00,"lol");
Battery battery("Battery",1,1.00,"lol");
Locomotor locomotor("Locomotor",1,1.00,"lol");
Arm arm("Arm",1,1.00,"lol");
Robot_model robot_model(head, torso, battery, locomotor, arm);
shop.create_new_robot_model(robot_model);
}

int main() {
Controller controller;
controller.execute();

}



