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
  Locomotor(string _name, int _model_number, double _cost, string _description, double _max_power) : Robot_part(_name,_model_number,_cost,_description), max_power{_max_power} {}

};

class Torso : public Robot_part {
 private:
  int battery_compartments;
  int max_arms;
 public:
  Torso(string _name, int _model_number, double _cost, string _description, int bat_comp, int _max_arms) : Robot_part(_name,_model_number,_cost,_description), battery_compartments{bat_comp}, max_arms{_max_arms} {}

}; 

class Battery : public Robot_part {
 private:
  double power_available;
  double max_energy;
 public:
  Battery(string _name, int _model_number, double _cost, string _description ,double pow_avail, double max_ener) : Robot_part(_name,_model_number,_cost,_description), power_available{pow_avail}, max_energy{max_ener} {}

};

class Arm : public Robot_part {
 private:
  double max_power;
 public:
  Arm(string _name, int _model_number, double _cost, string _description, double max_pow) : Robot_part(_name,_model_number,_cost,_description), max_power{max_pow} {}

};

///
/// Robot Model
///

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
  Robot_model(Robot_part _head, Robot_part _torso, Robot_part _battery, Robot_part _locomotor, Robot_part _arm, string _name, int mod_num) : head{_head}, torso{_torso}, battery{_battery}, locomotor{_locomotor}, arm{_arm}, name{_name}, model_number{mod_num} {}
  void robot_info();
  double cost();
  double max_speed();
  double max_battery_life();
};

class Customer {
 private:
  string name;
  int customer_number;
  string phone_number;
  string email_address;
 public:
  Customer(string nam, int cust_num, string pho_num, string em_add): name{nam}, customer_number{cust_num}, phone_number{pho_num}, email_address{em_add} {}
};

class Sales_associate {
  private:
   string name;
   int employee_number;
  public:
   Sales_associate(string nam, int cust_num): name{nam}, employee_number{cust_num} {}
};

class Order {
 private:
  int order_number;
  string date;
  Customer customer;
  Sales_associate sales_associate;
  int status;
 public:
  Order(int o_num, string dat, Customer cust, Sales_associate sales, int stat): order_number{o_num}, date{dat}, customer{cust}, sales_associate{sales}, status{stat} {}
  double robot_cost();
};
  

///
/// shop
///

class Shop { 
 public:
  void create_new_robot_part(Robot_part part) { parts.push_back(part);}
  void create_new_robot_model(Robot_model model) {models.push_back(model);}
  void create_new_customer() ;
  void create_new_sales_associate();
  void create_new_order();
 private:
  //Order order;
  //Customer customer;
  //Sales_associate sales_associate;                         
  vector<Robot_part> parts;
  vector<Robot_model> models;
};
 
  

class Controller {
  private:
   Shop shop;
  public:
    void execute(); //kind of like a view class
    void create_new_robot_model();
    void create_new_robot_parts();
    void pre_defined_models();	

};

void Controller::execute() {
 int choice;
 cout << "What would you like to do?\n\n"<<"(0) Create new robot parts\n" << "(1) Create new robot model\n" << "(2) Choose pre-made bots\n" << "Option: ";
 cin >> choice;

 if (choice == 0) {
  create_new_robot_parts();
 }
 
 else if(choice == 1) {
  create_new_robot_model();
 }
 
 else if(choice == 2) {
  pre_defined_models();
 }
 else {
  cout << "Invalid input\n" << "Exiting Program...\n";
  exit(0);
 }
}

void Controller::pre_defined_models() {
int choice;

Head head1("Basic Head",100,100.00,"basic bot",50.0);
Torso torso1("Basic Torso",100,100.00,"basicbot",2,1);			
Battery battery1("Basic Battery",100,100.00,"basic bot",50.0,100.0);
Locomotor locomotor1("Basic Locomotor",100,100.00,"basic bot",50.0);
Arm arm1("Basic Arm",100,100.00,"basic bot",50.0);

Head head2("Advanced Head",200,1000.00,"advanced bot",250.0);
Torso torso2("Advanced Torso",200,1000.00,"advanced bot",5,2);			
Battery battery2("Advanced Battery",200,1000.00,"advanced bot",250.0,450.0);
Locomotor locomotor2("Advanced Locomotor",200,1000.00,"advanced bot",250.0);
Arm arm2("Advanced Arm",200,1000.00,"advanced bot",250.0);

Head head3("Deluxe Head",300,10000.00,"Deluxe bot",500.0);
Torso torso3("Deluxe Torso",300,10000.00,"Deluxe bot",10,4);			
Battery battery3("Deluxe Battery",300,10000.00,"Deluxe bot",500.0,750.0);
Locomotor locomotor3("Deluxe Locomotor",300,10000.00,"Deluxe bot",500.0);
Arm arm3("Deluxe Arm",300,10000.00,"Deluxe bot",500.0);

cout << "Which robot would you like?\n(0)Basic Bot\n(1)Advanced Bot\n(2)Deluxe Bot\n";
cin >> choice;

if(choice == 0) {
Robot_model bbot(head1, torso1, battery1, locomotor1, arm1,"Basic bot",1);
cout << "Successfully Chosen Basic bot.\n";
}

else if(choice == 1) {
Robot_model abot(head2, torso2, battery2, locomotor2, arm2,"Advanced bot",2);
cout << "Successfully Chosen Advanced bot.\n";
}

else if(choice == 2) {
Robot_model dbot(head3, torso3, battery3, locomotor3, arm3,"Deluxe bot",3);
cout << "Successfully Chosen Deluxe bot.\n";
}
 
}

void Controller::create_new_robot_parts() {
string name, input;
int model_number, bat_compart, num_arms, get_out; //get_out is to break the loop
double cost, power,max_energy;
string description;

cout << "\n\n(0) quit\n(1) head\n(2) torso\n(3) battery\n(4) locomotor\n(5) arm\nEnter one of the choices: ";
cin >> get_out;
while(get_out != 0) {
 cin.ignore(); //consumes \n

 switch(get_out) {
  case(1): {
   cout << "Enter the name of the head: ";
   getline(cin,name);

   cout << "Enter the desired model number: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the part: ";
   getline(cin,description);

   cout << "How much power do you want your head to have?\n";
   cin >> power;
   cin.ignore();
   
   cost = 1000;
   cout << "Cost for all custom heads is $" << cost << " NON-NEGOTIABLE\n";
   shop.create_new_robot_part(Head(name,model_number,cost,description,power));
   cout << "Successfully created " << name <<'\n';
   break;
   }
  case(2): {
   cout << "Enter the name of the torso: ";
   getline(cin,name);

   cout << "Enter the desired model number: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the part: ";
   getline(cin,description);

   cout << "How many arms do you want your robot to have?\n";
   cin >> num_arms;
   cin.ignore();

   cout << "How many battery compartments do you want your robot to have?\n";
   cin >> bat_compart;
   cin.ignore();

   cost = 2000;
   cout << "Cost for all custom torsos is $" << cost << " NON-NEGOTIABLE\n";
   shop.create_new_robot_part(Torso(name,model_number,cost,description,bat_compart,num_arms));
   cout << "Successfully created " << name <<'\n';
   break;
  }
  case(3): {
   cout << "Enter the name of the battery: ";
   getline(cin,name);

   cout << "Enter the desired model number: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the part: ";
   getline(cin,description);

   cout << "How much power do you want your battery to have?\n";
   cin >> power;
   cin.ignore();

   cout << "What is the max energy you want to put on your battery?\n";
   cin >> max_energy;
   cin.ignore();

   cost = 1000;
   cout << "Cost for all custom batteries is $" << cost << " NON-NEGOTIABLE\n";
   shop.create_new_robot_part(Battery(name,model_number,cost,description,power,max_energy));
   cout << "Successfully created " << name <<'\n';
   break;
  }
  case(4): {
   cout << "Enter the name of the locomotor: ";
   getline(cin,name);

   cout << "Enter the desired model number: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the part: ";
   getline(cin,description);

   cout << "What is the max power you want to put on your locomotor?\n";
   cin >> power;
   cin.ignore();

   cost = 3000;
   cout << "Cost for all custom locomotors is $" << cost << " NON-NEGOTIABLE\n";
   shop.create_new_robot_part(Locomotor(name,model_number,cost,description,power));
   cout << "Successfully created " << name <<'\n';
   break;
   
  }
  case(5): {
   cout << "Enter the name of the arms: ";
   getline(cin,name);

   cout << "Enter the desired model number: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the part: ";
   getline(cin,description);

   cout << "What is the max power you want to put on your arms?\n";
   cin >> power;
   cin.ignore();

   cost = 1000;
   cout << "Cost for all custom arms is $" << cost << "each NON-NEGOTIABLE\n";
   shop.create_new_robot_part(Arm(name,model_number,cost,description,power));
   cout << "Successfully created " << name <<'\n';
   break;
   
  }
  default: {
   cout<<"\nWould you like to continue adding parts?\n\n(0) quit\n(1) head\n(2) torso\n(3) battery\n(4) locomotor\n(5) arm\nEnter one of the choices: ";
   cin >> get_out;
  }
 }
    cout<<"\nWould you like to continue adding parts?\n\n(0) quit\n(1) head\n(2) torso\n(3) battery\n(4) locomotor\n(5) arm\nEnter one of the choices: ";
   cin >> get_out;
}
//end of loop
}

void Controller::create_new_robot_model() {
string name, input;
int model_number, bat_compart, num_arms, get_out = 1; //get_out is 1 to get to every statement
double cost, power,max_energy;
string description;

Head head("Head",1,1.00,"lol",1.0);
Torso torso("Torso",1,1.00,"lol",1,1);			///Initialized so no errors arise
Battery battery("Battery",1,1.00,"lol",1.0,1.0);
Locomotor locomotor("Locomotor",1,1.00,"lol",1.0);
Arm arm("Arm",1,1.00,"lol",1.0);


while(get_out != 0) {
 switch(get_out) {
  case(1): {
   cout << "Enter the desired model number for the head: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter the name of the head: ";
   getline(cin,name);

   cout << "Enter a description of the head: ";
   getline(cin,description);

   cout << "How much power do you want your head to have?\n";
   cin >> power;
   cin.ignore();
   
   cost = 1000;
   cout << "Cost for all custom heads is $" << cost << " NON-NEGOTIABLE\n";
   head = Head(name,model_number,cost,description,power);
   cout << "Successfully created " << name <<'\n';
   }
  case(2): {
   cout << "\nEnter the name of the torso: ";
   getline(cin,name);

   cout << "Enter the desired model number for the torso: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the torso: ";
   getline(cin,description);

   cout << "How many arms do you want your robot to have?\n";
   cin >> num_arms;
   cin.ignore();

   cout << "How many battery compartments do you want your robot to have?\n";
   cin >> bat_compart;
   cin.ignore();

   cost = 2000;
   cout << "Cost for all custom torsos is $" << cost << " NON-NEGOTIABLE\n";
   torso = Torso(name,model_number,cost,description,bat_compart,num_arms);
   cout << "Successfully created " << name <<'\n';
  }
  case(3): {
   cout << "\nEnter the name of the battery: ";
   getline(cin,name);

   cout << "Enter the desired model number for your battery: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the battery: ";
   getline(cin,description);

   cout << "How much power do you want your battery to have?\n";
   cin >> power;
   cin.ignore();

   cout << "What is the max energy you want to put on your battery?\n";
   cin >> max_energy;
   cin.ignore();

   cost = 1000;
   cout << "Cost for all custom batteries is $" << cost << " NON-NEGOTIABLE\n";
   battery = Battery(name,model_number,cost,description,power,max_energy);
   cout << "Successfully created " << name <<'\n';
  }
  case(4): {
   cout << "\nEnter the name of the locomotor: ";
   getline(cin,name);

   cout << "Enter the desired model number for the locomotor: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the locomotor: ";
   getline(cin,description);

   cout << "What is the max power you want to put on your locomotor?\n";
   cin >> power;
   cin.ignore();

   cost = 3000;
   cout << "Cost for all custom locomotors is $" << cost << " NON-NEGOTIABLE\n";
   locomotor = Locomotor(name,model_number,cost,description,power);
   cout << "Successfully created " << name <<'\n';
  }
  case(5): {
   cout << "\nEnter the name of the arms: ";
   getline(cin,name);

   cout << "Enter the desired model numbe for the arms: ";
   cin >> model_number;
   cin.ignore();

   cout << "Enter a description of the arms: ";
   getline(cin,description);

   cout << "What is the max power you want to put on your arms?\n";
   cin >> power;
   cin.ignore();

   cost = 1000;
   cout << "Cost for all custom arms is $" << cost << "each NON-NEGOTIABLE\n";
   arm = Arm(name,model_number,cost,description,power);
   cout << "Successfully created " << name <<'\n';

  }
  default: {
   cout << "\nWhat is the model_number of this robot?";
   cin >> model_number;
   cin.ignore();
 
   cout << "What is the name of this robot?";
   getline(cin,name);

   Robot_model robot_model(head, torso, battery, locomotor, arm,name,model_number);
   shop.create_new_robot_model(robot_model);
   cout << "Successfully created robot.\n";
   cout<<"\nWould you like to continue adding models?\n\n(0) quit\n(1) continue\n";
   cin >> get_out;
  }
 }
}

}

int main() {
Controller controller;
controller.execute();
}



