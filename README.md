# lightning-am
*obs:this project is still under construction and, as of now, hasnt achieved a minimal viable product*


Converts presets (.xml) made in Alight motion into After effecs equivalent .ffx files. Allowing for modular user customization depending on installed Plugins on AE or their own implementations for certain effects

## How to Build
1.Be sure to have vcpkg set up on your system (building options for other package managers will come soon

2.run 
''' 
cmake --preset=gcc -DCMAKE_BUILD_TYPE=*Debug/Release*
cmake --build build 
'''
Executable will be generated at build/lightning-am

## Usage
1.Paste the desired alight motion xml file for conversion in the same folder as the executable

2.Be sure the alight motion effects used in the preset are supported by the program. Otherwise the program simply wont bring them to the final after effects composition

3.Open cmd in the executable directory and run 
'''
lightning-am -f your_file.xml -p plugin1 plugin2 
'''
4.If the program ran correctly, a json file will be generated.

*the rest of the readme will be build as the project is developed*

## Supported Effects









