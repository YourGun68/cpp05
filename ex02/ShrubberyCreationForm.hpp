
#pragma once

#include <fstream>
#include "aform.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	const std::string _target;

	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	void execute(Bureaucrat const &executor)const;

	std::string get_target(void)const;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);
