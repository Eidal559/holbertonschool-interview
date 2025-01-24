#!/usr/bin/python3
"""
Module: 0-rotate_2d_matrix
Defines a function rotate_2d_matrix(matrix) that rotates an n x n matrix
90 degrees clockwise in-place.
"""


def rotate_2d_matrix(matrix):
    """
    Rotates an n x n 2D matrix 90 degrees clockwise in-place.

    Args:
        matrix (list of list of int): 2D matrix to rotate (modified in-place).
    """
    n = len(matrix)

    # 1. Transpose the matrix in-place (swap rows and columns).
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # 2. Reverse each row to achieve the 90° clockwise rotation.
    for i in range(n):
        matrix[i].reverse()
