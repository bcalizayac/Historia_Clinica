#ifndef INICIO_SESION_H
#define INICIO_SESION_H
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Especialista.h"

using namespace std;

class Inicio_Sesion
{
    private:
        string Codigo;
        string Contra;
        int codmed;
        string contmed;
        int codenf;
        string contenf;
        int ces;
    public:
        Inicio_Sesion();
        int Verificar_Usuario(int);
        int LogearMedico(int , int);
};

#endif // INICIO_SESION_H
