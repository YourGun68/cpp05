/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:25:49 by jpeter            #+#    #+#             */
/*   Updated: 2024/11/16 10:07:25 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aform.hpp"

AForm::AForm(): _name("Jacky"), _sign(false), _grade(150), _exec(0) {}

AForm::AForm(std::string name, int i, int j): _name(name), _sign(false), _grade(i), _exec(j) {
	if (i > 150)
		throw GradeTooLowException();
	else if (i < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &ptr): _name(ptr._name), _sign(false), _grade(ptr._grade), _exec(ptr._exec) {}

AForm::~AForm() {}

AForm&	AForm::operator =(const AForm &ptr) {
	if (this != &ptr) {}
	return *this;
}

std::string	AForm::GradeTooLowException() const {
	return "AForm grade too low";
}

std::string	AForm::GradeTooHighException() const {
	return "AForm grade too high";
}

std::string	AForm::AlreadySigned() const {
	return "AForm is already signed";
}

void	AForm::beSigned(const Bureaucrat &bur) {
	if (_sign)
		throw AlreadySigned();
	if (_grade < bur.get_grade())
		throw GradeTooHighException();
	_sign = true;
}

std::string	AForm::get_name() const {
	return _name;
}

bool	AForm::get_sign() const {
	return _sign;
}

int	AForm::get_grade() const {
	return _grade;
}

int	AForm::get_exec() const {
	return _exec;
}

std::ostream&	operator<<(std::ostream &o, const AForm& ptr) {
	o	<< std::boolalpha << "form " << ptr.get_name() << ", signed: "
		<< ptr.get_sign() << ", grade to sign " << ptr.get_grade()
		<< ", grade to execute " << ptr.get_exec() << std::endl;
	return o;
}
