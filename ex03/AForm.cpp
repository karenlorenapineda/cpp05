/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:24:34 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/17 15:20:13 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("default"), _isSigned(false), _signGrade(30), _execGrade(60)
{
	
}
AForm::AForm(const std::string& name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if(this->_signGrade < 1)
		throw(AForm::GradeTooHighException());
	else if(this->_signGrade > 150)
		throw(AForm::GradeTooLowException());
	if(this->_execGrade < 1)
		throw(AForm::GradeTooHighException());
	else if(this->_execGrade >150)
		throw(AForm::GradeTooLowException());
}
AForm::AForm(AForm const &src):_name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{

}
AForm::~AForm(void)
{
	
}

AForm &AForm::operator=(AForm const &src)
{
	this->_isSigned = src._isSigned;
	return(*this);
}

const std::string&	AForm::getName() const
{
	return(_name);
}
bool			AForm::getIsSigned() const
{
	return(_isSigned);
}
int			AForm::getSignGrade() const
{
	return(_signGrade);
}
int			AForm::getExecGrade() const
{
	return(_execGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::checkExecution(Bureaucrat const& executor) const
{
	if(!_isSigned)
		throw FormNotSignedException();
	if(executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return("Form not signed!");
}

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
	str << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " SignGrade: " << form.getSignGrade() << " ExecuteGrade: " << form.getExecGrade() << std::endl;
	return(str);
}