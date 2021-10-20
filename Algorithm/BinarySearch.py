def binary_search(array, left, right, target):
    #while Loop 내에서 찾으면 존재
    while left <= right:
        middle_idx = (left + right) // 2
        middle = array[middle_idx]
        if target == middle:
            return True
        elif target < middle:
            right = middle_idx - 1
        else:
            left = middle_idx + 1
    #while Loop 내에서 찾지 못하면 존재하지 않음
    return False


if __name__ == "__main__":
    lst = [10, 5, 1, 9, 7, 39, 58, 24, 66, 73, 22, 11]
    lst.sort()
    if binary_search(lst, 0, len(lst), 24):
        print('exist')
    else:
        print('not exist')