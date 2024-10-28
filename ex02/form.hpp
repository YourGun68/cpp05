
#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_sign;
	const int			_grade;
	const int			_exec;
public:
	Form();
	Form(std::string name, int i, int j);
	Form(const Form &ptr);
	~Form();

	Form	&operator=(const Form &ptr);

	std::string	GradeTooHighException() const;
	std::string	GradeTooLowException() const;
	std::string	AlreadySigned() const;
	void		beSigned(const Bureaucrat &bur);

	std::string	get_name() const;
	bool		get_sign() const;
	int			get_grade() const;
	int			get_exec() const;
};

std::ostream	&operator<<(std::ostream &o, const Form &ptr);
