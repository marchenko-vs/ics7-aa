def compute_lps_array(string: str) -> list:
    string_len = len(string)
    lps = [0] * string_len
    left = 0
    i = 1
    while i < string_len:
        if string[i] == string[left]:
            left += 1
            lps[i] = left
            i += 1
        else:
            if left != 0:
                left = lps[left - 1]
            else:
                lps[i] = 0
                i += 1
    return lps


def search_kmp(string: str, text: str):
    occurrences = list()
    string_len = len(string)
    text_len = len(text)
    lps = compute_lps_array(string)
    num_of_occur = i = j = 0
    while (text_len - i) >= (string_len - j):
        if string[j] == text[i]:
            j += 1
            i += 1
        if j == string_len:
            occurrences.append(i - j)
            num_of_occur += 1
            j = lps[j - 1]
        elif i < text_len and string[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return num_of_occur, occurrences


def print_circuit(circuit: list):
    print(f'Название трассы: {circuit[1]}, протяженность: {circuit[0]} м.')


def main():
    terms = ["не очень коротк", "очень коротк", "коротк", "средн", "не очень длинн", "очень длинн", "длинн", "все"]
    dictionary = {terms[0]: [5000, 7000], terms[1]: [1000, 3000], terms[2]: [3000, 5000], terms[3]: [5000, 7000], terms[4]: [5000, 7000], terms[6]: [7000, 9000], terms[5]: [9000, 11000]}
    circuits = [[1367, 'Тренировочная трасса в Дохе'],
                [2313, 'Тренировочная трасса в Абу-Даби'],
                [2987, 'Тренировочная трасса в Валенсии'],
                [3340, 'Трасса Монте-Карло'],
                [3955, 'Moscow Raceway'],
                [4309, 'Интерлагос'],
                [5100, 'Нюрбургринг'],
                [5183, 'Игора Драйв'],
                [5793, 'Национальный автодром Монцы'],
                [5891, 'Автодром Сильверстоун'],
                [7004, 'Спа-Франкоршам'],
                [7464, 'Уличная трасса в Лас-Вегасе'],
                [8123, 'Национальная трасса Айдахо'],
                [8792, 'Автодром Нью-Йорка'],
                [10378, 'Северная петля'],
                [10801, 'Трасса Пескара']]
    obj = ['трасса Формулы 1', 'трассы Формулы 1', 'трасс Формулы 1']
    print('Гоночные трассы Формулы 1.')
    question = input('Задайте вопрос: ')
    obj_exists = False
    for i in range(len(obj)):
        result = search_kmp(obj[i].lower(), question.lower())
        if result[0] > 0:
            obj_exists = True
            break
    if not obj_exists:
        print('Ваш вопрос не связан с трассами Формулы 1.')
        return
    key = None
    for i in range(len(terms)):
        result = search_kmp(terms[i], question.lower())
        if result[0] > 0:
            key = terms[i]
            break
    if key == 'все':
        for i in range(len(circuits)):
            print_circuit(circuits[i])
    elif key:
        length = dictionary.get(key)
        if length:
            for i in range(len(circuits)):
                if (length[0] < circuits[i][0] < length[1]):
                    print_circuit(circuits[i])
    else:
        print('Я еще не умею отвечать на такие вопросы.')

if __name__ == '__main__':
    main()
