#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>
#include <ankerl/unordered_dense.h>
#include <pugixml.hpp>


using json = nlohmann::json;
typedef void (*func_ptr)(pugi::xml_node&, json&, std::vector<std::string>);

void oscillate(pugi::xml_node& effect, json& translatedDoc, std::vector<std::string> plugins){
  return; 
}
void exposure(pugi::xml_node& effect, json& translatedDoc, std::vector<std::string> plugins){
  return; 
}


typedef struct translator{
  ankerl::unordered_dense::map<std::string, func_ptr> dictionary;
  std::unique_ptr<json> translatedDoc;

  void initialization(){
    translatedDoc = std::make_unique<json>();
    
    //Inserts translation functions into map, unfortenatly this needs to be done manually :(
    //key is effect id in xml file and value is adress of translation function
    dictionary["com.alightcreative.effects.oscillate"] = &oscillate;
    dictionary["com.alightcreative.effects.exposure"] = &exposure;
  }

} translator;

