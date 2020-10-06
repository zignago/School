people = ['Bob', 'John', 'Smith']

def distinct(L):
    if len(L) < 2:
        return True
    else:
        j = L.pop()
        if j in L:
            return False
        return distinct(L)

def earnsMore(p1,p2):
    global carpenter, painter, plumber

    if p1 == p2:
        return False
    if (p1 == 'John') and (p2 == 'Bob'): #Bob makes more than John
        return False
    if (p1 == painter) and (p2 == plumber): #the plumber makes more than the painter
        return False
    return True

def heardOf(p1, p2):
    global carpenter, painter, plumber
    if p2 == painter: #We know that the carpenter and the plumber are each known by the other 2
        return False
    if(p1 == 'Smith') and (p2 == 'Bob'): #Smith has never heard of Bob
        return False
    return True

def solve2():
    global carpenter, painter, plumber

    for carpenter in people:
        for painter in people:
            for plumber in people:
                if distinct([carpenter, painter, plumber]):

                    sol = heardOf(painter, carpenter)
                    sol = sol and earnsMore('Smith', painter)
                    sol = sol and earnsMore(plumber, 'Bob')
                    sol = sol and heardOf(carpenter, plumber)
                    sol = sol and heardOf('Smith', carpenter)

                    if sol:
                        print("Carpenter =", carpenter, " Painter =", painter," Plumber =", plumber)

solve2()