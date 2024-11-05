#include "slide_line.h"

/* Function prototypes */
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers containing `size` elements
 * @size: Number of elements in `line`
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
    if (line == NULL || size == 0 || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    return 1;
}


/**
 * slide_left - Helper function to slide and merge elements to the left
 * @line: Points to an array of integers containing `size` elements
 * @size: Number of elements in `line`
 */

void slide_left(int *line, size_t size)
{
    size_t i, pos = 0;

    /* First pass: Slide all non-zero values to the left */
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[pos++] = line[i];
        }
    }
    /* Fill the rest with zeros */
    for (i = pos; i < size; i++)
    {
        line[i] = 0;
    }

    /* Second pass: Merge adjacent values and slide again */
    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == line[i + 1] && line[i] != 0)
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }

    /* Final pass: Slide all non-zero values to the left again */
    pos = 0;
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[pos++] = line[i];
        }
    }
    for (i = pos; i < size; i++)
    {
        line[i] = 0;
    }
}

/**
 * slide_right - Helper function to slide and merge elements to the right
 * @line: Points to an array of integers containing `size` elements
 * @size: Number of elements in `line`
 */

void slide_right(int *line, size_t size)
{
    size_t i, pos = size - 1;

    /* First pass: Slide all non-zero values to the right */
    for (i = size; i-- > 0;)
    {
        if (line[i] != 0)
        {
            line[pos--] = line[i];
        }
    }
    /* Fill the rest with zeros */
    for (i = 0; i <= pos; i++)
    {
        line[i] = 0;
    }

    /* Second pass: Merge adjacent values and slide again */
    for (i = size - 1; i > 0; i--)
    {
        if (line[i] == line[i - 1] && line[i] != 0)
        {
            line[i] *= 2;
            line[i - 1] = 0;
        }
    }

    /* Final pass: Slide all non-zero values to the right again */
    pos = size - 1;
    for (i = size; i-- > 0;)
    {
        if (line[i] != 0)
        {
            line[pos--] = line[i];
        }
    }
    for (i = 0; i <= pos; i++)
    {
        line[i] = 0;
    }
}
