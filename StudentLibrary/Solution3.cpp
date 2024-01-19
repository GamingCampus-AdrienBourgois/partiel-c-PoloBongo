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
        std::sort(words.begin(), words.end(), [](const std::string& first, const std::string& last)
        {
           return std::lexicographical_compare(first.begin(), first.end(), last.begin(), last.end(), [](char char1, char char2)
           {
                return std::tolower(char1) < std::tolower(char2);
           });
        });
    }
    catch (const std::exception& error)
    {
        std::cerr << "une erreur est survenue lors de la lecture du vecteur" << error.what();
    }

}

std::vector<std::string> Solution3::GetSortedWords() const
{
	return words;
}

#endif
