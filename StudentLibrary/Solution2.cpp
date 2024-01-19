#include "Solution2.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <exception>
#include <stdexcept>

// Don't forget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

float Solution2::GetBalance(const std::string& accountName)
{
	float totoalArgent = 0.0;
	std::string bankAccountName = "BankAccount/" + accountName + ".txt";
	std::ifstream fichier(bankAccountName);
	if (!fichier.is_open())
	{
		throw std::exception("Impossible d'ouvrir le fichier .TXT");
	}
	else
	{
		std::string ligne;
		while (std::getline(fichier, ligne))
		{
			std::istringstream iss(ligne);
			std::string action;
			float argent;
			

			if (iss >> action >> argent)
			{
				std::cout << "type : " << action << " montant : " << argent << "\n";
				totoalArgent = totoalArgent + argent;
			}
			else {
				throw std::runtime_error("impossible de lire la ligne suivante : " + ligne);
			}

			std::cout << ligne << std::endl;
		}
		fichier.close();
	}
}

#endif
