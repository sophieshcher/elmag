# 2 варіант

def word_count(text):
    words = text.lower().split()
    words = [word.strip(".,!?():;") for word in words]
    word_dict = {}

    for word in words:
        if word:
            word_dict[word] = word_dict.get(word, 0) + 1
    return word_dict

text = (input("Введіть текст: "))
# text = "Сім довгих, сповнених складнощів років Володимир витратив, щоб утвердитися в Києві. Сім довгих, сповнених складнощів років запровадив на Русі християнство."

for word, count in word_count(text).items():
    print(f"{word}: {count}")

