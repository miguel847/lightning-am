#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>
#include <ankerl/unordered_dense.h>
#include <pugixml.hpp>


using json = nlohmann::json;
typedef void (*func_ptr)(const pugi::xml_node&, json&, const std::vector<std::string>);

typedef struct Translator{
  ankerl::unordered_dense::map<std::string, func_ptr> dictionary;
  std::unique_ptr<json> translatedDoc;
  int numberOfPresetsWritten = 0;
  
  void translateAndWriteClip(const pugi::xml_node& clip, const std::vector<std::string> plugins);

  void initialize();

} translator;

