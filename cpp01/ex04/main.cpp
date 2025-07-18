/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:34:35 by gabo              #+#    #+#             */
/*   Updated: 2025/07/18 13:11:24 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

/*
	Siempre que se trabaja con streams, hay que pasar la referencia a la funcion
	para que se pueda modificar el contenido del archivo original.
	En este caso, se usa std::ifstream para leer el archivo original y std::ofstream
	para escribir en un nuevo archivo.
*/
void replace(std::ifstream& file, std::string& s1, std::string& s2, std::ofstream& newFile) {
	
	std::string line;
	
	while (getline(file, line)) {
		size_t pos = 0, find;
		std::string result = "";
		
		while ((find = line.find(s1, pos)) != std::string::npos) {
			result += line.substr(pos, find - pos); // Añade la parte de la línea antes de s1
			result += s2; // Añade s2 en lugar de s1
			pos  = find + s1.length(); // Mueve la posición al final de s1 en la línea
		}
		result += line.substr(pos); // Añade el resto de la línea después de s1
		
		newFile << result << std::endl; // Escribe la línea modificada en el nuevo archivo
	}
	newFile.close();
}

int validateArguments(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Invalid arguments. Must be: " << std::endl;
		std::cerr << "\t<filename> <string1> <string2>" << std::endl;
		return (1);
	}
	else if (std::string(argv[2]).empty() || std::string(argv[3]).empty()) {
		std::cerr << "Strings to replace cannot be empty." << std::endl;
		return (1);
	}
	else if (std::string(argv[2]) == std::string(argv[3])) {
		std::cerr << "Strings to replace cannot be the same." << std::endl;
		return (1);
	}
	return (0);
}
int main(int argc, char *argv[]) {
	if (validateArguments(argc, argv))
		return (1);

	std::ifstream filename(argv[1]);
	if (!filename) {
		std::cerr << "Unable to open file for reading." << std::endl;
		return (1);
	}
	
	std::string newFilename = std::string(argv[1]) + ".replace";
	std::ofstream newFile(newFilename.c_str());
	if (!newFile) {
		std::cerr << "Unable to open file for writting." << std::endl;
		return (1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	replace(filename, s1, s2, newFile);
	std::ifstream file(newFilename.c_str());

	if (!file) {
		std::cerr << "Unable to open file for reading." << std::endl;
		return (1);
	}
	std::string line;
	while (getline(file, line))
		std::cout << line << std::endl;
	file.close();
	filename.close();
	return (0);
}

/*
	Caso de prueba:
	./replace text vida muerte -> Debería reemplazar todas las ocurrencias de "vida" por "muerte"
	./replace text vida vida -> Debería mostrar un error porque las cadenas son iguales
	./replace text vida -> Debería mostrar un error porque faltan argumentos
	./replace text la LA -> Debería reemplazar todas las ocurrencias de "la" por "LA"
	./replace text " " "_" -> Debería reemplazar todos los espacios por guiones bajos
	./replace text_not_found vida muerte -> Debería mostrar un error porque el archivo no existe
	

*/