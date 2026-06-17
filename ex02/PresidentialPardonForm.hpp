/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:07:29 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/17 20:19:51 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	std::string 	_target;
public:
	
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

	std::string getTarget() const;
	void	execute(Bureaucrat const& executor) const;
};

std::ostream	&operator<<(std::ostream& str, const PresidentialPardonForm& presidentialPardonForm);

#endif