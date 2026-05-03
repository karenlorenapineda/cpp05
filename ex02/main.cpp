/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:45:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/05/03 12:47:03 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade(); // OK → pasa a 1
        std::cout << a << std::endl;

        a.incrementGrade(); // ERROR
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}