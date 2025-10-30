/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:27:14 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/30 17:50:56 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _args(), _exp(""){
    
};

RPN::RPN(std::string exp): _args(), _exp(exp){
    
};

RPN::RPN(const RPN& other): _args(other._args), _exp(other._exp){
    
};

RPN& RPN::operator=(const RPN& other ){
    if (this != &other){
        _args = other._args;
        _exp = other._exp;
    }
    return *this;
};

RPN::~RPN(){};

bool isOperator(char c)
{
    return std::string("+-*/").find(c) != std::string::npos;
}

bool RPN::parse(){
    for (std::string::iterator it = _exp.begin(); it != _exp.end(); ++it){
        if(std::isdigit(static_cast<unsigned char>(*it)))
            _args.push((int) *it - '0');
        if(isOperator(*it)){
            calculate();
        }
        
    }
    return true;
}


bool RPN::calc(){
    std::cout << _exp << std::endl;
    if (!parse())
        return false;
    std::cout << _args.top() << std::endl;
    return true;
}