def avg(list):
    return (float(sum(list)) / len(list))

def apply(map, f_x, f_y):
    return {f_x(x): f_y(y) for x,y in map.items()}

def get_utils(list):
    mean = avg(list)
    range = max(list) - min(list)
    print("\t{} {}".format(mean, range))
    range /= 2.0
    def normalize(x):
        return ((x - mean) / range)
    def denormalize(z):
        return (z * range + mean)
    return (normalize, denormalize)

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
    for (x, y) in map.items():
        print("{:.4}, {:.4}".format(x, y))
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
    norm_mil, denorm_mil = get_utils(F.keys())
    norm_pri, denorm_pri = get_utils(F.values())
    delta = distance(apply(F, norm_mil, norm_pri))
    avg_dist = delta(lambda f,x,y: y-f(x))
    adhoc = delta(lambda f,x,y: (y-f(x))*x)
    cost = delta(lambda f,x,y: (y-f(x))**2)
    theta = gradient_descent([avg_dist, adhoc, cost])
    return (denorm_pri(theta[0]), theta[1])

def gradient_descent(distance_functions):
    count = 0
    learning_rate = 1
    theta = [0, 0]
    prev_cost = 200
    cur_cost = 100
    while (count < 300 and abs(cur_cost - prev_cost) > 0.00001):
        f = linear(theta[1], theta[0])
        prev_cost = cur_cost
        cur_cost = distance_functions[2](f)
        for i in range(2):
            theta[i] += learning_rate * distance_functions[i](f)
        print("[{:.4}] f(x) = {:.4}.x + {:.4}".format(cur_cost, theta[1], theta[0]))
        count += 1
    print(count)
    return (theta)
