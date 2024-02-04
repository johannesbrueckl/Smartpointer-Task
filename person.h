#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>

class License;

class Person{
  
private:
  std::string name; 	//Name der Person.
  unsigned int wealth; 	//Vermoegen der Person.
  std::map<std::string, std::unique_ptr<License>> licenses; 	//Lizenzen der Person.
  
public:
  //default constructor raw
  Person(std::string, unsigned int = 0);
  
  virtual ~Person() = default;
  
  //methods raw
  void work(std::string);
  
  virtual void work(unsigned int) = 0;
  
  void increase_wealth(unsigned int);
  
  std::string get_name() const;
  
  bool pay_fee(unsigned int);
  
  void receive_license(std::unique_ptr<License>);
  
  void transfer_license(std::string, std::shared_ptr<Person>);
  
  bool eligible(std::string) const;
  
  //print method raw
  virtual std::ostream& print(std::ostream&) const;
};


////subclass Worker////
class Worker : public Person {
public:
  Worker(std::string, unsigned int = 0);
  
  void work(unsigned int);
  
  std::ostream& print(std::ostream&) const;
};


////subclass Superworker////
class Superworker : public Person {
private:
  unsigned int fee; 	//Extra Gehalt dass berechnet wird.
  
public:
  Superworker(unsigned int, std::string, unsigned int = 0);
  
  void work(unsigned int);
  
  std::ostream& print(std::ostream&) const;
};


////global////
std::ostream& operator<<(std::ostream&, const Person&);
std::ostream& operator<<(std::ostream&, const Worker&);
std::ostream& operator<<(std::ostream&, const Superworker&);


#endif
