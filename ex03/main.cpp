/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 23:14:17 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/22 11:43:55 by kpineda-         ###   ########.fr       */
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

	// ----------------------------------------------------
    // FAILURE CASES (EDGE CASES & EXCEPTIONS)
    // ----------------------------------------------------
    std::cout << "\n" << RED << BOLD << "[FAILURE CASES: Form creation errors & insufficient grades]" << RESET << std::endl;

    // Test 4: Intern tries to create an invalid form name
    std::cout << YELLOW << "\n--- Test 4: Invalid Form Name ---" << RESET << std::endl;
    AForm* unknownForm = someRandomIntern.makeForm("invalid form name", "Target");
    if (!unknownForm) 
    {
        std::cout << GREEN << "-> Success: Intern correctly returned NULL for an unknown form." << RESET << std::endl;
    }
    else 
    {
        std::cout << RED << "-> Failure: Intern should not have created this form!" << RESET << std::endl;
        delete unknownForm;
    }

    // Test 5: Form is valid, but Bureaucrat has a grade too low to sign
    std::cout << YELLOW << "\n--- Test 5: Bureaucrat Grade Too Low to Sign ---" << RESET << std::endl;
    AForm* lowGradeForm = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (lowGradeForm) 
    {
        std::cout << *lowGradeForm << std::endl;
        
        // lowRrank tiene grado 140, PresidentialPardon requiere grado 25 para firmar
        lowRrank.signForm(*lowGradeForm); 
        
        // Intentamos ejecutarlo sin estar firmado y con bajo rango
        lowRrank.executeForm(*lowGradeForm);
        
        delete lowGradeForm;
        std::cout << GREEN << "-> Memory freed for Low Grade Test Form" << RESET << std::endl;
    }

    // Test 6: Form is signed by Boss, but Low-Rank tries to execute it
    std::cout << YELLOW << "\n--- Test 6: Bureaucrat Grade Too Low to Execute ---" << RESET << std::endl;
    AForm* executeFailForm = someRandomIntern.makeForm("robotomy request", "Fry");
    if (executeFailForm) 
    {
        boss.signForm(*executeFailForm); // Boss lo firma con éxito
        
        // lowRrank intenta ejecutarlo (requiere grado 45, tiene 140)
        lowRrank.executeForm(*executeFailForm); 
        
        delete executeFailForm;
        std::cout << GREEN << "-> Memory freed for Execute Fail Test Form" << RESET << std::endl;
    }

    return 0;
}