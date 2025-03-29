#!/usr/bin/python3
"""
0-pascal_triangle
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing
    the Pascal's triangle of n.
    If n <= 0, returns an empty list.
    """
    if n <= 0:
        return []

    triangle = [[1]]  # first row is always [1]
    for _ in range(1, n):
        prev_row = triangle[-1]
        new_row = [1]  # each row starts with a 1
        # build the interior of the row
        for i in range(len(prev_row) - 1):
            new_row.append(prev_row[i] + prev_row[i + 1])
        new_row.append(1)  # each row ends with a 1
        triangle.append(new_row)
    return triangle
