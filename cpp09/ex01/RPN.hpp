/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:24:58 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/31 15:14:36 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cctype>

class RPN{
private:
    std::stack<int> _args;
    std::string _exp;
    bool isOperator(char c);
    
public:
    RPN();
    RPN(std::string exp);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other );
    ~RPN();

    bool calc();
};

#endif