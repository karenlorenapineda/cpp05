/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:31:52 by kpineda-          #+#    #+#             */
/*   Updated: 2026/05/03 21:22:11 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	this->_grade = grade;
	if(this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if(this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{
	
}

Bureaucrat const &Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_name = src._name;
	this->_grade = src._grade;
	return(*this);
}

std::string const &Bureaucrat::getName(void) const
{
	return(this->_name);
}

int const &Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if(this->_grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if(this->_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << _name << "signed " << form.getName() << std::endl;
	
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return("Grade is too low");
}

std::ostream &operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return(str << bureaucrat.getName() << ", bureacrat grade " << bureaucrat.getGrade() << std::endl);
}