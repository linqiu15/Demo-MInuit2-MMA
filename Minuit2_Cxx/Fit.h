// Using FCNBase
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include "Minuit2/FCNBase.h"
#include "Minuit2/MnMigrad.h"
#include "Minuit2/FunctionMinimum.h"
#include "Minuit2/MnPrint.h"
#include "wstp.h"

namespace ROOT
{

    namespace Minuit2
    {
        class FunctionFit : public FCNBase
        {
        public:
            FunctionFit() : fErrorDef(1.)
            {
                env = WSInitialize((WSEnvironmentParameter)0);
                if ((WSENV)0 == env)
                {
                    std::cout << "Unable to initialize environment..." << std::endl;
                }
                else
                {
                    std::cout << "The environment is initialized successfully..." << std::endl;
                }
                int argc = 4;
                char *argv[5] = {"-linkname", "QuadraticFunctionFit", "-linkmode", "connect", NULL};
                Link = WSOpen(argc, argv);
                if ((WSLINK)0 == Link)
                {
                    std::cout << " Unable to create the link..." << std::endl;
                }
                else
                {
                    std::cout << "Link is Created successfully..." << std::endl;
                }
                WSGetInteger32(Link, &NumOfParas);
                WSGetInteger32(Link, &dof);
                std::cout << "The Number of Parameters is:" << NumOfParas << std::endl;
                std::cout << "The Value of d.o.f is:" << dof << std::endl;
            }
            ~FunctionFit() {}
            virtual double Up() const { return fErrorDef; }
            void SetErrorDef(double ErrorDef) { fErrorDef = ErrorDef; }
            virtual double operator()(const std::vector<double> &Paras) const
            {
                double ReturnChiSqure;
                assert(Paras.size() == NumOfParas);
                std::for_each(Paras.begin(), Paras.end(), [](double item)
                              { std::cout << item << "   " << std::endl; });
                WSPutReal64List(Link, &Paras[0], NumOfParas);
                WSGetReal64(Link, &ReturnChiSqure);
                std::cout << "chiSqure/d.o.f=" << ReturnChiSqure / dof << std::endl;
                return ReturnChiSqure;
            }
            void LinkCloseAndDeinitialize()
            {
                WSClose(Link);
                WSDeinitialize(env);
                std::cout << "The link has been shuted down..." << std::endl;
            }

        private:
            WSENV env;
            WSLINK Link;
            double fErrorDef;
            int NumOfParas;
            int dof;
        };

    } // namespace Minuit2

} // namespace ROOT