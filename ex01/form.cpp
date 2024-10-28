/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:25:49 by jpeter            #+#    #+#             */
/*   Updated: 2024/10/28 11:17:50 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"

Form::Form(): _name("Jacky"), _sign(false), _grade(150), _exec(0) {}

Form::Form(std::string name, int i, int j): _name(name), _sign(false), _grade(i), _exec(j) {
	if (i > 150)
		throw GradeTooLowException();
	else if (i < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &ptr): _name(ptr._name), _sign(false), _grade(ptr._grade), _exec(ptr._exec) {}

Form::~Form() {}

Form&	Form::operator =(const Form &ptr) {
	if (this != &ptr) {}
	return *this;
}

std::string	Form::GradeTooLowException() const {
	return "Form grade too low";
}

std::string	Form::GradeTooHighException() const {
	return "Form grade too high";
}

std::string	Form::AlreadySigned() const {
	return "Form is already signed";
}

void	Form::beSigned(const Bureaucrat &bur) {
	if (_sign)
		throw AlreadySigned();
	if (_grade < bur.get_grade())
		throw GradeTooLowException();
	_sign = true;
}

std::string	Form::get_name() const {
	return _name;
}

bool	Form::get_sign() const {
	return _sign;
}

int	Form::get_grade() const {
	return _grade;
}

int	Form::get_exec() const {
	return _exec;
}

std::ostream&	operator<<(std::ostream &o, const Form& ptr) {
	o	<< std::boolalpha << "form " << ptr.get_name() << ", signed: "
		<< ptr.get_sign() << ", grade to sign " << ptr.get_grade()
		<< ", grade to execute " << ptr.get_exec() << std::endl;
	return o;
}
