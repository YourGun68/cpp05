/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:33 by jpeter            #+#    #+#             */
/*   Updated: 2024/11/08 10:59:46 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"
#include "intern.hpp"

void	sectionTitle(std::string title) {
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}


void	testMake(std::string name, std::string target) {
	sectionTitle(name);

	Bureaucrat	bur("bureau", 1);
	intern		inter;
	AForm		*form = inter.makeForm(name, target);

	std::cout << *form;
	bur.signForm(*form);
	bur.executeForm(*form);

	delete form;
}

int	main() {
	try {
		testMake("robotomy request", "Harry");
		testMake("presidential pardon", "Ron");
		testMake("shrubbery creation", "Hermione");
		testMake("not a form", "Hagrid");
	}
	catch (std::string e) {
		std::cout << "Error: " << e << std::endl;
	}
}
