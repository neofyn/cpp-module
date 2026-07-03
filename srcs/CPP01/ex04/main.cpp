/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:42:23 by fyudris           #+#    #+#             */
/*   Updated: 2026/07/03 19:22:25 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/**
 * @brief Creates a new string where every occurrence of s1 is replaced by s2.
 *
 * This function does not use std::string::replace, because it is forbidden
 * by the subject. Instead, it searches with find() and manually builds a new
 * result string using append().
 *
 * @param content The original file content.
 * @param s1 The string to search for.
 * @param s2 The replacement string.
 *
 * @return A new string with all non-overlapping occurrences of s1 replaced.
 */
static std::string replaceAll(
	const std::string &content,
	const std::string &s1,
	const std::string &s2
)
{
	std::string	result;
	std::size_t	position;
	std::size_t	found;

	position = 0;
	while ((found = content.find(s1, position)) != std::string::npos)
	{
		result.append(content, position, found - position);
		result.append(s2);
		position = found + s1.length();
	}
	result.append(content, position, content.length() - position);
	return (result);
}

/**
 * @brief Replaces all occurrences of s1 with s2 in a file.
 *
 * The program expects exactly three arguments:
 * 1. filename
 * 2. string to find
 * 3. replacement string
 *
 * It writes the result into a new file named <filename>.replace.
 */
int main(int argc, char **argv)
{
	std::string			filename;
	std::string			s1;
	std::string			s2;
	std::string			content;
	std::string			replacedContent;
	std::string			outputName;
	std::ifstream		input;
	std::ofstream		output;
	std::ostringstream	buffer;

	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return (1);
	}
	input.open(filename.c_str());
	if (!input)
	{
		std::cerr << "Error: cannot open input file." << std::endl;
		return (1);
	}
	buffer << input.rdbuf();
	if (input.bad())
	{
		std::cerr << "Error: failed while reading input file." << std::endl;
		return (1);
	}
	content = buffer.str();
	replacedContent = replaceAll(content, s1, s2);
	outputName = filename + ".replace";
	output.open(outputName.c_str());
	if (!output)
	{
		std::cerr << "Error: cannot open output file." << std::endl;
		return (1);
	}
	output << replacedContent;
	if (!output)
	{
		std::cerr << "Error: failed while writing output file." << std::endl;
		return (1);
	}
	return (0);
}