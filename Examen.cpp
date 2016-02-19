#include<iostream>
#include<cmath>
#include<iomanip>
using std::cout; 
using std::cin; 
using std::endl; 
using std::abs; 
using std::setw; 

void crearmatriz(char**,int); 
void llenar(char**,int);
void iniciarmatriz(char**,int); 
void eliminarmatriz(char**,int); 
void asigned(char**); 
int contarnumeral(char**,int);
int contarmas(char**,int); 
void imprimirmatriz(char**, int);
void validar(char**, int);   
bool validarmovimiento(char**, int,int); 
void moverpieza(char**, int,int,int); 

//---------------------------inicio main--------------------

int main(int argc, char*argv[]){

	char** matriz; 
	int tamanio = 7;
	int mov,mover; 
	int fila,columna; 
	matriz=new char* [tamanio];
	crearmatriz(matriz,tamanio);
	iniciarmatriz(matriz,tamanio);  
	asigned(matriz);


	cout<<"--------------------Bienvenidos--------------"<<endl;
	//while(contarnumeral(matriz,tamanio) ==0 || contarmas(matriz,tamanio)==0){

		imprimirmatriz(matriz,tamanio);
		cout<<"JUGADOR 1 - MUEVE +"<<endl;
		cout<<"Ingrese cuantos movimiento quiere mover: \n"
			<<"1 - un movimiento: \n"
			<<"2 - dos movimientos: "<<endl; 
		cin>>mov; 
		if (mov == 1){

			cout<<"Ingrese las coordenadas en las que se encuentra su pieza: (fila,columna) "<<endl; 
			cin>>fila>>columna; 
			cout<<"\nHacia donde desea moverse:"
				<<"\n1 - Arriba\n2 - Abajo\n3 - Derecha\n4. Izquierda"
				<<endl; 
			cin>>mover; 
			if((validarmovimiento(matriz,tamanio,mov)) ==false){

				cout<<"Movimiento incorrecto. pierde turno"<<endl;  

			}
			else{
				cout<<"Movimiento hecho satisfactoriamente"<<endl;
				moverpieza(matriz,fila,columna,mover); 
			}

			
		}
		if (mov==2){

		}

		
	//}
					
	eliminarmatriz(matriz,tamanio); 
	return 0; 
	
}



//----------------------------------funciones-----------------------------

void crearmatriz(char** matriz,int size){
	for(int i=0;i<size; i++){
		matriz[i]=new char[size];	
	}
}

void iniciarmatriz(char** matriz, int size){

	for (int i = 0; i <size; i++){
		for (int j = 0; j < size; j++){
			matriz[i][j] ='-'; 			
		}
	}
}

void eliminarmatriz(char** matriz,int size){

	for(int k=0; k<size; k++){
		delete[] matriz[k]; 
	}

	delete[] matriz; 
}

void asigned(char** matriz){

	matriz[4][0]= '#'; 
	matriz[4][6]= '#';
	matriz[0][4]= '+';
	matriz[6][4]= '+';  

}
int contarnumeral(char** matriz,int size){
	
	int cont=0; 
	for (int i = 0; i <size; i++){
		for (int j = 0; j < size; j++){
			if (matriz[i][j] =='#'){
				cont++; 
			}		

		}
	}
	return cont; 
}

int contarmas(char** matriz,int size){
	int cont=0; 
	for (int i = 0; i <size; i++){
		for (int j = 0; j < size; j++){
			if (matriz[i][j] =='+'){
				cont++; 
			}		

		}
	}
	return cont; 
}

void imprimirmatriz(char** matriz,int size){
	cout<<endl<<"-------Coordenadas Juego---------"<<endl; 
	cout<<setw(5); 
	for (int i = 0; i <size; i++){
		for (int j = 0; j < size; j++){
			
				cout<<matriz[i][j]<<setw(5); 	

		}
		cout<<endl; 
		
	}


}

bool validarmovimiento(char** matriz, int size, int eleccion){




}

void moverpieza(char** matriz, int fila,int columna,int eleccion){

	if (eleccion==1){
		if (matriz[fila][columna]=='#'){
			matriz[fila][columna]== '-';
			matriz[fila-1][columna]='#'; 
		}
		else{
			matriz[fila][columna]=='-'; 
			matriz[fila-1][columna]='+'; 
		}
		
	}
	if (eleccion==2){
		if (matriz[fila][columna]=='#'){
			matriz[fila][columna]== '-';
			matriz[fila+1][columna]='#'; 
		}
		else{
			matriz[fila][columna]=='-'; 
			matriz[fila+1][columna]='+'; 
		}
		
	}
	if (eleccion==3){
		if (matriz[fila][columna]=='#'){
			matriz[fila][columna]== '-';
			matriz[fila][columna+1]='#'; 
		}
		else{
			matriz[fila][columna]=='-'; 
			matriz[fila][columna+1]='+'; 
		}
		
	}
	if (eleccion==4){
		if (matriz[fila][columna]=='#'){
			matriz[fila][columna]== '-';
			matriz[fila][columna-1]='#'; 
		}
		else{
			matriz[fila][columna]=='-'; 
			matriz[fila][columna-1]='+'; 
		}
		
	}

	
	
}