#ifndef ShrubberyCREATIONFORM_HPP
#define ShrubberyCREATIONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	std::string	_target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

	std::string getTarget() const;
	void execute(Bureaucrat const& executor) const;

};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &shrubberyCreationForm);

#endif