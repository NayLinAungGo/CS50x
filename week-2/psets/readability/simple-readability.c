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
	int grade = (int)compute_coleman_liau_index(text) * 0.50f;
	printf("Grade: %i\n", grade);
}

int count_letters(string text)
{
	int sum = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		char c = text[i];
		sum += (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
	return sum;
}

int count_words(string text)
{
	int sum = 1;
	for (int i = 0; text[i] != '\0'; i++)
	{
		sum += (text[i] == ' ');
	}
	return sum;
}

int count_sentences(string text)
{
	int sum = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		char c = text[i];
		sum += (c == '.' || c == '?' || c == '!');
	}
	return sum;
}

float compute_coleman_liau_index(string text)
{
	// index = (0.0588 * L) - (0.296 * S) - 15.8
	// L: avg no. letters per 100 words; S: avg no. sentences per 100 words
	int word_count = count_words(text);
	float L = ((float)count_letters(text) / word_count) * 100.0f;
	float S = ((float)count_sentences(text) / word_count) * 100.0f;
	//printf("L: %f\nS: %f\n", L, S);
	return (0.0588f * L) - (0.296f * S) - 15.8f;
}
