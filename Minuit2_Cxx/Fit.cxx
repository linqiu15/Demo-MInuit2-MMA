#include "Fit.h"

using namespace ROOT::Minuit2;

int main()
{
    FunctionFit QuadraticFunctionFit;
    MnUserParameters UserParameters;
    UserParameters.Add("a", 1.0, 1.0);
    UserParameters.Add("b", 1.0, 1.0);
    UserParameters.Add("c", 1.0, 1.0);
    MnMigrad mnmigrad(QuadraticFunctionFit, UserParameters, 0);
    FunctionMinimum Min = mnmigrad();
    std::cout << Min.UserParameters() << std::endl;
    std::ofstream Minout("Minout.txt");
    Minout << "The total number of function calls during the minimization is:" << Min.NFcn() << std::endl;
    Minout << Min.UserParameters() << std::endl;
    Minout.close();
    QuadraticFunctionFit.LinkCloseAndDeinitialize();
    system("pause");

    return 0;
}