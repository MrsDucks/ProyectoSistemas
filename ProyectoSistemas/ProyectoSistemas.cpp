#include <iostream>

using namespace std;


int main() {
	int saldo_incial = 1000;
	int saldo, opcion, agregar, retirar;

	cout << "\tBienvenido a su cajero";
	cout << "\nEscoja una opcion: ";
	cout << "\n1. Deposito: ";
	cout << "\n2. Retiro de saldo:  ";
	cout << "\n3. Saldo en la cuenta ";
	cout << "\n0. Salir \n ";
	cin >> opcion;

	while (true) {

		if (opcion == 1) {
			cout << "\nIngrese la cantidad a depositar: ";
			cin >> agregar;
			_asm {
				mov eax, saldo_incial
				mov ebx, agregar
				add eax, ebx
				mov saldo, eax
			}
			cout << "\nCantidad disponible en su cuenta: " << saldo;
		}
		else if (opcion == 2) {
			cout << "\nIngrese la cantidad a retirar: ";
			cin >> retirar;
			if (retirar > saldo_incial) {
				cout << "La cantidad ingresada es mayor a su saldo actual." << endl;
				continue;

			}
			_asm {
				mov eax, saldo_incial
				mov ebx, retirar
				sub eax, ebx
				mov saldo, eax
			}
			cout << "\nCantidad disponible en su cuenta: " << saldo;
		}
		else if (opcion == 3) {
			cout << "Su saldo actual es de: " << saldo_incial;
		}
		else if (opcion == 0) {
			cout << "Gracias por utilizar nuestro cajero, pase un excelente dia";
		}
		else
		{
			cout << "Se equivoco de opcion en el menu";
		}
		cin.get();
		return 0;
	}
}