#ifndef MEDICO_H
#define MEDICO_H
#include "Especialista.h"
#include <iostream>

using namespace std;

class Medico:public Especialista
{
    private:
        int cod_Med;
        int cod_Esp;
        string area;
        int cant;
    public:
        Medico();
        void Registrar_CodMedico(int );
        void Modificar_Medico();
        void Buscar_Medico();
        void Listar_Medico();
};

#endif // MEDICO_H
