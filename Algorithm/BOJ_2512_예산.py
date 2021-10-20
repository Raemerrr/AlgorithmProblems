def binary_search(array, left, right, target):
    #예산과 딱 일치하는 값을 얻지 못했을때 가장 가까운 값을 답으로 택한다.
    tempAns = 0
    while left <= right:
        middle_value = (left + right) // 2
        middle = 0
        for i in array:
            middle += i if middle_value >= i else middle_value

        if target == middle:
            return middle_value
        elif target < middle:
            right = middle_value - 1
        else:
            left = middle_value + 1
            #이분 탐색을 하며 답은 아니지만 가능한 범위에 있는 값을 저장
            tempAns = middle_value
    #예산과 가장 가까운 값
    return tempAns


if __name__ == "__main__":
    n = int(input())
    lst = list(map(int, input().split()))
    m = int(input())
    lst.sort()
    print(binary_search(lst, 0, lst[len(lst) - 1], m))