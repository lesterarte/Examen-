#include<iostream>
#include<iomanip>
using std::cout; 
using std::cin; 
using std::endl; 
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
bool validarmovimiento(char**, int,int,int); 
void moverpieza(char**, int,int,int); 
void clonarpieza(char**,int,int,int); 
void ganador(char**, int,int,int);

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
	//while(contarnumeral(matriz,tamanio) !=0 || contarmas(matriz,tamanio)!=0){

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
				<<"\n5 - Diagonal superior derecha\n6 - Diagonal inferior derecha"
				<<"\n7 - Diagonal superir izquierda\n8 - Diagonal inferior izquierda"
				<<endl; 
			cin>>mover; 

			if((validarmovimiento(matriz,fila,columna,mover)) ==false){

				cout<<"Movimiento incorrecto, se sale del rango o casillaocupada --> pierde turno"<<endl;  

			}
			else{
				moverpieza(matriz,fila,columna,mover); 
				cout<<"Movimiento hecho satisfactoriamente"<<endl;
				
			}
		}



		//--------------------segundo Jugador------------------

		imprimirmatriz(matriz,tamanio);
		cout<<"JUGADOR 2 - MUEVE #"<<endl;
		cout<<"Ingrese cuantos movimiento quiere mover: \n"
			<<"1 - un movimiento: \n"
			<<"2 - dos movimientos: "<<endl; 
		cin>>mov; 

		if (mov == 1){

			cout<<"Ingrese las coordenadas en las que se encuentra su pieza: (fila,columna) "<<endl; 
			cin>>fila>>columna; 
			cout<<"\nHacia donde desea moverse:"
				<<"\n1 - Arriba\n2 - Abajo\n3 - Derecha\n4. Izquierda"
				<<"\n5 - Diagonal superior derecha\n6 - Diagonal inferior derecha"
				<<"\n7 - Diagonal superir izquierda\n8 - Diagonal inferior izquierda"
				<<endl; 
			cin>>mover; 

			if((validarmovimiento(matriz,fila,columna,mover)) ==false){

				cout<<"Movimiento incorrecto, se sale del rango o casillaocupada --> pierde turno"<<endl;  

			}
			else{
				moverpieza(matriz,fila,columna,mover); 
				cout<<"Movimiento hecho satisfactoriamente"<<endl;
				
			}
		}


	//}

	void ganador(matriz,tamanio);
			
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

	matriz[3][0]= '#'; 
	matriz[3][6]= '#';
	matriz[0][3]= '+';
	matriz[6][3]= '+';  

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
	cout<<setw(6)<<"0"<<setw(5)<<"1"<<setw(5)<<"2"<<setw(5)<<"3"<<setw(5)<<"4"<<setw(5)<<"5"<<setw(5)<<"6"<<endl; 
	for (int i = 0; i <size; i++){
		cout<<i; 
		for (int j = 0; j < size; j++){
			
				cout<<setw(5)<<matriz[i][j]; 	

		}
		cout<<endl; 
		
	}


}

bool validarmovimiento(char** matriz,int fila,int columna, int eleccion){

	if (eleccion==1){
		if (((fila-1)<0) || (matriz[fila-1][columna]=='#') ||(matriz[fila-1][columna]=='+')){
			return false; 
		}
		else{
			return true; 
		}
	}

	if (eleccion==2){
		if (((fila+1)>7) || (matriz[fila+1][columna]=='#') ||(matriz[fila+1][columna]=='+')){
			return false; 
		}
		else{
			return true; 
		}
	}
	
	if (eleccion==3){
		if (((columna+1)>7) || (matriz[fila][columna+1]=='#') ||(matriz[fila][columna+1]=='+')){
			return false; 
		}
		else{
			return true; 
		}
	}

	if (eleccion==4){
		cout<<columna-1<<endl; 
		if (((columna-1)<0) || (matriz[fila][columna-1]=='#') ||(matriz[fila][columna-1]=='+')){
			
			return false; 
		}
		else{
			return true; 
		}
	}

	if (eleccion==5){
		if (((fila-1)<0) || ((columna+1)>7)|| (matriz[fila-1][columna+1]=='#') ||(matriz[fila-1][columna+1]=='+')){
			return false; 
		}
		else{
			return true; 
		}
	}

	if (eleccion==6){
		if (((fila+1)>7) || ((columna+1)>7)|| (matriz[fila+1][columna+1]=='#') ||(matriz[fila+1][columna+1]=='+')){
			return false; 
		}
		else{
			return true; 
		}
	}


	if (eleccion==7){
		if (((fila-1)<0) || ((columna-1)<0)|| (matriz[fila-1][columna-1]=='#') ||(matriz[fila-1][columna-1]=='+')){
			return false; 
		}
		else{
			return true; 
		}
	}

	if (eleccion==8){
		if (((fila+1)>7) || ((columna-1)<0)|| (matriz[fila+1][columna-1]=='#') ||(matriz[fila+1][columna-1]=='+')){
			return false; 
		}
		else{
			return true; 
		}
	}

}//fin funcion 


void moverpieza(char** matriz, int fila,int columna,int eleccion){

	if (eleccion==1){
		if (matriz[fila][columna]=='#'){
			matriz[fila][columna]='-';
			matriz[fila-1][columna]='#'; 
		}
		else{
			matriz[fila][columna]='-'; 
			matriz[fila-1][columna]='+'; 
		}
		
	}
	if (eleccion==2){
		if (matriz[fila][columna]=='#'){
			matriz[fila][columna]= '-';
			matriz[fila+1][columna]='#'; 
		}
		else{
			matriz[fila][columna]='-'; 
			matriz[fila+1][columna]='+'; 
		}
		
	}
	if (eleccion==3){
		if (matriz[fila][columna]='#'){
			matriz[fila][columna]= '-';
			matriz[fila][columna+1]='#'; 
		}
		else{
			matriz[fila][columna]='-'; 
			matriz[fila][columna+1]='+'; 
		}
		
	}
	if (eleccion==4){
		if (matriz[fila][columna]=='#'){
			matriz[fila][columna]= '-';
			matriz[fila][columna-1]='#'; 
		}
		else{
			matriz[fila][columna]='-'; 
			matriz[fila][columna-1]='+'; 
		}
	}

	if (eleccion==5){
		if (matriz[fila-1][columna+1]=='#'){
			matriz[fila-1][columna+1]= '-';
			matriz[fila-1][columna+1]='#'; 
		}
		else{
			matriz[fila-1][columna+1]='-'; 
			matriz[fila-1][columna+1]='+'; 
		}
		
	}

	if (eleccion==6){
		if (matriz[fila+1][columna+1]=='#'){
			matriz[fila+1][columna+1]= '-';
			matriz[fila+1][columna+1]='#'; 
		}
		else{
			matriz[fila+1][columna+1]='-'; 
			matriz[fila+1][columna+1]='+'; 
		}
		
	}

	if (eleccion==7){
		if (matriz[fila-1][columna-1]=='#'){
			matriz[fila-1][columna-1]= '-';
			matriz[fila-1][columna-1]='#'; 
		}
		else{
			matriz[fila-1][columna-1]='-'; 
			matriz[fila-1][columna-1]='+'; 
		}
		
	}

	if (eleccion==8){
		if (matriz[fila+1][columna-1]=='#'){
			matriz[fila+1][columna-1]= '-';
			matriz[fila+1][columna-1]='#'; 
		}
		else{
			matriz[fila+1][columna-1]='-'; 
			matriz[fila+1][columna-1]='+'; 
		}
		
	}


}

void clonarpieza(char** matriz, int fila,int columna){

	if((matriz[fila-1][columna]=='-') ||(matriz[fila-1][columna]=='+')){

		matriz[fila-1][columna]=='#'; 
	}
	if((matriz[fila+1][columna]=='-') ||(matriz[fila+1][columna]=='+')){

		matriz[fila+1][columna]=='#'; 
	}
	if((matriz[fila][columna-1]=='-') ||(matriz[fila][columna-1]=='+')){

		matriz[fila][columna-1]=='#'; 
	}
	if((matriz[fila][columna+1]=='-') ||(matriz[fila][columna+1]=='+')){

		matriz[fila][columna+1]=='#'; 
	}
	
	if((matriz[fila-1][columna+1]=='-') ||(matriz[fila-1][columna+1]=='+')){

		matriz[fila-1][columna+1]=='#'; 
	}
	if((matriz[fila+1][columna+1]=='-') ||(matriz[fila+1][columna+1]=='+')){

		matriz[fila+1][columna+1]=='#'; 
	}

	if((matriz[fila-1][columna-1]=='-') ||(matriz[fila-1][columna-1]=='+')){

		matriz[fila-1][columna-1]=='#'; 
	}
	if((matriz[fila+1][columna-1]=='-') ||(matriz[fila+1][columna-1]=='+')){

		matriz[fila+1][columna-1]=='#'; 
	}
}


void ganador(char** matriz, int size){

	if((contarmas(matriz,size)==(contarnumeral(matriz,size))){
		cout<<"Hay un empate"<<endl; 

	}

	if((contarmas(matriz,size)>(contarnumeral(matriz,size))){
		cout<<"El Jugador 1  es el ganador"<<endl; 

	}
	else{
		cout<<"El Jugador 2 es el ganador"<<endl; 

	}

	
}