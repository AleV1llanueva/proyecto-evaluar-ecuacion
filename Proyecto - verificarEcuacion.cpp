#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

bool verEqu(string ecuation) {
	int nums = 0, simbs = 0; //Contadores de elementos
	bool isPoint = 0;
	if (!isdigit(ecuation[0]) || !isdigit(ecuation[ecuation.length() - 1])) { //No termine o inicie en un simbolo que no sea digito
		cout << "No puede iniciar o terminar asi";
		return 0;
	}
	for (int i = 0; i < ecuation.length(); i++){
		if (i == 0 || i == ecuation.length()) continue;
		if (ecuation[i] == '/' || ecuation[i] == '*' || ecuation[i] == '-' || ecuation[i] == '+' || ecuation[i] == '%') { //simbolos
			if (ecuation[i - 1] != ' ' || ecuation[i + 1] != ' ') {
				cout << "El simbolo esta mal colocado\n";
				return 0;
			}
			simbs++;
			isPoint = 0;
		}
		else if (ecuation[i] == '.') { //punto
			if (isPoint) {
				cout << "Coloco mas de un punto en este numero";
				return 0;
			}
			if (!isdigit(ecuation[i + 1]) || !isdigit(ecuation[i - 1])) {
				cout << "El punto esta mal colocado";
				return 0;
			}
			isPoint = 1;
		}
		else if (isdigit(ecuation[i])) {
			//numeros
			if (nums == 0) nums++;
			else if (nums == simbs) {
				nums++;
			};
		}
		else if (ecuation[i] == ' ') { //espacios
			if (ecuation[i - 1] == '/' || ecuation[i - 1] == '*' || ecuation[i - 1] == '-' || ecuation[i-1] == '%' || ecuation[i - 1] == '+' && ecuation[i + 1]) {
				
			}
			else if (ecuation[i + 1] == '/' || ecuation[i + 1] == '*' || ecuation[i + 1] == '-' || ecuation[i + 1] == '%' || ecuation[i + 1] == '+' && ecuation[i - 1]) {
				
			}
			else { //cualquier otro caracter/simbolo
				cout << "Error caracter";
				return 0;
			}
		}
		else {
			cout << "No es un simbolo adecuado";
			return 0;
		}
	}
	if (nums < 2 || simbs < 1) {
		cout << "Error, no completa";
		return 0;
	}
	cout << endl;
	cout << endl;
	return 1;
}


int main() {
	string ecuation;
	cout << "Ingrese el valor de la ecuacion\n";
	getline(cin, ecuation);
	if (verEqu(ecuation)) cout << "La operacion es correcta";
	return 0;
}
