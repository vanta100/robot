#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
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
 public:
  Order(int o_num, string dat, Customer cust, Sales_associate sales): order_number{o_num}, date{dat}, customer{cust}, sales_associate{sales} {}
  double robot_cost();
};
  

///
/// shop
///

class Shop { 
 public:
  void create_new_robot_part(Robot_part part) { parts.push_back(part);}
  void create_new_robot_model(Robot_model model) {models.push_back(model);}
  void create_new_customer(Customer cust) {cus.push_back(cust);} 
  void choose_new_sales_associate(Sales_associate sales) {sale.push_back(sales);}
  void create_new_order(Order ord) {ordo.push_back(ord);}
 private:
                      
  vector<Robot_part> parts;
  vector<Robot_model> models;
  vector<Order> ordo;
  vector<Sales_associate> sale;
  vector<Customer> cus;
};
 
  

class Controller {
  private:
   Shop shop;
  public:
    void execute(); //kind of like a view class
    void create_new_robot_model();
    void create_new_robot_parts();
    void pre_defined_models();	
    void create_order();
    void choose_sales_assoc();
    void create_customer();

};

void Controller::execute() {
string menu,cmd;

   Fl_Window *beacon = new Fl_Window(1,1);
   beacon->show();
   beacon->hide();

 int choice;
 menu = "\nWhat would you like to do?\n\n(0) Create new robot parts\n(1) Create new robot model\n(2) Choose pre-made bots\n(3) Create new customer\n(4) Create new Sales associate\n(5) Create new Order\n(#) insert any other number to quit\nOption: ";
cmd = fl_input(menu.c_str());
choice = std::stoi(cmd);
  //cin >> choice;
  //cin.ignore();
  if (choice == 0) {
   create_new_robot_parts();
  }
 
  else if(choice == 1) {
   create_new_robot_model();
  }
 
  else if(choice == 2) {
   pre_defined_models();
  }

  else if(choice == 3) {
   create_customer();
  }

  else if(choice == 4) {
   choose_sales_assoc();
  }

  else if(choice == 5) {
   create_order();
  }

  else {
   fl_message("Exiting Program...\n");
   exit(0);
  }
 execute(); //recursion, while loop won't repeat print statement
}

void Controller::create_customer() {
srand(time(NULL));
ofstream test;
ifstream read;
char check;
int icheck, customer_number = rand() % 1000;
string name, phone_number, email_address, read_file, customer_num, convert = to_string(customer_number);

/*
read.open("Customers");
  while(read >> check) {
   cout << check << '\n';
   if(isdigit(check)) {
    read.unget();
    icheck = check;
    cout << icheck << '\n';
exit(EXIT_SUCCESS);
   }


read.close();

}
*/
test.open("Customers", ios::app);

customer_num = "Your customer number is " + convert;
fl_message(customer_num.c_str());
name = fl_input("What is your full name?");

phone_number = fl_input("What is your phone number?");

email_address = fl_input("What is your email address?");

shop.create_new_customer(Customer(name,customer_number,phone_number,email_address));

test <<"Customer number: "<< customer_number << '\n';
test <<"Customer name: "<< name << '\n';
test <<"Customer phone number: "<< phone_number << '\n';
test <<"Customer name: "<< email_address << "\n\n";
test.close();
}

void Controller::choose_sales_assoc() {
ofstream assoc;
int marvel;
string convert;
Sales_associate employ1("Matt Murdock",1);
Sales_associate employ2("Jessica Jones",2);
Sales_associate employ3("Luke Cage",3);
Sales_associate employ4("Danny Rand",4);

assoc.open("Sales Associate", ios::app);

convert = fl_input("(1) Matt Murdock\n(2) Jessica Jones\n(3) Luke Cage\n(4) Danny Rand\n\nWhich sales associate would you like to help you?");
marvel = std::stoi(convert);
switch(marvel) {
 case(1):
  shop.choose_new_sales_associate(employ1);
  fl_message("You have choosen Matt Murdock.\n");
  assoc <<"Sales Associate: Matt Murdock.\n\n";
  break;
 case(2):
  shop.choose_new_sales_associate(employ2);
  fl_message("You have choosen Jessica Jones.\n");
  assoc <<"Sales Associate: Jessica Jones.\n\n";
  break;
 case(3):
  shop.choose_new_sales_associate(employ3);
  fl_message("You have choosen Luke Cage.\n");
  assoc <<"Sales Associate: Luke Cage.\n\n";
  break;
 case(4):
  shop.choose_new_sales_associate(employ4);
  fl_message("You have choosen Danny Rand.\n");
  assoc <<"Sales Associate: Danny Rand.\n\n";
  break;
 default:
  fl_message("No associate for you! HEHE XD\n");
  break;
 }
assoc.close();
}

void Controller::create_order() {
ofstream order;
int choice;
string date,name,phone_number,email_address,convert_cust,customer_num,convert_ord,order_num,convert;
int order_number = rand() % 1000;
int customer_number = rand() % 1000;
Customer custom("a",0,"a","a"); //Initializing to change later
Sales_associate employ("h",0); //Initializing to change later

order.open("Orders", ios::app);

convert_ord = to_string(order_number);
order_num = "Your order number is " + convert_ord;
fl_message(order_num.c_str());
date = fl_input("Enter the current date:");

convert_cust = to_string(customer_number);
customer_num = "Your customer number is " + convert_cust;
fl_message(customer_num.c_str());
name = fl_input("What is your full name?");

phone_number = fl_input("What is your phone number?");

email_address = fl_input("What is your email address?");

custom = Customer(name,customer_number,phone_number,email_address);

/*
cout << "Your customer number is " << customer_number <<".\n\n"; 
cout << "What is your full name? ";
getline(cin,name);
cout << "What is your phone number? ";				//////CREATES CUSTOMER FOR ORDER
getline(cin,phone_number);
cout << "What is your email address? ";
getline(cin,email_address);
custom = Customer(name,customer_number,phone_number,email_address);
*/
order <<"Order number: "<< order_number << '\n';
order <<"Customer number: "<< customer_number << '\n';
order <<"Customer name: "<< name << '\n';
order <<"Customer phone number: "<< phone_number << '\n';
order <<"Customer name: "<< email_address << "\n\n";


convert = fl_input("(1) Matt Murdock\n(2) Jessica Jones\n(3) Luke Cage\n(4) Danny Rand\n\nWhich sales associate would you like to help you?");
choice = std::stoi(convert);
switch(choice) {
 case(1):
  employ = Sales_associate("Matt Murdock",1);
  fl_message("You have choosen Matt Murdock.");
  order <<"Sales Associate: Matt Murdock.\n\n";
  break;
 case(2):
  employ = Sales_associate("Jessica Jones",2);
  fl_message("Youru have choosen Jessica Jones.");
  order <<"Sales Associate: Jessica Jones.\n\n";
  break;
 case(3):
  employ = Sales_associate("Luke Cage",3);
  fl_message("You have choosen Luke Cage.");
  order <<"Sales Associate: Luke Cage.\n\n";
  break;
 case(4):
  employ = Sales_associate("Danny Rand",4);
  fl_message("You have choosen Danny Rand.");
  order <<"Sales Associate: Danny Rand.\n\n";
  break;
 default:
  fl_message("No sales associate.\n");
  break;
 }
 Order _order(order_number,date,custom,employ);
 order.close();
}

void Controller::pre_defined_models() {
ofstream rbot_model;
int choice;
string convert;

rbot_model.open("Robot models", ios::app);

Head head1("Basic Head",100,100.00,"basic bot",50.0);
Torso torso1("Basic Torso",100,100.00,"basic bot",2,1);			
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

convert = fl_input("Which robot would you like?\n(0)Basic Bot\n(1)Advanced Bot\n(2)Deluxe Bot\n");
choice = std::stoi(convert);

if(choice == 0) {
Robot_model bbot(head1, torso1, battery1, locomotor1, arm1,"Basic bot",1);
fl_message("Successfully Chosen Basic bot.\n");
rbot_model << "You chose Basic Bot with these specs and parts:\n";
rbot_model << "Basic head specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic head part\n" << "Power: 50 Watts\n\n";
rbot_model << "Basic torso specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic torso part\n" << "Number of battery compartments: 2\n" << "Number of arms: 1\n\n";
rbot_model << "Basic battery specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic battery part\n" << "Power: 50 Watts\n" << "Max Energy: 100 Joules\n\n";
rbot_model << "Basic locomotor specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic locomotor part\n" << "Max power: 50 Watts\n\n";
rbot_model << "Basic arm specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic arm part\n" << "Max power: 50 Watts\n\n"; 
}

else if(choice == 1) {
Robot_model abot(head2, torso2, battery2, locomotor2, arm2,"Advanced bot",2);
fl_message("Successfully Chosen Advanced bot.\n");
rbot_model << "You chose Advanced Bot with these specs and parts:\n";
rbot_model << "Advanced head specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced head part\n" << "Power: 250 Watts\n\n";
rbot_model << "Advanced torso specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced torso part\n" << "Number of battery compartments: 5\n" << "Number of arms: 2\n\n";
rbot_model << "Advanced battery specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced battery part\n" << "Power: 250 Watts\n" << "Max Energy: 450 Joules\n\n";
rbot_model << "Advanced locomotor specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced locomotor part\n" << "Max power: 250 Watts\n\n";
rbot_model << "Advanced arm specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced arm part\n" << "Max power: 250 Watts\n\n"; 
}

else if(choice == 2) {
Robot_model dbot(head3, torso3, battery3, locomotor3, arm3,"Deluxe bot",3);
fl_message("Successfully Chosen Deluxe bot.\n");
rbot_model << "You chose Deluxe Bot with these specs and parts:\n";
rbot_model << "Deluxe head specs:\n" << "Model Number: 300\n" << "Cost: $10000\n" << "Description: Deluxe head part\n" << "Power: 500 Watts\n\n";
rbot_model << "Deluxe torso specs:\n" << "Model Number: 300\n" << "Cost: $10000\n" << "Description: Deluxe torso part\n" << "Number of battery compartments: 10\n" << "Number of arms: 4\n\n";
rbot_model << "Deluxe battery specs:\n" << "Model Number: 300\n" << "Cost: $10000\n" << "Description: Deluxe battery part\n" << "Power: 500 Watts\n" << "Max Energy: 750 Joules\n\n";
rbot_model << "Deluxe locomotor specs:\n" << "Model Number: 300\n" << "Cost: $10000\n" << "Description: Deluxe locomotor part\n" << "Max power: 500 Watts\n\n";
rbot_model << "Deluxe arm specs:\n" << "Model Number: 300\n" << "Cost: $10000\n" << "Description: Deluxe arm part\n" << "Max power: 500 Watts\n\n"; 
}
rbot_model.close();
}

void Controller::create_new_robot_parts() {
ofstream part;
string name, input, menu, mod_num, description, pow, numero_arm, max_ener, battery_compart, success;
int model_number, bat_compart, num_arms, get_out; //get_out is to break the loop
double cost, power,max_energy;

part.open("Robot parts", ios::app);

menu = fl_input("\n\n(0) quit\n(1) head\n(2) torso\n(3) battery\n(4) locomotor\n(5) arm\nEnter one of the choices: ");
get_out = std::stoi(menu);

while(get_out != 0) {

 switch(get_out) {
  case(1): {
   name = fl_input("Enter the name of the head: ");

   mod_num = fl_input("Enter the desired model number: ");

   model_number = std::stoi(mod_num);

   description = fl_input("Enter a description of the part: ");

   pow = fl_input("How much power do you want your head to have?\n");
   power = std::stoi(pow);
   
   cost = 1000;
   fl_message("Cost for all custom heads is $1000 NON-NEGOTIABLE\n");
   shop.create_new_robot_part(Head(name,model_number,cost,description,power));
   success = "Successfully created " + name;
   fl_message(success.c_str());
   part << name <<" head specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Power: " << power << "\n\n";
   break;
   }
  case(2): {
   name = fl_input("Enter the name of the torso: ");
   
   mod_num = fl_input("Enter the desired model number: ");

   model_number = std::stoi(mod_num);

   description = fl_input("Enter a description of the part: ");

   numero_arm = fl_input("How many arms do you want your robot to have?\n");
   num_arms = std::stoi(numero_arm);
   

   battery_compart = fl_input("How many battery compartments do you want your robot to have?\n");
   bat_compart = std::stoi(battery_compart);
   

   cost = 2000;
   fl_message("Cost for all custom torsos is $2000 NON-NEGOTIABLE\n");
   shop.create_new_robot_part(Torso(name,model_number,cost,description,bat_compart,num_arms));
   success = "Successfully created " + name;
   fl_message(success.c_str());
   part << name << " torso specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: " << cost << '\n' << "Description: "<< description << '\n' << "Number of battery compartments: "<< bat_compart << '\n' << "Number of arms: "<< num_arms <<"\n\n";
   break;
  }
  case(3): {
   name = fl_input("Enter the name of the battery: ");

   mod_num = fl_input("Enter the desired model number: ");
   model_number = std::stoi(mod_num);

   description = fl_input("Enter a description of the part: ");

   pow = fl_input("How much power do you want your battery to have?\n");
   power = std::stoi(pow);

   max_ener = fl_input("What is the max energy you want to put on your battery?\n");
   max_energy = std::stoi(max_ener);

   cost = 1000;
   fl_message("Cost for all custom batteries is $1000 each NON-NEGOTIABLE\n");
   shop.create_new_robot_part(Battery(name,model_number,cost,description,power,max_energy));
   success = "Successfully created " + name;
   fl_message(success.c_str());
   part << name << " battery specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: " << description << '\n' << "Power: "<< power << '\n' << "Max Energy: "<< max_energy << "\n\n";
   break;
  }
  case(4): {
   name = fl_input("Enter the name of the locomotor: ");
   
   mod_num = fl_input("Enter the desired model number: ");
   model_number = std::stoi(mod_num);

   description = fl_input("Enter a description of the part: ");

   pow = fl_input("What is the max power you want to put on your locomotor?\n");
   power = std::stoi(pow);

   cost = 3000;
   cout << "Cost for all custom locomotors is $3000 NON-NEGOTIABLE\n";
   shop.create_new_robot_part(Locomotor(name,model_number,cost,description,power));
   success = "Successfully created " + name;
   fl_message(success.c_str());
   part << name << " locomotor specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Max power: "<< power << "\n\n";
   break;
   
  }
  case(5): {
   name = fl_input("Enter the name of the arms: ");

   mod_num = fl_input("Enter the desired model number: ");
   model_number = std::stoi(mod_num);

   description = fl_input("Enter a description of the part: ");

   pow = fl_input("What is the max power you want to put on your arms?\n");
   power = std::stoi(pow);

   cost = 1000;
   cout << "Cost for all custom arms is $1000 each NON-NEGOTIABLE\n";
   shop.create_new_robot_part(Arm(name,model_number,cost,description,power));
   success = "Successfully created " + name;
   fl_message(success.c_str());
   part << name << " arm specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Max power: " << power << "\n\n"; 
   break;
   
  }
  default: {
   menu = fl_input("\nWould you like to continue adding parts?\n\n(0) quit\n(1) head\n(2) torso\n(3) battery\n(4) locomotor\n(5) arm\nEnter one of the choices: ");
   get_out = std::stoi(menu);
   break;
  }
 }
   menu = fl_input("\nWould you like to continue adding parts?\n\n(0) quit\n(1) head\n(2) torso\n(3) battery\n(4) locomotor\n(5) arm\nEnter one of the choices: ");
   get_out = std::stoi(menu);
}
part.close();
//end of loop
}

void Controller::create_new_robot_model() {
ofstream model;
string name, input;
int model_number, bat_compart, num_arms, get_out = 1; //get_out is 1 to get to every statement
double cost, power,max_energy;
string description;

model.open("Robot models", ios::app);

Head head("Head",1,1.00,"lol",1.0);
Torso torso("Torso",1,1.00,"lol",1,1);			///Initialized so no errors arise
Battery battery("Battery",1,1.00,"lol",1.0,1.0);
Locomotor locomotor("Locomotor",1,1.00,"lol",1.0);
Arm arm("Arm",1,1.00,"lol",1.0);


while(get_out != 0) {
 switch(get_out) {			///Switch statement is supposed to go through everything to make robot model.
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

   model << name <<" head specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Power: " << power << "\n\n";
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
   model << name << " torso specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: " << cost << '\n' << "Description: "<< description << '\n' << "Number of battery compartments: "<< bat_compart << '\n' << "Number of arms: "<< num_arms <<"\n\n";
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
   model << name << " battery specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: " << description << '\n' << "Power: "<< power << '\n' << "Max Energy: "<< max_energy << "\n\n";
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
   model << name << " locomotor specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Max power: "<< power << "\n\n";
  }
  case(5): {
   cout << "\nEnter the name of the arms: ";
   getline(cin,name);

   cout << "Enter the desired model number for the arms: ";
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
   model << name << " arm specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Max power: " << power << "\n\n"; 
  }
  default: {
   cout << "\nWhat is the model number of this robot? ";
   cin >> model_number;
   cin.ignore();
   model << "The model number of this robot model is: " << model_number << '\n';
 
   cout << "What is the name of this robot? ";
   getline(cin,name);
   model << "The name of this robot model is " << name << '\n';

   Robot_model robot_model(head, torso, battery, locomotor, arm,name,model_number);
   shop.create_new_robot_model(robot_model);
   cout << "Successfully created robot.\n";
   cout<<"\nWould you like to continue adding models?\n\n(0) quit\n(1) continue\n";
   cin >> get_out;
  }
 }
}
model.close();
}

int main() {
Controller controller;
controller.execute();
}



