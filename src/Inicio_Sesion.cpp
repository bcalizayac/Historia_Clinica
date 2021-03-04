#include "Inicio_Sesion.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cstring>


#define ENTER 13
#define BACKSPACE 8

using namespace std;

Inicio_Sesion::Inicio_Sesion()
{
    Codigo="";
    Contra="";
}

int Inicio_Sesion :: Verificar_Usuario(int is){
    do{
        cout<<"\t\t-------------------------------"<<endl;
        cout<<"\t\t-      Inicio de Sesion       -"<<endl;
        cout<<"\t\t-------------------------------"<<endl;
        cout<<"\n\n\tIngrese el usuario: ";
        fflush(stdin);
        cin>>Codigo;
        char caracter;
        cout<<"\n\n\tIngrese su contrase"<<char(164)<<"a: ";
        fflush(stdin);
        caracter = getch();
        Contra="";
        while (caracter != ENTER){
			if (caracter != BACKSPACE){
				Contra.push_back(caracter);
				cout << "*";
			} else{
				if(Contra.length() > 0) {
                    cout << "\b \b";
					Contra = Contra.substr(0, Contra.length() - 1);
				}
			}
        caracter = getch();
		}
        if(Codigo=="admin123"){
            if(Contra=="12345678"){
                is=1;
            }
        }
        system("cls");
    }while(is==0);
    return is;
}

int Inicio_Sesion :: LogearMedico(int im, int op){
    int codm;
    string contm;
    int code;
    string conte;
    if(op==1){
        do{
            cout<<"\t\t----------------------------------------"<<endl;
            cout<<"\t\t-      Inicio de Sesion de Medico      -"<<endl;
            cout<<"\t\t----------------------------------------"<<endl;
            cout<<"\n\n\tIngrese el Codigo de Medico: ";
            fflush(stdin);
            cin>>codm;
            char caracter;
            cout<<"\n\n\tIngrese su contrase"<<char(164)<<"a: ";
            fflush(stdin);
            caracter = getch();
            contm="";
            while (caracter != ENTER){
                if (caracter != BACKSPACE){
                    contm.push_back(caracter);
                    cout << "*";
                }
                else {
                    if (contm.length() > 0) {
                        cout << "\b \b";
                        contm = contm.substr(0, contm.length() - 1);
                    }
                }
            caracter = getch();
            }
            system("pause");
            ifstream contrasena;
            contrasena.open("contraseñas.txt", ios::in);
            FILE *rv;
            rv = fopen( "contraseñas.txt", "r" );
            fseek( rv, 0, SEEK_END );
            if (ftell( rv ) == 0 )
            {
                cout<<"Archivo vacio"<<endl;
            }
            else{
                contrasena>>codmed;
                while(!contrasena.eof())
                {
                    contrasena>>contmed>>ces;
                    if(codmed==codm){
                        if(contmed==contm){
                            if(ces==1){
                                im=1;
                            }
                        }
                    }
                    contrasena>>codmed;
                }
            }
            system("cls");
            contrasena.close();
        }while(im==0);
    }
    if(op==2){
        do{
            cout<<"\t\t----------------------------------------"<<endl;
            cout<<"\t\t-     Inicio de Sesion de Enfermero    -"<<endl;
            cout<<"\t\t----------------------------------------"<<endl;
            cout<<"\n\n\tIngrese el Codigo de Enfermero: ";
            fflush(stdin);
            cin>>code;
            char caracter;
            cout<<"\n\n\tIngrese su contrase"<<char(164)<<"a: ";
            fflush(stdin);
            caracter = getch();
            conte="";
            while (caracter != ENTER){
                if (caracter != BACKSPACE){
                    conte.push_back(caracter);
                    cout << "*";
                } else {
                    if (conte.length() > 0) {
                        cout << "\b \b";
                        conte = conte.substr(0, conte.length() - 1);
                    }
                }
            caracter = getch();
            }
            system("pause");
            ifstream contrasena;
            contrasena.open("contraseñas.txt", ios::in);
            FILE *rv;
            rv = fopen( "contraseñas.txt", "r" );
            fseek( rv, 0, SEEK_END );
            if (ftell( rv ) == 0 )
            {
                cout<<"\n\n\t\tArchivo vacio"<<endl;
            }

            else{
                contrasena>>codenf;
                while(!contrasena.eof())
                {
                    contrasena>>contenf>>ces;
                    if(codenf==code){
                        if(contenf==conte){
                            if(ces==2){
                                im=1;
                            }
                        }
                    }
                    contrasena>>codenf;
                }
            }
            contrasena.close();
            system("cls");
        }while(im==0);
    }
    return im;
}

