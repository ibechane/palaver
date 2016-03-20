#!/usr/bin/env python3
'''
Find target number (an integr) from source string by searching all possible
expressions made from source and the operations *, /, +, and -. Order of
numbers in source string is maintained and expressions are evaluated from left
to right, with order of operations ignored. Paths that hit the target are
printed to stdout.

Example:
    source = 314
    target = 12

Possible paths:
    Path                        Expression:         Evaluated Expression:
    3 -> 1 -> 4                 314                 314

    3 -> * -> 1 -> 4            3 * 14              42
    3 -> / -> 1 -> 4            3 / 14              0.21428571428571427
    3 -> + -> 1 -> 4            3 + 14              14
    3 -> - -> 1 -> 4            3 - 14              -11

    3 -> 1 -> * -> 4            31 * 4              124
    3 -> 1 -> / -> 4            31 / 4              7.75
    3 -> 1 -> + -> 4            31 + 4              35
    3 -> 1 -> - -> 4            31 - 4              27

    3 -> * -> 1 -> * -> 4       3 * 1 * 4           12
    3 -> / -> 1 -> / -> 4       3 / 1 / 4           0.75
    3 -> + -> 1 -> + -> 4       3 + 1 + 4           8
    3 -> - -> 1 -> - -> 4       3 - 1 - 4           -2

    etc...
'''
from copy import deepcopy


def evaluate_path(path):
    '''Returns the result of evaluating the path in order. The path is
    consumed. An empty path returns None.'''
    result = None
    operand, operator = '', None

    while len(path) > 0:
        itm = path.pop(0)

        while itm not in '*/+-' and len(path) > 0:
            operand += itm
            itm = path.pop(0)

        if len(path) == 0:
            operand += itm

        if operator is not None:
            if operator == '*':
                result *= int(operand)
            elif operator == '/':
                result /= int(operand)
            elif operator == '+':
                result += int(operand)
            elif operator == '-':
                result -= int(operand)
        else:
            result = int(operand)

        operator = itm
        operand = ''

    return result


def search(src_str, target, paths):
    '''Search entry point. Assumes non-empty src_str made of integers and a
    non-empty target made of integers.'''
    search_DFS(src_str, 1, target, [src_str[0]], paths)


def search_DFS(src_str, indx, target, path, paths):
    '''Recursive search for target. Paths that hit the target are appended to
    paths.'''
    if indx == len(src_str):
        check_path(path, target, paths)
    else:
        for vertex in src_str[indx] + '*/+-':
            if vertex == src_str[indx]:
                new_path = path + [vertex]
            else:
                new_path = path + [vertex, src_str[indx]]

            search_DFS(src_str, indx+1, target, new_path, paths)


def check_path(path, target, paths):
    '''Appends path to paths if it hits the target.'''
    if evaluate_path(deepcopy(path)) == int(target):
        paths.append(path)


if __name__ == '__main__':
    src = '3141'
    target = '12'

    paths = []
    search(src, target, paths)

    for path in paths:
        expression = ''

        for itm in path:
            expression += itm

        expression += ' = ' + target

        print(expression)
