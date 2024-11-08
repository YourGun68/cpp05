
#pragma once

#include <iostream>
#include <string>
#include "aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class intern;

typedef AForm* (intern::*Form)(const std::string&) const;

class intern
{
private:
	static const std::string	_str[3];
	static const Form			_forms[3];

	AForm	*ShrubberyCreation(const std::string& target) const;
	AForm	*RobotomyRequest(const std::string& target) const;
	AForm	*PresidentialPardon(const std::string& target) const;
public:
	intern();
	intern(const intern &ptr);
	~intern();

	intern	&operator=(const intern& ptr);

	AForm		*makeForm(std::string a, std::string b) const;
	std::string	NotAForm() const;
};
