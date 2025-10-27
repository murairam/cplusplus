#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other){
		_target = other._target;
		setIsSigned(other.getIsSigned());
	}
	return *this;
}

void ShrubberyCreationForm::performAction() const
{
	std::ofstream outfile;
	std::string filename = _target + "_shrubbery";
	outfile.open(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
		return;
	}

	outfile << " 	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⣀⢂⣁⣧⣖⡖⠠⢠⠀⠀⢤⡀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣶⡭⣛⠫⡞⠡⠀⡤⢦⠆⠨⠀⠀⢸⠋⠬⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠒⢈⠀⢭⣉⠂⡄⢠⠖⣸⠑⣆⡦⠊⢀⠀⡂⢉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠍⠚⣁⣀⡀⣤⣰⢶⢷⢼⣿⠏⡡⢠⢗⡙⣶⣞⠛⣍⣪⣼⡠⠠⢶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢄⣎⡠⢠⠉⠋⠓⠉⠋⢨⠘⠚⢉⡄⠁⢾⡌⣗⢿⠛⠲⠛⠋⡝⠑⠀⠌⡤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "        ⠘⠥⠄⡚⣜⢣⣴⡨⢀⡀⣈⡅⠀⣀ ⠈⣄⣀⢿⣯⡔⢊⢺⣷⠆⣷⠶⠂     ⢀⡀⠁			 " << std::endl;
	outfile << " ⠀⠀⠀⠀⠀⠀⠀⠘⢁⣨⡅⠨⣤⣭⣵⣿⢿⢏⠿⠯⡁⠹⣿⡯⡜⠫⢯⢿⡾⣻⡅⣠⣆⣄⣰⡐⠲⠼⢶⠒⠯⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << " ⠀⠀⠀⠀⠀⠀⠂⢈⠙⡋⣟⡛⣷⠴⢼⠓⠋⣺⣴⣷⣷⢾⣿⡿⣡⣠⣸⠗⠻⠹⠿⣟⢥⠯⣿⠻⢅⢴⢎⠄⠀⡄⢠⣀⠀⡀⠀⢄⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⢘⠳⠋⣤⣶⡿⢜⣳⢦⢶⣌⣩⠶⢠⣤⣯⠷⠈⠬⡉⠎⠎⣀⡌⠟⣝⣿⠇⡚⠒⠔⢀⣴⣍⣾⢲⠋⠟⠈⠙⠑⠉⢀⠄⠀" << std::endl;
	outfile << "⠀⠀⠀⡀⣽⠿⠻⡈⠱⢻⣽⡟⣶⣚⡻⢏⢹⡋⠁⣀⣂⣤⣴⠄⢤⣐⣴⡾⣶⠯⣄⣉⢓⡭⢍⡆⡀⣈⣿⣷⡷⠶⠒⢂⣠⣠⢶⣾⣳⣯⣵⡄" << std::endl;
	outfile << "⠀⠀⠀⠰⠴⠀⢘⢉⣧⣥⣏⠳⢈⣫⠞⣿⣷⢤⣤⣿⣿⣾⣧⣾⣿⣿⣿⣗⣿⣿⣿⠋⣚⡃⠿⡭⠹⣷⣿⠾⡿⢤⣤⣜⢿⣯⡿⣷⠯⣽⣿⡾" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠐⠞⠻⣿⢟⣿⢿⠷⠥⣼⣷⢷⣯⠟⠻⠙⢉⡿⣿⢻⣹⣿⣿⢉⢳⣿⣿⣯⡶⡄⡶⢦⣷⣶⣿⡬⢥⠨⣭⣹⠏⠁⡘⢫⠉⠈⠀" << std::endl;
	outfile << "⠀⠀⠔⣼⢂⠬⢌⠧⢋⡛⢡⣮⡡⠈⠓⣃⢀⣒⣊⣽⠻⣛⠟⢿⢸⣯⣿⣓⣿⡟⣷⣟⣿⣿⣿⣿⣻⣷⣟⣒⡺⠏⢰⡿⠿⣶⣶⡻⠒⡿⠦⡀" << std::endl;
	outfile << "⠀⢆⣀⣆⣸⣿⠋⡴⢲⡁⡋⠀⢴⣮⣷⠟⠫⠿⣿⢶⢅⢴⣇⣸⣷⣿⣿⣧⣾⣿⣿⣿⣿⣿⣿⣿⣿⢿⢿⣟⣲⢦⠦⢋⡀⢿⣾⣷⣶⣤⠋⠆" << std::endl;
	outfile << "⠈⠘⠛⠼⠿⡝⣻⠛⠻⠀⠀⠐⠛⢹⣱⣟⣽⣯⣿⡟⡊⣿⣷⣖⢽⣿⣿⣿⢿⣿⠀⠀⠘⠋⠃⠁⠀⠀⠨⠟⠿⡷⣥⣉⠁⠘⠉⠊⠚⠚⠓⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠀⠀⠀⠈⠋⠹⣎⢻⣿⠟⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⢳⡕⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠚⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile.close();
}

std::ostream &operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "Form Name: " << i.getName() << std::endl;
	o << "Is Signed: " << (i.getIsSigned() ? "Yes" : "No") << std::endl;
	o << "Sign Grade: " << i.getSignGrade() << std::endl;
	o << "Exec Grade: " << i.getExecGrade() << std::endl;
	return o;
}
