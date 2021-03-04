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
        cout<<"\n\t\tNo se pudo abrir el archivo"<<endl;
        system("pause");
        system("cls");
    }
    else{
    cout<<endl;
    cout<<"\t\t\t-----------------------------------"<<endl;
    cout<<"\t\t\t-       REGISTRO DE PACIENTES     -"<<endl;
    cout<<"\t\t\t-----------------------------------"<<endl;
    cout<<"\n\t\tCantidad de pacientes: ";
    cin>>n;
    system("cls");
        for(int i=0;i<n;i++){
        do{
        repetido=false;
        cout<<"\n\t\tCodigo: ";
        cin>>codguardado;
        FILE *rv;
        rv = fopen( "pacientes.txt", "r" );
        fseek( rv, 0, SEEK_END );
        if (ftell( rv ) == 0 )
        {
            cout<<"\n\n\t\tArchivo vacio"<<endl;
        }
        else{
        consulta>>codigo;
         while(!consulta.eof()){
            consulta>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
            consulta>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;}
            if(codigo==codguardado){
                cout<<"\n\t\tYa existe un registro con ese codigo, vuelva a ingresar los datos"<<endl;
                system("pause");
                system("cls");
                repetido=true;
                break;
            }
            consulta>>codigo;
            }
        }
        if(repetido==false){
        codigo=codguardado;
        cin.get(aux);
        cout<<"\n\t\tIngrese los nombres: ";
        getline(cin,Nombres);
        cout<<"\n\t\tIngrese los apellidos: ";
        fflush(stdin);
        getline(cin,Apellidos);
        cout<<"\n\t\tIngrese la edad: ";
        cin>>edad;
        cout<<"\n\t\tIngrese el DNI: ";
        cin>>DNI;
        cout<<"\n\t\tIngrese el Genero: ";
        cin.get(aux);
        getline(cin,Genero);
        cout<<"\n\t\tIngrese la masa: ";
        cin>>masa;
        cout<<"\n\t\tIngrese el tipo de sangre: ";
        cin.get(aux);
        getline(cin,Tipo_Sangre);
        cout<<"\n\t\tIngrese la talla: ";
        cin>>Talla;
        cout<<"\n\t\tIngrese el nacimiento: ";
        cin.get(aux);
        getline(cin,Nacimiento);
            if((edad<18)){
            cout<<endl<<endl;
            cout<<"\t\t\t    DATOS DEL APODERADO   ";
            cout<<"\t\t\t--------------------------"<<endl;
            cout<<"\n\t\tIngrese el nombre completo: ";
            getline(cin,Nom_Ap);
            cout<<"\n\t\tIngrese los apellidos: ";
            getline(cin,Apell_Ap);
            cout<<"\n\t\tIngrese el parentesco: ";
            getline(cin,Parentesco_Ap);
            cout<<"\n\t\tIngrese el DNI: ";
            cin>>DNI_Ap;
            archivo<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
            }
            else{
                archivo<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
            }

            }

            }while(repetido==true);

        }
        system("cls");
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
        cout<<"\n\t\tArchivo vacio"<<endl;
        system("pause");
        system("cls");
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
        cout<<"\n\t\tNo se ha encontrado el archivo...";
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
                cout<<"\n\t\tCodigo: "<<codigo<<endl;
                cout<<"\t\tNombre: "<<Nombres<<endl;
                cout<<"\t\tApellidos: "<<Apellidos<<endl;
                cout<<"\t\tEdad: "<<edad<<endl;
                cout<<"\t\tDNI: "<<DNI<<endl;
                cout<<"\t\tGenero: "<<Genero<<endl;
                cout<<"\t\tMasa: "<<masa<<endl;
                cout<<"\t\tTalla: "<<Talla<<endl;
                cout<<"\t\tTipo de sangre: "<<Tipo_Sangre<<endl;
                cout<<"\t\tNacimiento: "<<Nacimiento<<endl;
                if(edad<18){
                cout<<"\t\tNombre del Apoderado: "<<Nom_Ap<<endl;
                cout<<"\t\tApellido del Apoderado: "<<Apell_Ap<<endl;
                cout<<"\t\tDNI: "<<DNI_Ap<<endl;
                cout<<"\t\tParentesco: "<<Parentesco_Ap<<endl;
                }
            }
                        listar>>codigo;
            }
    }
    else{
        cout<<"\n\t\tNo se ha encontrado el archivo...";
    }
        i++;

     listar.close();
     }while(i!=cant);
    }
            system("PAUSE");
            system("cls");

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
                cout<<"\n\t\t\t-------------------------------";
                cout<<"\n\t\t\t-     Registro encontrado     -";
                cout<<"\n\t\t\t-------------------------------"<<endl;
                cout<<"\n\t\tCodigo: "<<codigo<<endl;
                cout<<"\t\tNombre: "<<Nombres<<endl;
                cout<<"\t\tApellidos: "<<Apellidos<<endl;
                cout<<"\t\tEdad: "<<edad<<endl;
                cout<<"\t\tDNI: "<<DNI<<endl;
                cout<<"\t\tGenero: "<<Genero<<endl;
                cout<<"\t\tMasa: "<<masa<<endl;
                cout<<"\t\tTalla: "<<Talla<<endl;
                cout<<"\t\tTipo de sangre: "<<Tipo_Sangre<<endl;
                cout<<"\t\tNacimiento: "<<Nacimiento<<endl;
                if(edad<18){
                cout<<"\t\tNombre del Apoderado: "<<Nom_Ap<<endl;
                cout<<"\t\tApellido del Apoderado: "<<Apell_Ap<<endl;
                cout<<"\t\tDNI: "<<DNI_Ap<<endl;
                cout<<"\t\tParentesco: "<<Parentesco_Ap<<endl;
                }
            }
            encontrar>>codigo;

    }
    }
    else{
        cout<<"\n\t\tNo se ha encontrado el archivo...";
    }
     encontrar.close();
     system("cls");
}
void Paciente::Eliminar_Paciente(){
    int codi;
    ifstream eliminar;
    ofstream entrada;
    eliminar.open(("pacientes.txt"),ios::in);
    entrada.open(("temporal.txt"),ios::out);
    if(eliminar.fail()){
        cout<<"\n\t\tExiste un error al abrir el archivo...";
    }
    else{
        cout<<"\n\t\tIntroduzca el codigo: ";
        cin>>codi;
        system("cls");
        eliminar>>codigo;
        while(!eliminar.eof()){
            eliminar>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
            eliminar>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;}
                if(codi==codigo){

                    cout<<"\n\t\tEliminado..."<<endl;
                    system("pause");
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
    system("cls");
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
		cout<<"\n\t\tIngrese el codigo del paciente a modificar: "<<endl;
		cin>>auxcodigo;
		lectura>>codigo;
		while(!lectura.eof()){
		lectura>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
            if(edad<18){
                lectura>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;
            }
            if(auxcodigo==codigo){
                encontrado=true;
                system("cls");
                Encontrar_Paciente(auxcodigo);
                cout<<endl<<endl;
                cout<<"\t\t\t----------------------------------"<<endl;
                cout<<"\t\t\t-        MODIFICAR PACIENTE      -"<<endl;
                cout<<"\t\t\t----------------------------------"<<endl;
                cout<<"\n\t\t1.Nombres\n\t\t2.Apellidos\n\t\t3.Edad\n\t\t4.DNI\n\t\t5.Genero\n\t\t6.Masa\n\t\t7.Talla\n\t\t8.Tipo de sangre\n\t\t9.Fecha de Nacimiento"<<endl;
                if(edad<18){
                    cout<<"\t\t10.Nombre del Apoderado\n\t\t11.Apellidos del apoderado\n\t\t12.DNI del apoderado\n\t\t13.Parentesco"<<endl;
                }
                cout<<"\n\t\tElija la opción a modificar: ";
                cin>>op;
                system("cls");
                if(edad>=18){
                       switch(op){
                            case 1:
                                cout<<"\n\t\tNombres: ";
                                cin.get(espacio);
                                getline(cin,auxnom);
                                aux<<codigo<<" "<<auxnom<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;

                                system("PAUSE");
                            break;
                            case 2:
                                 fflush(stdin);
                            	cout<<"\n\t\tApellidos: ";
                                getline(cin,auxapell);
                                aux<<codigo<<" "<<Nombres<<" "<<auxapell<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 3:
                            	cout<<"\n\t\tEdad: ";
                                cin>>auxedad;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<auxedad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 4:
                            	cout<<"\n\t\tDNI: ";
                                cin>>auxdni;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<auxdni<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 5:
                            	cout<<"\n\t\tMasa: ";
                                cin>>auxmasa;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<auxmasa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 6:
                            	cout<<"\n\t\tTalla: ";
                                cin>>auxtalla;
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<auxtalla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 7:
                            	cout<<"\n\t\tGenero: ";
                                cin.get(espacio);
                                getline(cin,auxgen);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<auxgen<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 8:
                                cin.get(espacio);
                            	cout<<"\n\t\tTipo de sangre: ";
                                getline(cin,auxts);
                                aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<auxts<<" "<<Nacimiento<<endl;
                                system("PAUSE");
                            break;
                            case 9:
                                cout<<"\n\t\tFecha de nacimiento: ";
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
                                    cout<<"\n\t\tNombres: ";
                                    cin.get(espacio);
                                    getline(cin,auxnom);
                                    aux<<codigo<<" "<<auxnom<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    fflush(stdin);
                                    system("PAUSE");
                                    break;
                                case 2:
                                    fflush(stdin);
                                    cout<<"\n\t\tApellidos: ";
                                    getline(cin,auxapell);
                                    aux<<codigo<<" "<<Nombres<<" "<<auxapell<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 3:
                                    cout<<"\n\t\tEdad: ";
                                    cin>>auxedad;
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<auxedad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 4:
                                    cout<<"\n\t\tDNI: ";
                                    cin>>auxdni;
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<auxdni<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 5:
                                    cout<<"\n\t\tMasa: ";
                                    cin>>auxmasa;
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<auxmasa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 6:
                                    cout<<"\n\t\tTalla: ";
                                    cin>>auxtalla;
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<auxtalla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 7:
                                    cout<<"\n\t\tGenero: ";
                                    cin.get(espacio);
                                    getline(cin,auxgen);
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<auxgen<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 8:
                                     cin.get(espacio);
                                    cout<<"\n\t\tTipo de sangre: ";
                                    getline(cin,auxts);
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<auxts<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 9:
                                    cout<<"\n\t\tFecha de nacimiento: ";
                                    getline(cin,auxnac);
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<auxnac<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 10:
                                    cout<<"\n\t\tNombre del apoderado: ";
                                    getline(cin,auxNomAp);
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<auxNomAp<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 11:
                                    cout<<"\n\t\tApellido del apoderado: ";
                                    getline(cin,auxApelAp);
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<auxApelAp<<" "<<DNI_Ap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 12:
                                    cout<<"\n\t\tDNI del apoderado: ";
                                    cin>>auxdniap;
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<auxdniap<<" "<<Parentesco_Ap<<endl;
                                    system("PAUSE");
                                    break;
                                case 13:
                                    cout<<"\n\t\tParentesco del apoderado: ";
                                    cin.get(espacio);
                                    getline(cin,auxparen);
                                    aux<<codigo<<" "<<Nombres<<" "<<Apellidos<<" "<<edad<<" "<<DNI<<" "<<Genero<<" "<<masa<<" "<<Talla<<" "<<Tipo_Sangre<<" "<<Nacimiento<<" "<<Nom_Ap<<" "<<Apell_Ap<<" "<<DNI_Ap<<" "<<auxparen<<endl;
                                    system("PAUSE");
                                    break;
                                default:
                                    break;
                            }
                        }
                        system("cls");
                        cout<<"\n\t\tModificación realizada..."<<endl;
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
		cout<<"\n\t\tNo se puede abrir el archivo...";
	}
    if(encontrado==false){
        cout<<"\n\t\tNo se ha encontrado un registro con ese codigo..."<<endl;
    }
    aux.close();
    lectura.close();
    remove("pacientes.txt");
    rename("auxiliar.txt","pacientes.txt");
    system("cls");
}

void Paciente::Historia_Clin(int op){

    int auxcod;

  switch(op){
            case 1:
            {
                 ifstream verificar;
                 cout<<"\n\t\tIngrese el codigo del paciente para crear su historia clinica: ";
                 cin>>auxcod;
                 verificar.open("pacientes.txt",ios::in);
                    if(verificar.is_open()){
                    verificar>>codigo;
                    while(!verificar.eof()){
                    verificar>>Nombres>>Apellidos>>edad>>DNI>>Genero>>masa>>Talla>>Tipo_Sangre>>Nacimiento;
                    if(edad<18){
                    verificar>>Nom_Ap>>Apell_Ap>>DNI_Ap>>Parentesco_Ap;}
                    if(auxcod==codigo){
                    cout<<"\n\t\tExiste el paciente..."<<endl;
                        Historia->setcodPac(auxcod);
                        Historia->Registrar_Historia();
                        }
                    verificar>>codigo;
                    }
                    }
                    else{
                    cout<<"\n\t\tNo se ha encontrado el archivo...";
                    }

                    verificar.close();

                    system("PAUSE");
            }
                break;
            case 2:
                {
                cout<<"\n\t\t\tLISTADO DE HISTORIAS CLINICAS";
                cout<<"\n\t\t\t-----------------------------";
                Historia->Listar_Historia();
                system("PAUSE");
                }
                break;
            case 3:
                {
                int auxcodigo,auxcodp;
                cout<<"\n\t\tIngrese el codigo de Historia: ";
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
