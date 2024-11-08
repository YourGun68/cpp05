
#pragma once

#include "aform.hpp"

class PresidentialPardonForm: public AForm
{
private:
	const std::string _target;
	
	PresidentialPardonForm(void);
public:
// Constructors
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &src);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	void execute(Bureaucrat const &executor)const;

	std::string get_target(void)const;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);
