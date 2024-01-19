#include "Solution2.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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
		throw std::runtime_error("Impossible d'ouvrir le fichier suivant : " + bankAccountName);
	}
	else
	{
		std::string ligne;
		while (std::getline(fichier, ligne))
		{
			std::istringstream iss(ligne);
			std::string typeAction;
			float argent;
			

			if (iss >> typeAction >> argent)
			{				
				if (typeAction != "DEPOSIT" || typeAction != "WITHDRAW")
				{
					throw std::runtime_error("impossible de lire le type d'action suivant : " + typeAction);
				}

				if (typeAction == "DEPOSIT")
				{
					totoalArgent += argent;
				}
				else if (typeAction == "WITHDRAW")
				{
					totoalArgent -= argent;
				}
			}
			else
			{
				throw std::runtime_error("impossible de lire la ligne suivante : " + ligne);
			}
		}
		fichier.close();
	}
	return totoalArgent;
}

#endif
