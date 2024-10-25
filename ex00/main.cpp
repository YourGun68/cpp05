/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:33 by jpeter            #+#    #+#             */
/*   Updated: 2021/12/04 02:19:55 by jpeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

void	sectionTitle(const std::string& title) {
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

int	main() {
	sectionTitle("constructor");

	try {
		Bureaucrat	pippo("pippo", 1);
		std::cout << pippo;
	}
	catch (std::string e) {
		std::cout << "Error: " << e << std::endl;
	}

	try {
		Bureaucrat	poppi("poppi", -42);
		std::cout << poppi;
	}
	catch (std::string e) {
		std::cout << "Error: " << e << std::endl;
	}
	try {
		Bureaucrat	poppi("poppi", 4242);
		std::cout << poppi;
	}
	catch (std::string e) {
		std::cout << "Error: " << e << std::endl;
	}
	sectionTitle("increment");
	try {
		Bureaucrat	pippo("pippo", 12);
		std::cout << pippo;
		pippo.Increment(10);
		std::cout << pippo;
		pippo.Increment(1);
		std::cout << pippo;
		pippo.Increment(1);
		std::cout << pippo;
	}
	catch (std::string e) {
		std::cout << "Error: " << e << std::endl;
	}
	sectionTitle("decrement");
	try {
		Bureaucrat	pippo("pippo", 139);
		std::cout << pippo;
		pippo.Decrement(10);
		std::cout << pippo;
		pippo.Decrement(1);
		std::cout << pippo;
		pippo.Decrement(1);
		std::cout << pippo;
	}
	catch (std::string e) {
		std::cout << "Error: " << e << std::endl;
	}
}
