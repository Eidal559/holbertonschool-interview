#!/usr/bin/python3

def calculate_min_operations(n):
    if n <= 1:
        return 0
    if n % 2 == 0:
        return 1 + calculate_min_operations(n // 2)
    else:
        return 1 + calculate_min_operations(n - 1)
    
def min_operations(n):
    return calculate_min_operations(n)

