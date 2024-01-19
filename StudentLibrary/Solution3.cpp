#include "Solution3.h"

#include <algorithm>
#include <iostream>
#include<exception>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_3

void Solution3::SetWords(const std::vector<std::string>& _words)
{
	words = _words;
}

void Solution3::SortWords() 
{
	try 
	{
		std::sort(words.begin(), words.end());
	}
	catch (const std::exception& error)
	{
		std::cerr << "Erreur : " << error.what() << std::endl;
	}

}

std::vector<std::string> Solution3::GetSortedWords() const
{
	return words;
}

#endif
