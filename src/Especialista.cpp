#include "Especialista.h"
#include "Enfermero.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Historia_Clinica.h"
Especialista::Especialista()
{

}
bool Especialista::getValidado(){
    return validar;
}
void Especialista::setValidado(bool a){
    validar=a;
}

int Especialista::getId_Esp(){
return Id_Esp;
}
void Especialista::setId_Esp(int i){
Id_Esp=i;
}


void Especialista::setcodEsp(int c){
Cod_Esp=c;
}

void Especialista :: Registrar_Especialista(int cod,int codeesp){
int pc, vw=0;
    bool a;
    ifstream espci;
    ofstream esp;
    ofstream contrasena;
    char aux;
    contrasena.open("contraseñas.txt",ios::app);
    espci.open("especialistas.txt", ios::in);
    esp.open("especialistas.txt", ios::app);
    if(espci.fail()&&esp.fail()&&(contrasena.fail())){
        cout<<"No se encontro el archivo";
    }
    else{
        cout<<"\n\t\t\tRegistro"<<endl;
        cout<<"\t\t\t--------"<<endl;
        espci>>Id_Esp;
        FILE *rv;
        rv = fopen( "especialistas.txt", "r" );
        fseek( rv, 0, SEEK_END );
        if (ftell( rv ) == 0 )
        {
            cout<<"Archivo vacio"<<endl;
        }
        else{
            while(!espci.eof())
            {
                espci>>Nombre>>Apellido>>Cod_Esp>>DNI>>Genero>>ocupacion>>Telefono>>Correo>>Direccion>>Contrasena;
                if(Id_Esp==codeesp){
                    cout<<"Ya existe un especialista con este Codigo, ingrese otro codigo";
                    vw=1;
                    a=false;
                setValidado(a);

                }
                espci>>Id_Esp;
            }
        }

        if(vw==0){
            a=true;
            setValidado(a);

            Cod_Esp=cod;
            Id_Esp=codeesp;
            cout<<"\t\tIngrese el Nombre: ";
            fflush(stdin);
            getline(cin,Nombre);
            cout<<"\t\tIngrese el Apellido: ";
            getline(cin,Apellido);
            fflush(stdin);
            cout<<"\t\tIngrese el DNI: ";
            cin>>DNI;
            fflush(stdin);
            int gn=0;
            do{
                cout<<"\t\tIngrese el Genero(Femenino/Masculino): ";
                fflush(stdin);
                cin>>Genero;
                if(Genero=="Masculino"){
                    gn=1;
                }
                if(Genero=="Femenino"){
                    gn=1;
                }
            }while(gn==0);
            switch(Cod_Esp){
                case 1:
                    ocupacion="Medico";
                break;
                case 2:
                    ocupacion="Enfermero";
                break;
            }
            cout<<"\t\tIngrese el nro. de Telefono: ";
            fflush(stdin);
            cin>>Telefono;
            fflush(stdin);
            cout<<"\t\tIngrese el Correo: ";
            getline(cin,Correo);
            fflush(stdin);
            cout<<"\t\tIngrese la Direccion: ";
            getline(cin,Direccion);
            fflush(stdin);
            cout<<"\t\tIngrese la Contrase"<<char(164)<<"a: ";
            getline(cin,Contrasena);
            contrasena<<Id_Esp<<" "<<Contrasena<<" "<<Cod_Esp<<endl;
            esp<<Id_Esp<<" "<<Nombre<<" "<<Apellido<<" "<<Cod_Esp<<" "<<DNI<<" "<<Genero<<" "<<ocupacion<<" "<<Telefono<<" "<<Correo<<" "<<Direccion<<" "<<Contrasena<<endl;
        }
    }
    vw=0;
    contrasena.close();
    espci.close();
    esp.close();
}

void Especialista :: Mostrar_Especialista(int c){
    ifstream encontrar;
    encontrar.open("especialistas.txt",ios::in);
    if(encontrar.is_open()){
        encontrar>>Id_Esp;
        while(!encontrar.eof()){
            encontrar>>Nombre>>Apellido>>Cod_Esp>>DNI>>Genero>>ocupacion>>Telefono>>Correo>>Direccion>>Contrasena;
            if(Id_Esp==c){
                cout<<"\t\t\t    Registro Especialista encontrado   "<<endl;
                cout<<"\t\t\t----------------------------------------"<<endl;
                cout<<"\n\t\tIdentificacion del Especialista: "<<Id_Esp<<endl;
                cout<<"\n\t\tNombre del Especialista: "<<Nombre<<endl;
                cout<<"\n\t\tApellido del Especialista: "<<Apellido<<endl;
                cout<<"\n\t\tCodigo del Especialista: "<<Cod_Esp<<endl;
                cout<<"\n\t\tDNI del Especialista: "<<DNI<<endl;
                cout<<"\n\t\tGenero del Especialista: "<<Genero<<endl;
                cout<<"\n\t\tOcupacion del Especialista: "<<ocupacion<<endl;
                cout<<"\n\t\tTelefono del Especialista: "<<Telefono<<endl;
                cout<<"\n\t\tCorreo del Especialista: "<<Correo<<endl;
                cout<<"\n\t\tDireccion del Especialista: "<<Direccion<<endl;
                cout<<"\n\t\tContraseña del Especialista: "<<Contrasena<<endl;
            }
            encontrar>>Id_Esp;
        }
    }
    else{
        cout<<"\n\t\tNo se ha encontrado el archivo...";
    }
    encontrar.close();
    system("pause");
    system("cls");
}
