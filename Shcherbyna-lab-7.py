import matplotlib.pyplot as plt

def read_sunspot_data(filename):
    months = []
    sunspots = []
    with open(filename, "r", encoding="utf-8-sig") as file:
        for line in file:
            month = int(line.split()[0])
            spot = float(line.split()[1])
            months.append(month)
            sunspots.append(spot)
    return months, sunspots


def plot_first_1000(months, sunspots):
    m1000 = months[:1000]
    y1000 = sunspots[:1000]

    plt.figure(figsize=(10, 4))
    plt.plot(m1000, y1000, label="Перші 1000 значень", color="green")
    plt.title("Сонячні затемнення — перші 1000 місяців")
    plt.xlabel("Місяць")
    plt.ylabel("Кількість затемнень")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.show()

filename = "sunspots.txt"
months, sunspots = read_sunspot_data(filename)

plot_first_1000(months, sunspots)

