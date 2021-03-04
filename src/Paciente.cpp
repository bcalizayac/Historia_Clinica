#include "Paciente.h"
#include<string>
#include<string.h>
#include<iostream>
#include <fstream>
#include "Historia_Clinica.h"
using namespace std;
Paciente::Paciente()
{
    Nombres="";
    Apellidos="";
    Genero="";
    Tipo_Sangre="";
    Nacimiento="";
    Parentesco_Ap="";
    Nom_Ap="";
    Apell_Ap="";
    Historia=new Historia_Clinica;
}
void Paciente::set_cantidad(int cant){
cantidad=cant;
}
int Paciente::get_cantidad(){
return cantidad;
}

void Paciente::Registrar_Paciente(){
    int n,codguardado;
    char aux;
    bool repetido=false;
    ifstream consulta;
    ofstream archivo;
    consulta.open("pacientes.txt",ios::in);
    archivo.open("pacientes.txt",ios::app);
    if(archivo.fail()&& consulta.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    else{
    cout<<"\n---REGISTRO DE PACIENTES---"<<endl<<endl;
    cout<<"Cantidad de pacientes: ";
    cin>>n;
        for(int i=0;i<n;i++){
        do{
        repetido=false;
        cout<<"Codigo: ";
        cin>>codguardado;
        FILE *rv;
        rv = fopen( "pacientes.txt", "r" );
        fseek( rv, 0, SEEK_END );
        if (ftell( rv ) == 0 )
        {
        cout<<"Archivo vacio"<<endl;
        }
        else{
        consulta>>codigo;
         while(!consulta.eof()){
            consulta>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
            consulta>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;}
            if(codigo==codguardado){
                cout<<"Ya existe un registro con ese codigo, vuelva a ingresar los datos"<<endl;
                repetido=true;
                break;
            }
            consulta>>codigo;
            }


        }
        if(repetido==false){
        codigo=codguardado;
        cin.get(aux);
        cout<<"Ingrese los nombres: ";
        getline(cin,Nombres);
        cout<<"Ingrese los apellidos: ";
        fflush(stdin);
        getline(cin,Apellidos);
        cout<<"Ingrese la edad: ";
        cin>>edad;
        cout<<"Ingrese el DNI: ";
        cin>>DNI;
        cout<<"Ingrese el Genero: ";
        cin.get(aux);
        getline(cin,Genero);
        cout<<"Ingrese la masa: ";
        cin>>masa;
        cout<<"Ingrese el tipo de sangre: ";
        cin.get(aux);
        getline(cin,Tipo_Sangre);
        cout<<"Ingrese la talla: ";
        cin>>Talla;
        cout<<"Ingrese el nacimiento: ";
        cin.get(aux);
        getline(cin,Nacimiento);
            if((edad<18)){
            cout<<"DATOS DEL APODERADO"<<endl<<endl;
            cout<<"Ingrese el nombre completo: ";
            getline(cin,Nom_Ap);
            cout<<"Ingrese los apellidos: ";
            getline(cin,Apell_Ap);
            cout<<"Ingrese el parentesco: ";
            getline(cin,Parentesco_Ap);
            cout<<"Ingrese el DNI: ";
            cin>>DNI_Ap;
            archivo<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
            }
            else{
                archivo<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
            }

            }

            }while(repetido==true);

        }
    }
    consulta.close();
    archivo.close();
}
void Paciente::Listar_Paciente(){
    int A[100],i=0,cant,pos,aux;
     FILE *rv;
    rv = fopen( "historias.txt", "r" );
    fseek( rv, 0, SEEK_END );
    if (ftell( rv ) == 0 )
    {
        cout<<"Archivo vacio"<<endl;
    }
    else{
    ifstream listar;
    listar.open("pacientes.txt",ios::in);
    if(listar.is_open()){
        listar>>codigo;
        while(!listar.eof()){
            listar>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
            listar>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;
            }
            A[i]=codigo;
            listar>>codigo;
            i++;
            }
    }
    else{
        cout<<"No se ha encontrado el archivo...";
    }
        cant=i;
    //insercion
    for(int i=0;i<cant;i++){
        pos=i;
        aux=A[i];
        while((pos>0)&&(A[pos-1]>aux)){
            A[pos]=A[pos-1];
            pos--;
        }
        A[pos]=aux;
    }
    i=0;
   do{
    listar.open("pacientes.txt",ios::in);
    if(listar.is_open()){
        listar>>codigo;
         while(!listar.eof()){
            listar>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
            listar>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;
            }
            if(codigo==A[i]){
                cout<<"Codigo: "<<codigo<<endl;
                cout<<"Nombre: "<<Nombres<<endl;
                cout<<"Apellidos: "<<Apellidos<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"DNI: "<<DNI<<endl;
                cout<<"Genero: "<<Genero<<endl;
                cout<<"Masa: "<<masa<<endl;
                cout<<"Talla: "<<Talla<<endl;
                cout<<"Tipo de sangre: "<<Tipo_Sangre<<endl;
                cout<<"Nacimiento: "<<Nacimiento<<endl;
                if(edad<18){
                cout<<"Nombre del Apoderado: "<<Nom_Ap<<endl;
                cout<<"Apellido del Apoderado: "<<Apell_Ap<<endl;
                cout<<"DNI: "<<DNI_Ap<<endl;
                cout<<"Parentesco: "<<Parentesco_Ap<<endl;
                }
            }
                        listar>>codigo;

            }
    }
    else{
        cout<<"No se ha encontrado el archivo...";
    }
        i++;

     listar.close();
     }while(i!=cant);
    }
             system("PAUSE");


}

void Paciente::Encontrar_Paciente(int c){
    ifstream encontrar;
    encontrar.open("pacientes.txt",ios::in);
    if(encontrar.is_open()){
        encontrar>>codigo;
        while(!encontrar.eof()){
            encontrar>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
            encontrar>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;
            }
            if(codigo==c){
                cout<<"Registro encontrado..."<<endl<<endl;
                cout<<"Codigo: "<<codigo<<endl;
                cout<<"Nombre: "<<Nombres<<endl;
                cout<<"Apellidos: "<<Apellidos<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"DNI: "<<DNI<<endl;
                cout<<"Genero: "<<Genero<<endl;
                cout<<"Masa: "<<masa<<endl;
                cout<<"Talla: "<<Talla<<endl;
                cout<<"Tipo de sangre: "<<Tipo_Sangre<<endl;
                cout<<"Nacimiento: "<<Nacimiento<<endl;
                if(edad<18){
                cout<<"Nombre del Apoderado: "<<Nom_Ap<<endl;
                cout<<"Apellido del Apoderado: "<<Apell_Ap<<endl;
                cout<<"DNI: "<<DNI_Ap<<endl;
                cout<<"Parentesco: "<<Parentesco_Ap<<endl;
                }
            }
            encontrar>>codigo;

    }
    }
    else{
        cout<<"No se ha encontrado el archivo...";
    }
     encontrar.close();
}
void Paciente::Eliminar_Paciente(){
    int codi;
    ifstream eliminar;
    ofstream entrada;
    eliminar.open(("pacientes.txt"),ios::in);
    entrada.open(("temporal.txt"),ios::out);
    if(eliminar.fail()){
        cout<<"Existe un error al abrir el archivo...";
    }
    else{
        cout<<"Introduzca el codigo: ";
        cin>>codi;
        eliminar>>codigo;
        while(!eliminar.eof()){
            eliminar>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
            eliminar>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;}
                if(codi==codigo){

                    cout<<"Eliminado..."<<endl;
                }
                else{
                        if(edad<18){
                            entrada<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                        }
                        else{
                        entrada<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;

                        }
                }

                eliminar>>codigo;
        }

    entrada.close();
    eliminar.close();
    remove("pacientes.txt");
    rename("temporal.txt","pacientes.txt");
    Historia->Eliminar_Paciente(codi);
    }

}

void Paciente::Modificar_Paciente(){
	ofstream aux;
	ifstream lectura;
	char espacio;
	bool encontrado=false;
	int auxcodigo,auxdni,auxtel,auxdniap,op,auxedad;
	float auxmasa,auxtalla;
	string auxnom,auxapell,auxgen,auxts,auxNomAp,auxApelAp,auxnac,auxparen;
	aux.open("auxiliar.txt",ios::out);
	lectura.open("pacientes.txt",ios::in);
	if(aux.is_open() && lectura.is_open()){
		cout<<"Ingrese el codigo del paciente a modificar: "<<endl;
		cin>>auxcodigo;
		lectura>>codigo;
		while(!lectura.eof()){
		lectura>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
            lectura>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;
            }
          	  if(auxcodigo==codigo){
            	encontrado=true;
                   Encontrar_Paciente(auxcodigo);
					cout<<"\n\nElija la opción a modificar: "<<endl<<endl;
                    cout<<"1.Nombres\n2.Apellidos\n3.Edad\n4.DNI\n5.Genero\n6.Masa\n7.Talla\n8.Tipo de sangre\n9.Fecha de Nacimiento"<<endl;
                    if(edad<18){
                    cout<<"10.Nombre del Apoderado\n11.Apellidos del apoderado\n12.DNI del apoderado\n13.Parentesco"<<endl;
                    }
                       cin>>op;
                       if(edad>=18){
                       switch(op){
                            case 1:
                                cout<<"Nombres: ";
                                cin.get(espacio);
                                getline(cin,auxnom);
                                aux<<codigo<<" "<<auxnom<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;

                                system("PAUSE");
                            break;
                            case 2:
                                 fflush(stdin);
                            	cout<<"Apellidos: ";
                                getline(cin,auxapell);
                                aux<<codigo<<" "<<Nombres<<" "<<auxapell<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 3:
                            	cout<<"Edad: ";
                                cin>>auxedad;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<auxedad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 4:
                            	cout<<"DNI: ";
                                cin>>auxdni;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<auxdni<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 5:
                            	cout<<"Masa: ";
                                cin>>auxmasa;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<auxmasa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 6:
                            	cout<<"Talla: ";
                                cin>>auxtalla;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<auxtalla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 7:
                            	cout<<"Genero: ";
                                cin.get(espacio);
                                getline(cin,auxgen);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<auxgen<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 8:
                                cin.get(espacio);
                            	cout<<"Tipo de sangre: ";
                                getline(cin,auxts);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<auxts<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 9:
                                cout<<"Fecha de nacimiento: ";
                                getline(cin,auxnac);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<auxnac<<endl;
                                system("PAUSE");
                            break;
                            default:
                            break;
                       }
                       }
                       else{
                           switch(op){
                            case 1:
                                cout<<"Nombres: ";
                                cin.get(espacio);
                                getline(cin,auxnom);
                                aux<<codigo<<" "<<auxnom<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                fflush(stdin);
                                system("PAUSE");
                            break;
                            case 2:
                                fflush(stdin);
                            	cout<<"Apellidos: ";
                                getline(cin,auxapell);
                                aux<<codigo<<" "<<Nombres<<" "<<auxapell<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 3:
                            	cout<<"Edad: ";
                                cin>>auxedad;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<auxedad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 4:
                            	cout<<"DNI: ";
                                cin>>auxdni;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<auxdni<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 5:
                            	cout<<"Masa: ";
                                cin>>auxmasa;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<auxmasa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 6:
                            	cout<<"Talla: ";
                                cin>>auxtalla;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<auxtalla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 7:
                            	cout<<"Genero: ";
                                cin.get(espacio);
                                getline(cin,auxgen);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<auxgen<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 8:
                                 cin.get(espacio);
                            	cout<<"Tipo de sangre: ";
                                getline(cin,auxts);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<auxts<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 9:
                                cout<<"Fecha de nacimiento: ";
                                getline(cin,auxnac);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<auxnac<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 10:
                                cout<<"Nombre del apoderado: ";
                                getline(cin,auxNomAp);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<auxNomAp<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;
                            case 11:
                                cout<<"Apellido del apoderado: ";
                                getline(cin,auxApelAp);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<auxApelAp<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                                break;
                            case 12:
                                cout<<"DNI del apoderado: ";
                                cin>>auxdniap;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<auxdniap<<" "<<Parentesco_Ap<<endl;
                                system("PAUSE");
                            break;w

                            case 13:
                                cout<<"Parentesco del apoderado: ";
                                cin.get(espacio);
                                getline(cin,auxparen);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<auxparen<<endl;
                                system("PAUSE");
                            break;
                            default:
                            break;

                       }
                       }
                            cout<<"Modificación realizada..."<<endl;

                }
                else{
                        if((edad<18)){
                          aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                        }
                        else{
                         aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                        }
                }
                    lectura>>codigo;
              }

    }
	else{
		cout<<"No se puede abrir el archivo...";
	}
    if(encontrado==false){
        cout<<"No se ha encontrado un registro con ese codigo..."<<endl;
    }
    aux.close();
    lectura.close();
    remove("pacientes.txt");
    rename("auxiliar.txt","pacientes.txt");
}

void Paciente::Historia_Clin(int op){

    int auxcod;

  switch(op){
            case 1:
            {
                 ifstream verificar;
                 cout<<"Ingrese el codigo del paciente para crear su historia clinica: ";
                 cin>>auxcod;
                 verificar.open("pacientes.txt",ios::in);
                    if(verificar.is_open()){
                    verificar>>codigo;
                    while(!verificar.eof()){
                    verificar>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
                    if(edad<18){
                    verificar>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;}
                    if(auxcod==codigo){
                    cout<<"Existe el paciente..."<<endl;
                        Historia->setcodPac(auxcod);
                        Historia->Registrar_Historia();
                        }
                    verificar>>codigo;
                    }
                    }
                    else{
                    cout<<"No se ha encontrado el archivo...";
                    }

                    verificar.close();

                    system("PAUSE");
            }
                break;
            case 2:
                {
                cout<<"LISTADO DE HISTORIAS CLINICAS";
                Historia->Listar_Historia();
                system("PAUSE");
                }

                break;
            case 3:
                {
                int auxcodigo,auxcodp;
                cout<<"Ingrese el codigo de Historia: ";
                cin>>auxcodigo;
                Historia->Buscar_Historia(auxcodigo);
                auxcodp=Historia->getcodPac();
                Encontrar_Paciente(auxcodp);

                }


                break;
            case 4:
                Historia->Modificar_Historia();
                system("PAUSE");

                break;
            case 6:
                break;
            default:
                break;

          }


}
