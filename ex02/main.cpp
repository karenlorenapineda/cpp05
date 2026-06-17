/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:01:52 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/17 21:01:53 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

int main()
{
    // Seed the random number generator only once at the beginning
    std::srand(time(NULL));

    std::cout << "\n\033[36m----------- Shrubbery Tests [Sign: 145, Exec: 137] -----------\n\033[0m" << std::endl;
    try
    {
        Bureaucrat            alfred("Alfred", 10);
        Bureaucrat            lowGrade("LowGrade_Bob", 150);
        ShrubberyCreationForm plant("Garden");

        std::cout << "Initial state:\n" << plant << std::endl;

        std::cout << "\n-> [TEST] " << lowGrade << " tries to sign..." << std::endl;
        lowGrade.signForm(plant);
        
        std::cout << "\n-> [TEST] " << alfred << " tries to sign..." << std::endl;
        alfred.signForm(plant);
        
        std::cout << "\nUpdated state:\n" << plant << std::endl;
        
        std::cout << "-> [TEST] " << alfred << " tries to execute..." << std::endl;
        alfred.executeForm(plant);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


    std::cout << "\n\033[36m----------- Robotomy Tests [Sign: 72, Exec: 45] -----------\n\033[0m" << std::endl;
    try
    {
        Bureaucrat          doc("Doc", 40);
        RobotomyRequestForm robot1("Bender");
        RobotomyRequestForm robot2("Wall-E");
        RobotomyRequestForm robot3("R2-D2");

        std::cout << "Initial state:\n" << robot1 << std::endl;

        // Error Case: Try to execute before signing
        std::cout << "\n-> [TEST] " << doc << " tries to execute unsigned form..." << std::endl;
        doc.executeForm(robot1); 

        std::cout << "\n-> [TEST] Signing all forms with " << doc << "..." << std::endl;
        doc.signForm(robot1);
        doc.signForm(robot2);
        doc.signForm(robot3);

        std::cout << "\n-> [TEST] Executing all 3 to test 50% success rate randomness..." << std::endl;
        doc.executeForm(robot1);
        doc.executeForm(robot2);
        doc.executeForm(robot3);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


    std::cout << "\n\033[36m----------- Presidential Tests [Sign: 25, Exec: 5] -----------\n\033[0m" << std::endl;
    try
    {
        Bureaucrat             president("President_Zaphod", 5);
        Bureaucrat             minister("Minister_Jim", 20); // Can sign (req 25) but cannot execute (req 5)
        PresidentialPardonForm fool("The Fool");

        std::cout << "Initial state:\n" << fool << std::endl;

        std::cout << "\n-> [TEST] " << minister << " tries to sign..." << std::endl;
        minister.signForm(fool);
        
        // Error Case: Has high enough grade to sign, but too low to execute
        std::cout << "\n-> [TEST] " << minister << " tries to execute..." << std::endl;
        minister.executeForm(fool); 

        // Success Case: President executes it
        std::cout << "\n-> [TEST] " << president << " tries to execute..." << std::endl;
        president.executeForm(fool);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


    std::cout << "\n\033[31m----------- Construction Fail Tests -----------\n\033[0m" << std::endl;
    try
    {
        std::cout << "-> [TEST] Attempting to create a Bureaucrat with grade 151..." << std::endl;
        Bureaucrat boss("Invalid_Guy", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}