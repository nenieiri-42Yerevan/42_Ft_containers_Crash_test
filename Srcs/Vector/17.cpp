/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:34:18 by vismaily          #+#    #+#             */
/*   Updated: 2022/12/11 17:49:10 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Example 17 */
/* Example for assign */

#include "test.hpp"

namespace	NS_TEST
{
	const std::string	example17()
	{
		std::ostringstream	ss;
	
		NS::vector<int> vec(5, int(42));
		ss << " " << vec.capacity();
		ss << " " << vec.size();
		for (size_t i = 0; i < vec.size(); ++i)
			ss << ' ' << vec[i];
		vec.assign(11, 48);
		ss << " " << vec.capacity();
		ss << " " << vec.size();
		for (size_t i = 0; i < vec.size(); ++i)
			ss << ' ' << vec[i];
		vec.assign(3, 21);
		ss << " " << vec.capacity();
		ss << " " << vec.size();
		for (size_t i = 0; i < vec.size(); ++i)
			ss << ' ' << vec[i];
		vec.assign(0, 2);
		ss << " " << vec.capacity();
		ss << " " << vec.size();
		for (size_t i = 0; i < vec.size(); ++i)
			ss << ' ' << vec[i];
		return (ss.str());
	}
}
