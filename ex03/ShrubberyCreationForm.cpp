/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:02:30 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/22 11:37:50 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if(this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);

    std::ofstream file((_target + "_shrubbery").c_str());
	if(!file.is_open())
	{
		std::cerr << "Couldn't create file." << std::endl;
		return;
	}
    file << "     ccee88oo" << std::endl;
	file << "  C8O8O8Q8PoOb o8oo" << std::endl;
	file << " dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "    6OuU  /p u gcoUodpP" << std::endl;
	file << "      \\\\\\//  /douUP" << std::endl;
	file << "        \\\\\\////" << std::endl;
	file << "         |||/\\" << std::endl;
	file << "         |||\\/" << std::endl;
	file << "         |||||" << std::endl;
	file << "   .....//||||\\...." << std::endl;
    file.close();
}

std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
    str << "Form: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Exec Grade: " << form.getExecGrade();
    return str;
}