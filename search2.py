from __future__ import division
import re


def find_paths(src, target):
    """ Loop through possible expressions and check if they equal the target """
    src = str(src)
    inserts = ['', '+', '-', '*', '/']
    num_insert_combos = len(inserts) ** (len(src) - 1)
    good_paths = []
    for combo in xrange(num_insert_combos):
        insert = change_base(combo, len(inserts)).zfill(len(src) - 1)
        path = []
        for i in xrange(len(src)):
            path.append(src[i])  # append a digit
            try:
                operation = inserts[int(insert[i])]  # use digit of base-changed number as index of operation
            except IndexError:  # there will always be one fewer operation than digits
                operation = ''
            path.append(operation)
        path = ''.join(path)
        result = evaluate_sequentially(path)
        # print("%s = %s" % (path, result))
        if result == target:
            expression = "%s = %s" % (path, target)
            good_paths.append(expression)
    return good_paths


def change_base(num, base):
    """ Takes in base-10 number and returns base-5 representation as string """
    if base > 10 or base < 2 or type(base) is not int:
        raise Exception("Only supports integer bases from 2 - 10")
    if base == 10:
        return str(num)
    digits = []
    while num != 0:
        digits.append(num % base)
        num //= base
    return ''.join(map(str, digits))[::-1]


def evaluate_sequentially(path):
    """ Takes a mathematical expression without parens and performs the operations sequentially,
        ignoring normal order of operations """
    ops = re.findall(r'\W*\d+', path)  # returns operation pieces, e.g. ['3', '*1', '/41']
    result = ops[0]
    for op in ops[1:]:
        try:
            result = eval(str(result) + op)
        except ZeroDivisionError:
            result = 'NaN'
            break
    return result


if __name__ == "__main__":
    my_src = 3141
    my_target = 12
    my_paths = find_paths(my_src, my_target)
    print("\n".join(my_paths))
