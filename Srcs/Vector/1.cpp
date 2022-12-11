/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:40:01 by vismaily          #+#    #+#             */
/*   Updated: 2022/12/11 17:04:46 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Example 1 */
/* Example for constructor without parametrs */
/* Example for size and capacity with int */
/* Example for push_back */

#include "test.hpp"

namespace	NS_TEST
{
	const std::string	example1()
	{
		std::ostringstream	ss;

		NS::vector<int>	vec;
		(ss << " ", ss << vec.capacity());
		(ss << " ", ss << vec.size());
		vec.push_back(42);
		(ss <<  " ", ss << vec[0]);
		(ss <<  " ", ss << vec.capacity());
		(ss <<  " ", ss << vec.size());
		vec.push_back(84);
		(ss << " ", ss << vec[1]);
		(ss << " ", ss << vec.capacity());
		(ss << " ", ss << vec.size());
		vec.push_back(168);
		(ss << " ", ss << vec.at(2));
		(ss << " ", ss << vec.capacity());
		(ss << " ", ss << vec.size());
		vec.push_back(336);
		vec.push_back(672);
		(ss << " ", ss << vec.at(3));
		(ss << " ", ss << vec.capacity());
		(ss << " ", ss << vec.size());
		return (ss.str());
	}
}
