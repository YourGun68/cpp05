/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:28:21 by jpeter            #+#    #+#             */
/*   Updated: 2024/11/08 10:55:01 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.hpp"

const std::string	intern::_str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const Form			intern::_forms[3] = {&intern::ShrubberyCreation, &intern::RobotomyRequest, &intern::PresidentialPardon};

intern::intern() {
	std::cout << "Default Intern constructor called" << std::endl;
}

intern::intern(const intern &ptr) {
	std::cout << "Copy Intern constructor called" << std::endl;
	*this = ptr;
}

intern::~intern() {
	std::cout << "Default Intern destructor called" << std::endl;
}

intern	&intern::operator=(const intern &ptr) {
	std::cout << "Assignation Intern constructor called" << std::endl;
	if (this != &ptr)
		*this = ptr;
	return *this;
}

AForm	*intern::ShrubberyCreation(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm	*intern::RobotomyRequest(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm	*intern::PresidentialPardon(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm	*intern::makeForm(std::string a, std::string b) const {
	for (int i = 0; i < 3; i++)
		if (_str[i] == a)
			return (this->*(_forms[i]))(b);
	throw intern::NotAForm();
}

std::string	intern::NotAForm() const {
	return "Form not found";
}
