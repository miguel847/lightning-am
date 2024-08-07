#include <iostream>
#include <fmt/core.h>
#include <pugixml.hpp>

using namespace std;

int main(int argc, char** argv){
  pugi::xml_document doc;
  pugi::parse_result data = doc.load_file()
	fmt::print("Hello Git \n");
	return 0;
}
