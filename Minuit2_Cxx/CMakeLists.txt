cmake_minimum_required(VERSION 3.1)
# This is a test of the Minuit2 CMake build system.

project(Fit LANGUAGES CXX)


# CMake should be able to find the Minuit2 package if you have either built it or installed it
find_package(Minuit2 CONFIG REQUIRED)

# Using a demo source and header file in current dir
add_executable(Fit
    ./Fit.cxx
    ./Fit.h
    )

# adding wstp stuffs
include_directories(/Applications/Mathematica.app/Contents/SystemFiles/Links/WSTP/DeveloperKit/MacOSX-ARM64/CompilerAdditions)  # Mac 
link_directories(/Applications/Mathematica.app/Contents/SystemFiles/Links/WSTP/DeveloperKit/MacOSX-ARM64/CompilerAdditions) #Mac
# include_directories(/usr/local/Wolfram/Mathematica/13.1/SystemFiles/Links/WSTP/DeveloperKit/Linux-x86-64/CompilerAdditions)  # Linux
# link_directories(/usr/local/Wolfram/Mathematica/13.1/SystemFiles/Links/WSTP/DeveloperKit/Linux-x86-64/CompilerAdditions) # Linux



# Linking with Minuit2::Minuit2 target
target_link_libraries(Fit PUBLIC Minuit2::Minuit2)

target_link_libraries(Fit PUBLIC
   /Applications/Mathematica.app/Contents/SystemFiles/Links/WSTP/DeveloperKit/MacOSX-ARM64/CompilerAdditions/libWSTPi4.a
   "-framework CoreFoundation"
)
#target_link_libraries(Fit PUBLIC
#    /usr/local/Wolfram/Mathematica/13.1/SystemFiles/Links/WSTP/DeveloperKit/Linux-x86-64/CompilerAdditions/libWSTP64i4.a
#)