//Instituto Politecnico Nacional 
//Ingenieria en Computacion
//Alumno. Castillo Martinez Angela Belen


#include <iostream>
#include <conio.h>
using namespace std;

class Paciente{
	int nmss,edad;
	public:
		Paciente(){};
		
		void ingresarnmss(int ns){
			nmss=ns;
		}
		void ingresaredad(int ed){
			edad=ed;
		}
		void verdatos1(){
			cout<<nmss<<"\t\t"<<edad;
		}
		bool nums(int ed)const {
	
			if (edad==ed){
				return true;
			}else{
				return false;
			}
		}
};
class ESTADO:public Paciente{
	protected:
		int f1;
	public:
		void estadopaciente(int esp){
			f1=esp;
		}
		void verdatos(){
			cout<<"\t\t"<<f1;
		}
};
class FECHA:public ESTADO{
	protected:
		int dia, mes, anyo;
	public:
		void fechaingreso(int di,int mi, int ai){
			dia=di;
			mes=mi;
			anyo=ai;
		}
			void fechasalida(int ds,int ms, int as){
			dia=ds;
			mes=ms;
			anyo=as;
		}
		void verfechain(){
			cout<<"\t\t"<<dia<<"/"<<mes<<"/"<<anyo;
		}
		void verfechasal(){
			cout<<"\t\t"<<dia<<"/"<<mes<<"/"<<anyo<<endl;
		}
};
class COSTOS: private ESTADO{
	private:
		int p1,PH;
	public:
		COSTOS(int a): p1(a){}
		COSTOS():p1(0){}
		void dias_hospitalizacion(int dh){
			PH=dh;
		}
		friend 	COSTOS operator +(COSTOS u,COSTOS n){
			COSTOS s;
			s.p1=u.p1*n.PH;
			return s;
		}
		void vercostos(){
			cout<<"el costo actual de la hospitalizacion es de: "<<p1<<endl;;
		}
		void vercostohxs(){
			cout<<"el costo total es:"<<PH<<endl;
		}
};
int main() {
	int salir=0,salida,i,opc;
	int np,numeros,edad1,estadop,Di,Mi,Ai,Ds,Ms,As;
	char paciente[10];
	while (salir!=1){
		cout<<"\t MENU DE PACIENTES REPORTADOS CON COVID-19\n";
		cout<<"------------------------------------------------------\n";
		cout<<"1.-Agregar paciente nuevo.\n";
		cout<<"2.-Ver pacientes registrados.\n";
		cout<<"3.-Buscar  pacientes por edad.\n";
		cout<<"4.-ver costos de Pacientes.\n";
		cout<<"5.-SALIR.\n";
		cout<<"------------------------------------------------------\n";
		cout<<"porfavor ingresa el numero de tu opcion: ";
		cin>>opc;
		system("pause");
		system("cls");
		FECHA arreglo[20],*ptr;
	    ptr=arreglo;
		switch (opc){
			case 1:
				cout<<"\t AGREGAR PACIENTE\n";
				cout<<"------------------------------------------------------\n";
				cout<<"cuantos pacientes desea agregar: ";
				cin>>np;
				for (i=0;i<np;i++){
					cout<<"PACIENTE"<<i+1<<endl;
					cout<<"ingresa numero de seguro social del paciente:"<<endl;
					cin>>numeros;
					(ptr+i)->ingresarnmss(numeros);
					cout<<"ingresa la edad del paciente:"<<endl;
					cin>>edad1;
					(ptr+i)->ingresaredad(edad1);
					cout<<"ingrese estado del paciente(1=leve, 2=regular, 3=riesgo, 4=alto riesgo):"<<endl;
					cin>>estadop;
					(ptr+i)->estadopaciente(estadop);
					cout<<"ingrese fecha de ingreso del paciente(dd/mm/aa):"<<endl;
					cin>>Di>>Mi>>Ai;
					(ptr+i)->fechaingreso(Di,Mi,Ai);
					cout<<"ingrese fecha de salida del paciente(dd/mm/aa):"<<endl;
					cin>>Ds>>Ms>>As;
					(ptr+i)->fechasalida(Ds,Ms,As);
					system("pause");
					system("cls");
				}
				break;
				
				case 2:
					int i;
					cout<<"\tLISTA DE PACIENTES COVID-19"<<endl;
					cout<"----------------------------------------------------------------\n";
					cout<<"N.Seguro Social\tEdad\tEstado de Salud\tFeha de Ingreso\tFecha de Salida"<<endl;
					for (i=0;i<np;i++){
						(ptr+i)->verdatos1(),(ptr+i)->verdatos(),(ptr+i)->verfechain(),(ptr+i)->verfechasal();
					}
					break;
			
					
				case 3:
					int ed;
					cout<<"ingresa la la edad de pacientes a buscar:";
					cin>>ed;
					for(i=0;i<np;i++){
						if((ptr+i)->nums(ed)){
							(ptr+i)->verdatos1(),(ptr+i)->verdatos(),(ptr+i)->verfechain(),(ptr+i)->verfechasal();
						}
						  
					}
					break;
				case 4:
					{
					int sh;
					COSTOS a(100),obj2,c;
					cout<<"ingrese las semnas de hospitalizacion del paciente:"<<endl;
					cin>>sh;
					obj2.dias_hospitalizacion(sh);
					c=a+obj2;
					c.vercostos();
				}
					break;
				case 5:
				    cout<<"saliendo del programa...";
				    salir=1;
				    break;
			    	default:
					  cout<<"no valido";
					break;			
				
		}
		
	}
	return 0;
}
