store = {}
while True:
    try:
        line = input()
    except:
        break
    if line[0] == '!':
        store.pop(line[1:], None)
    elif '=' in line:
        key, value = line.split('=', 1)
        if not key in store:
            store[key] = value
    else:
        if line in store:
            print(store[line])
        else:
            print(f"{line}: Not found")
