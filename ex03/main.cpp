/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 23:14:17 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/17 23:14:18 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

// Color formatting definitions for scannable logs
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() 
{
    // Seed random number generator for Robotomy success rates
    std::srand(time(NULL));

    std::cout << CYAN << BOLD << "==================================================" << RESET << std::endl;
    std::cout << CYAN << BOLD << "          INTERN & FORM CREATION TESTS            " << RESET << std::endl;
    std::cout << CYAN << BOLD << "==================================================" << RESET << std::endl;

    Intern someRandomIntern;
    Bureaucrat boss("High-Rank Boss", 1);
    Bureaucrat lowRrank("Low-Rank Employee", 140);

    // ----------------------------------------------------
    // SUCCESS CASES (HAPPY PATHS)
    // ----------------------------------------------------
    std::cout << "\n" << GREEN << BOLD << "[SUCCESS CASES: Intern creates valid forms]" << RESET << std::endl;

    // Test 1: Shrubbery Creation
    std::cout << YELLOW << "\n--- Test 1: Shrubbery Creation Form ---" << RESET << std::endl;
    AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "HomeGarden");
    if (shrubbery) 
    {
        std::cout << *shrubbery << std::endl;
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
        delete shrubbery; // Clean memory allocated by 'new'
        std::cout << GREEN << "-> Memory freed for Shrubbery Form" << RESET << std::endl;
    }

    // Test 2: Robotomy Request
    std::cout << YELLOW << "\n--- Test 2: Robotomy Request Form ---" << RESET << std::endl;
    AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robotomy) 
    {
        std::cout << *robotomy << std::endl;
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
        delete robotomy;
        std::cout << GREEN << "-> Memory freed for Robotomy Form" << RESET << std::endl;
    }

    // Test 3: Presidential Pardon
    std::cout << YELLOW << "\n--- Test 3: Presidential Pardon Form ---" << RESET << std::endl;
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (pardon) 
    {
        std::cout << *pardon << std::endl;
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
        std::cout << GREEN << "-> Memory freed for Pardon Form" << RESET << std::endl;
    }

	std::cout << "\n" << CYAN << BOLD << "==================================================" << RESET << std::endl;
    std::cout << CYAN << BOLD << "                END OF TEST SUITE                 " << RESET << std::endl;
    std::cout << CYAN << BOLD << "==================================================" << RESET << std::endl;

    return 0;
}