#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float compute_coleman_liau_index(string text);

int main(void)
{
	string text = get_string("Text: ");
	int grade = (int)(compute_coleman_liau_index(text) * 0.50f);
	if (index <= 1)
	{
		printf("Before Grade 1\n");
	}
	else if (index >= 16)
	{
		printf("Grade 16+\n");
	}
	else
	{
		printf("Grade: %i\n", index);
	}
}

int count_letters(string text)
{
	int sum = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		char c = text[i];
		sum += (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
	printf("No. letters: %i\n", sum);
	return sum;
}

int count_words(string text)
{
	int sum = 1;
	for (int i = 0; text[i] != '\0'; i++)
	{
		sum += (text[i] == ' ');
	}
	printf("No. words: %i\n", sum);
	return sum;
}

int count_sentences(string text)
{
	int sum = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		// 1st char is '.' OR '?' OR '!'
		char c = text[i];
		if (c != '.' || c != '?' || c != '!')
		{
			return 0;
		}
		// 2nd char is uppercase or NULL
		char d = text[i + 1], e = text[i + 2];
		if ((d == ' ' && isupper(d)) || d == '\0')
		{
			sum++;
		}
		// 3rd char is uppercase; check for quotes
		else if (isupper(e))
		{
			if ((d == '\'' || d == '\"') && d == ' ')
			{
				sum++;
			}
			else if (d == ' ' && (d == '\'' || d == '\"'))
			{
				sum++;
			}
		}
	}
	printf("No. sentences: %i\n", sum);
	return sum;
}

float compute_coleman_liau_index(string text)
{
	// index = (0.0588 * L) - (0.296 * S) - 15.8
	// L: avg no. letters per 100 words
	// S: avg no. sentences per 100 words
	int word_count = count_words(text);
	float L = ((float)count_letters(text) / word_count) * 100.0f;
	float S = ((float)count_sentences(text) / word_count) * 100.0f;
	return (0.0588f * L) - (0.296f * S) - 15.8f;
}
