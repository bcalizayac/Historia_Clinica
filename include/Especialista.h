#ifndef ESPECIALISTA_H
#define ESPECIALISTA_H
#include<fstream>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

class Especialista{
    private:
        string Nombre;
        string Apellido;
        int Cod_Esp;
        int DNI;
        string Genero;
        string ocupacion;
        int Telefono;
        string Correo;
        string Direccion;
        int Id_Esp;
        bool validar;
        string Contrasena;
    public:
        Especialista();
        void Registrar_Especialista(int ,int);
        int getId_Esp();
        void setId_Esp(int);
        bool getValidado();
        void setValidado(bool);
        void setcodEsp(int);
        void Listar_Especialista();
        void Mostrar_Especialista(int );
        void Modificar_Especialista();
};

#endif // ESPECIALISTA_H
