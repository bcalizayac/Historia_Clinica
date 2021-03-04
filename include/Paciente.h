#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
#include<iostream>
#include <fstream>
#include "Historia_Clinica.h"
using namespace std;
class Paciente
{
    private:
        string Nombres;
        string Apellidos;
        int DNI;
        int edad;
        string Genero;
        float masa;
        string Tipo_Sangre;
        int telefono;
        int codigo;
        string Nom_Ap;
        string Apell_Ap;
        int DNI_Ap;
        string Nacimiento;
        string Parentesco_Ap;
        float Talla;
        int cantidad;
        Historia_Clinica *Historia; //composicion

    public:
        Paciente();
        int get_cantidad();
        void set_cantidad(int);
        void Registrar_Paciente();
        void Listar_Paciente();
        void Modificar_Paciente();
        void Encontrar_Paciente(int );
        void Eliminar_Paciente();
        void Historia_Clin(int);

};

#endif // PACIENTE_H
