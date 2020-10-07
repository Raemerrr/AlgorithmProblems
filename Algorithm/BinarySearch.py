def binary_search(array, left, right, target):
    middle_idx = (left + right) // 2
    #마지막 인덱스이면서 target과 같지 않거나 첫번째 인덱스이면서 target과 같지 않다면 종료
    if (middle_idx == len(array) - 1 or middle_idx == 0) and array[middle_idx] != target:
        return False

    middle = array[middle_idx]
    if target == middle:
        return True
    elif target < middle:
        binary_search(array, left, middle_idx - 1, target)
    else : # target > middle:
        binary_search(array, middle_idx + 1, right, target)


if __name__ == "__main__":
    lst = [10, 5, 1, 9, 7, 39, 58, 24, 66, 73, 22, 11]
    lst.sort()
    if binary_search(lst, 0, len(lst), 100):
        print('exist')
    else:
        print('not exist')