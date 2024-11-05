
#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string	_name;
	bool				_sign;
	const int			_grade;
	const int			_exec;

	AForm();
	AForm(std::string name, int i, int j);
public:
	AForm(const AForm &ptr);
	virtual ~AForm();

	AForm	&operator=(const AForm &ptr);

	std::string		GradeTooHighException() const;
	std::string		GradeTooLowException() const;
	std::string		AlreadySigned() const;
	void			beSigned(const Bureaucrat &bur);
	
	virtual void	execute(Bureaucrat const &executor) const = 0;

	std::string		get_name() const;
	bool			get_sign() const;
	int				get_grade() const;
	int				get_exec() const;
};

std::ostream	&operator<<(std::ostream &o, const AForm &ptr);
