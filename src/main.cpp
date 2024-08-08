#include <iostream>
#include <fmt/core.h>
#include <pugixml.hpp>
#include <CLI/CLI.hpp>
#include <string>
#include "cstring"
#include <vector>

using namespace std;

int main(int argc, char** argv){
  
  string fileName = "default";
  vector<string> plugins = {};

  CLI::App app{"Convert Alight Motion xml elements to After effects presets"};
  app.add_option("-f,--file", fileName, "-f yourfilename.xml, required")->required()->check(CLI::ExistingFile);
  app.add_option("-p,--plugins", plugins, "Pass all the plugins available that could be used instead of native AE effects");

  CLI11_PARSE(app, argc, argv);


  fmt::print("Plugins: [");
  for (auto i : plugins){
    fmt::print("{},", i);
  }
  fmt::print("] \n");

  pugi::xml_document doc;
  pugi::xml_parse_result data = doc.load_file(fileName.c_str());
	return 0;
}
