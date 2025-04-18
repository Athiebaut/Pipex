/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:13:45 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 01:38:17 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Frees a dynamically allocated array of strings.
 *
 * This function is used to free all the memory allocated for an array of 
 * strings, including each individual string and the array itself.
 *
 * @param ptr A pointer to the array of strings to be freed.
 * @param i The number of strings in the array that need to be freed.
 *          This should be the count of allocated strings before the function is called.
 *
 * @return Always returns NULL (0) to indicate the array has been freed.
 */
static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

/**
 * @brief Counts the number of words in a string separated by a given delimiter.
 * 
 * This function iterates through the input string `str` and counts the number
 * of words, where a word is defined as a sequence of characters not equal to
 * the delimiter `c`. Consecutive delimiters are skipped, and the function 
 * ensures that only valid words are counted.
 * 
 * @param str The input string to be analyzed.
 * @param c The delimiter character used to separate words in the string.
 * @return The number of words found in the string.
 */
static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

/**
 * @brief Copies a word from the source string `s` into the provided `word` buffer.
 *
 * This function takes a substring from the source string `s` starting at index
 * `i - word_len` and copies it into the `word` buffer. The copied substring is
 * null-terminated.
 *
 * @param word      A pointer to the buffer where the word will be stored.
 * @param s         The source string from which the word is extracted.
 * @param i         The current index in the source string.
 * @param word_len  The length of the word to be copied.
 * @return          A pointer to the `word` buffer containing the copied word.
 */
static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

/**
 * @brief Splits a string into an array of words based on a delimiter character.
 *
 * This function processes the input string `s` and splits it into individual
 * words separated by the character `c`. It allocates memory for each word and
 * stores them in the array `s2`. The number of words to split is specified by
 * `num_words`.
 *
 * @param s The input string to be split.
 * @param c The delimiter character used to separate words.
 * @param s2 A pre-allocated array of strings to store the resulting words.
 * @param num_words The number of words to extract from the input string.
 * @return A pointer to the array of strings `s2` containing the split words,
 *         or NULL if memory allocation fails.
 *
 * @note The caller is responsible for ensuring that `s2` has enough space to
 *       store `num_words` pointers. If memory allocation for a word fails,
 *       the function will free any previously allocated memory using
 *       `free_array` and return NULL.
 */
static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2)
			return (free_array(s2, word));
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

/**
 * ft_split - Splits a string into an array of strings based on a delimiter.
 *
 * @s: The input string to be split. Must be a null-terminated string.
 * @c: The delimiter character used to split the string.
 *
 * Return: A pointer to an array of strings (char **), where each string is a 
 *         segment of the input string separated by the delimiter. The array 
 *         is null-terminated. Returns NULL if memory allocation fails or if 
 *         the input string is NULL.
 *
 * Note: This function relies on helper functions `ft_count_words` to count 
 *       the number of words in the input string and `ft_split_words` to 
 *       perform the actual splitting and populate the array.
 */
char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	s2 = ft_split_words(s, c, s2, num_words);
	return (s2);
}
