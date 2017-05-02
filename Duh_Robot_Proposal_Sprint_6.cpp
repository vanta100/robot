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
#include <ctype.h>
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
    void execute(int choice); //kind of like a view class
    void create_new_robot_model();
    void create_new_robot_parts();
    void pre_defined_models();	
    void create_order();
    void choose_sales_assoc();
    void create_customer();

};
void Controller::execute(int choice) {
string menu,cmd;

   Fl_Window *beacon = new Fl_Window(1,1);
   beacon->show();
   beacon->hide();
/*
 int choice;
 menu = "\nWhat would you like to do?\n\n(0) Create new robot parts\n(1) Create new robot model\n(2) Choose pre-made bots\n(3) Create new customer\n(4) Create new Sales associate\n(5) Create new Order\n(#) insert any other number to quit\nOption: ";
cmd = fl_input(menu.c_str());
choice = std::stoi(cmd);
*/
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
 //execute(); //recursion, while loop won't repeat print statement
}

void Controller::create_customer() {
srand(time(NULL));
ofstream test;
ifstream read;
int customer_number = rand() % 1000;
string name, phone_number, email_address, read_file, customer_num, convert = to_string(customer_number), line;

read.open("Customers");
if(read.is_open()) {
	for(int i = 0;getline(read,line); i++) {
		
		if( i == 0){
		 customer_number = atoi(line.c_str());
		}

		else if( i == 1){
		 name = line;
		}

		else if( i == 2){
		 phone_number = line;
		}

		else if( i == 3){
		 email_address = line;
		 shop.create_new_customer(Customer(name,customer_number,phone_number,email_address));
		}
	}
}
read.close();
test.open("Customers", ios::app);

customer_num = "Your customer number is " + convert;
fl_message(customer_num.c_str());
name = fl_input("What is your full name?");

phone_number = fl_input("What is your phone number?");

email_address = fl_input("What is your email address?");

shop.create_new_customer(Customer(name,customer_number,phone_number,email_address));

test << customer_number << '\n';
test << name << '\n';
test << phone_number << '\n';
test << email_address << "\n";
test.close();
}

void Controller::choose_sales_assoc() {

ofstream assoc;
ifstream read;
int marvel;
string convert, line;
Sales_associate employ1("Matt Murdock",1);
Sales_associate employ2("Jessica Jones",2);
Sales_associate employ3("Luke Cage",3);
Sales_associate employ4("Danny Rand",4);

read.open("Sales Associate");
if(read.is_open()) {
	while(getline(read,line)) {
		
		if( line == "Matt Murdock"){
		 shop.choose_new_sales_associate(employ1);
		}

		else if( line == "Jessica Jones"){
		 shop.choose_new_sales_associate(employ2);		
		}

		else if( line == "Luke Cage"){
		 shop.choose_new_sales_associate(employ3);
		}

		else if( line == "Danny Rand"){
		 shop.choose_new_sales_associate(employ4);		}
	}
}
read.close();

assoc.open("Sales Associate", ios::app);

convert = fl_input("(1) Matt Murdock\n(2) Jessica Jones\n(3) Luke Cage\n(4) Danny Rand\n\nWhich sales associate would you like to help you?");
marvel = std::stoi(convert);
switch(marvel) {
 case(1):
  shop.choose_new_sales_associate(employ1);
  fl_message("You have choosen Matt Murdock.\n");
  assoc <<"Matt Murdock.\n";
  break;
 case(2):
  shop.choose_new_sales_associate(employ2);
  fl_message("You have choosen Jessica Jones.\n");
  assoc <<"Jessica Jones.\n";
  break;
 case(3):
  shop.choose_new_sales_associate(employ3);
  fl_message("You have choosen Luke Cage.\n");
  assoc <<"Luke Cage.\n";
  break;
 case(4):
  shop.choose_new_sales_associate(employ4);
  fl_message("You have choosen Danny Rand.\n");
  assoc <<"Danny Rand.\n";
  break;
 default:
  fl_message("No associate for you! HEHE XD\n");
  break;
 }
assoc.close();
}

void Controller::create_order() {
ofstream order;
ifstream read;
int choice;
string date,name,phone_number,email_address,convert_cust,customer_num,convert_ord,order_num,convert,line;
int order_number = rand() % 1000;
int customer_number = rand() % 1000;
Customer custom("a",0,"a","a"); //Initializing to change later
Sales_associate employ("h",0); //Initializing to change later

read.open("Orders");
if(read.is_open()) {
 for(int i = 0;getline(read,line); i++) {

 	if(i == 0){
 	 date = line;	
 	}

	else if( i == 1){
	 order_number = atoi(line.c_str());
	}

	else if( i == 2){
	 customer_number = atoi(line.c_str());
	}

	else if( i == 3){
	 phone_number = line;
	}

	else if( i == 4){
	 name = line;
	 
    }

	else if( i == 5){
	 phone_number = line;
	}

	else if( i == 6){
	 email_address = line;
	 custom = Customer(name,customer_number,phone_number,email_address);
	}

	else if( i == 7){

	 if (line == "Matt Murdock 1"){
	 	employ = Sales_associate("Matt Murdock",1);
	 }

	 else if (line == "Matt Murdock 1"){
	 	employ = Sales_associate("Matt Murdock",1);
	 }

	 else if (line == "Matt Murdock 1"){
	 	employ = Sales_associate("Matt Murdock",1);
	 }

	 else if (line == "Matt Murdock 1"){
	 	employ = Sales_associate("Matt Murdock",1);
	 }

	 Order _order(order_number,date,custom,employ);
	 shop.create_new_order(_order);
    }
  }
}
read.close();
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

order << date <<'\n';
order << order_number << '\n';
order << customer_number << '\n';
order << name << '\n';
order << phone_number << '\n';
order << email_address << "\n";

convert = fl_input("(1) Matt Murdock\n(2) Jessica Jones\n(3) Luke Cage\n(4) Danny Rand\n\nWhich sales associate would you like to help you?");

choice = std::stoi(convert);
switch(choice) {
 case(1):
  employ = Sales_associate("Matt Murdock",1);
  fl_message("You have choosen Matt Murdock.");
  order <<"Matt Murdock 1.\n";
  break;
 case(2):
  employ = Sales_associate("Jessica Jones",2);
  fl_message("You have choosen Jessica Jones.");
  order <<"Jessica Jones 2.\n";
  break;
 case(3):
  employ = Sales_associate("Luke Cage",3);
  fl_message("You have choosen Luke Cage.");
  order <<"Luke Cage 3.\n";
  break;
 case(4):
  employ = Sales_associate("Danny Rand",4);
  fl_message("You have choosen Danny Rand.");
  order <<"Danny Rand 4.\n";
  break;
 default:
  fl_message("No sales associate.\n");
  break;
 }

 Order _order(order_number,date,custom,employ);
 shop.create_new_order(_order);
 order.close();
}

void Controller::pre_defined_models() {
ofstream rbot_model;
ifstream read;
int choice;
string convert,line;

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

read.open("Robot models");

 while(getline(read,line)){
  if (line == "Basic Bot:")
  {
  	Robot_model bbot(head1,torso1,battery1,locomotor1,arm1,"Basic bot",1);
  	shop.create_new_robot_model(bbot);
  }

  else if (line == "Advanced Bot:")
  {
  	Robot_model abot(head2,torso2,battery2,locomotor2,arm2,"Advanced bot",2);
  	shop.create_new_robot_model(abot);
  }

  else if (line == "Deluxe Bot:")
  {
  	Robot_model dbot(head3,torso3,battery3,locomotor3,arm3,"Deluxe bot",3);
  	shop.create_new_robot_model(dbot);
  }

 }

read.close();
convert = fl_input("Which robot would you like?\n(0)Basic Bot\n(1)Advanced Bot\n(2)Deluxe Bot\n");
choice = std::stoi(convert);

rbot_model.open("Robot models", ios::app);

if(choice == 0) {
Robot_model bbot(head1, torso1, battery1, locomotor1, arm1,"Basic bot",1);
shop.create_new_robot_model(bbot);
fl_message("Successfully Chosen Basic bot.\n");
rbot_model << "Basic Bot:\n";
rbot_model << "Basic head specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic head part\n" << "Power: 50 Watts\n\n";
rbot_model << "Basic torso specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic torso part\n" << "Number of battery compartments: 2\n" << "Number of arms: 1\n\n";
rbot_model << "Basic battery specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic battery part\n" << "Power: 50 Watts\n" << "Max Energy: 100 Joules\n\n";
rbot_model << "Basic locomotor specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic locomotor part\n" << "Max power: 50 Watts\n\n";
rbot_model << "Basic arm specs:\n" << "Model Number: 100\n" << "Cost: $100\n" << "Description: basic arm part\n" << "Max power: 50 Watts\n\n"; 
}

else if(choice == 1) {
Robot_model abot(head2, torso2, battery2, locomotor2, arm2,"Advanced bot",2);
shop.create_new_robot_model(abot);
fl_message("Successfully Chosen Advanced bot.\n");
rbot_model << "Advanced Bot:\n";
rbot_model << "Advanced head specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced head part\n" << "Power: 250 Watts\n\n";
rbot_model << "Advanced torso specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced torso part\n" << "Number of battery compartments: 5\n" << "Number of arms: 2\n\n";
rbot_model << "Advanced battery specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced battery part\n" << "Power: 250 Watts\n" << "Max Energy: 450 Joules\n\n";
rbot_model << "Advanced locomotor specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced locomotor part\n" << "Max power: 250 Watts\n\n";
rbot_model << "Advanced arm specs:\n" << "Model Number: 200\n" << "Cost: $1000\n" << "Description: Advanced arm part\n" << "Max power: 250 Watts\n\n"; 
}

else if(choice == 2) {
Robot_model dbot(head3, torso3, battery3, locomotor3, arm3,"Deluxe bot",3);
shop.create_new_robot_model(dbot);
fl_message("Successfully Chosen Deluxe bot.\n");
rbot_model << "Deluxe Bot:\n";
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
ifstream read;
string name, input, menu, mod_num, description, pow, numero_arm, max_ener, battery_compart, success,line,check;
int model_number, bat_compart, num_arms, get_out; //get_out is to break the loop
double cost, power,max_energy;

read.open("Robot parts");

while(getline(read,line)){
 if (line == "Head:")
 {
  for(int i=0; getline(read,line); i++){
   if (i == 0)
   {
    name = line;
   }
   else if (i == 1){
    model_number = atoi(line.c_str());
   }
   else if (i == 2){
    cost = atoi(line.c_str());
   }
   else if (i == 3){
    description = line;
   }
   else if(i == 4){
  	power = atoi(line.c_str());
   }
  }
  shop.create_new_robot_part(Head(name,model_number,cost,description,power));
 }

 else if (line == "Torso:"){

  for(int i=0; getline(read,line); i++){
   if (i == 0)
   {
    name = line;
   }
   else if (i == 1){
    model_number = atoi(line.c_str());
   }
   else if (i == 2){
    cost = atoi(line.c_str());
   }
   else if (i == 3){
    description = line;
   }
   else if(i == 4){
  	bat_compart = atoi(line.c_str());
   }
   else if(i == 5){
   	num_arms = atoi(line.c_str());
   }
  }
  shop.create_new_robot_part(Torso(name,model_number,cost,description,bat_compart,num_arms));
 }

  else if (line == "Battery:"){

  for(int i=0; getline(read,line); i++){
   if (i == 0)
   {
    name = line;
   }
   else if (i == 1){
    model_number = atoi(line.c_str());
   }
   else if (i == 2){
    cost = atoi(line.c_str());
   }
   else if (i == 3){
    description = line;
   }
   else if(i == 4){
  	power = atoi(line.c_str());
   }
   else if(i == 5){
   	max_energy = atoi(line.c_str());
   }
  }
  shop.create_new_robot_part(Battery(name,model_number,cost,description,power,max_energy));
 }

  else if (line == "Locomotor:"){

  for(int i=0; getline(read,line); i++){
   if (i == 0)
   {
    name = line;
   }
   else if (i == 1){
    model_number = atoi(line.c_str());
   }
   else if (i == 2){
    cost = atoi(line.c_str());
   }
   else if (i == 3){
    description = line;
   }
   else if(i == 4){
  	power = atoi(line.c_str());
   }
  }
  shop.create_new_robot_part(Locomotor(name,model_number,cost,description,power));
 }

  else if (line == "Arm:"){

  for(int i=0; getline(read,line); i++){
   if (i == 0)
   {
    name = line;
   }
   else if (i == 1){
    model_number = atoi(line.c_str());
   }
   else if (i == 2){
    cost = atoi(line.c_str());
   }
   else if (i == 3){
    description = line;
   }
   else if(i == 4){
  	power = atoi(line.c_str());
   }
  }
  shop.create_new_robot_part(Arm(name,model_number,cost,description,power));
 }

}

read.close();

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
   part << "Head:\n"<< name <<"\n" << model_number << '\n' << cost << '\n' << "Description: "<< description << '\n' << power << "\n";
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
   part << "Torso:\n"<< name << "\n" << model_number << '\n' << cost << '\n' << "Description: "<< description << '\n' << bat_compart << '\n' << num_arms <<"\n";
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
   part <<"Battery:\n"<< name << "\n" << model_number << '\n' << cost << '\n' << "Description: " << description << '\n' <<  power << '\n' << max_energy << "\n";
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
   fl_message("Cost for all custom locomotors is $3000 NON-NEGOTIABLE\n");
   shop.create_new_robot_part(Locomotor(name,model_number,cost,description,power));
   success = "Successfully created " + name;
   fl_message(success.c_str());
   part<< "Locomotor:\n"<< name << "\n" << model_number << '\n' << cost << '\n' << "Description: "<< description << '\n' << power << "\n";
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
   fl_message("Cost for all custom arms is $1000 each NON-NEGOTIABLE\n");
   shop.create_new_robot_part(Arm(name,model_number,cost,description,power));
   success = "Successfully created " + name;
   fl_message(success.c_str());
   part << "Arm:\n"<< name << "\n" << model_number << '\n' << cost << '\n' << "Description: "<< description << '\n' << power << "\n"; 
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
ifstream read;
string name, input, menu, mod_num, description, pow, numero_arm, max_ener, battery_compart, success, line;
int model_number, bat_compart, num_arms, get_out = 1; //get_out is to break the loop
double cost, power,max_energy;

Head head("Head",1,1.00,"lol",1.0);
Torso torso("Torso",1,1.00,"lol",1,1);			///Initialized so no errors arise
Battery battery("Battery",1,1.00,"lol",1.0,1.0);
Locomotor locomotor("Locomotor",1,1.00,"lol",1.0);
Arm arm("Arm",1,1.00,"lol",1.0);

read.open("Robot models");
while(read.is_open()){
 for(int g = 0;getline(read,line); g++){
  if (g == 0)
  {
   for(int i=0; getline(read,line); i++){
    if (i == 0)
    {
     name = line;
    }
    else if (i == 1){
     model_number = atoi(line.c_str());
    }
    else if (i == 2){
     cost = atoi(line.c_str());
    }
    else if (i == 3){
     description = line;
    }
    else if(i == 4){
  	 power = atoi(line.c_str());
    }
   }
   head = Head(name,model_number,cost,description,power);
  }

    else if (g == 1 ){

    for(int i=0; getline(read,line); i++){
     if (i == 0)
     {
      name = line;
     }
     else if (i == 1){
      model_number = atoi(line.c_str());
     }
     else if (i == 2){
      cost = atoi(line.c_str());
     }
     else if (i == 3){
      description = line;
     }
     else if(i == 4){
  	  bat_compart = atoi(line.c_str());
     }
     else if(i == 5){
   	  num_arms = atoi(line.c_str());
     }
   }
  torso = Torso(name,model_number,cost,description,bat_compart,num_arms);
 }

  else if (g == 2){

  for(int i=0; getline(read,line); i++){
   if (i == 0)
   {
    name = line;
   }
   else if (i == 1){
    model_number = atoi(line.c_str());
   }
   else if (i == 2){
    cost = atoi(line.c_str());
   }
   else if (i == 3){
    description = line;
   }
   else if(i == 4){
  	power = atoi(line.c_str());
   }
   else if(i == 5){
   	max_energy = atoi(line.c_str());
   }
  }

  battery = Battery(name,model_number,cost,description,power,max_energy);
 }

  else if (g == 3){

  for(int i=0; getline(read,line); i++){
   if (i == 0)
   {
    name = line;
   }
   else if (i == 1){
    model_number = atoi(line.c_str());
   }
   else if (i == 2){
    cost = atoi(line.c_str());
   }
   else if (i == 3){
    description = line;
   }
   else if(i == 4){
  	power = atoi(line.c_str());
   }
  }
  locomotor = Locomotor(name,model_number,cost,description,power);
 }

  else if (g == 4){

  for(int i=0; getline(read,line); i++){
   if (i == 0)
   {
    name = line;
   }
   else if (i == 1){
    model_number = atoi(line.c_str());
   }
   else if (i == 2){
    cost = atoi(line.c_str());
   }
   else if (i == 3){
    description = line;
   }
   else if(i == 4){
  	power = atoi(line.c_str());
   }
  }
  arm = Arm(name,model_number,cost,description,power);
 }
   Robot_model robot_model(head, torso, battery, locomotor, arm,name,model_number);
   shop.create_new_robot_model(robot_model);
 }
 read.close();
}

model.open("Robot models", ios::app);

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
   head = Head(name,model_number,cost,description,power);
   success = "Successfully created " + name;
   model << name <<" head specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Power: " << power << "\n\n";
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
   torso = Torso(name,model_number,cost,description,bat_compart,num_arms);
   success = "Successfully created " + name;
   fl_message(success.c_str());
   model << name << " torso specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: " << cost << '\n' << "Description: "<< description << '\n' << "Number of battery compartments: "<< bat_compart << '\n' << "Number of arms: "<< num_arms <<"\n\n";
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
   battery = Battery(name,model_number,cost,description,power,max_energy);
   success = "Successfully created " + name;
   fl_message(success.c_str());
   model << name << " battery specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: " << description << '\n' << "Power: "<< power << '\n' << "Max Energy: "<< max_energy << "\n\n";
  }
  case(4): {
   name = fl_input("Enter the name of the locomotor: ");
   
   mod_num = fl_input("Enter the desired model number: ");
   model_number = std::stoi(mod_num);

   description = fl_input("Enter a description of the part: ");

   pow = fl_input("What is the max power you want to put on your locomotor?\n");
   power = std::stoi(pow);

   cost = 3000;
   fl_message("Cost for all custom locomotors is $3000 NON-NEGOTIABLE\n");
   locomotor = Locomotor(name,model_number,cost,description,power);
   success = "Successfully created " + name;
   fl_message(success.c_str());
   model << name << " locomotor specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Max power: "<< power << "\n\n";
  }
  case(5): {
   name = fl_input("Enter the name of the arms: ");

   mod_num = fl_input("Enter the desired model number: ");
   model_number = std::stoi(mod_num);

   description = fl_input("Enter a description of the part: ");

   pow = fl_input("What is the max power you want to put on your arms?\n");
   power = std::stoi(pow);

   cost = 1000;
   fl_message("Cost for all custom arms is $1000 each NON-NEGOTIABLE\n");
   arm = Arm(name,model_number,cost,description,power);
   success = "Successfully created " + name;
   fl_message(success.c_str());
   model << name << " arm specs:\n" << "Model Number: "<< model_number << '\n' << "Cost: "<< cost << '\n' << "Description: "<< description << '\n' << "Max power: " << power << "\n\n"; 
  }
  default: {
   mod_num = fl_input("\nWhat is the model number of this robot? ");
   model_number = std::stoi(mod_num);
   model << "The model number of this robot model is: " << model_number << '\n';
 
   name = fl_input("What is the name of this robot? ");
   model << "The name of this robot model is " << name << '\n';

   Robot_model robot_model(head, torso, battery, locomotor, arm,name,model_number);
   shop.create_new_robot_model(robot_model);
   success = "Successfully created " + name;
   fl_message(success.c_str());
   menu = fl_input("\nWould you like to continue adding models?\n\n(0) quit\n(1) continue\n");
   get_out = std::stoi(menu);
  }
 }
}
model.close();
}

//WIDGETS
Fl_Window *win;
Fl_Menu_Bar *menubar;

//CALLBACKS
void quitCB(Fl_Widget* w, void* p) {win->hide();}

void create_robot_partsCB(Fl_Widget* w, void* p) {
 Controller controller;
 controller.execute(0);
}

void create_robot_modelCB(Fl_Widget* w, void* p) {
 Controller controller;
 controller.execute(1);
}

void create_pre_defined_modelCB(Fl_Widget* w, void* p) {
 Controller controller;
 controller.execute(2);
}
void create_customerCB(Fl_Widget* w, void* p) {
 Controller controller;
 controller.execute(3);
}

void choose_sales_associateCB(Fl_Widget* w, void* p) {
 Controller controller;
 controller.execute(4);
}

void create_orderCB(Fl_Widget* w, void* p) {
 Controller controller;
 controller.execute(5);
}

//MENU

Fl_Menu_Item menuitems[] = {
  { "&File",0,0,0,FL_SUBMENU },
   {"&Quit", FL_CTRL + 'q', (Fl_Callback*)quitCB},
   {0},

  { "&Robot",0,0,0,FL_SUBMENU },
   {"Create Robot Parts", 0, (Fl_Callback*)create_robot_partsCB},
   {"Create Robot Model", 0, (Fl_Callback*)create_robot_modelCB},
   {"Create Pre-Defined Model", 0, (Fl_Callback*)create_pre_defined_modelCB},
   {0},

  { "&Customer Information",0,0,0,FL_SUBMENU },
   {"Add Customer", 0, (Fl_Callback*)create_customerCB},
   {"Choose sales associate", 0, (Fl_Callback*)choose_sales_associateCB},
   {0},

  { "&Order",0,0,0,FL_SUBMENU },
   {"order", 0, (Fl_Callback*)create_orderCB},
   {0},  

  {0}
};

int main() {

  const int w = 360;
  const int h = 220;
 
  win = new Fl_Window{w,h,"Duh Robot Proposal"};
  win->color(FL_WHITE);

  menubar = new Fl_Menu_Bar(0, 0, w, 30);
  menubar->menu(menuitems);

  win->end();
  win->show(); 
  
  return(Fl::run()); 
}



