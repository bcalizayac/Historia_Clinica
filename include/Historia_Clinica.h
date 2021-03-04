#ifndef HISTORIA_CLINICA_H
#define HISTORIA_CLINICA_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Paciente;

class Historia_Clinica
{
    private:
            int N_Hist;
            int codPac;
            int aux;
            string Estado;
            string fecha;

    public:
        Historia_Clinica();
        int getcodPac();
        void setcodPac(int);
        void Registrar_Historia();
        void Buscar_Historia(int );
        void Listar_Historia();
        void Modificar_Historia();
        void Eliminar_Paciente(int);

};

#endif // HISTORIA_CLINICA_H
