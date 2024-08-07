#include <iostream>
#include <fmt/core.h>
#include <pugixml.hpp>
#include <string>
#include "cstring"

using namespace std;

int main(int argc, char *argv[]){
  
  bool fileFound = false;
  std::string fileName;

  for (int i = 0; i < argc; ++i){
    if (strcmp(argv[i],"-f") == 0){
      if (argv[i+1] != nullptr){
        fmt::print("{} \n", argv[i+1]);
        fileFound = true;
        fileName = argv[i+1];
      }
      else {
        fmt::print("xml file not passed or passed incorectly");
        return -1;
      }
    }
  }
  if (!fileFound){
    fmt::print("Xml file hasnt been found, use -f file_name when executing file in command line");
    return -1;
  }

  pugi::xml_document doc;
  pugi::xml_parse_result data = doc.load_file(fileName.c_str());
	fmt::print("Size of data: {} \n", sizeof(data));
	return 0;
}
