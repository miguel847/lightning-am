#include <iostream>
#include <fmt/core.h>
#include <pugixml.hpp>

using namespace std;

int main(int argc, char** argv){
  
  bool fileFound = false;

  pugi::xml_document doc;
  for (int i = 0; i < argc; ++i){
    if (argv[i] == "-f"){
      fmt::print("{} \n", argv[i+1]);
      fileFound = true;
    }
  }
  if (!fileFound){
    fmt::print("Xml file hasnt been found, use -f file_name when executing file in command line");
    return -1;
  }
  pugi::xml_parse_result data = doc.load_file(argv[1]);
	fmt::print("Hello Git \n");
	return 0;
}
