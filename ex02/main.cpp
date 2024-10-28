/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:33 by jpeter            #+#    #+#             */
/*   Updated: 2024/10/28 11:18:11 by jpeter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"
#include "form.hpp"

void	sectionTitle(const std::string& title) {
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

void	printError(std::string e) {
	std::cout << "Error: " << e << std::endl;
}

int	main() {
	Bureaucrat	burro("burro", 42);
	std::cout << burro;

	sectionTitle("constructor");
	try {
		Form	formaccio("formaccio", 1000, 1);
	}
	catch (std::string e) {
		printError(e);
	}
	try {
		Form	formaccio("formaccio", 42, 0);
	}
	catch (std::string e) {
		printError(e);
	}
	try {
		Form	formino("formino", 42, 42);
		Form	formone("formone", 1, 1);

		std::cout << std::endl << formino << formone;

		sectionTitle("sign twice");
		burro.signForm(formino);
		std::cout << formino;
		burro.signForm(formino);

		sectionTitle("grade too low");
		burro.signForm(formone);
	}
	catch (std::string e) {
		printError(e);
	}
}
