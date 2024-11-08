/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:33 by jpeter            #+#    #+#             */
/*   Updated: 2024/11/06 10:44:23 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"
#include "aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "-------------------------------------------" << std::endl;
	{
		
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Ganon", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("Link");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		try
		{
			a->signForm(*c);
			a->executeForm(*c);
			b->execute(*a);
		}
		catch(std::string e)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Ganon", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Zelda");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("Linbeck");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		try
		{
			b->beSigned(*a);
			a->signForm(*c);
			for (int i= 0; i < 4; i++)
				b->execute(*a);
			c->execute(*a);
		}
		catch(std::string e)
		{
			std::cout << e << std::endl; 
		}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	return (0);
}
