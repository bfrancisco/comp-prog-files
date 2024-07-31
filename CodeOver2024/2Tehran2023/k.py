stock = {}
containers = {}
cur_id = 1

def printContainers():
    print()
    print("+"*20, "CONTAINER")
    for k, v in containers.items():
        print(f'ID: {k}')
        for e in v:
            print(e)
        print()
    print("+"*20)
    print()

def printStock():
    print()
    print("+"*20, "STOCK")
    for k, v in stock.items():
        print(f'{k} : {v}')
    print("+"*20)
    print()

class Good:
    def __init__(self, name, count):
        self.name = name
        self.count = count

    def __str__(self):
        return f'{self.count} {self.name}'

    def __repr__(self):
        return self.__str__()

def parseItem(item):
    tmp = item.split()
    tmp.sort()
    if len(tmp) == 1:
        return Good(tmp[0].lower(), 1)
    # print(tmp)
    count, name = tmp
    return Good(name.lower(), int(count))

def listify(data):
    if len(data) == 2:
        return []
    le, ri = 0, 0 # open close brackets
    lei, rii = -1, -1 # leftmost and rightmost brackets
    data = data[1:-1]
    container = []
    item = ""
    for i in range(len(data)):
        c = data[i]
        if c == '(':
            if le == 0:
                lei = i
            le += 1
        elif c == ')':
            rii = i
            ri += 1
            if le==ri and le+ri > 0:
                container.append(listify(data[lei:rii+1]))
                le, ri = 0, 0
        elif le == ri and c == ',':
            #process item
            if item.strip() == "": continue
            container.append(parseItem(item))
            item = ""
        elif le == ri:
            item += c

    if item.strip() != "":
        container.append(parseItem(item))

    return container

def deleteContainer(id):
    if (id not in containers):
        return False
    containers.pop(id)
    return True

def unpack(delID):
    global cur_id
    if delID not in containers:
        return -1
    addCount = 0
    for ele in containers[delID]:
        if isinstance(ele, Good):
            if ele.name in stock:
                stock[ele.name] += ele.count
            else:
                stock[ele.name] = ele.count

        else:
            containers[cur_id] = ele
            cur_id += 1
            addCount += 1
    
    containers.pop(delID)
    
    return addCount

def countFreq(container):
    global neededFreq
    for ele in container:
        if isinstance(ele, Good):
            if ele.name in neededFreq:
                neededFreq[ele.name] += ele.count
            else:
                neededFreq[ele.name] = ele.count
        else:
            countFreq(ele)

def canPack(neededFreq):
    for name, needCount in neededFreq.items():
        if (name not in stock) or (stock[name] < needCount):
            return False
    
    toRem = []
    for name, needCount in neededFreq.items():
        stock[name] -= needCount
        if stock[name] == 0:
            toRem.append(name)
    
    for name in toRem:
        stock.pop(name)

    return True

def findGood(container, good):
    found = False
    for ele in container:
        if isinstance(ele, Good):
            if good == ele.name:
                return True
        else:
            found = found or findGood(ele, good)
            if found:
                return True
    
    return False     

def contains(good):
    containerCount = 0
    for containerWid in containers.values():
        if (isinstance(containerWid, Good)):
            if containerWid.name == good:
                containerCount += 1
        elif (findGood(containerWid, good)):
            containerCount += 1
    
    return containerCount

def findDepthUtil(good, container, depth):
    global minDepth
    for ele in container:
        if isinstance(ele, Good):
            if ele.name == good:
                minDepth = min(minDepth, depth)
        elif minDepth > depth+1:
            minDepth = min(minDepth, findDepthUtil(good, ele, depth+1))
    
    return minDepth

def findDepth(good):
    global minDepth
    if good in stock:
        minDepth = 0
        return        
    for ele in containers.values():
        findDepthUtil(good, ele, 1)


while True:
    try:
        line = input()
    except:
        break
    
    command, data = line.split(' ', 1)

    if command == "BUY":
        # data is container
        containers[cur_id] = listify(data)
        cur_id += 1
        print("OK")
        # printContainers()
        # printStock()


    elif command == "SELL":
        # data is id
        isOk = deleteContainer(int(data))
        print("OK" if isOk else "DISCARD")
    
    elif command == "UNPACK":
        # data is id
        addCount = unpack(int(data))
        if addCount == -1:
            print("DISCARD")
        else:
            withS = "s" if addCount != 1 else ""
            count = str(addCount) if addCount != 0 else "No"
            print(f"OK, {count} container{withS} added.")
        # printContainers()
        # printStock()
        
    
    elif command == "PACK":
        neededContainers = listify(data)
        neededFreq = {}
        countFreq(neededContainers)
        if (canPack(neededFreq)):
            containers[cur_id] = neededContainers
            cur_id += 1
            print("OK")
        else:
            print("DISCARD")
        
    
    elif command == "?":
        query, good = data.split(' ', 1)
        good = good.lower()
        if query == "COUNT":
            print((0 if good not in stock else stock[good]))
        elif query == "CONTAINS":
            print(contains(good))
        elif query == "MIN":
            minDepth = 10**9
            findDepth(good)
            print(minDepth if minDepth < 10**9 else -1)

# print("\nLAST")
# printContainers()
# printStock()
    