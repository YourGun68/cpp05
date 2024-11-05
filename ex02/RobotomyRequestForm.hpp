
#pragma once

#include "aform.hpp"

class RobotomyRequestForm: public AForm
{
private:
	const std::string _target;
	
	RobotomyRequestForm(void);
public:

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	void execute(Bureaucrat const &executor)const;

	std::string get_target(void)const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);
