
#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "aform.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string _name;
	int         _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int i);
	Bureaucrat(const Bureaucrat &ptr);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &ptr);

	std::string	GradeTooHighException() const;
	std::string	GradeTooLowException() const;
	void		Increment(int i);
	void		Decrement(int i);
	void		signForm(AForm &form) const ;
	void		executeForm(AForm const &form) const;

	std::string	get_name() const;
	int			get_grade() const;
	void		set_name(std::string name);
	void		set_grade(int i);
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &ptr);
