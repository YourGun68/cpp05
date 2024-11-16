/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <jpeter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:33 by jpeter            #+#    #+#             */
/*   Updated: 2024/11/16 09:57:26 by jpeter           ###   ########.fr       */
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
	Bureaucrat	burro("Gerald", 42);
	std::cout << burro;

	sectionTitle("constructor");
	try {
		Form	form("Jaskier", 1000, 1);
	}
	catch (std::string e) {
		printError(e);
	}
	try {
		Form	formA("Yenefer", 42, 42);
		Form	formB("Triss", 1, 1);

		std::cout << std::endl << formA << formB;

		sectionTitle("sign twice");
		burro.signForm(formA);
		std::cout << formA;
		burro.signForm(formA);

		sectionTitle("grade too low");
		burro.signForm(formB);
	}
	catch (std::string e) {
		printError(e);
	}
}
