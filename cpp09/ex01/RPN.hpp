/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:24:58 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/30 17:06:01 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN{
private:
    std::stack<int> _args;
    std::string _exp;
    
public:
    RPN();
    RPN(std::string exp);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other );
    ~RPN();

    bool calc();
    bool parse();
};

#endif