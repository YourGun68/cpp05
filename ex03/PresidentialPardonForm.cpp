/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:25:49 by jpeter            #+#    #+#             */
/*   Updated: 2024/11/06 10:45:06 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default") {
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm Constructor for target called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): AForm("PresidentialPardonForm", 25, 5), _target(src.get_target()) {
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;

	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Deconstructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if ((int)executor.get_grade() > this->get_exec())
		throw (executor.GradeTooLowException());
	else if (this->get_sign() == false)
		throw (AForm::AlreadySigned());
	else
		std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	PresidentialPardonForm::get_target(void) const {
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a) {
	o << "Form " << a->get_target() <<
	":\n\tsign-grade:\t" << a->get_grade() <<
	"\n\texec-grade:\t" << a->get_exec() <<
	"\n\tis signed:\t" << a->get_sign() <<
	std::endl;
	return (o);
}
