
def binary_search_deluxe(arr, target):
    def binary_search_left(arr, target):
        left = 0
        right = len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left

    def binary_search_right(arr, target):
        left = 0
        right = len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        return right

    left_index = binary_search_left(arr, target)
    right_index = binary_search_right(arr, target)

    if left_index <= right_index:
        return [left_index, right_index]
    else:
        return [-1, -1]

arr = [1, 2, 3, 10, 10, 10, 12, 12]
target = 10
print(binary_search_deluxe(arr, target))
