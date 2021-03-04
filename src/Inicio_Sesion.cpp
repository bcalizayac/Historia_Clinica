#include "Inicio_Sesion.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>

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
			} else {
				if (Contra.length() > 0) {
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
