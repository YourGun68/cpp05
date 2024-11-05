/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:00:27 by jpeter            #+#    #+#             */
/*   Updated: 2024/10/28 11:04:22 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Jack"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int i) {
	set_name(name);
	set_grade(i);
	if (i > 150)
		throw GradeTooLowException();
	else if (i < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ptr): _name(ptr._name), _grade(ptr._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator =(const Bureaucrat &ptr) {
	if (this != &ptr)
	{
		set_name(ptr._name);
		set_grade(ptr._grade);
	}
	return *this;
}

void	Bureaucrat::Increment(int i) {
	if (_grade - i < 1)
		throw GradeTooHighException();
	_grade -= i;
}

void	Bureaucrat::Decrement(int i) {
	if (_grade + i > 150)
		throw GradeTooLowException();
	_grade += i;
}

std::string	Bureaucrat::GradeTooLowException() const {
	return "Bureaucrat grade too low";
}

std::string	Bureaucrat::GradeTooHighException() const {
	return "Bureaucrat grade too high";
}

void	Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.get_name() << std::endl;
	}
	catch (std::string e) {
		std::cout	<< _name << " cannot sign " << form.get_name() << " because "
					<< e << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const {
		form.execute(*this);
}

std::string	Bureaucrat::get_name() const {
	return _name;
}

int	Bureaucrat::get_grade() const {
	return _grade;
}

void	Bureaucrat::set_name(std::string name) {
	_name = name;
}

void	Bureaucrat::set_grade(int i) {
	_grade = i;
	if (i > 150)
		throw GradeTooLowException();
	else if (i < 1)
		throw GradeTooHighException();
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &ptr) {
	o	<< ptr.get_name() << ", bureaucrat of grade "
		<< ptr.get_grade() << std::endl;
	return o;
}
