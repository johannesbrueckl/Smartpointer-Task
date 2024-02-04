#ifndef GUILD_H
#define GUILD_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>

class Person;
class License;


class Guild{

private:
  //Instanzvariablen
  std::string name; 	//Name der Gilde (eindeutig).
  unsigned int fee; 	//Lizensgebühr.
  unsigned int salary; 	//Gehalt per Aufgabe.
  std::map<std::string, std::shared_ptr<Person>> members; 	//Gildenmitglieder.
  
public:
  //default constructor raw
  Guild(std::string, unsigned int, unsigned int, const std::vector<std::shared_ptr<Person>>& = {});
  
  //methods raw
  bool add_member(std::shared_ptr<Person>);
  
  bool remove_member(std::string);
  
  void grant_license(std::string);
  
  bool offer_job(std::shared_ptr<Person>) const;
  
  //print method raw
  std::ostream& print(std::ostream&) const;
};

////global////
std::ostream& operator<<(std::ostream&, const Guild&);

#endif
