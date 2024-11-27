# Demo-MInuit2-MMA
A simple demo of connecting [a standalone Minuit2](https://github.com/GooFit/Minuit2) with Mathematica via WSTP.

# Reference
## WSTP
    - [基于WSTP的C++与Mathematica的混合编程及其应用](https://zhuanlan.zhihu.com/p/24988238?from_voters_page=true)
    - [WSTP API](https://reference.wolfram.com/language/guide/WSTPAPI.html)
    - [WSTPDeveloperGuide-WindowsOverview](https://reference.wolfram.com/language/tutorial/WSTPDeveloperGuide-WindowsOverview.html)
## CMake
    - [全网最细的CMake教程！(强烈建议收藏)](https://zhuanlan.zhihu.com/p/534439206)

# Installation and Usage
## Install [a standalone Minuit2](https://github.com/GooFit/Minuit2) with Cmake
1. install ``Cmake`` and ``make``
2. install Minuit2
```bash
mkdir PATH_TO_MINIUT2_BUILD
cd PATH_TO_MINUIT2_BUILD
cmake PATH_TO_MINUIT2_SOURCE
cmake --build .
```

## Modify ``Fit.cxx`` and ``Fit.h`` for your need
## Modify ``CMakeList.txt``
change the ``include_directories``, ``link_directories`` and ``target_link_libraries`` of WSTP on your laptop accordingly.
## Build Cmake project
```bash
cmake .
make
```
and then there should be an executable filed generated along with which you can run ``Mathematica`` to fit.