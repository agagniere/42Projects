def avg(list):
    return (float(sum(list)) / len(list))

def apply(map, f_x, f_y):
    return {f_x(x): f_y(y) for x,y in map.items()}

def linear(a, b):
    return (lambda x: (a * x + b))

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
    def partial(single_cost):
        def total(f):
            sum = 0
            for (x,y) in map.items():
                sum += single_cost(f, x, y)
            return (sum / len(map))
        return (total)
    return (partial)

def train():
    F = read_csv("data.csv")
    mx, my = max(F.keys()), max(F.values())
    delta = distance(apply(F, lambda x: x/mx, lambda y: y/my))
    dx = delta(lambda f,x,y: y - f(x))
    dy = delta(lambda f,x,y: (y - f(x)) * x)
    cost = delta(lambda f,x,y: (y - f(x)) ** 2)
    theta = gradient_descent([dx, dy, cost])
    return (theta[0] * my, theta[1] * my / mx)

def gradient_descent(distance_functions):
    count = 0
    learning_rate = 1.5
    theta = [0, 0]
    prev_cost = 200
    cur_cost = 100
    while (count < 1000 and abs(cur_cost - prev_cost) > 10e-11):
        f = linear(theta[1], theta[0])
        prev_cost = cur_cost
        cur_cost = distance_functions[2](f)
        for i in range(2):
            theta[i] += learning_rate * distance_functions[i](f)
        count += 1
    print("Performed {} iterations".format(count))
    return (theta)
