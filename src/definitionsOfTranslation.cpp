#include <iostream>
#include <vector>
#include <string>
#include "string.h"
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>
#include <ankerl/unordered_dense.h>
#include <pugixml.hpp>
#include <fmt/core.h>


using json = nlohmann::json;
typedef void (*func_ptr)(const pugi::xml_node&, json&, const std::vector<std::string>);

void oscillate(const pugi::xml_node& effect, json& translatedDoc, const std::vector<std::string> plugins){
  return; 
}
void exposure(const pugi::xml_node& effect, json& translatedDoc, const std::vector<std::string> plugins){
  return; 
}


typedef struct Translator{
  ankerl::unordered_dense::map<std::string, func_ptr> dictionary;
  std::unique_ptr<json> translatedDoc;
  int numberOfPresetsWritten = 0;
  
  void translateAndWriteClip(const pugi::xml_node& clip, const std::vector<std::string> plugins);
  void initialize();

} translator;

void Translator::initialize(){
  translatedDoc = std::make_unique<json>();
    
  //Inserts translation functions into map, unfortenatly this needs to be done manually :(
  //key is effect id in xml file and value is adress of translation function
  dictionary["com.alightcreative.effects.oscillate"] = &oscillate;
  dictionary["com.alightcreative.effects.exposure"] = &exposure;
}

void Translator::translateAndWriteClip(const pugi::xml_node& clip, const std::vector<std::string> plugins){
  (*translatedDoc)["preset"+std::to_string(numberOfPresetsWritten)] = {};

  for (pugi::xml_node property : clip.children()){
    if (strcmp(property.name(),"effect") == 0){
      fmt::print("{} \n", property.attribute("id").value());
    }
  }
}

