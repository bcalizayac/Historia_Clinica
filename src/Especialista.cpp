#include "Especialista.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

Especialista :: Especialista(){
    Nombre="";
    Apellido="";
    Cod_Esp="";
    DNI=0;
    Genero="";
    ocupacion="";
    Telefono;
    Correo="";
    Direccion="";
    Id_Esp=0;
    Contrasena="";
}

void Especialista :: Registrar_Especialista(int cod,int codeesp){
int pc, vw=0;
    bool a;
    ifstream espci;
    ofstream esp;
    ofstream contrasena;
    char aux;
    contrasena.open("contraseñas.txt",ios::out);
    espci.open("especialistas.txt", ios::in);
    esp.open("especialistas.txt", ios::app);
    if(espci.fail()&&esp.fail()&&(contrasena.fail())){
        cout<<"No se encontro el archivo";
    }
    else{
        cout<<"\t\tRegistro"<<endl;
        cout<<"\t\t--------"<<endl;
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
        cout<<"Ingrese el Nombre: ";
        fflush(stdin);
        getline(cin,Nombre);
        cout<<"Ingrese el Apellido: ";
        getline(cin,Apellido);
        fflush(stdin);
        cout<<"Ingrese el DNI: ";
        cin>>DNI;
        fflush(stdin);
        cout<<"Ingrese el Genero: ";
        getline(cin,Genero);
        switch(Cod_Esp){
        case 1:
            ocupacion="Medico";
        break;
        case 2:
            ocupacion="Enfermero";
        break;

        }
        cout<<"Ingrese el nro. de Telefono: ";
        fflush(stdin);
        cin>>Telefono;
        fflush(stdin);
        cout<<"Ingrese el Correo: ";
        getline(cin,Correo);
        fflush(stdin);
        cout<<"Ingrese la Direccion: ";
        getline(cin,Direccion);
        fflush(stdin);
        cout<<"Ingrese la Contrasena: ";
        getline(cin,Contrasena);
        contrasena<<Id_Esp<<" "<<Contrasena;
        esp<<Id_Esp<<" "<<Nombre<<" "<<Apellido<<" "<<Cod_Esp<<" "<<DNI<<" "<<Genero<<" "<<ocupacion<<" "<<Telefono<<" "<<Correo<<" "<<Direccion<<" "<<Contrasena<<endl;
    }
    }
    vw=0;
    contrasena.close();
    espci.close();
    esp.close();
}


void Especialista :: Listar_Especialista(int n){
    cout<<"Identificacion: "<<Id_Esp;
    cout<<"Nombre: "<<Nombre;
    cout<<"Apellido: "<<Apellido;
    cout<<"DNI: "<<DNI;
    cout<<"Genero: "<<Genero;
    cout<<"Ocupacion: "<<ocupacion;
    cout<<"Telefono: "<<Telefono;
    cout<<"Correo: "<<Correo;
    cout<<"Direccion: "<<Direccion;
    cout<<"Codigo: "<<Cod_Esp;
}

void Especialista :: Mostrar_Especialista(){
    cout<<"Nombre: "<<Nombre;
    cout<<"Apellido: "<<Apellido;
    cout<<"DNI: "<<DNI;
    cout<<"Genero: "<<Genero;
    cout<<"Ocupacion: "<<ocupacion;
    cout<<"Telefono: "<<Telefono;
    cout<<"Correo: "<<Correo;
    cout<<"Direccion: "<<Direccion;
    cout<<"Codigo de Identificacion: "<<Id_Esp;
}

void Especialista :: Modificar_Especialista(){
    int op, dt=0;
    cout<<"\t\tModificar Datos de Especialista"<<endl;
    do{
        cout<<"\t1.Nombre"<<endl;
        cout<<"\t2.Apellido"<<endl;
        cout<<"\t3.DNI"<<endl;
        cout<<"\t4.Genero"<<endl;
        cout<<"\t5.Ocupacion"<<endl;
        cout<<"\t6.Telefono"<<endl;
        cout<<"\t7.Correo"<<endl;
        cout<<"\t8.Direccion"<<endl;
        cout<<"\t9.Codigo de Identificacion"<<endl;
        cout<<"\t10.Salir"<<endl;
        cout<<"Escoja que dato desea modificar: ";
        cin>>op;
        switch(op){
            case 1:
                cout<<"Ingrese el nuevo nombre: ";
                fflush(stdin);
                cin>>Nombre;
                break;
            case 2:
                cout<<"Ingrese el nuevo Apellido: ";
                fflush(stdin);
                cin>>Apellido;
                break;
            case 3:
                cout<<"Ingrese el nuevo nro. DNI: ";
                fflush(stdin);
                cin>>DNI;
                break;
            case 4:
                cout<<"Ingrese el Genero: ";
                fflush(stdin);
                cin>>Genero;
                break;
            case 5:
                cout<<"Ingrese la nueva Ocupacion: ";
                fflush(stdin);
                cin>>ocupacion;
                break;
            case 6:
                cout<<"Ingrese el nuevo nro. de Telefono: ";
                cin>>Telefono;
                break;
            case 7:
                cout<<"Ingrese el nuevo Correo: ";
                fflush(stdin);
                cin>>Correo;
                break;
            case 8:
                cout<<"Ingrese la nueva Direccion: ";
                fflush(stdin);
                cin>>Direccion;
                break;
            case 9:
                cout<<"Ingrese el nuev Codigo de Identificacion: ";
                cin>>Id_Esp;
                break;
            case 10:
                dt=1;
            default:
                cout<<"Dato erroneo";
        }
    }while(dt==1);
}
