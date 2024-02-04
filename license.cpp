#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "license.h"

//default constructor implementation
License::License(std::string name, unsigned int salary) : name {name}, salary {salary}, counter {0} {
	if(name.empty() || salary <= 0) {
  	throw std::runtime_error("illegal license constructor values");
  }
}

//methods implementation
std::string License::get_guildname() const {
  return name;
}

unsigned int License::get_salary() const {
  return salary;
}

bool License::valid() const {
  if(counter <= 3) {
    return true;
  }
  else {
  return false;
  }
}

bool License::use() {
  if(valid()) {
    counter++;
		return true;
  }
  else {
  return false;
  }
}

//print method
std::ostream& License::print(std::ostream& o) const {
  o << "[License for " << name << ", Salary: " << salary << ", Used: " << counter << ']';
  return o;
}

////global////
std::ostream& operator<<(std::ostream& o, const License& l) {
    return l.print(o);
}