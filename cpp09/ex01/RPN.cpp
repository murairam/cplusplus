/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:27:14 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/31 15:15:48 by mmiilpal         ###   ########.fr       */
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

bool RPN::isOperator(char c){
    return std::string("+-*/").find(c) != std::string::npos;
}


bool RPN::calc(){
    std::istringstream iss(_exp);
    std::string token;

    while (iss >> token){
		if (token.length() == 1 && std::isdigit(token[0])){
			int value = token[0] - '0';  // Convert char to int
			_args.push(value);
			continue;
		}

        // token is not a number -> must be single operator
        if (token.length() != 1 || !isOperator(token[0])){
            std::cout << "Error" << std::endl;
            return false;
        }

        if (_args.size() < 2){
            std::cout << "Error" << std::endl;
            return false;
        }

        int second = _args.top(); _args.pop();
        int first  = _args.top(); _args.pop();
        int result = 0;
        switch (token[0]){
            case '+': result = first + second; break;
            case '-': result = first - second; break;
            case '*': result = first * second; break;
            case '/':
                if (second == 0){
                    std::cout << "Error" << std::endl;
                    return false;
                }
                result = first / second; break;
            default:
                std::cout << "Error" << std::endl;
                return false;
        }
        _args.push(result);
    }

    if (_args.size() != 1){
        std::cout << "Error" << std::endl;
        return false;
    }
    std::cout << _args.top() << std::endl;
    return true;
}