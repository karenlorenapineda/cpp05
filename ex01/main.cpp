/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:45:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/16 22:12:45 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// Colores para que la terminal sea legible y bonita para el corrector
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(void)
{
    // =====================================================================
    // TEST 1: EXCEPCIONES EN BURÓCRATAS (CONSTRUCTORES Y RANGOS)
    // =====================================================================
    std::cout << YELLOW << "\n--- TEST 1: Bureaucrat Exceptions (Creation) ---" << RESET << std::endl;
    try {
        Bureaucrat hernd("Bernd", 1500);
    } catch(const std::exception &e) {
        std::cerr << RED << "Exception caught (Too Low): " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat olaf("Olaf", -10);
    } catch(const std::exception &e) {
        std::cerr << RED << "Exception caught (Too High): " << e.what() << RESET << std::endl;
    }

    // =====================================================================
    // TEST 2: EXCEPCIONES EN FORMULARIOS (¡NUEVO!)
    // =====================================================================
    std::cout << YELLOW << "\n--- TEST 2: Form Exceptions (Creation) ---" << RESET << std::endl;
    try {
        Form invalidForm1("Tax Form", 0, 50); // Grado 0 no existe
    } catch(const std::exception &e) {
        std::cerr << RED << "Exception caught (Form Too High): " << e.what() << RESET << std::endl;
    }

    try {
        Form invalidForm2("Permit Form", 50, 151); // Grado 151 no existe
    } catch(const std::exception &e) {
        std::cerr << RED << "Exception caught (Form Too Low): " << e.what() << RESET << std::endl;
    }

    // =====================================================================
    // TEST 3: INCREMENTAR / DECREMENTAR HASTA EL LÍMITE
    // =====================================================================
    std::cout << YELLOW << "\n--- TEST 3: Bureaucrat Grade Modifications ---" << RESET << std::endl;
    Bureaucrat bob("Bob", 2);
    std::cout << bob;
    try {
        bob.incrementGrade(); // Pasa a grado 1
        std::cout << GREEN << " Incremented: " << RESET << bob;
        bob.incrementGrade(); // Debería lanzar excepción (0 no existe)
    } catch(const std::exception& e) {
        std::cerr << RED << " Exception caught (Bob): " << e.what() << RESET << std::endl;
    }

    Bureaucrat tim("Tim", 149);
    std::cout << tim;
    try {
        tim.decrementGrade(); // Pasa a grado 150
        std::cout << GREEN << " Decremented: " << RESET << tim;
        tim.decrementGrade(); // Debería lanzar excepción (151 no existe)
    } catch(const std::exception& e) {
        std::cerr << RED << " Exception caught (Tim): " << e.what() << RESET << std::endl;
    }

    // =====================================================================
    // TEST 4: FIRMA DE FORMULARIOS (ÉXITO Y ERROR)
    // =====================================================================
    std::cout << YELLOW << "\n--- TEST 4: Form Signing ---" << RESET << std::endl;
    
    Form id_form("ID-Form", 100, 90);
    Bureaucrat mr_slow("Mr. Slow", 150); // Constructor por defecto o explícito bajo
    Bureaucrat mr_id("Mr. ID", 100);     // Justo en el límite exigido

    std::cout << BLUE << "[Initial State]" << RESET << std::endl;
    std::cout << id_form;
    
    std::cout << BLUE << "\n[Attempt 1: Rank too low]" << RESET << std::endl;
    mr_slow.signForm(id_form);
    std::cout << id_form;

    std::cout << BLUE << "\n[Attempt 2: Rank adequate (Boundary)]" << RESET << std::endl;
    mr_id.signForm(id_form);
    std::cout << id_form;

    // =====================================================================
    // TEST 5: RE-FIRMAR UN FORMULARIO (¡NUEVO!)
    // =====================================================================
    std::cout << YELLOW << "\n--- TEST 5: Double Signing ---" << RESET << std::endl;
    Bureaucrat boss("The Boss", 1);
    
    std::cout << BLUE << "[Attempt 3: Try to sign an already signed form]" << RESET << std::endl;
    boss.signForm(id_form); // Comportamiento controlado
    
    std::cout << GREEN << "\n--- All tests completed successfully ---" << RESET << std::endl;
    return (0);
}