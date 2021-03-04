#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Especialista.h"
#include<fstream>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
class Especialista;

class Enfermero: public Especialista
{
    private:
        int cod_Enf;
        int cod_Esp;
        string area;
        int cant;

    public:
        Enfermero();
        void Registrar_CodEnfermero(int );
        void Modificar_Enfermero();
        void Buscar_Enfermero();
        void Listar_Enfermero();


};

#endif // ENFERMERO_H
