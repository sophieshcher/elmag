# import re
# def split_paragraph_into_sentences(paragraph):
#     sentences = re.split(r'(?<=[.!?])\s+|(?<=\.\.\.)\s+', paragraph)
#     sentences = [sentence.strip() for sentence in sentences if sentence.strip()]
#     return sentences
#
# paragraph = input("Введіть текст: ")
# sentences = split_paragraph_into_sentences(paragraph)
#
# print("Речення:")
# for sentence in sentences:
#     print(sentence)

sentences = [
    "яблуко",
    "банан",
    "груша",
    "gghjh",
    "453673",
    "gghjh",
    "wefb",
    "апельсин",
    "яблуко",
    "банан",
    "киві",
    "груша",
    "мандарин",
    "апельсин",
    "груша",
    "банан"
]


def remove_duplicates(input_list):
    unique_list = []
    for item in input_list:
        if item not in unique_list:
            unique_list.append(item)
    return unique_list

unique_fruits = remove_duplicates(sentences)

def merge_sort(input_list):
    if len(input_list) <= 1:
        return input_list
    mid = len(input_list) // 2
    left_half = merge_sort(input_list[:mid])
    right_half = merge_sort(input_list[mid:])
    return merge(left_half, right_half)

def merge(left, right):
    sorted_list = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_list.append(left[i])
            i += 1
        else:
            sorted_list.append(right[j])
            j += 1

    sorted_list.extend(left[i:])
    sorted_list.extend(right[j:])

    return sorted_list

print(merge_sort(unique_fruits))

