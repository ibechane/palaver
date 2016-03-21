from __future__ import division

def find_paths(src, target):
    """ Loop through possible expressions and check if they equal the target """
    src = str(src)
    inserts = ['', '+', '-', '*', '/']
    num_insert_combos = len(inserts) ** (len(src) - 1)
    good_paths = []
    for combo in xrange(num_insert_combos):
        insert = get_base_five(combo).zfill(len(src) - 1)
        path = []
        for i in xrange(len(src)):
            path.append(src[i]) # append a digit
            try:
                operation = inserts[int(insert[i])]
                path.append(operation)
            except IndexError:
                pass
        path = ''.join(path)
        result = eval(path)
        if result == target:
            expression = "%s = %s" % (path, target)
            good_paths.append(expression)
    return good_paths

def get_base_five(num):
    """ Takes in base-10 number and returns base-5 representation as string """
    digits = []
    while num != 0:
        digits.append(num % 5)
        num //= 5
    return ''.join(map(str,digits))[::-1]

if __name__ == "__main__":
    src = 3141
    target = 12
    paths = find_paths(src, target)
    print("\n".join(paths))
