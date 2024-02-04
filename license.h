#ifndef LICENSE_H
#define LICENSE_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>


class License{
  
private:
  //Instanzvariablen
  std::string name; 	//name der ausstellenden Gilde.
  unsigned int salary; 	//Lohn einer Aufgabe.
  unsigned int counter; 	//erledigte aufgaben.
  
public:
  //default constructor raw
  License(std::string, unsigned int);
  
  //methods raw
  std::string get_guildname() const;
  
  unsigned int get_salary() const;
  
  bool valid() const;
  
  bool use();
  
  //print method raw
  std::ostream& print(std::ostream&) const;
    
};

////global////
std::ostream& operator<<(std::ostream&, const License&);
#endif
