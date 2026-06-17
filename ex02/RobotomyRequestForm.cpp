/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:02:22 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/17 21:02:23 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const  std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if(this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);

	std::cout << "* DRILLING NOISES *" << std::endl;

	if(std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy of " << _target << " failed!" << std::endl;
}

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
    str << "Form: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Exec Grade: " << form.getExecGrade();
    return str;
}