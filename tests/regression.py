def linear(a, b):
    def f(x):
        return (a * x + b)
    return (f)

def read_csv(filename):
    file = open(filename, "r")
    labels = file.readline()[:-1].split(',')
    print("We get {} from {}".format(labels[1], labels[0]))
    map = {}
    for line in file:
        x, y = line.split(',')
        map[int(x)] = int(y)
    file.close()
    return (map)

def distance(map):
    def partial(is_horizontal):
        def total(f):
            sum = 0
            for (x,y) in map.items():
                sum += (y - f(x)) * (x if (is_horizontal) else 1)
            return (sum / len(map))
        return (total)
    return (partial)

def train():
    a = b = 0
    F = read_csv("data.csv")
    dist = distance(F)
    b_delta = dist(False)
    a_delta = dist(True)
    count = 0
    while (abs(b_delta(linear(a,b))) + abs(a_delta(linear(a,b))) > 0.001):
        b += b_delta(linear(a, b))
        m = max(F)
        a += a_delta(linear(a, b)) / (m * F[m] * 3)
        print("f(x) = {}.x + {}".format(a, b))
        count += 1
    print(count)
    return (a, b)
