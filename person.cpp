#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "person.h"
#include "license.h"

//default constructor
Person::Person(std::string name, unsigned int wealth) : name {name}, wealth {wealth} {
  if(name.empty()) { throw std::runtime_error("illegal license constructor values"); }
}

//methods
void Person::work(std::string guild) {
  if(eligible(guild)){
    auto search = licenses.find(guild);
    work(search->second->get_salary());
    search->second->use();
  }
  else {
  throw std::runtime_error("not able to work");
  }
}
  
void Person::work(unsigned int i) {
	increase_wealth(i);
}
  
void Person::increase_wealth(unsigned int i) {
  wealth += i;
}

std::string Person::get_name() const {
  return name;
}

bool Person::pay_fee(unsigned int i) {
  if(i == 0 || wealth < i) {
    return false;
  }
  else {
  wealth -= i;
  return true;
  }
}
  
void Person::receive_license(std::unique_ptr<License> l) {
  licenses.insert_or_assign(l->get_guildname(), std::move(l));
}
  
void Person::transfer_license(std::string l, std::shared_ptr<Person> p){
  if(this->eligible(l)) {
    auto search = licenses.find(l);
    p->licenses.insert(std::make_pair(l, std::move(search->second)));
    this->licenses.erase(search);
  }
  else {
  throw std::runtime_error("license not found or valid");
  }
}
  
bool Person::eligible(std::string l) const {
	auto search = licenses.find(l);
  if(search != licenses.end()) {
    return search->second->valid();     
  }
  else {
  return false;
  }
}

//print method
std::ostream& Person::print(std::ostream& o) const {
  o << name << ", " << wealth << " Coins, {";
  bool first {true};
  for(auto e = licenses.begin(); e != licenses.end(); ++e) {
    if(first) {
      e->second->print(o);
      first = false;
    }
    else {
    o << ", ";
    e->second->print(o);
    }
  }
  o << "}]";
  return o;
}


////worker////
Worker::Worker(std::string name, unsigned int wealth) : Person(name, wealth) {}
  
void Worker::work(unsigned int i) {
  increase_wealth(i);
}
  
std::ostream& Worker::print(std::ostream& o) const {
  o << "[Worker ";
  Person::print(o);
  return o;
}


////superworker////
Superworker::Superworker(unsigned int fee, std::string name, unsigned int wealth) : Person(name, wealth), fee{fee} {}
  
void Superworker::work(unsigned int i) {
  increase_wealth(i + fee);
}
  
std::ostream& Superworker::print(std::ostream& o) const {
  o << "[Superworker ";
  Person::print(o);
  return o;
}


////global////
std::ostream& operator<<(std::ostream& o, const Person& p) {
    return p.print(o);
}
std::ostream& operator<<(std::ostream& o, const Worker& w) {
    return w.print(o);
}
std::ostream& operator<<(std::ostream& o, const Superworker& s) {
    return s.print(o);
}