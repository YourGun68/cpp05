/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:25:49 by jpeter            #+#    #+#             */
/*   Updated: 2024/10/28 11:17:50 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default") {
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm Constructor for target " << this->get_target() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", 145, 137), _target(src.get_target()) {
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << src.get_name() <<
	" into " << this->get_name() << std::endl;

	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Deconstructor " << this->get_name() << " called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if ((int)executor.get_grade() > this->get_exec())
		throw (executor.GradeTooLowException());
	else if (this->get_sign() == false)
		throw (AForm::AlreadySigned());
	else
	{
		std::ofstream outfile (this->get_target().append("_tree").c_str());
		outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		std::endl;
		outfile.close();
	}
}

std::string	ShrubberyCreationForm::get_target(void) const {
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a) {
	o << "Form " << a->get_name() <<
	":\n\tsign-grade:\t" << a->get_grade() <<
	"\n\texec-grade:\t" << a->get_exec() <<
	"\n\tis signed:\t" << a->get_sign() <<
	std::endl;
	return (o);
}
