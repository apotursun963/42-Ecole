import random

def generate_unique_random_numbers(count, lower_bound=1, upper_bound=10000):
    random_numbers = set()
    while len(random_numbers) < count:
        num = random.randint(lower_bound, upper_bound)
        random_numbers.add(num)
    return list(random_numbers)

# Kullanıcıdan sayıyı alalım
count = int(input("Kaç tane rastgele sayı üretmek istersiniz? "))

# Sayıları üret
random_numbers = generate_unique_random_numbers(count)

# Sonuçları yazdır
print("Üretilen rastgele sayılar:")
print(" ".join(map(str, random_numbers)))
print(len(random_numbers))