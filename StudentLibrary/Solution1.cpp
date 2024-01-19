#include "Solution1.h"
#include <iostream>
#include <exception>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

float Solution1::ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to)
{
	float resultat = 0.0;
	if (_to == _from)
	{
		resultat = _value;
	}
	else {
		switch (_from)
		{
		case TemperatureUnits::CELSIUS:
			if (_to == TemperatureUnits::FAHRENHEIT)
			{
				resultat = (_value * 9 / 5) + 32;
			}
			else if (_to == TemperatureUnits::KELVIN)
			{
				resultat = _value + 273;
			}
			break;
		case TemperatureUnits::FAHRENHEIT:
			if (_to == TemperatureUnits::CELSIUS)
			{
				resultat = (_value - 32) * 5 / 9;
			}
			else if (_to == TemperatureUnits::KELVIN)
			{
				resultat = (_value - 32) * 5 / 9 + 273;
			}
			break;
		case TemperatureUnits::KELVIN:
			if (_to == TemperatureUnits::CELSIUS)
			{
				resultat = _value - 273;
			}
			else if (_to == TemperatureUnits::FAHRENHEIT)
			{
				resultat = (_value - 273) * 9 / 5 + 32;
			}
			break;
		default:
			throw std::exception("pas de température a calcule");
		}
	}
	
	return round(resultat * 100) / 100;
}

#endif
