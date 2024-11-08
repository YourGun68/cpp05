/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:25:49 by jpeter            #+#    #+#             */
/*   Updated: 2024/11/06 10:45:24 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default") {
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm Constructor for target called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): AForm("RobotomyRequestForm", 72, 45), _target(src.get_target()) {
	std::cout << "RobotomyRequestForm Copy Constructor called to copy" << std::endl;

	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Deconstructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

static int robot_fail = 0;

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if ((int)executor.get_grade() > this->get_exec())
		throw (executor.GradeTooLowException());
	else if (this->get_sign() == false)
		throw (AForm::AlreadySigned());
	else if (robot_fail++ % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->get_target() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::string	RobotomyRequestForm::get_target(void) const {
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a) {
	o << "Form " << a->get_target() <<
	":\n\tsign-grade:\t" << a->get_grade() <<
	"\n\texec-grade:\t" << a->get_exec() <<
	"\n\tis signed:\t" << a->get_sign() <<
	std::endl;
	return (o);
}
