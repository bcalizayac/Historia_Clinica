#ifndef ESPECIALISTA_H
#define ESPECIALISTA_H
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Inicio_Sesion.h"

using namespace std;

class Especialista{
    private:
        string Nombre;
        string Apellido;
        string Cod_Esp;
        int DNI;
        string Genero;
        string ocupacion;
        int Telefono;
        string Correo;
        string Direccion;
        int Id_Esp;
        string Contrasena;
    public:
        Especialista();
        void Registrar_Especialista(int , int);
        void Listar_Especialista(int );
        void Mostrar_Especialista();
        void Modificar_Especialista();
        friend class Inicio_Sesion;
};

#endif // ESPECIALISTA_H
