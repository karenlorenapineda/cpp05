/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:24:34 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/16 21:55:04 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("default"), _isSigned(false), _signGrade(30), _execGrade(60)
{
	
}
Form::Form(const std::string& name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if(this->_signGrade < 1)
		throw(Form::GradeTooHighException());
	else if(this->_signGrade > 150)
		throw(Form::GradeTooLowException());
	if(this->_execGrade < 1)
		throw(Form::GradeTooHighException());
	else if(this->_execGrade >150)
		throw(Form::GradeTooLowException());
}
Form::Form(Form const &src):_name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{

}
Form::~Form(void)
{
	
}

Form &Form::operator=(Form const &src)
{
	this->_isSigned = src._isSigned;
	return(*this);
}

const std::string&	Form::getName() const
{
	return(_name);
}
bool			Form::getIsSigned() const
{
	return(_isSigned);
}
int			Form::getSignGrade() const
{
	return(_signGrade);
}
int			Form::getExecGrade() const
{
	return(_execGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Grade too low!");
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
	str << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " SignGrade: " << form.getSignGrade() << " ExecuteGrade: " << form.getExecGrade() << std::endl;
	return(str);
}