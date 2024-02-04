#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<stdexcept>
#include<set>
#include<algorithm>
#include<map>
#include "guild.h"
#include "license.h"
#include "person.h"

//default constructor
Guild::Guild(std::string n, unsigned int f, unsigned int s, const std::vector<std::shared_ptr<Person>>& m) : name {n}, fee {f}, salary {s}  {
  if(n.empty() || f <= 0 || s <= 0) { throw std::runtime_error("illegal license constructor values"); }
	
  for(auto e : m) {
  	if (!(members.emplace(e->get_name(), e).second))
    	throw std::runtime_error("illegal license constructor values");
	}
}
  
//methods
bool Guild::add_member(std::shared_ptr<Person> p) { 
  if (members.emplace(p->get_name(), p).second) {
    return true;
  }
  else {
  return false;
  }
}
  
bool Guild::remove_member(std::string n) {
  auto search = members.find(n);
  if(search != members.end()) {
    members.erase(search);
    return true;
  }
  else {
  return false;
  }
}
  
void Guild::grant_license(std::string n) {
  auto search = members.find(n);
  if(search != members.end()) {
    if(search->second->pay_fee(fee)) {
      search->second->receive_license(std::make_unique<License>(name, salary));
    }
    else {
      throw std::runtime_error("not a member or too poor");
    }
  }
  else {
  throw std::runtime_error("not a member or too poor");
  }
}
  
bool Guild::offer_job(std::shared_ptr<Person> p) const {
  auto search = members.find(p->get_name());
  if(search != members.end()) {
    search->second->work(salary * 2);
    return true;
  }
  else {
  try {
  p->work(name);
  }
  catch(std::runtime_error e) {
    return false;
  }
  return true;
  }
}

//print method  
std::ostream& Guild::print(std::ostream& o) const {
  o << '[' << name << ", License fee: " << fee << ", Job salary: " << salary << ", {";
  bool first {true};
  for(auto e : members) {
    if(first) {
      o << e.first;
      first = false;
    }
    else {
    o << ", " << e.first;
    }
  }
  o << "}]";
  return o;
}

////global////
std::ostream& operator<<(std::ostream& o, const Guild& g) {
    return g.print(o);
}